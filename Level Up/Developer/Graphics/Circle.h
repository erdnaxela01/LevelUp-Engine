#ifndef __CIRCLE_H
#define __CIRCLE_H

#include "Shape.h"
#include "../Services/Math/DataTypes.h"

#include <vector>

namespace LevelUp
{
	const int NUM_OF_SIDES = 360;

	class Circle :public Shape
	{
	public:
		Circle(LVLfloat4 color, float radius);
		virtual ~Circle();

		bool loadContent();
		void unloadContent();

		void render();

		float getRadius() const;
		void setRadius(float r);
	private:
		ColorVertexPos* getVertices(float radius);
		void resetVertices();
		float m_radius;


	};
}

#endif