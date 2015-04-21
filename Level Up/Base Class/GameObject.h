#ifndef __GAME_OBJECT_H
#define __GAME_OBJECT_H

#include "../Services/Math/LevelUpMath.h"

namespace LevelUp
{
    /*
    Virtual Class meant to be inherited from for a connection between all objects
    - Alex Sabourin April 2015
    */


	class GameObject
	{
	public:
        //sets the position of the object
		virtual void setPosition(float x, float y);
        virtual void setPosition(LVLfloat2& pos);

        //return the object's position
		virtual LVLfloat2& getPosition();
	protected:
        LVLfloat2 m_position;
	};
}

#endif