#include "ViewShape.h"
#include "Shape.h"

namespace LevelUp
{
	ViewShape::ViewShape(APT::StrongPointer<Shape> s)
	{
		m_shape.setPtr(s.getPtr());
		s.releasePtr();
	}
	ViewShape::~ViewShape()
	{
	}

	void ViewShape::render()
	{
		m_shape->render();
	}

	//get the x
	float ViewShape::getX() const
	{
		return m_shape->getPosition().x;
	}
	//get the y
	float ViewShape::getY() const
	{
		return m_shape->getPosition().y;
	}
	//get the height
	float ViewShape::getH() const
	{
		return 0;
	}
	//get the width
	float ViewShape::getW() const
	{
		return 0;
	}
	//set the x
	void ViewShape::setX(float x)
	{
		m_shape->setPosition(x, m_shape->getPosition().y);
	}
	//set the y
	void ViewShape::setY(float y)
	{
		m_shape->setPosition(m_shape->getPosition().x, y);
	}

	void ViewShape::changeShape(APT::StrongPointer<Shape> s)
	{
		m_shape.clear();

		m_shape.setPtr(s.releasePtr());
	}
	APT::WeakPointer<Shape> ViewShape::getShape()
	{
		return m_shape;
	}
}