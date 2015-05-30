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

	std::map<controllerType, std::vector<Controller*>> MVCContainer::getControllers() const
	{
		return m_controllers;
	}

	std::vector<Model*> MVCContainer::getModels() const
	{
		return m_models;
	}
	std::vector<View*> MVCContainer::getViews() const
	{
		return m_views;
	}
	void MVCContainer::addToControllerMap(Controller* controller)
	{
		m_controllers[controller->getType()].push_back(controller);
	}

	void MVCContainer::addToModelMap(Model* model)
	{
		m_models.push_back(model);
	}

	void MVCContainer::addToViewMap(View* view)
	{
		m_views.push_back(view);
	}

	void MVCContainer::addToCameraMap(Camera* cam)
	{
		m_cameras.push_back(cam);
	}

    void MVCContainer::keyDown(LevelUpKeys key)
	{

        //run through thevecotr and activate all the controllers
		std::vector < Controller* > keyController = m_controllers[controllerType::KEYCONTROLLER];
		for (auto i:keyController)
		{
			auto tempPtr = dynamic_cast<KeyController*>(i);
			if (tempPtr->canControl())
			{
				tempPtr->handleKeyDown(key);
			}
		}
	}

    void MVCContainer::keyUp(LevelUpKeys key)
	{
		//run through thevecotr and activate all the controllers
		std::vector < Controller* > keyController = m_controllers[controllerType::KEYCONTROLLER];
		for (auto i : keyController)
		{
			auto tempPtr = dynamic_cast<KeyController*>(i);
			if (tempPtr->canControl())
			{
				tempPtr->handleKeyUp(key);
			}
		}
	}

	//update all key controllers
	void MVCContainer::justPressed(LevelUpKeys key)
	{
		//run through thevecotr and activate all the controllers
		std::vector < Controller* > keyController = m_controllers[controllerType::KEYCONTROLLER];
		for (auto i : keyController)
		{
			auto tempPtr = dynamic_cast<KeyController*>(i);
			if (tempPtr->canControl())
			{
				tempPtr->justPressed(key);
			}
		}
	}

	void MVCContainer::timeElapsed(double delta)
	{
		//run through thevecotr and activate all the controllers
		std::vector < Controller* > keyController = m_controllers[controllerType::TIMERCONTROLLER];
		for (auto i : keyController)
		{
			auto tempPtr = dynamic_cast<TimerController*>(i);
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
		std::vector<Controller*> mouseController = m_controllers[controllerType::TIMERCONTROLLER];
		for (auto i : mouseController)
		{
			tempPtr = (MouseController*)(i);
			if (tempPtr->canControl())
			{
				tempPtr->mouseMove(pos);
			}
		}
	}

	void MVCContainer::updateModels(double delta)
	{
        //run through the models and update them
		for (auto i : m_models)
		{
			if (i->canUpdate())
			{
				i->update(delta);
			}
		}
	}

	void MVCContainer::renderViewsWithCamera()
	{
        //render all the cameras
		for (auto i : m_cameras)
		{
			if (i->canView())
			{
				i->render();
			}
		}
	}
    void MVCContainer::removeFromControllerMap(Controller* c)
    {
		std::vector<Controller*> controllers = m_controllers[c->getType()];
        controllers.erase(std::find(controllers.begin(), controllers.end(), c));
    }
    void MVCContainer::removeFromModelMap(Model* m)
    {
        m_models.erase(std::find(m_models.begin(), m_models.end(), m));
    }
    void MVCContainer::removeFromViewMap(View* v)
    {
        m_views.erase(std::find(m_views.begin(), m_views.end(), v));
    }
    void MVCContainer::removeFromCameraMap(Camera* c)
    {
        m_cameras.erase(std::find(m_cameras.begin(), m_cameras.end(), c));
    }
}