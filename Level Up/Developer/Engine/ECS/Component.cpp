#include "Component.h"
#include "ECSTypes.h"

namespace LevelUp
{
	Component::Component() :m_isActivated(true)
	{
	}
	Component::~Component()
	{

	}
	bool Component::isType(std::string s)
	{
		return (s == m_type);
	}
	bool Component::isECSType(ECSType t)
	{
        //it is a component
		return ECSType::ECSTYPE_COMPONENT == t;
	}
	bool Component::isActivated()
	{
		return m_isActivated;
	}
	void Component::setIsActivated(bool b)
	{
		m_isActivated = b;
	}
}