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
			SafeDelete(i);
		}
	}

	std::vector<Attribute*> Agent::getAttributesOfType(std::string type)
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
	Attribute* Agent::getAttribute(std::string ID)
	{
		//llop through all the attributes and check if it has the specified ID
		for (auto i : m_attributes)
		{
			if (i->hasID(ID))
			{
				return i;
			}
		}
	}
	void Agent::removeAttribute(std::string ID)
	{
		//find the attribute with the ID and remove it
		for (auto i : m_attributes)
		{
			if (i->hasID(ID))
			{
				SafeDelete(i);
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
				SafeDelete(i);
				m_attributes.erase(std::find(m_attributes.begin(), m_attributes.end(), i));
			}
		}
	}
}