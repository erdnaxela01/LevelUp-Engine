#ifndef __MVCCONTAINER_H
#define __MVCCONTAINER_H

#include <map>
#include <string>
#include <vector>
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
		virtual ~MVCContainer();
        //get all the controllers
		std::map<controllerType, std::vector<Controller*>> getControllers() const;
        //get all the models
		std::vector<Model*> getModels() const;
        //get all the views
		std::vector<View*> getViews() const;

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
		void keyDown(LevelUpKeys key);
        //update all the key controllers
        void keyUp(LevelUpKeys key);
		//update all key controllers
		void justPressed(LevelUpKeys key);

        //check the time elapsed for the controllers
		void timeElapsed(double delta);
        //check the mouse for the mouse controllers
		void mouseMove(LVLfloat2 pos);
        //update all the models
		void updateModels(double delta);

        //render all the views with the cameras
		void renderViewsWithCamera();


	private:
		std::map<controllerType, std::vector<Controller*>> m_controllers;
		std::vector<Model*> m_models;
		std::vector<View*> m_views;
		std::vector<Camera*> m_cameras;

	};
}
#endif