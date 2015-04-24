
#include "../TheEngine.h"
#include "../SceneManager/SceneManager.h"
#include "../SceneManager/Scene.h"
#include "KeyController.h"
#include <string>
namespace LevelUp
{
	int KeyController::m_numberOfKeyControllers = 0;


	KeyController::KeyController()
	{
        //increment the number of key controllers
		m_numberOfKeyControllers++;
		addToMap();
	}

	KeyController::~KeyController()
	{
        //decrement the number of controllers
		m_numberOfKeyControllers--;
        removeFromMap();

	}

	void KeyController::addToMap()
	{
        //add the key controller to the mpa of the active scene or the engine if there is none
		m_ID = "KeyController " + std::to_string(m_numberOfKeyControllers);
		m_type = KEYCONTROLLER;
		Scene* s = TheEngine::getInstance()->getSceneManager()->getActiveScene();
		if (s != nullptr)
		{
            m_parentScene = s->sceneID();
			s->addController(this);
		}
		else
		{
			TheEngine::getInstance()->addController(this);
		}
	}

    void KeyController::removeFromMap()
    {
        //remove the controller from the scene
        if (m_parentScene != "")
        {
            Scene* s = TheEngine::getInstance()->getSceneManager()->getScene(m_parentScene);
            if (s != nullptr)
            {
                s->removeController(this);
            }
        }
        else
        {
            TheEngine::getInstance()->removeController(this);
        }
    }
	std::string KeyController::keyControllerID()
	{
		return m_ID;
	}
}