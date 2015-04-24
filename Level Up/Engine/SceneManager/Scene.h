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
        //get the model view controller container
		MVCContainer* getContainer();
        //load the scenes content
		virtual bool loadContent() = 0;
        //unload the scenes content
		virtual bool unloadContent() = 0;
        //update the scene
		virtual void update(double delta) = 0;
        //render the scene
		virtual void render() = 0;
        //get this scenes ID
		std::string sceneID();

        // adds the controller
		void addController(Controller* c);
        // adds the model
		void addModel(Model* m);
        // adds the view
		void addView(View* v);
        // adds the camera
		void addCamera(Camera* c);

        // adds the controller
        void removeController(Controller* c);

        // adds the model
        void removeModel(Model* m);

        // adds the view
        void removeView(View* v);
        // adds the camera
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