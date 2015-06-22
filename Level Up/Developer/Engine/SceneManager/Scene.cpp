#include "Scene.h"
#include "../MVC/MVCContainer.h"
#include "../MVC/MVC.h"
#include "../../UI/Cameras/Camera.h"
#include "../../Core/StandardTemplates.h"

namespace LevelUp
{
	Scene::Scene(std::string sceneID)
	{
		m_mvc.setPtr(new MVCContainer());
		m_ID = sceneID;
        m_initialCamera.setPtr(new Camera(this));
	}
	Scene::~Scene()
	{
	}
	APT::WeakPointer<MVCContainer> Scene::getContainer() const
	{
		return m_mvc;
	}
	std::string  Scene::sceneID() const
	{
		return m_ID;
	}

	void Scene::addController(APT::WeakPointer<Controller> c)
	{
		m_mvc->addToControllerMap(c);
	}
	void Scene::addModel(APT::WeakPointer<Model> m)
	{
		m_mvc->addToModelMap(m);
	}
	void Scene::addView(APT::WeakPointer<View> v)
	{
		m_mvc->addToViewMap(v);
	}
	void Scene::addCamera(APT::WeakPointer<Camera> c)
	{
		m_mvc->addToCameraMap(c);
	}


	void Scene::removeController(APT::WeakPointer<Controller> c)
    {
        m_mvc->removeFromControllerMap(c);
    }
	void Scene::removeModel(APT::WeakPointer<Model> m)
    {
        m_mvc->removeFromModelMap(m);
    }
	void Scene::removeView(APT::WeakPointer<View> v)
    {
        m_mvc->removeFromViewMap(v);
    }
	void Scene::removeCamera(APT::WeakPointer<Camera> c)
    {
        m_mvc->removeFromCameraMap(c);
    }
    void Scene::removeInitialCamera()
    {
		m_initialCamera.clear();
    }
	APT::WeakPointer<Camera> Scene::getInitialCamera()
	{
		return m_initialCamera;
	}
}