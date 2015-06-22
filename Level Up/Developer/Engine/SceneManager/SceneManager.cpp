#include "SceneManager.h"
#include "Scene.h"
#include "../../Core/StandardTemplates.h"
namespace LevelUp
{
	SceneManager::SceneManager() :m_activeScene(nullptr)
	{

	}
	SceneManager::~SceneManager()
	{

	}

	APT::WeakPointer<Scene> SceneManager::getScene(std::string s)
	{
		return m_allScenes.at(s);
	}
	void SceneManager::addSceneToMap(APT::StrongPointer<Scene> s)
	{
		m_allScenes[s->sceneID()].setPtr(s.getPtr());
		s.releasePtr();
	}
	void SceneManager::pushScene(std::string s)
	{
        //unload the current scenes stuff
        if (m_activeScenes.size() != 0)
        {
            m_activeScene->unloadContent();
        }
        //make the current scene the active scene
		m_activeScene = m_allScenes[s];
        //make push the active scene to the active scenes stack
		m_activeScenes.push(m_allScenes[s]);
        //load the scenes contenmt
		bool result = m_activeScene->loadContent();
	}
	void SceneManager::popScene()
	{
		m_activeScenes.pop();
	}
	APT::WeakPointer<Scene> SceneManager::getActiveScene()
	{
		return m_activeScene;
	}
	void SceneManager::resetTo(std::string s)
	{
        //walk through all the active scenes and unload their content then pop them
		for (unsigned int i = 0; i < m_activeScenes.size(); i++)
        {
            m_activeScenes.top()->unloadContent();
            m_activeScenes.pop();
        }
        //add the current scene
		m_activeScenes.push(m_allScenes[s]);
	}
}