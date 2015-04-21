#ifndef __MovementSpriteView_H
#define __MovementSpriteView_H

#include "View.h"
#include "../../Graphics/Sprite.h"

#include <string>
namespace LevelUp
{
	class MovementModel;
	class MovementSpriteView : public View
	{
	public:
		MovementSpriteView(std::wstring fName, MovementModel* sm, float z = 1.0f);
		void setSprite(std::wstring fName);
		virtual ~MovementSpriteView();
        void render();
		float getX();
		float getY();
		float getH();
		float getW();
		void setX(float x);
		void setY(float y);
		void rotate(float angle);
		void setScale(float x, float y);
        //camera is a friend to be able to access the location render
        friend Camera;
	private:
		Sprite* m_sprite;
		MovementModel* m_movementModel;
        //object must be able to get drawn somewhere else for the camera
        void render(float x, float y);

	};
}

#endif