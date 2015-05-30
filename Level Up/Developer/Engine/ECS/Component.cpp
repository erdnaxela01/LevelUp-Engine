#include "Component.h"
#include "ECSTypes.h"

namespace LevelUp
{
    int Component::m_numberOfComponents = 0;
    Component::Component() :m_isActivated(true), m_type("")
	{
        m_numberOfComponents++;
        m_ID = "Component " + m_numberOfComponents;
	}
	Component::~Component()
	{
	}
	bool Component::isType(std::string s) const
	{
		return (s == m_type);
	}
	bool Component::isECSType(ECSType t) const
	{
        //it is a component
		return ECSType::ECSTYPE_COMPONENT == t;
	}
	bool Component::isActivated() const
	{
		return m_isActivated;
	}
	void Component::setIsActivated(bool b)
	{
		m_isActivated = b;
	}
}