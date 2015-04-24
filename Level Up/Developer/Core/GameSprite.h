#ifndef __GAME_SPRITE_H
#define __GAME_SPRITE_H

#include "../Base Class/GameObject.h"
#include "../Services/Math/LevelUpMath.h"
namespace LevelUp
{
    /*
    DirectX 11.1 based sprite that holds values for matrices and returns the world matrix
    - Alex Sabourin
    */

	class GameSprite : public GameObject
	{
	public:
		GameSprite();
		virtual ~GameSprite();
        //returns the world matrix
		LVL4X4matrix GetWorldMatrix();

        //sets the rotation
		void setRotation(float rotation);
        //sets the scale of the sprite
		void setScale(LVLfloat2 &scale);

	private:
        //used for rotation and scale
		float m_rotation;
		LVLfloat2 m_scale;

	};
}

#endif

