#include "BaseLevelObject.h"
#include "../../Core/StandardTemplates.h"
#include "../MVC/MVC.h"

namespace LevelUp
{
    BaseLevelObject::BaseLevelObject() : m_model(nullptr), m_view(nullptr), m_controller(nullptr), GameObject()
	{

	}
	BaseLevelObject::~BaseLevelObject()
	{
        //deletes all the objects
		SafeDelete(m_controller);
		SafeDelete(m_model);
		SafeDelete(m_view);
	}
	Model* BaseLevelObject::getModel()
	{
		return m_model;
	}
	View* BaseLevelObject::getView()
	{
		return m_view;
	}
	Controller* BaseLevelObject::getController()
	{
		return m_controller;
	}
	void BaseLevelObject::setModel(Model* m)
	{
		m_model = m;
	}
	void BaseLevelObject::setView(View* v)
	{
		m_view = v;
	}
	void BaseLevelObject::setController(Controller* c)
	{
		m_controller = c;
	}
	void BaseLevelObject::initialize(Model* m, View* v, Controller* c)
	{
		m_model = m;
		m_view = v;
		m_controller = c;
	}

	void BaseLevelObject::setPosition(float x, float y)
	{
        //set the position to the view and the gameObject parent class
		m_view->setX(x);
		m_view->setY(y);
        m_position.x = x;
        m_position.y = y;
	}
    void BaseLevelObject::setPosition(LVLfloat2 pos)
	{
        //set the position to the view and the gameObject parent class
		m_position = pos;
		m_view->setX(pos.x);
		m_view->setY(pos.y);
	}
    LVLfloat2& BaseLevelObject::getPosition()
	{
        //set the position to the game objet if it changed and return the position
        setPosition(m_view->getX(), m_view->getY());
		return m_position;
	}
}