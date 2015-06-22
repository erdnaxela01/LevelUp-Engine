#include "System.h"

namespace LevelUp
{
	void System::addEntity(APT::WeakPointer<Entity> e)
    {
        m_entities.push_back(e);
    }
	void System::removeEntity(APT::WeakPointer<Entity> e)
    {
        //using an algorithm rease the entity
        m_entities.erase(std::find(m_entities.begin(), m_entities.end(), e));
    }
    bool System::isECSType(ECSType t) const
    {
        return ECSType::ECSTYPE_SYSTEM == t;
    }
}