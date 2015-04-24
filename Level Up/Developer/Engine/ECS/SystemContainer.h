#ifndef __SYSTEMCONTAINER_H
#define __SYSTEMCONTAINER_H

#include <vector>

namespace LevelUp
{
    class Entity;
    class System;
    class SystemContainer
    {
    public:
        virtual ~SystemContainer();
        void removedComponent(Entity* e);
        void addedComponent(Entity* e);
        void addSystem(System* s);
    private:
        std::vector<System*> m_systems;
    };
}

#endif