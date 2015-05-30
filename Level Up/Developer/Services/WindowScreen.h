#ifndef __WINDOWSCREEN_H
#define __WINDOWSCREEN_H

#include <Windows.h>
#include "ScreenSize.h"
#include "../Services/Math/LevelUpMath.h"

namespace LevelUp
{
    //window screen derived of screen size will give you the screensize with the windows API
    //Alex Sabourin April 2015
	class WindowScreen : public ScreenSize
	{
	public:
		WindowScreen() {};
		virtual ~WindowScreen() {};
		//gets the size of the screen
		WindowScreen(HWND windowHandle);
        //get the screen size
        LVLfloat2 getScreenSize();
	private:
		HWND m_windowHandle;
	};
}

#endif