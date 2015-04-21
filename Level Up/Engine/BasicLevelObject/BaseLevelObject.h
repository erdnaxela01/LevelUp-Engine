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
        //returns MVC components
		Model* getModel();
		View* getView();
		Controller* getController();

        //sets MVC components
		void setModel(Model* m);
		void setView(View* v);
		void setController(Controller* c);

        //initialize the object with all MVC components
		void initialize(Model* m, View* v, Controller* c);
		void setPosition(float x, float y);
        void setPosition(LVLfloat2 pos);
        LVLfloat2& getPosition();
	private:
		Model* m_model;
		View* m_view;
		Controller* m_controller;

	};
}

#endif