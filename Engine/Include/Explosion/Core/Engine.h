//
// Created by John Kindem on 2021/3/23.
//

#ifndef EXPLOSION_ENGINE_H
#define EXPLOSION_ENGINE_H

#include <cstdint>
#include <string>

namespace Explosion {
    class World;
    class Renderer;

    class Engine {
    public:
        World* CreateWorld(const std::string& name);
        void DestroyWorld(World* world);
        Renderer* CreateRenderer(void* surface, uint32_t width, uint32_t height);
        void DestroyRenderer(Renderer* renderer);

    private:
    };
}

#endif //EXPLOSION_ENGINE_H