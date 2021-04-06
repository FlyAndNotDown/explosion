//
// Created by John Kindem on 2021/3/30.
//

#include <Explosion/Driver/Driver.h>
#include <Explosion/Driver/Device.h>
#include <Explosion/Driver/SwapChain.h>

namespace Explosion {
    Driver::Driver() : device(std::make_unique<Device>()) {}

    Driver::~Driver() = default;

    SwapChain* Driver::CreateSwapChain(void* surface, uint32_t width, uint32_t height)
    {
        return new SwapChain(*device, surface, width, height);
    }

    void Driver::DestroySwapChain(SwapChain* swapChain)
    {
        delete swapChain;
    }
}
