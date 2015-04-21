#include "Scene.h"
#include "../MVC/MVCContainer.h"
#include "../MVC/MVC.h"
#include "../../UI/Cameras/Camera.h"

namespace LevelUp
{
	Scene::Scene(std::string sceneID)
	{
		m_mvc = new MVCContainer();
		m_ID = sceneID;
        m_initialCamera = new Camera(this);
	}
	Scene::~Scene()
	{

	}
	MVCContainer* Scene::getContainer()
	{
		return m_mvc;
	}
	std::string  Scene::sceneID()
	{
		return m_ID;
	}

	void Scene::addController(Controller* c)
	{
		m_mvc->addToControllerMap(c);
	}
	void Scene::addModel(Model* m)
	{
		m_mvc->addToModelMap(m);
	}
	void Scene::addView(View* v)
	{
		m_mvc->addToViewMap(v);
	}
	void Scene::addCamera(Camera* c)
	{
		m_mvc->addToCameraMap(c);
	}


    void Scene::removeController(Controller* c)
    {
        m_mvc->removeFromControllerMap(c);
    }
    void Scene::removeModel(Model* m)
    {
        m_mvc->removeFromModelMap(m);
    }
    void Scene::removeView(View* v)
    {
        m_mvc->removeFromViewMap(v);
    }
    void Scene::removeCamera(Camera* c)
    {
        m_mvc->removeFromCameraMap(c);
    }
    void Scene::removeInitialCamera()
    {
        m_mvc->removeFromCameraMap(m_initialCamera);
        m_initialCamera = nullptr;
    }
}