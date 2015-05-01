#include "CollisionAttribute.h"
#include "../../../Developer/Engine/BasicLevelObject/BaseLevelObject.h"
#include "../../../Developer/Graphics/Rectangle.h"

namespace LevelUp
{
	CollisionAttribute::CollisionAttribute(float width, float height) :m_offset(0.0f, 0.0f)
	{
		m_proportions.x = width;
		m_proportions.y = height;
		m_type = "CollisionAttribute";
	}
	LVLrect CollisionAttribute::getCollisionRect()
	{
		updateCollisionRect();
		return m_collisionRect;
	}
	LVLfloat2 CollisionAttribute::getOffset()
	{
		return m_offset;
	}
	void CollisionAttribute::setOffset(LVLfloat2 l)
	{
		m_offset = l;
	}
	bool CollisionAttribute::doesCollide(LVLrect r)
	{
		updateCollisionRect();
		if ((m_collisionRect.top < r.bot) ||
			(m_collisionRect.bot > r.top) ||
			(m_collisionRect.left > r.right) ||
			(m_collisionRect.right < r.left))
		{
			return false;
		}
		return true;
	}
	void CollisionAttribute::updateCollisionRect()
	{
		m_position.x = m_parent->getPosition().x + m_offset.x;
		m_position.y = m_parent->getPosition().y + m_offset.y;

		m_collisionRect.bot = m_position.y - m_proportions.y * 0.5f;
		m_collisionRect.top = m_position.y + m_proportions.y * 0.5f;
		m_collisionRect.left = m_position.x - m_proportions.x * 0.5f;
		m_collisionRect.right = m_position.x + m_proportions.x * 0.5f;
	}
	void CollisionAttribute::setProportions(float width, float height)
	{
		m_proportions.x = width;
		m_proportions.y = height;
	}

}