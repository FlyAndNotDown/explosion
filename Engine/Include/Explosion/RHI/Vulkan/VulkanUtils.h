//
// Created by John Kindem on 2021/4/28.
//

#ifndef EXPLOSION_VULKANUTILS_H
#define EXPLOSION_VULKANUTILS_H

#include <vector>
#include <string>
#include <functional>
#include <algorithm>
#include <optional>

#include <vulkan/vulkan.h>

namespace Explosion::RHI {
    template <typename T>
    using NameComparer = std::function<bool(const char*, const T&)>;

    template <typename T>
    bool CheckPropertySupport(
        const std::vector<const char*>& needs,
        const std::vector<T>& properties,
        const NameComparer<T>& comparer
    ) {
        for (auto& need : needs) {
            bool found = false;
            for (auto& property : properties) {
                if (comparer(need, property)) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                return false;
            }
        }
        return true;
    }

    template <typename TargetType>
    using RateRule = std::function<uint32_t(const TargetType& target)>;

    template <typename TargetType>
    std::vector<std::pair<uint32_t, TargetType>> Rate(const std::vector<TargetType>& targets, const std::vector<RateRule<TargetType>>& rules)
    {
        std::vector<std::pair<uint32_t, TargetType>> result;
        for (auto& target : targets) {
            uint32_t scores = 0;
            for (const auto& rule : rules) {
                scores += rule(target);
            }
            result.emplace_back(std::make_pair(scores, target));
        }
        std::sort(result.begin(), result.end(), [](const auto& a, const auto& b) -> bool { return a.first > b.first; });
        return result;
    }
}

namespace Explosion::RHI {
    std::optional<uint32_t> FindMemoryType(VkPhysicalDeviceMemoryProperties physicalDeviceProps, uint32_t typeFilter, VkMemoryPropertyFlags memProps);
}

#endif //EXPLOSION_VULKANUTILS_H
