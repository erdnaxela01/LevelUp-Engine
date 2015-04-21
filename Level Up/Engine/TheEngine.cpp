#include "TheEngine.h"
#include "../Core/RenderEngine.h"
#include "../Game/Game.h"
#include "../Core/StandardTemplates.h"
#include "../Core/PerformanceCounter.h"
#include "../UI/Cameras/Camera.h"
#include "../Engine/SceneManager/SceneManager.h"
#include "../Services/ServiceLocator.h"
#include "MVC/MVC.h"
#include <Windows.h>
#include <string>
#include <DirectXMath.h>

namespace LevelUp
{
	TheEngine* TheEngine::m_theEngine = nullptr;



	LRESULT CALLBACK WndProc(HWND hwnd, //handle to the window
		UINT msg, //the message
		WPARAM wParam, //additional info about the message
		LPARAM lParam) //also additional info about the message
	{

		//wrapped wnd proc inside the engine object
		return TheEngine::getInstance()->handleMessages(hwnd, msg, wParam, lParam);
	}

	LRESULT TheEngine::handleMessages(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
	{
		Scene* s;
		switch (msg)
		{

		case WM_DESTROY: //when the destroy message is received post a quit message with parameter 0
			PostQuitMessage(0);
			break;
		case WM_PAINT:
			PAINTSTRUCT paintStruct;
			HDC hDC;
			hDC = BeginPaint(hwnd, &paintStruct);
			EndPaint(hwnd, &paintStruct);
			break;
		case WM_KEYDOWN:
			m_container.KeyDown(wParam);
			s = m_scenes.getActiveScene();
			if (s != nullptr)
			{
				s->getContainer()->KeyDown(wParam);
			}
			break;
		case WM_KEYUP:
			m_container.KeyUp(wParam);
			s = m_scenes.getActiveScene();
			if (s != nullptr)
			{
				s->getContainer()->KeyUp(wParam);
			}
			break;
		case WM_MOUSEMOVE:
			m_container.mouseMove(getMousePos());
			s = m_scenes.getActiveScene();
			if (s != nullptr)
			{
				s->getContainer()->mouseMove(getMousePos());
			}
			break;
        case WM_SIZE:
            m_dispatcher.dispatchEvent(DispatchEvents::DISPATCHEVENTS_SCREENRESIZE);
            break;
		default:
			//go to the default window's processing for other messages
			return DefWindowProc(hwnd, msg, wParam, lParam);
		}
		return 0;
	}

	TheEngine::TheEngine()
	{
	}
	bool TheEngine::initialize(HINSTANCE h, int showCmd)
	{

		bool result;
		result = PerformanceCounter::startCounter();
		if (!result)
		{
			return result;
		}
		result = initializeWindow(h);
		if (!result)
		{
			return result;
		}

        ServiceLocator::provideMathAdapter(&m_adapter);

		m_screenSize = new WindowScreen(m_windowHandle);
		ServiceLocator::provideScreenSizeService(m_screenSize);

		ShowWindow(m_windowHandle, showCmd);

		result = m_render.initialize(h, m_windowHandle);
		ServiceLocator::provideRenderService(&m_render);
		if (!result)
		{
			return result;
		}


		m_frameTime = (unsigned long)((1.0 / 60.0) * 1000.0);

		//Cache the last tick count, and calculate the next tick count.
		m_lastTickCount = PerformanceCounter::getCounter();
		m_nextTickCount = PerformanceCounter::getCounter() + m_frameTime;

		m_sleepTime = m_frameTime;

		//initialize the model view controller holder
		m_container.initializeContainer();

		m_scenes.addSceneToMap(new Game());
		m_scenes.pushScene("Game");

		return result;
	}
	void TheEngine::render()
	{
		m_render.beginRender();

		m_container.renderViewsWithCamera();
		Scene* s = m_scenes.getActiveScene();
		if (s != nullptr)
		{
			s->getContainer()->renderViewsWithCamera();
			s->render();
		}

		m_render.finishRender();
	}
	void TheEngine::update(double delta)
	{
		//model view controller specific
		m_container.timeElapsed(delta);
		m_container.updateModels(delta);

		Scene* s = m_scenes.getActiveScene();
		if (s != nullptr)
		{
			s->getContainer()->updateModels(delta);
			s->update(delta);
		}
	}

	void TheEngine::shutdown()
	{

		m_render.shutdown();
		SafeDelete(m_screenSize);


		//this has to stay last
		SafeDelete(m_theEngine);

	}

	TheEngine* TheEngine::getInstance()
	{
		if (m_theEngine == nullptr)
		{
			m_theEngine = new TheEngine();
		}
		return m_theEngine;
	}

	bool TheEngine::initializeWindow(HINSTANCE hInstance)
	{

		/******************************************
		Step 1: Create the window class and set up the parameters
		*******************************************/

		WNDCLASSEX wc = {}; //struct that contains the window's class information

		wc.cbSize = sizeof(WNDCLASSEX); //the size of the window in bytes
		wc.hIconSm = 0; //used to associte and icon to the window
		wc.style = CS_HREDRAW | CS_VREDRAW; //sets the styles using the bitwise operator in order to set the style flags
		wc.lpfnWndProc = WndProc; //points to the window's procedure, can be used by CallWindowProc
		wc.cbClsExtra = 0; //the extra bytes to be allocated to the window class struct, system sets to 0
		wc.cbWndExtra = 0; //teh extra bytes to be allocated after the window instance, system sets it to 0
		wc.hInstance = hInstance; //a handle to the instance that contains the window's wndProc
		wc.hCursor = LoadCursor(0, IDC_ARROW); // cursor to use for the class
		wc.hbrBackground = CreateSolidBrush(0xFFFFFF); //used to determine the background's color, takes an HBRUSH

		wc.lpszMenuName = 0; // specifies the ressource menu associated with the window class 
		wc.lpszClassName = L"Level Up window"; //specifies the window class' name registered with RegisterClass or Register Class EX for findinge later


		/******************************************
		Step 2: Register the newly created class
		*******************************************/


		if (!RegisterClassEx(&wc))
			return false;//Registers a window class (wc) for use by CreateWindow and CreateWindowEx

		//sets the initial size to max size


		/******************************************
		Step 3: Create your window using you window class
		*******************************************/

		RECT rc = { 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT };
		AdjustWindowRect(&rc, WS_OVERLAPPEDWINDOW, FALSE);


		//creates a window and specifies the class, title, style and position, can also take the parent
		m_windowHandle = CreateWindowA("Level Up window", "Level Up window",
            WS_OVERLAPPEDWINDOW,
			CW_USEDEFAULT,
			CW_USEDEFAULT,
			rc.right - rc.left,
			rc.bottom - rc.top,
			NULL,
			NULL,
			hInstance,
			NULL);

		//if the window handle is null display error message
		if (0 == m_windowHandle)
		{
			MessageBox(0, L"CreateWindow Failed", L"Application Error Message", 0);
			return false;
		}
		return true;
	}

	double TheEngine::updateTimer()
	{
		double currentTickCount = PerformanceCounter::getCounter();
		double deltaTime = (currentTickCount - m_lastTickCount) / 1000.0;


		m_lastTickCount = currentTickCount;
		m_nextTickCount = m_nextTickCount + m_frameTime;

		m_sleepTime = m_nextTickCount - PerformanceCounter::getCounter();

		if (m_sleepTime > m_frameTime)
		{
			m_sleepTime = m_frameTime;
			m_nextTickCount = PerformanceCounter::getCounter() + m_frameTime;
		}
		m_delta = deltaTime;

		return deltaTime;
	}

	HWND TheEngine::getHWND()
	{
		return m_windowHandle;
	}

	void TheEngine::addController(Controller* c)
	{
		m_container.addToControllerMap(c);
	}

	double TheEngine::delta()
	{
		return m_delta;
	}

	MVCContainer* TheEngine::getContainer()
	{
		return &m_container;
	}

	/**************************************************
	followMouse
	Description: gets the cursor's position and returns it through reference
	Arguments:  int x : used to pass the value
	int y : used to pass the value
	HWND windowHandle: used to get the cursor pos
	Return: void
	Date: 2015/02/11
	Author: Alexandre Sabourin
	***************************************************/
	LVLfloat2 TheEngine::getMousePos()
	{
		//get the cursor's position if its valid continue to code
		POINT p;
		LVLfloat2 pos;
		if (GetCursorPos(&p))
		{
			RECT rect;
			//get the rect of the client and get the position of the rect relative to the parent window
			GetClientRect(m_windowHandle, &rect);
			MapWindowPoints(m_windowHandle, GetParent(m_windowHandle), (LPPOINT)&rect, 2);


			float xOffSet = (p.x) - rect.left;
			pos.x = xOffSet;
			float yOffSet = (p.y) - rect.top;
			pos.y = yOffSet;
		}
		return pos;
	}

	void TheEngine::addModel(Model* m)
	{
		m_container.addToModelMap(m);
	}

	void TheEngine::addView(View* v)
	{
		m_container.addToViewMap(v);
	}

	void TheEngine::addCamera(Camera* c)
	{
		m_container.addToCameraMap(c);
	}
	SceneManager* TheEngine::getSceneManager()
	{
		return &m_scenes;
	}

    void TheEngine::removeController(Controller* c)
    {
        m_container.removeFromControllerMap(c);
    }
    void TheEngine::removeModel(Model* m)
    {
        m_container.removeFromModelMap(m);
    }
    void TheEngine::removeView(View* v)
    {
        m_container.removeFromViewMap(v);
    }
    void TheEngine::removeCamera(Camera* c)
    {
        m_container.removeFromCameraMap(c);
    }

    void TheEngine::addEventHandler(EventHandler* e)
    {
        m_dispatcher.addHandler(e);
    }
}