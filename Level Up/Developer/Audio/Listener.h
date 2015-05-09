#ifndef __LISTENER_H
#define __LISTENER_H

#include <SFML/Audio.hpp>
#include "../Services/Math/DataTypes.h"

namespace LevelUp
{
	/*
	Class used to wrap around the SFMl library listener, the listener controlls the speakers
	- Alex Sabourin May 2015
	*/
	class Listener
	{
		//set the global volume
		static void setVolume(float volume);
		//set the position of the listener
		static void setPosition(LVLfloat3 pos);
		//get the position of the listener
		static LVLfloat3 getPosition();
		//get the volume of the listener
		static float getVolume();
	};
}

#endif