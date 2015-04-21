#ifndef __MOVEMENTMODEL_H
#define __MOVEMENTMODEL_H

#include "Model.h"
namespace LevelUp
{
    //model for the spaceship like movement
    //Alex Sabourin April 2015
	class MovementModel : public Model
	{
	public:
        MovementModel(float speed = 0.0f, float spinSpeed = 0.0f);
		virtual ~MovementModel();
		float getX();
		float getY();
		float getWidth();
		float getHeight();
		float getAngle();
		float getSpeed();
		bool canMoveForward();
		bool canMoveBack();
		bool isRotatingRight();
		bool isRotatingLeft();

		void setX(float x);
		void setY(float y);
		void setWidth(float w);
		void setHeight(float h);
		void setAngle(float a);
		void setSpeed(float s);
		void setCanMoveForward(bool b);
		void setCanMoveBack(bool b);
		void setAngularVelocity(float av);
		void setIsRotatingRight(bool b);
		void setIsRotatingLeft(bool b);

		virtual void update(double delta);
	protected:
		float m_x;
		float m_y;
		float m_width;
		float m_height;
		float m_angle;
		float m_speed;
		float m_angularVelocity;
		bool m_isRotatingRight;
		bool m_isRotatingLeft;
		bool m_canMoveForward;
		bool m_canMoveBack;
	private:

	};
}

#endif