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
        removeFromMap();
	}

	void TimerController::addToMap()
	{
        //add the timer controller to the current scene or the engine
		m_ID = "TimerController " + std::to_string(m_numberOfTimerControllers);
		m_type = TIMERCONTROLLER;
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


    void TimerController::removeFromMap()
    {
        //remove the timer controller to the current scene or the engine
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
	std::string TimerController::TimerControllerID() const
	{
		return m_ID;
	}
}
