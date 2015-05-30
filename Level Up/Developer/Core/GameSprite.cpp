
#include "GameSprite.h"
#include "../Services/ServiceLocator.h"
#include "../Services/Math/LevelUpMath.h"
namespace LevelUp
{

	GameSprite::GameSprite() :m_rotation(0)
	{
        //set the initial values to 1
		m_scale.x = m_scale.y = 1.0f;
	}


	GameSprite::~GameSprite()
	{
	}

	LVL4X4matrix GameSprite::GetWorldMatrix() const
	{
        //get the translation rotation and scaling matrices and return the world matrix
        LVL4X4matrix translation = MathHelper::translationMatrix2D(LVLfloat2(getPosition().x, getPosition().y));
        LVL4X4matrix rotationZ = MathHelper::zRotationMatrix(m_rotation);
        LVL4X4matrix scale = MathHelper::scalingMatrix2D(LVLfloat2(m_scale.x, m_scale.y));


        LVL4X4matrix m = rotationZ *scale * translation;


		return m;
	}

	void GameSprite::setRotation(float rotation)
	{
        //set the rotation of the matrix
		m_rotation = rotation;
	}

	void GameSprite::setScale(LVLfloat2 &scale)
	{
        //set the scale of the matrix
		m_scale = scale;
	}
	LVLfloat2 GameSprite::getPosition() const
	{
		return m_position;
	}

	void GameSprite::setPosition(LVLfloat2 l)
	{
		m_position = l;
	}
}
