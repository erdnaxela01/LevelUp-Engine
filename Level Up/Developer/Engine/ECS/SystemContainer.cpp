#include "SystemContainer.h"
#include "System.h"
#include "Entity.h"
#include "../../Core/StandardTemplates.h"

namespace LevelUp
{

	SystemContainer::SystemContainer()
	{
		m_systems = {};
	}
    SystemContainer::~SystemContainer()
    {
    }
	void SystemContainer::removedComponent(APT::WeakPointer<Entity> e)
    {
		for (unsigned int i = 0; i < m_systems.size(); i++)
        {
			m_systems[i]->notifyHasLostComponent(e);
        }
    }
	void SystemContainer::addedComponent(APT::WeakPointer<Entity> e)
    {
		for (unsigned int i = 0; i < m_systems.size(); i++)
		{
			m_systems[i]->notifyHasNewComponent(e);
        }
    }
	void SystemContainer::addSystem(APT::StrongPointer<System> s)
    {
        m_systems.push_back(s.releasePtr());
    }
}