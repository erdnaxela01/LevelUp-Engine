#ifndef __ENTITY_H
#define __ENTITY_H

#include <vector>
#include <string>
#include "Component.h"
#include "ECSTypes.h"
#include "../../../Addons/AutomaticPointers/AutomaticPointers.h"

namespace LevelUp
{
    /*
    Box for all the components, can be tacked on to objects for things like physics etc
    - Alex Sabourin
    */
	class Entity
	{
	public:
		Entity();
		virtual ~Entity();
        //get all the components
		std::vector<APT::WeakPointer<Component>> getAllComponentsOfType(std::string s);
        //checks the type
		virtual bool isECSType(ECSType t);
        //add a component to the vector of components
        void addComponent(APT::WeakPointer<Component> c);
        //remove all the components of the same type
        void removeAllComponentsOfType(std::string s);

        //check if it has any specific components
        bool hasComponent(std::string s);

        //check if the entity is active
        bool isActive();
        //set if the entity is active
        void setIsActive(bool b);
	private:
        bool m_isActive;
		std::vector<APT::StrongPointer<Component>> m_components;
		std::vector<APT::StrongPointer<Component>> getAllComponentsOfTypeStrong(std::string s);


	};
}

#endif