#ifndef __SCENE_H
#define __SCENE_H

#include <string>
#include "../MVC/MVCContainer.h"

namespace LevelUp
{
	class Camera;
	class Model;
	class View;
	class Controller;

    /*
    is the objects that display things in the engine, for things like menus and game scenes
    Alex sabourin April 2015
    */
	class Scene
	{
	public:
		Scene(std::string sceneID);
		virtual ~Scene();
		MVCContainer* getContainer();
		virtual bool loadContent() = 0;
		virtual bool unloadContent() = 0;
		virtual void update(double delta) = 0;
		virtual void render() = 0;
        //get this scenes ID
		std::string sceneID();

        // adds to the mvc container
		void addController(Controller* c);
		void addModel(Model* m);
		void addView(View* v);
		void addCamera(Camera* c);

        void removeController(Controller* c);
        void removeModel(Model* m);
        void removeView(View* v);
        void removeCamera(Camera* c);

        //removes the starting camera
        void removeInitialCamera();
	private:
		MVCContainer* m_mvc;
		std::string m_ID;
        Camera* m_initialCamera;
	};
}

#endif