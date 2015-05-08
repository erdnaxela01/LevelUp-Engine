#include "MouseController.h"
#include "../TheEngine.h"
#include "../SceneManager/SceneManager.h"
#include "../SceneManager/Scene.h"

namespace LevelUp
{
	int MouseController::m_numberOfMouseControllers = 0;

	MouseController::MouseController()
	{
		m_numberOfMouseControllers++;
		addToMap();
	}
	MouseController::~MouseController()
	{
        removeFromMap();
	}

	void MouseController::addToMap()
	{
        //add the mouse controller to the current scene or the engine
		m_ID = "MouseController " + std::to_string(m_numberOfMouseControllers);
		m_type = MOUSECONTROLLER;
		Scene* s = getEngine()->getSceneManager()->getActiveScene();
		if (s != nullptr)
		{
            m_parentScene = s->sceneID();
			s->addController(this);
		}
		else
		{
			getEngine()->addController(this);
		}
	}

    void MouseController::removeFromMap()
    {
        //remove the mouse controller to the current scene or the engine
        if (m_parentScene != "")
        {
            Scene* s = getEngine()->getSceneManager()->getScene(m_parentScene);
            if (s != nullptr)
            {
                s->removeController(this);
            }
        }
        else
        {
            getEngine()->removeController(this);
        }
    }
	std::string MouseController::mouseControllerID()
	{
		return m_ID;
	}
}