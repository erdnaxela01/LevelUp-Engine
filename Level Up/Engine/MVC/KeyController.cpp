
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
		m_numberOfKeyControllers++;
		addToMap();
	}

	KeyController::~KeyController()
	{
		m_numberOfKeyControllers--;
        removeFromMap();

	}

	void KeyController::addToMap()
	{
		m_ID = "KeyController " + std::to_string(m_numberOfKeyControllers);
		m_type = KEYCONTROLLER;
		Scene* s = TheEngine::getInstance()->getSceneManager()->getActiveScene();
		if (s != nullptr)
		{
			s->addController(this);
		}
		else
		{
			TheEngine::getInstance()->addController(this);
		}
	}

    void KeyController::removeFromMap()
    {
        Scene* s = TheEngine::getInstance()->getSceneManager()->getActiveScene();
        if (s != nullptr)
        {
            s->removeController(this);
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