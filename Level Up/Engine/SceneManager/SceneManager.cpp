#include "SceneManager.h"
#include "Scene.h"
namespace LevelUp
{
	SceneManager::SceneManager() :m_activeScene(nullptr)
	{

	}
	SceneManager::~SceneManager()
	{

	}

	Scene* SceneManager::getScene(std::string s)
	{
		return m_allScenes.at(s);
	}
	void SceneManager::addSceneToMap(Scene* s)
	{
		m_allScenes[s->sceneID()] = s;
	}
	void SceneManager::pushScene(std::string s)
	{
		m_activeScene = m_allScenes[s];
		m_activeScenes.push(m_allScenes[s]);
		m_activeScene->loadContent();
	}
	void SceneManager::popScene()
	{
		m_activeScenes.pop();
	}
	Scene* SceneManager::getActiveScene()
	{
		return m_activeScene;
	}
	void SceneManager::resetTo(std::string s)
	{
		m_activeScenes.empty();
		m_activeScenes.push(m_allScenes[s]);
	}
}