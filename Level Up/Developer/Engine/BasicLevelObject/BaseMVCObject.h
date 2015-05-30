#ifndef __BASEMVCOBJECT_H
#define __BASEMVCOBJECT_H
#include "BaseLevelObject.h"
namespace LevelUp
{
	//Basic model view controller object for the whole 
	class BaseMVCObject : public BaseLevelObject
	{
	public:
		BaseMVCObject();
		virtual ~BaseMVCObject();
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

		void setPosition(float x, float y);
		//set the position of the object
		void setPosition(LVLfloat2 pos);
		//return the objects position
		LVLfloat2 getPosition() const;

		float getZ() const;
		void setZ(float z);
	private:
		//MVC components
		Model* m_model;
		View* m_view;
		Controller* m_controller;
	};
}

#endif