#include "Camera.h"
#include "../../Engine/MVC/MVC.h"
#include "../../Engine/TheEngine.h"
#include "../../Services/WindowScreen.h"
#include "../../Services/ServiceLocator.h"

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

	Camera::Camera() :m_x(0.0f), m_y(0.0f), m_canView(true), m_parentScene("")
	{
		m_numberOfCameras++;
		m_ID = "Camera " + std::to_string(m_numberOfCameras);
		Scene* s = TheEngine::getInstance()->getSceneManager()->getActiveScene();
		if (s != nullptr)
		{
			s->addCamera(this);
			m_parentScene = s->sceneID();
		}
		else
		{
			TheEngine::getInstance()->addCamera(this);
		}
		m_height = ServiceLocator::getScreenSizeService()->getScreenSize().y;
		m_width = ServiceLocator::getScreenSizeService()->getScreenSize().x;
		m_x = 0.0f;
		m_y = 0.0f;
        m_screenPos = (LVLfloat2(0.0f, 0.0f));
		SecureZeroMemory(&m_viewport, sizeof(D3D11_VIEWPORT));
		m_viewport.TopLeftX = 0.0f;
        m_viewport.TopLeftY = 0.0f;
        m_viewport.Width = ServiceLocator::getScreenSizeService()->getScreenSize().x;
        m_viewport.Height = ServiceLocator::getScreenSizeService()->getScreenSize().y;
        m_viewport.MinDepth = 0.0f;
        m_viewport.MaxDepth = 1.0f;

        m_currentScreenSize = ServiceLocator::getScreenSizeService()->getScreenSize();
	}

    Camera::Camera(Scene* s)
    {
        m_numberOfCameras++;
        m_ID = "Camera " + std::to_string(m_numberOfCameras);
        if (s != nullptr)
        {
            s->addCamera(this);
            m_parentScene = s->sceneID();
        }
        else
        {
            TheEngine::getInstance()->addCamera(this);
        }
        m_height = ServiceLocator::getScreenSizeService()->getScreenSize().y;
        m_width = ServiceLocator::getScreenSizeService()->getScreenSize().x;
        m_x = 0.0f;
        m_y = 0.0f;
        m_screenPos = (LVLfloat2(0.0f, 0.0f));
        SecureZeroMemory(&m_viewport, sizeof(D3D11_VIEWPORT));
        m_viewport.TopLeftX = 0.0f;
        m_viewport.TopLeftY = 0.0f;
        m_viewport.Width = ServiceLocator::getScreenSizeService()->getScreenSize().x;
        m_viewport.Height = ServiceLocator::getScreenSizeService()->getScreenSize().y;
        m_viewport.MinDepth = 0.0f;
        m_viewport.MaxDepth = 1.0f;

        m_currentScreenSize = ServiceLocator::getScreenSizeService()->getScreenSize();
    }
	Camera::~Camera()
	{
		m_numberOfCameras--;
        Scene* s = TheEngine::getInstance()->getSceneManager()->getActiveScene();
        if (s != nullptr)
        {
            s->removeCamera(this);
        }
        else
        {
            TheEngine::getInstance()->removeCamera(this);
        }
	}
	std::string Camera::CameraID()
	{
		return m_ID;
	}

    void Camera::render()
    {
        ServiceLocator::getRenderService()->getContext()->RSSetViewports(1, &m_viewport);


        if (m_viewPortIsDirty)
        {
            DirectX::XMMATRIX view = DirectX::XMMatrixIdentity();
            DirectX::XMMATRIX projection = DirectX::XMMatrixOrthographicOffCenterLH(0.0f, m_width, 0.0f, m_height, 0.1f, 100.0f);

            (ServiceLocator::getRenderService()->setVPMatrix(DirectX::XMMatrixMultiply(view, projection)));
        }

        std::vector<View*> sortedViews;

        std::map<std::string, View*> views;
        if (m_parentScene == "")
        {
            views = TheEngine::getInstance()->getContainer()->getViewMap();
        }
        else
        {
            views = TheEngine::getInstance()->getSceneManager()->getScene(m_parentScene)->getContainer()->getViewMap();
        }
        typedef std::map<std::string, View* > ::iterator it_type;
        for (it_type iterator = views.begin(); iterator != views.end(); iterator++)
        {
            View *v = iterator->second;
            if (v->canView() && v->isPartOfCameraVector(m_ID))
            {
                sortedViews.push_back(v);
            }
        }
        //lambda function for sorting algorithm callback
        std::sort(sortedViews.begin(), sortedViews.end(), [](View* a, View* b)->bool{return a->getZ() < b->getZ(); });
        //renders the view list completely sorted by z value
        for (auto i : sortedViews)
        {
            float x = (i->getX() - m_x);
            float y = (i->getY() - m_y);
            i->render(x + m_screenPos.x, y);
        }
    }

	void Camera::setPos(float x, float y)
	{
		m_x = x;
		m_y = y;
	}
	void Camera::setH(float h)
	{
		m_height = h;
		m_viewport.Height = h;
        m_viewPortIsDirty = true;
	}
	void Camera::setW(float w)
	{
		m_width = w;
		m_viewport.Width = w;
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
		m_viewport.TopLeftX = x;
	}
	void Camera::setScreenY(float y)
	{
		m_screenPos.y = y;
		m_viewport.TopLeftY = y;
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
        if (e == DispatchEvents::DISPATCHEVENTS_SCREENRESIZE)
        {
            float percentageX = m_width / m_currentScreenSize.x;
            float percentageY = m_height / m_currentScreenSize.y;

            m_width = ServiceLocator::getScreenSizeService()->getScreenSize().x * percentageX;
            m_height = ServiceLocator::getScreenSizeService()->getScreenSize().y * percentageY;

            m_currentScreenSize.x = ServiceLocator::getScreenSizeService()->getScreenSize().x;
            m_currentScreenSize.y = ServiceLocator::getScreenSizeService()->getScreenSize().y;

            m_viewPortIsDirty = true;
        }

    }
}