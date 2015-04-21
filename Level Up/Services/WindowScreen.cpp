
#include "WindowScreen.h"
#include "../Engine/TheEngine.h"
#include <DirectXMath.h>
#include <Windows.h>
#include <assert.h>

using namespace DirectX;

namespace LevelUp
{
	WindowScreen::WindowScreen(HWND windowHandle)
	{
        assert(windowHandle != nullptr);
		m_windowHandle = windowHandle;
	}

    LVLfloat2 WindowScreen::getScreenSize()
	{
		//get the window rect and return it in float
		RECT dimensions;
		GetClientRect(m_windowHandle, &dimensions);

		unsigned int width = dimensions.right - dimensions.left;
		unsigned int height = dimensions.bottom - dimensions.top;
        return (LVLfloat2((float)width, (float)height));
	}
}