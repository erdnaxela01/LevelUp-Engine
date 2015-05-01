#ifndef __COLLISIONATTRIBUTE_H
#define __COLLISIONATTRIBUTE_H

#include "../../../Developer/Engine/Attributes/Attributes.h"
#include "../../../Developer/Services/Math/DataTypes.h"
#include "../../../Developer/Engine/MVC/View.h"

namespace LevelUp
{
	class CollisionAttribute : public Attribute
	{
	public:
		CollisionAttribute(float width, float height);
		virtual ~CollisionAttribute() {};
		LVLrect getCollisionRect();
		LVLfloat2 getOffset();
		void setOffset(LVLfloat2 l);
		bool doesCollide(LVLrect r);
		void setProportions(float width, float height);
		void render();

		float getX() { return 0.0f; }
		float getY() { return 0.0f; }
		float getW() { return 0.0f; }
		float getH() { return 0.0f; }
		void setX(float x){};
		void setY(float x){};
	private:
		LVLrect m_collisionRect;
		LVLfloat2 m_offset;
		LVLfloat2 m_position;
		LVLfloat2 m_proportions;
		void updateCollisionRect();
		void render(float x, float y);
	};
}

#endif