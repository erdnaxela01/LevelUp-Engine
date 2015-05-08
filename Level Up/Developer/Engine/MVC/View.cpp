#include "View.h"
#include "../TheEngine.h"
#include "../SceneManager/SceneManager.h"
#include "../SceneManager/Scene.h"
#include "../../UI/Cameras/Camera.h"
#include <string>

namespace LevelUp
{
	int View::m_numberOfViews = 0;

    View::View(float z) : m_canView(true), m_useCameraVector(false), m_z(z), m_parentScene("")
	{
		m_numberOfViews++;
		addToMap();
	}
	View::~View()
	{
        removeFromMap();
	}

	void View::setCanView(bool b)
	{
		m_canView = b;
	}

	std::string View::viewID()
	{
		return m_ID;
	}

	void View::addToMap()
	{
        //add the view to the current scene then the engine
		m_ID = "View " + std::to_string(m_numberOfViews);
		Scene* s = getEngine()->getSceneManager()->getActiveScene();
		if (s != nullptr)
		{
            m_parentScene = s->sceneID();
			s->addView(this);
		}
		else
		{
			getEngine()->addView(this);
		}
	}

    void View::removeFromMap()
    {
        //remove the scene from the parent scene or the engine
        if (m_parentScene != "")
        {
            Scene* s = getEngine()->getSceneManager()->getScene(m_parentScene);
            if (s != nullptr)
            {
                s->removeView(this);
            }
        }
        else
        {
            getEngine()->removeView(this);
        }
    }

	bool View::canView()
	{
		return m_canView;
	}

	bool View::usesCameraVector()
	{
		return m_useCameraVector;
	}
	void View::addCamera(Camera* c)
	{
		m_useCameraVector = true;
		m_activeCameras.push_back(c);
	}
	void View::removeCamera(Camera* c)
	{
		m_activeCameras.erase(std::find(m_activeCameras.begin(), m_activeCameras.end(), c));
	}
	void View::setUseCameraVector(bool b)
	{
		m_useCameraVector = b;
	}

	bool View::isPartOfCameraVector(std::string cameraID)
	{
        //if the camera is part of the vector return true
		if (m_useCameraVector == false)
		{
			return true;
		}
		for (auto i : m_activeCameras)
		{
			if (i->CameraID() == cameraID)
			{
				return true;
			}
		}
		return false;
	}
	float View::getZ()
	{
		return m_z;
	}
	void View::setZ(float z)
	{
		m_z = z;
	}
}