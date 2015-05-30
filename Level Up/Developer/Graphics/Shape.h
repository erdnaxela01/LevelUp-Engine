#ifndef __SHAPE_H
#define __SHAPE_H

#include "../Services/Math/DataTypes.h"
#include "RenderObject.h"

namespace LevelUp
{
	struct ColorVertexPos
	{
		LVLfloat3 pos;
		LVLfloat4 color;
	};
	class Shape : public RenderObject
	{
	public:
		Shape(LVLfloat4 color);
		virtual ~Shape();

		virtual void render() = 0;
		//set the rectangles alpha
		void setAlpha(float a);
		//get the rectangles alpha
		float getAlpha();
		//set the color of the rectangle
		void setColor(LVLfloat3 c);
	protected:
		LVLfloat4 m_color;
		float m_alpha;
		bool m_verticesAreDirty;
		bool setVertexBuffer(ColorVertexPos vertices[], int num);
	};
}

#endif