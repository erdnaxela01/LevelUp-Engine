#ifndef __AGENT_H
#define __AGENT_H

#include <vector>
#include <string>
#include "../../../Addons/AutomaticPointers/AutomaticPointers.h"

/*
Class meant to hold attributes
Alex Sabourin April 2015

*/

namespace LevelUp
{
	class Attribute;
	class Agent
	{
	public:
		Agent();
		virtual ~Agent();
		//get all the attributes of a specified type
		std::vector<APT::WeakPointer<Attribute>> getAttributesOfType(std::string type) const;
		//get a specific attribute
		Attribute* getAttribute(std::string ID) const;
		//remove a specific attribute
		void removeAttribute(std::string ID);
		//remove all the attributes of a specified type
		void removeAllAttributesOfType(std::string type);

	protected:
		std::vector<APT::StrongPointer<Attribute>> m_attributes;
	};
}

#endif