//
// Created by John Kindem on 2021/3/30.
//

#ifndef EXPLOSION_SWAPCHAIN_H
#define EXPLOSION_SWAPCHAIN_H

#include <cstdint>

#include <vulkan/vulkan.h>

namespace Explosion {
    class Device;

    class SwapChain {
    public:
        SwapChain(Device& device, void* surface, uint32_t width, uint32_t height);
        ~SwapChain();

        void CreateSurface();
        void DestroySurface();

    private:
        Device& device;
        void* surface;
        uint32_t width;
        uint32_t height;
        VkSurfaceKHR vkSurface = VK_NULL_HANDLE;
    };
}

#endif //EXPLOSION_SWAPCHAIN_H
