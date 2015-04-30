#include "Attributes.h"
#include "../../Core/StandardTemplates.h"
#include "../BasicLevelObject/BaseLevelObject.h"


namespace LevelUp
{
	int Attribute::m_numberOfAttributes = 0;

	Attribute::Attribute() :m_parent(nullptr), m_type("")
	{
		m_numberOfAttributes++;
		m_ID = "Attribute " + m_numberOfAttributes;
	}

	bool Attribute::isType(std::string t)
	{
		return m_type == t;
	}

	BaseLevelObject* Attribute::getParent()
	{
		return m_parent;
	}

	void Attribute::setParent(BaseLevelObject* blo)
	{
		m_parent == blo;
	}

	
	void Attribute::resetParent()
	{
		m_parent = nullptr;
	}

	bool Attribute::hasID(std::string ID)
	{
		return m_ID == ID;
	}
}