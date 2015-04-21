#ifndef __COMPONENT_H
#define __COMPONENT_H

#include <string>
#include "ECSTypes.h"

namespace LevelUp
{
    /*
    Component for entity pattern, can be placed inside an entity will be run by a system
    - Alex Sabourin April 2015
    */
	class Component
	{
	public:
		Component();
		virtual ~Component();
        //checks the type
		bool isType(std::string s);
        //checks the entity component system type
		virtual bool isECSType(ECSType t);
        //can be deactivated
		bool isActivated();
		void setIsActivated(bool b);
	private:
		std::string m_type;
		bool m_isActivated;
	};
}


#endif