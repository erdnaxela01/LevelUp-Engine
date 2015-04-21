
#include "GameSprite.h"
#include "../Services/ServiceLocator.h"
#include "../Services/Math/LevelUpMath.h"
namespace LevelUp
{

	GameSprite::GameSprite() :m_rotation(0)
	{
		m_scale.x = m_scale.y = 1.0f;
	}


	GameSprite::~GameSprite()
	{
	}

	LVL4X4matrix GameSprite::GetWorldMatrix()
	{
        LVL4X4matrix translation2 = translationMatrix2D(LVLfloat2(getPosition().x, getPosition().y));
        LVL4X4matrix rotationZ2 = zRotationMatrix(m_rotation);
        LVL4X4matrix scale2 = scalingMatrix2D(LVLfloat2(m_scale.x, m_scale.y));


        LVL4X4matrix m2 = rotationZ2 *scale2 * translation2;


		return m2;
	}

	void GameSprite::setRotation(float rotation)
	{
		m_rotation = rotation;
	}

	void GameSprite::setScale(LVLfloat2 &scale)
	{
		m_scale = scale;
	}
}
