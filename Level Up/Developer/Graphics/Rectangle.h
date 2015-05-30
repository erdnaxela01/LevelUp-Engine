#ifndef __RECTANGLE_H
#define __RECTANGLE_H

#include "../Services/Math/LevelUpMath.h"
#include "Shape.h"
#include <vector>

namespace LevelUp
{


    //draws a rectangle on the screen with the specified values
    //Alex Sabourin April 2015
	class Rectangle : public Shape
	{
	public:
        Rectangle(LVLfloat4 color, float width, float height);
		virtual ~Rectangle();
        //load the rectangles content
		bool loadContent();
        //unload the rectangles content
		void unloadContent();
        //render the rectangle
		void render();
        //get the width of the rectangle
		float getWidth(){ return m_width; }
        //get the rectangles height
		float getHeight(){ return m_height; }
		//set the rectangle
		void setRect(LVLrect r);
	private:
		float m_width;
		float m_height;
		//set the rectangles vertex buffer
		ColorVertexPos* getVertices(float halfWidth, float halfHeight);
		void resetVertices();
	};
}

#endif