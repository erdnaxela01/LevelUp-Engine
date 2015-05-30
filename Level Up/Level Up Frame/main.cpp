
#include "../Developer/Engine/TheEngine.h"
#include <Windows.h>

using namespace std;


int WINAPI WinMain(HINSTANCE hInstance, //is a handle to the current instance of the application
	HINSTANCE hPrevInstance, //legace code from c, used to be a handle to the previous instance of the application, parameter is always NULL
	PSTR cmdLine, // is the command line of the application except for the name
	int showCmd) //controls how the window is show, it can be changed using a SW_ enum, is set at SW_SHOWNORMAL at begining of program
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(cmdLine);

	//initialize the internal engine, including window logic and render
	if (!LevelUp::getEngine()->initialize(hInstance, showCmd))
	{
		return -1;
	}


	//contains the messages to be processed by wndProd
	MSG msg = {};
	SecureZeroMemory(&msg, sizeof(MSG)); // sets a block of memory to NULL or 0 and returns a pointer to the memory

	int returnValue = 0; //  Used to check if GetMessage failed


	while (msg.message != WM_QUIT) // exit loop if we get a quit message
	{
		if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
		{

			if (-1 == returnValue)
			{
				// handle the error then break if desired
				MessageBoxA(0, "GetMessage Failed!", "Error Message", MB_OK);
				break;
			}
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			//updates delta time and passes it to update and render
			LevelUp::getEngine()->updateTimer();
			LevelUp::getEngine()->update();
			LevelUp::getEngine()->render();
			//draw
		}
		
	}

	LevelUp::getEngine()->shutdown(); //shutdown the engine

	return static_cast<int>(msg.wParam);
}