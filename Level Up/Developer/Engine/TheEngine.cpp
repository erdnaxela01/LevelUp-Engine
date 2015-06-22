#include "TheEngine.h"
#include "../Core/RenderEngine.h"
#include "../../Game Builder/Game/Game.h"
#include "../Core/StandardTemplates.h"
#include "../Core/PerformanceCounter.h"
#include "../UI/Cameras/Camera.h"
#include "../Engine/SceneManager/SceneManager.h"
#include "../Services/ServiceLocator.h"
#include "../Enums/Keys.h"
#include "MVC/MVC.h"
#include <Windows.h>
#include <string>
#include <DirectXMath.h>

namespace LevelUp
{
	APT::StrongPointer<TheEngine> TheEngine::m_theEngine = nullptr;



	LRESULT CALLBACK WndProc(HWND hwnd, //handle to the window
		UINT msg, //the message
		WPARAM wParam, //additional info about the message
		LPARAM lParam) //also additional info about the message
	{

		//wrapped wnd proc inside the engine object
		return getEngine()->handleMessages(hwnd, msg, wParam, lParam);
	}

	LRESULT TheEngine::handleMessages(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
	{
        APT::WeakPointer<Scene> s;
        LevelUpKeys downKey;
        LevelUpKeys upKey;
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
            downKey = convertToKey(wParam);
            m_container.keyDown(downKey);
			s = m_scenes.getActiveScene();
			if (s.getPtr() != nullptr)
			{
                s->getContainer()->keyDown(downKey);
			}
			if (downKey != controllers.down)
			{
				controllers.justPressed = downKey;
				s->getContainer()->justPressed(downKey);
			}
			controllers.down = downKey;
			break;
		case WM_KEYUP:
            upKey = convertToKey(wParam);
            m_container.keyUp(upKey);
			s = m_scenes.getActiveScene();
			if (s.getPtr() != nullptr)
			{
                s->getContainer()->keyUp(upKey);
			}
			controllers.justReleased = upKey;
			break;
		case WM_MOUSEMOVE:
			m_container.mouseMove(getMousePos());
			s = m_scenes.getActiveScene();
			if (s.getPtr() != nullptr)
			{
				s->getContainer()->mouseMove(getMousePos());
			}
			break;
        case WM_SIZE:
			if (m_screenSize.getPtr() != nullptr)
			{
				ServiceLocator::getRenderService()->resizeBuffer(ServiceLocator::getScreenSizeService()->getScreenSize());
			}
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

	TheEngine::~TheEngine()
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
        //initialize the window
		result = initializeWindow(h);
		if (!result)
		{
			return result;
		}

        //display the window
        ShowWindow(m_windowHandle, showCmd);

        if (!(result = provideServices(h)))
        {
            return result;
        }

		m_frameTime = ((1.0 / 60.0));

		//Cache the last tick count, and calculate the next tick count.
		m_lastTickCount = PerformanceCounter::getCounter() * 0.001;
		m_nextTickCount = PerformanceCounter::getCounter() * 0.001 + m_frameTime;

		m_sleepTime = m_frameTime;


        m_sceneBuilder.SystemAdd();
        m_sceneBuilder.SceneLayout();

		return result;
	}
	void TheEngine::render()
	{
		m_render.beginRender();

		m_container.renderViewsWithCamera();
		APT::WeakPointer<Scene> s = m_scenes.getActiveScene();
		if (s.getPtr() != nullptr)
		{
			s->getContainer()->renderViewsWithCamera();
			s->render();
		}

		m_render.finishRender();
	}
	void TheEngine::update()
	{
		//model view controller specific
		m_container.timeElapsed(m_delta);
		m_container.updateModels(m_delta);

		APT::WeakPointer<Scene> s = m_scenes.getActiveScene();
		if (s.getPtr() != nullptr)
		{
			s->getContainer()->updateModels(m_delta);
			s->update(m_delta);
		}
		controllers.resetKeys();
	}

	void TheEngine::shutdown()
	{

		m_render.shutdown();


	}

	APT::WeakPointer<TheEngine> TheEngine::getInstance()
	{
		if (m_theEngine.getPtr() == nullptr)
		{
			m_theEngine.setPtr(new TheEngine());
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
		wc.hbrBackground = CreateSolidBrush(0x000000); //used to determine the background's color, takes an HBRUSH

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

	void TheEngine::updateTimer()
	{
		double currentTickCount = PerformanceCounter::getCounter() * 0.001; // /1000.0;
		double deltaTime = (currentTickCount - m_lastTickCount);
		m_lastTickCount = currentTickCount;
		m_nextTickCount = m_nextTickCount + m_frameTime;
		if (deltaTime > 0.2)
		{
			deltaTime = 0.2;
		}
		m_delta = deltaTime;

		m_sleepTime = PerformanceCounter::getCounter() * 0.001 - m_nextTickCount;

		if (m_sleepTime > m_frameTime)
		{
			m_sleepTime = m_frameTime;
			m_nextTickCount = PerformanceCounter::getCounter() * 0.001 + m_frameTime;
		}
	}

	HWND TheEngine::getHWND()
	{
		return m_windowHandle;
	}

	void TheEngine::addController(APT::WeakPointer<Controller> c)
	{
		m_container.addToControllerMap(c);
	}

	double TheEngine::delta()
	{
		return m_delta;
	}

	APT::WeakPointer<MVCContainer> TheEngine::getContainer()
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


			float xOffSet = static_cast<LONG>(p.x) - rect.left;
			pos.x = xOffSet;
			float yOffSet = static_cast<LONG>(p.y) - rect.top;
			pos.y = yOffSet;
		}
		return pos;
	}

	void TheEngine::addModel(APT::WeakPointer<Model> m)
	{
		m_container.addToModelMap(m);
	}

	void TheEngine::addView(APT::WeakPointer<View> v)
	{
		m_container.addToViewMap(v);
	}

	void TheEngine::addCamera(APT::WeakPointer<Camera> c)
	{
		m_container.addToCameraMap(c);
	}
	APT::WeakPointer<SceneManager> TheEngine::getSceneManager()
	{
		return &m_scenes;
	}

	void TheEngine::removeController(APT::WeakPointer<Controller> c)
    {
        m_container.removeFromControllerMap(c);
    }
	void TheEngine::removeModel(APT::WeakPointer<Model> m)
    {
        m_container.removeFromModelMap(m);
    }
	void TheEngine::removeView(APT::WeakPointer<View> v)
    {
        m_container.removeFromViewMap(v);
    }
	void TheEngine::removeCamera(APT::WeakPointer<Camera> c)
    {
        m_container.removeFromCameraMap(c);
    }

	void TheEngine::addEventHandler(APT::WeakPointer<EventHandler> e)
    {
        m_dispatcher.addHandler(e);
    }
	void TheEngine::removeEventHandler(APT::WeakPointer<EventHandler> e)
	{
		m_dispatcher.removeHandler(e);
	}
    bool TheEngine::provideServices(HINSTANCE h)
    {
        bool result = true;
        ServiceLocator::provideMathAdapter(&m_adapter);

        m_screenSize.setPtr(new WindowScreen(m_windowHandle));
        ServiceLocator::provideScreenSizeService(m_screenSize.getPtr());

        result = m_render.initialize(h, m_windowHandle);
        ServiceLocator::provideRenderService(&m_render);

        return result;
    }

	APT::WeakPointer<SystemContainer> TheEngine::getSystems()
    {
        return &m_systems;
    }
	APT::WeakPointer<TheEngine> getEngine()
	{
		return TheEngine::getInstance();
	}

	bool TheEngine::justPressed(LevelUpKeys key)
	{
		if (key == controllers.justPressed)
		{
			return true;
		}
		return false;
	}
	bool TheEngine::justReleased(LevelUpKeys key)
	{
		if (key == controllers.justReleased)
		{
			return true;
		}
		return false;
	}
	bool TheEngine::keyDown(LevelUpKeys key)
	{
		if (key == controllers.down)
		{
			return true;
		}
		return false;
	}
}