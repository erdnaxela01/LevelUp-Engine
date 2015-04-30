#include "BaseLevelObject.h"
#include "../Attributes/Attributes.h"

namespace LevelUp
{
	BaseLevelObject::BaseLevelObject()
	{

	}

	BaseLevelObject::~BaseLevelObject()
	{

	}

	void BaseLevelObject::addAttribute(Attribute* a)
	{
		a->setParent(this);
		m_attributes.push_back(a);
	}
}