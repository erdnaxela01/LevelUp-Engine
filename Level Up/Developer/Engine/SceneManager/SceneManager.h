#ifndef __SCENEMANAGER_H
#define __SCENEMANAGER_H

#include <string>
#include <stack>
#include <map>
#include "../../../Addons/AutomaticPointers/AutomaticPointers.h"

namespace LevelUp
{
	class Scene;
    //all the scene manager does is take care of organizing the screens
    //Alex Sabourin April 2015
	class SceneManager final
	{
	public:
        //get a scene compared to the name
		APT::WeakPointer<Scene> getScene(std::string s);
        //add a scene this scene gets deleted by the scene manager
		void addSceneToMap(APT::StrongPointer<Scene> s);
        //make this the active scene
		void pushScene(std::string s);
        //go back a scene
		void popScene();
        //get the current scene
		APT::WeakPointer<Scene> getActiveScene();
        //set the scene to this scene
		void resetTo(std::string s);
		SceneManager();
		virtual ~SceneManager();
	private:
		APT::WeakPointer<Scene> m_activeScene;
		std::stack<APT::WeakPointer<Scene>> m_activeScenes;
		std::map<std::string, APT::StrongPointer<Scene>> m_allScenes;



	};
}


#endif