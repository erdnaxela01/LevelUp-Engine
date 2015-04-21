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

        //sets the rotation and scale of the sprite
		void setRotation(float rotation);
		void setScale(LVLfloat2 &scale);

	private:
		float m_rotation;
		LVLfloat2 m_scale;

	};
}

#endif

