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
        void addComponent(Component* c);
        void removeAllComponentsOfType(std::string s);
	private:
		std::vector<Component*> m_components;


	};
}

#endif