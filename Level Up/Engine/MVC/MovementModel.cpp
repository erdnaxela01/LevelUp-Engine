#include "MovementModel.h"

namespace LevelUp
{
    MovementModel::MovementModel(float speed, float spinSpeed)
		: m_width(0.0f), m_height(0.0f), m_x(0.0f), m_y(0.0f), m_angle(0.0f), m_speed(speed), m_canMoveForward(false), m_canMoveBack(false),
		m_isRotatingRight(false), m_isRotatingLeft(false), m_angularVelocity(spinSpeed)
	{

	}


	MovementModel::~MovementModel()
	{

	}
	float MovementModel::getX()
	{
		return m_x;
	}
	float MovementModel::getY()
	{
		return m_y;
	}
	float MovementModel::getWidth()
	{
		return m_width;
	}
	float MovementModel::getHeight()
	{
		return m_height;
	}

	void MovementModel::setX(float x)
	{
		m_x = x;
	}
	void MovementModel::setY(float y)
	{
		m_y = y;
	}
	void MovementModel::setWidth(float w)
	{
		m_width = w;
	}
	void MovementModel::setHeight(float h)
	{
		m_height = h;
	}

	void MovementModel::update(double delta)
	{
        //update the model // this will be abstracted away with a command message queue
		if (m_canMoveForward)
		{
			m_x += (std::cos(m_angle) * m_speed) * delta;
			m_y += (std::sin(m_angle) * m_speed) * delta;
		}
		if (m_canMoveBack)
		{
			m_x -= (std::cos(m_angle) * m_speed) * delta;
			m_y -= (std::sin(m_angle) * m_speed) * delta;
		}
		if (m_isRotatingLeft)
		{
			m_angle += m_angularVelocity * delta;
		}
		if (m_isRotatingRight)
		{
			m_angle -= m_angularVelocity * delta;
		}
	}

	void MovementModel::setAngle(float a)
	{
		m_angle = a;
	}
	void MovementModel::setSpeed(float s)
	{
		m_speed = s;
	}
	float MovementModel::getAngle()
	{
		return m_angle;
	}
	float MovementModel::getSpeed()
	{
		return m_speed;
	}
	bool MovementModel::canMoveForward()
	{
		return m_canMoveForward;
	}

	void MovementModel::setCanMoveBack(bool b)
	{
		m_canMoveBack = b;
	}
	void MovementModel::setCanMoveForward(bool b)
	{
		m_canMoveForward = b;
	}
	bool MovementModel::canMoveBack()
	{
		return m_canMoveBack;
	}

	void MovementModel::setAngularVelocity(float av)
	{
		m_angularVelocity = av;
	}
	void MovementModel::setIsRotatingRight(bool b)
	{
		m_isRotatingRight = b;
	}
	void MovementModel::setIsRotatingLeft(bool b)
	{
		m_isRotatingLeft = b;
	}

	bool MovementModel::isRotatingLeft()
	{
		return m_isRotatingLeft;
	}
	bool MovementModel::isRotatingRight()
	{
		return m_isRotatingRight;
	}
}