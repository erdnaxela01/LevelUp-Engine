#ifndef __ENGINE_H
#define __ENGING_H

#include <Windows.h>
#include <string>
#include <map>
#include <DirectXMath.h>
#include "../Core/RenderEngine.h"
#include "../Engine/MVC/MVCContainer.h"
#include "SceneManager\SceneManager.h"
#include "../Services/WindowScreen.h"
#include "EventHandler\EventDispatcher.h"
#include "../Services/Math/MathAdapters/DirectXMathAdapter.h"

namespace LevelUp
{
	class Game;
	class GameBase;
	class Controller;
	class Model;
	class View;
	class Camera;


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
		void update(double delta);

		//shut down all components of the engine
		void shutdown();
		//singleton specific
		static TheEngine* getInstance();
		//update the timer at the pass through
		double updateTimer();

		//wrap wndproc engine singleton
		LRESULT handleMessages(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

		//get the window handle
		HWND getHWND();

        //add stuff to the model view controller container
		void addController(Controller* c);
		void addModel(Model* m);
		void addView(View* v);
		void addCamera(Camera* c);

        void removeController(Controller* c);
        void removeModel(Model* m);
        void removeView(View* v);
        void removeCamera(Camera* c);

        void addEventHandler(EventHandler* e);

        //get the current elapsed if necessary
		double delta();

		MVCContainer* getContainer();
		SceneManager* getSceneManager();

	private:
		static TheEngine* m_theEngine;

		bool initializeWindow(HINSTANCE hInstance);

		MVCContainer m_container;
		RenderEngine m_render;
		SceneManager m_scenes;
		WindowScreen* m_screenSize;
        DirectXMathAdapter m_adapter;
		


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

		//no copies
		TheEngine();
		TheEngine(TheEngine& e) {};
		TheEngine& operator= (TheEngine& rhs) { return rhs; }

	};
}


#endif