#ifndef __SYSTEMCONTAINER_H
#define __SYSTEMCONTAINER_H

#include "System.h"
#include <vector>
#include "../../../Addons/AutomaticPointers/AutomaticPointers.h"

namespace LevelUp
{
    class Entity;
    class SystemContainer
    {
    public:
		SystemContainer();
        virtual ~SystemContainer();
        void removedComponent(APT::WeakPointer<Entity> e);
		void addedComponent(APT::WeakPointer<Entity> e);
		void addSystem(APT::StrongPointer<System> s);
    private:
		std::vector<APT::StrongPointer<System>> m_systems;
    };
}

#endif