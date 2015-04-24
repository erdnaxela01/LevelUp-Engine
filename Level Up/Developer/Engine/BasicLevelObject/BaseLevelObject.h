#ifndef __BASELEVELOBJECT_H
#define __BASELEVELOBJECT_H
#include "../../Base Class/GameObject.h"
#include "../ECS/Entity.h"
#include <DirectXMath.h>

namespace LevelUp
{
	class Model;
	class View;
	class Controller;
    /*
    Basic container for MVC safely deletes objects passed into it and ability to change components
    -Alex April 2015
    */
	class BaseLevelObject : public GameObject, public Entity
	{
	public:
		BaseLevelObject();
		virtual ~BaseLevelObject();
        //get the model
		Model* getModel();
        //get the view
		View* getView();
        //get the controller
		Controller* getController();

        //sets the model, it will be deleted
		void setModel(Model* m);
        //sets the view, it will be deleted
		void setView(View* v);
        //sets the controller, it will be deleted
		void setController(Controller* c);

        //initialize the object with all MVC components
		void initialize(Model* m, View* v, Controller* c);
        //set the position of the object
		void setPosition(float x, float y);
        //set the position of the object
        void setPosition(LVLfloat2 pos);
        //return the objects position
        LVLfloat2& getPosition();
	private:
        //MVC components
		Model* m_model;
		View* m_view;
		Controller* m_controller;

	};
}

#endif