#ifndef __BASELEVELOBJECT_H
#define __BASELEVELOBJECT_H
#include "../ECS/Entity.h"
#include "../Attributes/Agent.h"
#include "../../Services/Math/LevelUpMath.h"
#include "../../../Addons/AutomaticPointers/AutomaticPointers.h"

namespace LevelUp
{
	class Model;
	class View;
	class Controller;
	class Attribute;
    /*
    Basic object for the whole engine
    -Alex April 2015
    */
	class BaseLevelObject : public Entity, public Agent
	{
	public:
		BaseLevelObject();
		virtual ~BaseLevelObject();
        
        //set the position of the object
		virtual void setPosition(float x, float y) = 0;
        //set the position of the object
        virtual void setPosition(LVLfloat2 pos) = 0;
        //return the objects position
        virtual LVLfloat2 getPosition() const = 0;

		virtual float getZ() const = 0;

		virtual void setZ(float z) = 0;

		//adds attributes to its vector of attributes base level object adds the attribute so it can set the parent as itself
		void addAttribute(APT::StrongPointer<Attribute> a);

	};
}

#endif