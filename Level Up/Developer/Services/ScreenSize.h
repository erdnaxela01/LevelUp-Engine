#ifndef __SCREENSIZE_H
#define __SCREENSIZE_H

#include <DirectXMath.h>
#include "Math\LevelUpMath.h"

namespace LevelUp
{
    //screen size service that will give you your service
	class ScreenSize
	{
	public:
		ScreenSize() {};
		virtual ~ScreenSize() {};
        //get the screens size
        virtual LVLfloat2 getScreenSize() = 0;
	};
}

#endif
