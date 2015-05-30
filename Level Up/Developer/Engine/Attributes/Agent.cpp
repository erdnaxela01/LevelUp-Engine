#include "Agent.h"
#include "Attributes.h"
#include "../../Core/StandardTemplates.h"

namespace LevelUp
{
	Agent::Agent()
	{

	}
	Agent::~Agent()
	{
		//delete all the attributes
		for (auto i : m_attributes)
		{
			if (i != nullptr)
			{
				delete i;
				i = nullptr;
			};
		}
	}

	std::vector<Attribute*> Agent::getAttributesOfType(std::string type) const
	{
		//loop through all the attributes and push back all the attributes with a specified type
		std::vector<Attribute*> attrib;
		for (auto i : m_attributes)
		{
			if (i->isType(type))
			{
				attrib.push_back(i);
			}
		}
		return attrib;
	}
	Attribute* Agent::getAttribute(std::string ID) const
	{
		//llop through all the attributes and check if it has the specified ID
		for (auto i : m_attributes)
		{
			if (i->hasID(ID))
			{
				return i;
			}
		}
		return nullptr;
	}
	void Agent::removeAttribute(std::string ID)
	{
		//find the attribute with the ID and remove it
		for (auto i : m_attributes)
		{
			if (i->hasID(ID))
			{
				if (i != nullptr)
				{
					delete i;
					i = nullptr;
				}
				m_attributes.erase(std::find(m_attributes.begin(), m_attributes.end(), i));
			}
		}
	}
	void Agent::removeAllAttributesOfType(std::string type)
	{
		//loop through all the attributes and push back all the attributes with a specified type
		for (auto i : m_attributes)
		{
			if (i->isType(type))
			{
				if (i != nullptr)
				{
					delete i;
					i = nullptr;
				};
				m_attributes.erase(std::find(m_attributes.begin(), m_attributes.end(), i));
			}
		}
	}
}