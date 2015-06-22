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

	std::map<controllerType, std::vector<APT::WeakPointer<Controller>>> MVCContainer::getControllers() const
	{
		return m_controllers;
	}

	std::vector<APT::WeakPointer<Model>> MVCContainer::getModels() const
	{
		return m_models;
	}
	std::vector<APT::WeakPointer<View>> MVCContainer::getViews() const
	{
		return m_views;
	}
	void MVCContainer::addToControllerMap(APT::WeakPointer<Controller> controller)
	{
		m_controllers[controller->getType()].push_back(controller);
	}

	void MVCContainer::addToModelMap(APT::WeakPointer<Model> model)
	{
		
		m_models.push_back(model);
	}

	void MVCContainer::addToViewMap(APT::WeakPointer<View> view)
	{
		m_views.push_back(view);
	}

	void MVCContainer::addToCameraMap(APT::WeakPointer<Camera> cam)
	{
		m_cameras.push_back(cam);
	}

    void MVCContainer::keyDown(LevelUpKeys key)
	{

        //run through thevecotr and activate all the controllers
		std::vector < APT::WeakPointer<Controller> > keyController = m_controllers[controllerType::KEYCONTROLLER];
		for (auto i:keyController)
		{
			auto tempPtr = dynamic_cast<KeyController*>(i.getPtr());
			if (tempPtr->canControl())
			{
				tempPtr->handleKeyDown(key);
			}
		}
	}

    void MVCContainer::keyUp(LevelUpKeys key)
	{
		//run through thevecotr and activate all the controllers
		std::vector < APT::WeakPointer<Controller> > keyController = m_controllers[controllerType::KEYCONTROLLER];
		for (auto i : keyController)
		{
			auto tempPtr = dynamic_cast<KeyController*>(i.getPtr());
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
		std::vector < APT::WeakPointer<Controller> > keyController = m_controllers[controllerType::KEYCONTROLLER];
		for (auto i : keyController)
		{
			auto tempPtr = dynamic_cast<KeyController*>(i.getPtr());
			if (tempPtr->canControl())
			{
				tempPtr->justPressed(key);
			}
		}
	}

	void MVCContainer::timeElapsed(double delta)
	{
		//run through thevecotr and activate all the controllers
		std::vector < APT::WeakPointer<Controller> > keyController = m_controllers[controllerType::TIMERCONTROLLER];
		for (auto i : keyController)
		{
			auto tempPtr = dynamic_cast<TimerController*>(i.getPtr());
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
		std::vector<APT::WeakPointer<Controller>> mouseController = m_controllers[controllerType::TIMERCONTROLLER];
		for (auto i : mouseController)
		{
			tempPtr = (MouseController*)(i.getPtr());
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
	void MVCContainer::removeFromControllerMap(APT::WeakPointer<Controller> c)
    {
		std::vector<APT::WeakPointer<Controller>>& controllers = m_controllers[c->getType()];
		for (unsigned int i = 0; i < controllers.size(); i++)
		{
			if (controllers[i]->ControllerID() == c->ControllerID())
			{
				controllers.erase(controllers.begin() + i);
				break;
			}
		}
    }
	void MVCContainer::removeFromModelMap(APT::WeakPointer<Model> m)
    {
		for (unsigned int i = 0; i < m_models.size(); i++)
		{
			if(m_models[i]->ModelID() == m->ModelID())
			{
				m_models.erase(m_models.begin() + i);
				break;
			}
		}
    }
	void MVCContainer::removeFromViewMap(APT::WeakPointer<View> v)
    {
		for (unsigned int i = 0; i < m_views.size(); i++)
		{
			if (m_views[i]->viewID() == v->viewID())
			{
				m_views.erase(m_views.begin() + i);
				break;
			}
		}
    }
	void MVCContainer::removeFromCameraMap(APT::WeakPointer<Camera> c)
    {
		for (unsigned int i = 0; i < m_cameras.size(); i++)
		{
			if (m_cameras[i]->CameraID() == c->CameraID())
			{
				m_cameras.erase(m_cameras.begin() + i);
				break;
			}
		}
    }
}