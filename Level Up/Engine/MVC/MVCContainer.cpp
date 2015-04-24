#include "MVC.h"
#include "../../UI/Cameras/Camera.h"
#include "../../Core/StandardTemplates.h"
#include <vector>
#include <DirectXMath.h>

namespace LevelUp
{
	MVCContainer::MVCContainer()
	{
	}


	MVCContainer::~MVCContainer()
	{
	}

	std::map<controllerType, std::map<std::string, Controller*>> MVCContainer::getControllerMap()
	{
		return m_controllers;
	}

	std::map<std::string, Model*> MVCContainer::getModelMap()
	{
		return m_models;
	}
	std::map<std::string, View*> MVCContainer::getViewMap()
	{
		return m_views;
	}
	void MVCContainer::addToControllerMap(Controller* controller)
	{
		m_controllers[controller->getType()][controller->ControllerID()] = controller;
	}

	void MVCContainer::addToModelMap(Model* model)
	{
		m_models[model->ModelID()] = model;
	}

	void MVCContainer::addToViewMap(View* view)
	{
		m_views[view->ViewID()] = view;
	}

	void MVCContainer::addToCameraMap(Camera* cam)
	{
		m_cameras[cam->CameraID()] = cam;
	}

	void MVCContainer::KeyDown(int key)
	{
		KeyController* tempPtr;

        //run through the map and activate all the controllers
		typedef std::map<std::string, Controller* > ::iterator it_type;
		std::map < std::string, Controller* > keyController = m_controllers[controllerType::KEYCONTROLLER];
		for (it_type iterator = keyController.begin(); iterator != keyController.end(); iterator++)
		{
			tempPtr = (KeyController*)(iterator->second);
			if (tempPtr->canControl())
			{
				tempPtr->handleKeyDown(key);
			}
		}
	}

	void MVCContainer::KeyUp(int key)
	{
		KeyController* tempPtr;
        //run through the map and activate all the controllers
		typedef std::map<std::string, Controller* > ::iterator it_type;
		std::map < std::string, Controller* > keyController = m_controllers[controllerType::KEYCONTROLLER];
		for (it_type iterator = keyController.begin(); iterator != keyController.end(); iterator++)
		{
			tempPtr = (KeyController*)(iterator->second);
			if (tempPtr->canControl())
			{
				tempPtr->handleKeyUp(key);
			}
		}
	}

	void MVCContainer::timeElapsed(double delta)
	{
		TimerController* tempPtr;
        //run through the map and activate all the controllers
		typedef std::map<std::string, Controller* > ::iterator it_type;
		std::map < std::string, Controller* > timerController = m_controllers[controllerType::TIMERCONTROLLER];
		for (it_type iterator = timerController.begin(); iterator != timerController.end(); iterator++)
		{
			tempPtr = (TimerController*)(iterator->second);
			if (tempPtr->canControl())
			{
				tempPtr->timeElapsed(delta);
			}
		}
	}
	void MVCContainer::mouseMove(LVLfloat2 pos)
	{
		MouseController* tempPtr;
        //run through the map and activate all the controllers
		typedef std::map<std::string, Controller* > ::iterator it_type;
		std::map < std::string, Controller* > mouseController = m_controllers[controllerType::TIMERCONTROLLER];
		for (it_type iterator = mouseController.begin(); iterator != mouseController.end(); iterator++)
		{
			tempPtr = (MouseController*)(iterator->second);
			if (tempPtr->canControl())
			{
				tempPtr->mouseMove(pos);
			}
		}
	}

	void MVCContainer::updateModels(double delta)
	{
        //run through the models and update them
		typedef std::map<std::string, Model* > ::iterator it_type;
		for (it_type iterator = m_models.begin(); iterator != m_models.end(); iterator++)
		{
			if (iterator->second->canUpdate())
			{
				iterator->second->update(delta);
			}
		}
	}

	void MVCContainer::renderViewsWithCamera()
	{
        //render all the cameras
		typedef std::map<std::string, Camera* > ::iterator it_type;
		for (it_type iterator = m_cameras.begin(); iterator != m_cameras.end(); iterator++)
		{
			if (iterator->second->canView())
			{
				iterator->second->render();
			}
		}
	}
    void MVCContainer::removeFromControllerMap(Controller* c)
    {
        m_controllers[c->getType()].erase(c->ControllerID());
    }
    void MVCContainer::removeFromModelMap(Model* m)
    {
        m_models.erase(m->ModelID());
    }
    void MVCContainer::removeFromViewMap(View* v)
    {
        m_views.erase(v->ViewID());
    }
    void MVCContainer::removeFromCameraMap(Camera* c)
    {
        m_cameras.erase(c->CameraID());
    }
}