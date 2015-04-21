#ifndef __MVCCONTAINER_H
#define __MVCCONTAINER_H

#include <map>
#include <string>
#include <DirectXMath.h>
#include "Controller.h"
#include "../../Services/Math/LevelUpMath.h"

namespace LevelUp
{
	class KeyController;
	class TimerController;
	class Model;
	class View;
	class Camera;

    //used to contain all model view controller components and cameras
    //Alex Sabourin April 2015
	class MVCContainer
	{
	public:
		MVCContainer();
		~MVCContainer();
		void initializeContainer();
		std::map<controllerType, std::map<std::string, Controller*>> getControllerMap();
		std::map<std::string, Model*> getModelMap();
		std::map<std::string, View*> getViewMap();
		void addToControllerMap(Controller* controller);
		void addToModelMap(Model* model);
		void addToViewMap(View* view);
		void addToCameraMap(Camera* cam);

        void removeFromControllerMap(Controller* c);
        void removeFromModelMap(Model* m);
        void removeFromViewMap(View* v);
        void removeFromCameraMap(Camera* c);

		void KeyDown(int key);
		void KeyUp(int key);
		void timeElapsed(double delta);
		void mouseMove(LVLfloat2 pos);
		void updateModels(double delta);
		void renderViewsWithCamera();


	private:
		std::map<controllerType, std::map<std::string, Controller*>> m_controllers;
		std::map<std::string, Model*> m_models;
		std::map<std::string, View*> m_views;
		std::map<std::string, Camera*> m_cameras;

	};
}
#endif