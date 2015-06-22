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
	}

	std::vector<APT::WeakPointer<Attribute>> Agent::getAttributesOfType(std::string type) const
	{
		//loop through all the attributes and push back all the attributes with a specified type
		std::vector<APT::WeakPointer<Attribute>> attrib;
		for (unsigned int i = 0; i < m_attributes.size(); i++)
		{
			if ((m_attributes[i])->isType(type))
			{
				attrib.push_back(m_attributes[i]);
			}
		}
		return attrib;
	}
	Attribute* Agent::getAttribute(std::string ID) const
	{
		//llop through all the attributes and check if it has the specified ID
		for (unsigned int i = 0; i < m_attributes.size(); i++)
		{
			if (m_attributes[i]->hasID(ID))
			{
				return m_attributes[i].getPtr();
			}
		}
		return nullptr;
	}
	void Agent::removeAttribute(std::string ID)
	{
		//find the attribute with the ID and remove it
		for (unsigned int i = 0; i < m_attributes.size(); i++)
		{
			if (m_attributes[i]->hasID(ID))
			{
				m_attributes[i].clear();
				m_attributes.erase(std::find(m_attributes.begin(), m_attributes.end(), m_attributes[i]));
			}
		}
	}
	void Agent::removeAllAttributesOfType(std::string type)
	{
		//loop through all the attributes and push back all the attributes with a specified type
		for (unsigned int i = 0; i < m_attributes.size(); i++)
		{
			if (m_attributes[i]->isType(type))
			{
				m_attributes[i].clear();
				m_attributes.erase(std::find(m_attributes.begin(), m_attributes.end(), m_attributes[i]));
			}
		}
	}
}