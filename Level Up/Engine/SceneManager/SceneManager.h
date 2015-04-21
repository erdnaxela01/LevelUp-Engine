#ifndef __SCENEMANAGER_H
#define __SCENEMANAGER_H

#include <string>
#include <stack>
#include <map>

namespace LevelUp
{
	class Scene;
    //all the scene manager does is take care of organizing the screens
    //Alex Sabourin April 2015
	class SceneManager final
	{
	public:

		Scene* getScene(std::string s);
        //add a scene
		void addSceneToMap(Scene* s);
        //make this the active scene
		void pushScene(std::string s);
        //go back a scene
		void popScene();
		Scene* getActiveScene();
        //set the scene to this scene
		void resetTo(std::string s);
		SceneManager();
		~SceneManager();
	private:
		Scene* m_activeScene;
		std::stack<Scene*> m_activeScenes;
		std::map<std::string, Scene*> m_allScenes;



	};
}


#endif