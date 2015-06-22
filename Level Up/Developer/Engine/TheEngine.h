#ifndef __ENGINE_H
#define __ENGING_H

#include <Windows.h>
#include <string>
#include "../Core/RenderEngine.h"
#include "../Engine/MVC/MVCContainer.h"
#include "SceneManager\SceneManager.h"
#include "../Services/WindowScreen.h"
#include "EventHandler\EventDispatcher.h"
#include "../Services/Math/MathAdapters/DirectXMathAdapter.h"
#include "../../Game Builder/Scene Builder/Playground.h"
#include "ECS\SystemContainer.h"
#include "../../../Addons/AutomaticPointers/AutomaticPointers.h"

namespace LevelUp
{
	class GameBase;
	class Controller;
	class Model;
	class View;
	class Camera;


    //function used as a proxy to send to engines own wndproc
	LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

    /*
    Core of the engine is a singleton, starts the render engine and makes everything run
    - Alex Sabourin April 2015
    */
	class TheEngine final
	{
	public:
		//initializes the window, the game and directX 11
		bool initialize(HINSTANCE h, int showCmd);

		//game loop specific
		void render();
		void update();

		//shut down all components of the engine
		void shutdown();
		//singleton specific
		static APT::WeakPointer<TheEngine> getInstance();
		//update the timer at the pass through
		void updateTimer();

		//wrap wndproc engine singleton
		LRESULT handleMessages(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

		//get the window handle
		HWND getHWND();

        //add a controller to the mvc container
		void addController(APT::WeakPointer<Controller> c);
        //add a model to the mvc container
		void addModel(APT::WeakPointer<Model> m);
        //add a view to the mvc container
		void addView(APT::WeakPointer<View> v);
        //add a camera to the mvc container
		void addCamera(APT::WeakPointer<Camera> c);

        //remove a controller
		void removeController(APT::WeakPointer<Controller> c);
        //remove a model
		void removeModel(APT::WeakPointer<Model> m);
        //remove a view
		void removeView(APT::WeakPointer<View> v);
        //remove a camera
		void removeCamera(APT::WeakPointer<Camera> c);

        //add an event handle to the event dispatcher
		void addEventHandler(APT::WeakPointer<EventHandler> e);

		//remove an event handler
		void removeEventHandler(APT::WeakPointer<EventHandler> e);

        //get the current elapsed if necessary
		double delta();

        //get the mvc container
		APT::WeakPointer<MVCContainer> getContainer();

        //get the scene manager
		APT::WeakPointer<SceneManager> getSceneManager();

        //returns all the systems in the engine
		APT::WeakPointer<SystemContainer> getSystems();

		//handle keys just pressed and released
		bool justPressed(LevelUpKeys key);
		bool justReleased(LevelUpKeys key);

		//handle held down keys
		bool keyDown(LevelUpKeys key);

		//get the mouse position
		LVLfloat2 getMousePos();

		~TheEngine();

	private:
		struct ControllerVals
		{
			LevelUpKeys down;
			LevelUpKeys up;
			LevelUpKeys justPressed;
			LevelUpKeys justReleased;
			void resetKeys()
			{
				if (down == justReleased)
				{
					down = KEY_NULL;
				}
				justPressed = KEY_NULL;
				justReleased = KEY_NULL;
			}
		};

		ControllerVals controllers;

        //singleton
		static APT::StrongPointer<TheEngine> m_theEngine;

        //initialize the window
		bool initializeWindow(HINSTANCE hInstance);

		EventDispatcher m_dispatcher;

		MVCContainer m_container;
		RenderEngine m_render;
		SceneManager m_scenes;
		APT::StrongPointer<WindowScreen> m_screenSize;
        DirectXMathAdapter m_adapter;

        SystemContainer m_systems;

        Playground m_sceneBuilder;

		HWND m_windowHandle;

		//timer specific variables;
		double m_lastTickCount;
		double m_nextTickCount;
		double m_sleepTime;
		double m_frameTime;
		double m_delta;

		const int WINDOW_WIDTH = 800;
		const int WINDOW_HEIGHT = 600;



        bool provideServices(HINSTANCE h);

		//no copies
		TheEngine();
		TheEngine(TheEngine& e) {};
		TheEngine& operator= (TheEngine& rhs) { return rhs; }


	};

	APT::WeakPointer<TheEngine> getEngine();
}

#endif