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
		static TheEngine* getInstance();
		//update the timer at the pass through
		void updateTimer();

		//wrap wndproc engine singleton
		LRESULT handleMessages(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

		//get the window handle
		HWND getHWND();

        //add a controller to the mvc container
		void addController(Controller* c);
        //add a model to the mvc container
		void addModel(Model* m);
        //add a view to the mvc container
		void addView(View* v);
        //add a camera to the mvc container
		void addCamera(Camera* c);

        //remove a controller
        void removeController(Controller* c);
        //remove a model
        void removeModel(Model* m);
        //remove a view
        void removeView(View* v);
        //remove a camera
        void removeCamera(Camera* c);

        //add an event handle to the event dispatcher
        void addEventHandler(EventHandler* e);

        //get the current elapsed if necessary
		double delta();

        //get the mvc container
		MVCContainer* getContainer();

        //get the scene manager
		SceneManager* getSceneManager();

        //returns all the systems in the engine
        SystemContainer* getSystems();



	private:
        //singleton
		static TheEngine* m_theEngine;

        //initialize the window
		bool initializeWindow(HINSTANCE hInstance);

        
		MVCContainer m_container;
		RenderEngine m_render;
		SceneManager m_scenes;
		WindowScreen* m_screenSize;
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

		LVLfloat2 getMousePos();

        EventDispatcher m_dispatcher;

        bool provideServices(HINSTANCE h);

		//no copies
		TheEngine();
		TheEngine(TheEngine& e) {};
		TheEngine& operator= (TheEngine& rhs) { return rhs; }

		bool m_canUpdate;

	};
}


#endif