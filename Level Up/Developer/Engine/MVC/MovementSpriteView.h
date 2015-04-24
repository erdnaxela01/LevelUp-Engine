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
        //set the views sprite
		void setSprite(std::wstring fName);
        //descructior
		virtual ~MovementSpriteView();
        //render the sprite
        void render();
        //get the x
		float getX();

        //get the y
		float getY();

        //get the height
		float getH();

        //get the width
		float getW();

        //set the x
		void setX(float x);

        //set the y
		void setY(float y);

        //rotate the sprite
		void rotate(float angle);
        //set the scale of the sprite
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