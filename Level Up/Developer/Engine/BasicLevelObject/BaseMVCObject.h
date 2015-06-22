#ifndef __BASEMVCOBJECT_H
#define __BASEMVCOBJECT_H
#include "BaseLevelObject.h"
#include "../../../Addons/AutomaticPointers/AutomaticPointers.h"
namespace LevelUp
{
	//Basic model view controller object for the whole 
	class BaseMVCObject : public BaseLevelObject
	{
	public:
		BaseMVCObject();
		virtual ~BaseMVCObject();
		//get the model
		APT::WeakPointer<Model> getModel();
		//get the view
		APT::WeakPointer<View> getView();
		//get the controller
		APT::WeakPointer<Controller> getController();

		//sets the model, it will be deleted
		void setModel(APT::StrongPointer<Model> m);
		//sets the view, it will be deleted
		void setView(APT::StrongPointer<View> v);
		//sets the controller, it will be deleted
		void setController(APT::StrongPointer<Controller> c);

		//initialize the object with all MVC components
		void initialize(APT::StrongPointer<Model> m, APT::StrongPointer<View> v, APT::StrongPointer<Controller> c);

		void setPosition(float x, float y);
		//set the position of the object
		void setPosition(LVLfloat2 pos);
		//return the objects position
		LVLfloat2 getPosition() const;

		float getZ() const;
		void setZ(float z);
	private:
		//MVC components
		APT::StrongPointer<Model> m_model;
		APT::StrongPointer<View> m_view;
		APT::StrongPointer<Controller> m_controller;
	};
}

#endif