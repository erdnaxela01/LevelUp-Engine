#ifndef __MOVEMENTMODEL_H
#define __MOVEMENTMODEL_H

#include "../../../Developer/Engine/MVC/Model.h"
namespace LevelUp
{
    //model for the spaceship like movement
    //Alex Sabourin April 2015
	class MovementModel : public Model
	{
	public:
        //set the inital values of the model
        MovementModel(float speed = 0.0f, float spinSpeed = 0.0f);
		virtual ~MovementModel();
        //get the x position of the model
		float getX();
        //get the y position of the model
		float getY();
        //get the width
		float getWidth();
        //get the height
		float getHeight();
        //get the angle of the model not the sprite
		float getAngle();
        //get the speed of the model
		float getSpeed();
        //can it move forward?
		bool canMoveForward();
        //can it move back?
		bool canMoveBack();
        //is it rotating to the right?
		bool isRotatingRight();
        //is it rotating to the left?
		bool isRotatingLeft();

        //set the x value of the model
		void setX(float x);
        //set the y value of the model
		void setY(float y);
        //set the width
		void setWidth(float w);
        //set the height
		void setHeight(float h);
        //set the angle of the model
		void setAngle(float a);
        //set the speed of the model
		void setSpeed(float s);
        //set if the model can move forward
		void setCanMoveForward(bool b);
        //set if the model can move back
		void setCanMoveBack(bool b);
        //set the angular velocity of the model
		void setAngularVelocity(float av);
        //set if the model is turning right
		void setIsRotatingRight(bool b);
        //set if the model is turning left
		void setIsRotatingLeft(bool b);

        //update the model
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