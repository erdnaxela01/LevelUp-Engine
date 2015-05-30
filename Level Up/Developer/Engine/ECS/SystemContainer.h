#ifndef __SYSTEMCONTAINER_H
#define __SYSTEMCONTAINER_H

#include "System.h"
#include <vector>
#include <memory>

namespace LevelUp
{
    class Entity;
    class SystemContainer
    {
    public:
		SystemContainer() {};
        virtual ~SystemContainer();
        void removedComponent(Entity* e);
        void addedComponent(Entity* e);
        void addSystem(System* s);
    private:
        std::vector<System*> m_systems;
    };
}

#endif