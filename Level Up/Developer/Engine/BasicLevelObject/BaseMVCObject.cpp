#include "BaseMVCObject.h"
#include "../../Core/StandardTemplates.h"
#include "../MVC/MVC.h"

namespace LevelUp
{
	BaseMVCObject::BaseMVCObject() : m_model(nullptr), m_view(nullptr), m_controller(nullptr)
	{

	}
	BaseMVCObject::~BaseMVCObject()
	{
		//deletes all the objects
		SafeDelete(m_controller);
		SafeDelete(m_model);
		SafeDelete(m_view);
	}
	Model* BaseMVCObject::getModel()
	{
		return m_model;
	}
	View* BaseMVCObject::getView()
	{
		return m_view;
	}
	Controller* BaseMVCObject::getController()
	{
		return m_controller;
	}
	void BaseMVCObject::setModel(Model* m)
	{
		m_model = m;
	}
	void BaseMVCObject::setView(View* v)
	{
		m_view = v;
	}
	void BaseMVCObject::setController(Controller* c)
	{
		m_controller = c;
	}
	void BaseMVCObject::initialize(Model* m, View* v, Controller* c)
	{
		m_model = m;
		m_view = v;
		m_controller = c;
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
	LVLfloat2 BaseMVCObject::getPosition()
	{
		//set the position to the game objet if it changed and return the position
		LVLfloat2 pos;
		pos.x = m_view->getX();
		pos.y = m_view->getY();
		return pos;
	}

}