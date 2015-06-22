#include "BaseLevelObject.h"
#include "../Attributes/Attributes.h"

namespace LevelUp
{
	BaseLevelObject::BaseLevelObject() :Entity(), Agent()
	{

	}

	BaseLevelObject::~BaseLevelObject()
	{

	}

	void BaseLevelObject::addAttribute(APT::StrongPointer<Attribute> a)
	{
		a->setParent(this);
		m_attributes.push_back(a.releasePtr());
	}
}