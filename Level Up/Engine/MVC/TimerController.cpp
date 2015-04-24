#include "TimerController.h"
#include "../TheEngine.h"
#include "../SceneManager/SceneManager.h"
#include "../SceneManager/Scene.h"
#include <string>

namespace LevelUp
{
	int TimerController::m_numberOfTimerControllers = 0;

	TimerController::TimerController()
	{
		m_elapsed = 0;
		m_numberOfTimerControllers++;
		addToMap();
	}

	TimerController::~TimerController()
	{
		m_numberOfTimerControllers--;
        removeFromMap();
	}

	void TimerController::addToMap()
	{
        //add the timer controller to the current scene or the engine
		m_ID = "TimerController " + std::to_string(m_numberOfTimerControllers);
		m_type = TIMERCONTROLLER;
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


    void TimerController::removeFromMap()
    {
        //remove the timer controller to the current scene or the engine
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
	std::string TimerController::TimerControllerID()
	{
		return m_ID;
	}
}
