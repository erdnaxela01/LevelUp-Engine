#ifndef __MVCCONTAINER_H
#define __MVCCONTAINER_H

#include <map>
#include <string>
#include <DirectXMath.h>
#include "Controller.h"
#include "../../Services/Math/LevelUpMath.h"
#include "../../Enums/Keys.h"

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
        //get all the controllers
		std::map<controllerType, std::map<std::string, Controller*>> getControllerMap();
        //get all the models
		std::map<std::string, Model*> getModelMap();
        //get all the views
		std::map<std::string, View*> getViewMap();

        //add a controller to the map
		void addToControllerMap(Controller* controller);
        //add a model to the map
		void addToModelMap(Model* model);
        //add a view to the map
		void addToViewMap(View* view);
        //add a camera to the map
		void addToCameraMap(Camera* cam);

        //remove a controller from the map
        void removeFromControllerMap(Controller* c);
        //remove a model from the map
        void removeFromModelMap(Model* m);
        //remove a view from the map
        void removeFromViewMap(View* v);
        //remove a camera from the map
        void removeFromCameraMap(Camera* c);

        //update all the key controllers
		void KeyDown(LevelUpKeys key);
        //update all the key controllers
        void KeyUp(LevelUpKeys key);
        //check the time elapsed for the controllers
		void timeElapsed(double delta);
        //check the mouse for the mouse controllers
		void mouseMove(LVLfloat2 pos);
        //update all the models
		void updateModels(double delta);

        //render all the views with the cameras
		void renderViewsWithCamera();


	private:
		std::map<controllerType, std::map<std::string, Controller*>> m_controllers;
		std::map<std::string, Model*> m_models;
		std::map<std::string, View*> m_views;
		std::map<std::string, Camera*> m_cameras;

	};
}
#endif