#include "BaseMVCObject.h"
#include "../../Core/StandardTemplates.h"
#include "../MVC/MVC.h"

namespace LevelUp
{
	BaseMVCObject::BaseMVCObject() : m_model(nullptr), m_view(nullptr), m_controller(nullptr), BaseLevelObject()
	{

	}
	BaseMVCObject::~BaseMVCObject()
	{
		
	}
	APT::WeakPointer<Model> BaseMVCObject::getModel()
	{
		return m_model;
	}
	APT::WeakPointer<View> BaseMVCObject::getView()
	{
		return m_view;
	}
	APT::WeakPointer<Controller> BaseMVCObject::getController()
	{
		return m_controller;
	}
	void BaseMVCObject::setModel(APT::StrongPointer<Model> m)
	{
		m_model.setPtr(m.getPtr());
		m.releasePtr();
	}
	void BaseMVCObject::setView(APT::StrongPointer<View> v)
	{
		m_view.setPtr(v.getPtr());
		v.releasePtr();
	}
	void BaseMVCObject::setController(APT::StrongPointer<Controller> c)
	{
		m_controller.setPtr(c.getPtr());
		c.releasePtr();
	}
	void BaseMVCObject::initialize(APT::StrongPointer<Model> m, APT::StrongPointer<View> v, APT::StrongPointer<Controller> c)
	{
		m_model.setPtr(m.getPtr());
		m.releasePtr();
		m_view.setPtr(v.getPtr());
		v.releasePtr();
		m_controller.setPtr(c.getPtr());
		c.releasePtr();
	}
	void BaseMVCObject::setPosition(float x, float y)
	{
		//set the position to the view and the gameObject parent class
		m_view->setX(x);
		m_view->setY(y);
	}
	void BaseMVCObject::setPosition(LVLfloat2 pos)
	{
		//set the position to the view and the gameObject parent class
		m_view->setX(pos.x);
		m_view->setY(pos.y);
	}
	LVLfloat2 BaseMVCObject::getPosition() const
	{
		//set the position to the game objet if it changed and return the position
		LVLfloat2 pos;
		pos.x = m_view->getX();
		pos.y = m_view->getY();
		return pos;
	}
	float BaseMVCObject::getZ() const
	{
		return m_view->getZ();
	}

	void BaseMVCObject::setZ(float z)
	{
		m_view->setZ(z);
	}

}