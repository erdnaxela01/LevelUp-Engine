#ifndef __GAME_SPRITE_H
#define __GAME_SPRITE_H

#include "../Services/Math/LevelUpMath.h"
namespace LevelUp
{
    /*
    DirectX 11.1 based sprite that holds values for matrices and returns the world matrix
    - Alex Sabourin
    */

	class GameSprite
	{
	public:
		GameSprite();
		virtual ~GameSprite();
        //returns the world matrix
		LVL4X4matrix GetWorldMatrix() const;

        //sets the rotation
		void setRotation(float rotation);
        //sets the scale of the sprite
		void setScale(LVLfloat2 &scale);

		LVLfloat2 getPosition() const;

		void setPosition(LVLfloat2 l);

	private:
        //used for rotation and scale
		float m_rotation;
		LVLfloat2 m_scale;
		LVLfloat2 m_position;

	};
}

#endif

