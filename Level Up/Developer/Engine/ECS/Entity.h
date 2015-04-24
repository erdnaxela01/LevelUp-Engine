#ifndef __ENTITY_H
#define __ENTITY_H

#include <vector>
#include <string>
#include "Component.h"
#include "ECSTypes.h"

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
		std::vector<Component*> getAllComponentsOfType(std::string s);
        //checks the type
		virtual bool isECSType(ECSType t);
        //add a component to the vector of components
        void addComponent(Component* c);
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
		std::vector<Component*> m_components;


	};
}

#endif