#include "SystemContainer.h"
#include "System.h"
#include "Entity.h"
#include "../../Core/StandardTemplates.h"

namespace LevelUp
{
    SystemContainer::~SystemContainer()
    {
        for (auto i : m_systems)
        {
			if (i != nullptr)
			{
				delete i;
				i = nullptr;
			}
        }
    }
    void SystemContainer::removedComponent(Entity* e)
    {
        for (auto i : m_systems)
        {
            i->notifyHasLostComponent(e);
        }
    }
    void SystemContainer::addedComponent(Entity* e)
    {
        for (auto i : m_systems)
        {
            i->notifyHasNewComponent(e);
        }
    }
    void SystemContainer::addSystem(System* s)
    {
        m_systems.push_back(s);
    }
}