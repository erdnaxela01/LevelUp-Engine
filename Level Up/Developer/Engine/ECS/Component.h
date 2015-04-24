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
        //set the activation of the component
		void setIsActivated(bool b);
        std::string componentID();
    protected:
        //get the tyoe of component and if its activated
        std::string m_type;
        std::string m_ID;
	private:
		bool m_isActivated;
        static int m_numberOfComponents;
	};
}


#endif