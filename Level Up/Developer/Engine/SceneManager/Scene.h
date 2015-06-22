#ifndef __SCENE_H
#define __SCENE_H

#include <string>
#include "../MVC/MVCContainer.h"
#include "../../UI/Cameras/Camera.h"
#include "../../../Addons/AutomaticPointers/AutomaticPointers.h"

namespace LevelUp
{
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
		APT::WeakPointer<MVCContainer> getContainer() const;
        //load the scenes content
		virtual bool loadContent() = 0;
        //unload the scenes content
		virtual bool unloadContent() = 0;
        //update the scene
		virtual void update(double delta) = 0;
        //render the scene
		virtual void render() = 0;
        //get this scenes ID
		std::string sceneID() const;

        // adds the controller
		void addController(APT::WeakPointer<Controller> c);
        // adds the model
		void addModel(APT::WeakPointer<Model> m);
        // adds the view
		void addView(APT::WeakPointer<View> v);
        // adds the camera
		void addCamera(APT::WeakPointer<Camera> c);

        // adds the controller
		void removeController(APT::WeakPointer<Controller> c);

        // adds the model
		void removeModel(APT::WeakPointer<Model> m);

        // adds the view
		void removeView(APT::WeakPointer<View> v);
        // adds the camera
		void removeCamera(APT::WeakPointer<Camera> c);

        //removes the starting camera
        void removeInitialCamera();

		APT::WeakPointer<Camera> getInitialCamera();
	private:
		APT::StrongPointer<MVCContainer> m_mvc;
		std::string m_ID;
		APT::StrongPointer<Camera> m_initialCamera;
	};
}

#endif