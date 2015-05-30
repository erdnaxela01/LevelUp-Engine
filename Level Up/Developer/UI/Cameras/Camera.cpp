#include "Camera.h"
#include "../../Engine/MVC/MVC.h"
#include "../../Engine/TheEngine.h"
#include "../../Services/WindowScreen.h"
#include "../../Services/ServiceLocator.h"
#include "../../Core/StandardTemplates.h"
#include "../../Services/Math/LevelUpMath.h"
#include "../../Engine/Command/CameraResizeCommand.h"

#include <string>
#include <map>
#include <DirectXMath.h>
#include <d3d11.h>
#include <algorithm>
#include "../../Engine/SceneManager/SceneManager.h"
#include "../../Engine/SceneManager/Scene.h"

namespace LevelUp
{
	int Camera::m_numberOfCameras = 0;

	Camera::Camera() :m_x(0.0f), m_y(0.0f), m_canView(true), m_parentScene(""), m_command(nullptr), m_zoom(1.0f)
	{
        //add to the number of cameras
		m_numberOfCameras++;
        //set the cameras isd
		m_ID = "Camera " + std::to_string(m_numberOfCameras);
        //set the camera to a scene or an engine
		Scene* s = getEngine()->getSceneManager()->getActiveScene();
		if (s != nullptr)
		{
			s->addCamera(this);
			m_parentScene = s->sceneID();
		}
		else
		{
			getEngine()->addCamera(this);
		}
        //set the width height and positions of the camera
		m_height = ServiceLocator::getScreenSizeService()->getScreenSize().y;
		m_width = ServiceLocator::getScreenSizeService()->getScreenSize().x;
		m_x = 0.0f;
		m_y = 0.0f;
        m_screenPos = (LVLfloat2(0.0f, 0.0f));

        //get a viewport for the camera
        m_viewport = ServiceLocator::getRenderService()->produceViewport();

        //get the current screen size
        m_currentScreenSize = ServiceLocator::getScreenSizeService()->getScreenSize();

		m_viewPortIsDirty = true;
	}

	Camera::Camera(Scene* s) : m_canView(true), m_command(nullptr), m_zoom(1.0f)
    {
        // add to the number of cameras
        m_numberOfCameras++;
        m_ID = "Camera " + std::to_string(m_numberOfCameras);
        //set the cameras isd
        //set the camera to a scene or an engine
        if (s != nullptr)
        {
            s->addCamera(this);
            m_parentScene = s->sceneID();
        }
        else
        {
            getEngine()->addCamera(this);
        }
        //set the width height and positions of the camera
        m_height = ServiceLocator::getScreenSizeService()->getScreenSize().y;
        m_width = ServiceLocator::getScreenSizeService()->getScreenSize().x;
        m_x = 0.0f;
        m_y = 0.0f;
        m_screenPos = (LVLfloat2(0.0f, 0.0f));
        //get a viewport for the camera
        m_viewport = ServiceLocator::getRenderService()->produceViewport();
        //get the current screen size
        m_currentScreenSize = ServiceLocator::getScreenSizeService()->getScreenSize();
		m_viewPortIsDirty = true;
    }
	Camera::~Camera()
	{
        if (m_parentScene != "")
        {
            Scene* s = getEngine()->getSceneManager()->getScene(m_parentScene);
            if (s != nullptr)
            {
                s->removeCamera(this);
            }
        }
        else
        {
            getEngine()->removeCamera(this);
        }
        //delete the viewport
		if (m_viewport != nullptr)
		{
			delete m_viewport;
			m_viewport = nullptr;
		}

		if (m_command != nullptr)
		{
			delete m_command;
			m_command = nullptr;
		}
	}
	std::string Camera::CameraID()
	{
		return m_ID;
	}

    void Camera::render()
    {
        //set the viewport as the rendering one
        m_viewport->setViewPort();

        //if the view port has changed set it to the new values
        if (m_viewPortIsDirty)
        {
            LVL4X4matrix view = MathHelper::identityMatrix();
            LVL4X4matrix proj;
            ServiceLocator::getMathAdapter()->convertToLVLMatrix(&proj, &DirectXMatrixContainer(&DirectX::XMMatrixOrthographicOffCenterLH(0.0f, m_width, 0.0f, m_height, 0.1f, 100.0f)));
            (ServiceLocator::getRenderService()->setVPMatrix(view * proj));
			m_viewPortIsDirty = false;
        }

        //get a sorted views for z sorting
        std::vector<View*> sortedViews;

        //if there is no parent scene get the engines view map else get the scene
        if (m_parentScene == "")
        {
            sortedViews = getEngine()->getContainer()->getViews();
        }
        else
        {
            sortedViews = getEngine()->getSceneManager()->getScene(m_parentScene)->getContainer()->getViews();
        }
        //lambda function for sorting algorithm callback
        std::sort(sortedViews.begin(), sortedViews.end(), [](View* a, View* b)->bool{return a->getZ() < b->getZ(); });
        //renders the view list completely sorted by z value
        for (auto i : sortedViews)
        {
            float x = (i->getX() - m_x);
            float y = (i->getY() - m_y);
			float prevX = i->getX();
			float prevY = i->getY();
			i->setX(x);
			i->setY(y);
            i->render();
			i->setX(prevX);
			i->setY(prevY);
        }
    }

	void Camera::setPos(float x, float y)
	{
		m_x = x;
		m_y = y;
	}
	void Camera::setH(float h)
	{
		m_height = h / m_zoom;
		m_viewport->setHeight(h);
        m_viewPortIsDirty = true;
	}
	void Camera::setW(float w)
	{
		m_width = w / m_zoom;
        m_viewport->setWidth(w);
        m_viewPortIsDirty = true;
	}
    LVLfloat2 Camera::getPos()
	{
        return (LVLfloat2(m_x, m_y));
	}
	float Camera::getH()
	{
		return m_height;
	}
	float Camera::getW()
	{
		return m_width;
	}

	bool Camera::canView()
	{
		return m_canView;
	}

	void Camera::setX(float x)
	{
		m_x = x;
	}
	void Camera::setY(float y)
	{
		m_y = y;
	}
	void Camera::setScreenX(float x)
	{
		m_screenPos.x = x;
        m_viewport->setTopX(x);
	}
	void Camera::setScreenY(float y)
	{
		m_screenPos.y = y;
        m_viewport->setTopY(y);
	}
	float Camera::getScreenX()
	{
		return m_screenPos.x;
	}
	float Camera::getscreenY()
	{
		return m_screenPos.y;
	}

	void Camera::setCanView(bool b)
	{
		m_canView = b;
	}
    void Camera::handleEvent(DispatchEvents e)
    {
        //if the screen is resized set it to the screen resizing

        if (e == DispatchEvents::DISPATCHEVENTS_SCREENRESIZE)
        {
            ///if there is no callback for resizing go to default
            if (m_command == nullptr)
            {
				setW(ServiceLocator::getScreenSizeService()->getScreenSize().x);
				setH(ServiceLocator::getScreenSizeService()->getScreenSize().y);
            }
            else
            {
                m_command->execute();
            }
            m_viewPortIsDirty = true;
        }


    }
    void Camera::setResizeMethod(CameraResizeCommand* c)
    {
        //set the resizing method
        m_command = c;
    }
	void Camera::setZoom(float zoom)
	{
		m_zoom = zoom;
		m_width = m_width / m_zoom;
		m_height = m_height / m_zoom;
		m_viewPortIsDirty = true;
	}
	//get the zoom of the camera
	float Camera::getZoom()
	{
		return m_zoom;
	}
}