#ifndef __SYSTEM_H
#define __SYSTEM_H

#include <vector>
#include "ECSTypes.h"
#include "../../../Addons/AutomaticPointers/AutomaticPointers.h"
namespace LevelUp
{
    class Entity;

    /*
    abstract system meant to be inherited by all the other systems, much like a notification system
    -Alex Sabourin April 2015
    */

    class System
    {
    public:
		System() {};
		virtual ~System() {};
        //add an entity to the vector
		void addEntity(APT::WeakPointer<Entity> e);
        //notify the system that someone has a new component check if he wants it
		virtual void notifyHasNewComponent(APT::WeakPointer<Entity> e) = 0;
        //notify the system that someone lost a component, he decides what to do with that
		virtual void notifyHasLostComponent(APT::WeakPointer<Entity> e) = 0;
        //remove an entity from the vecotr
        void removeEntity(APT::WeakPointer<Entity> e);

        virtual bool isECSType(ECSType t) const;
    protected:
		std::vector<APT::WeakPointer<Entity>> m_entities;

    };


}


#endif