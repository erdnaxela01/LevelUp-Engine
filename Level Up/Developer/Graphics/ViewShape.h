#ifndef __VIEWSHAPE_H
#define __VIEWSHAPE_H

#include "../Engine/MVC/View.h"
#include "../../Addons/AutomaticPointers/AutomaticPointers.h"

namespace LevelUp
{
	class Shape;

	class ViewShape : public View
	{
	public:
		ViewShape(APT::StrongPointer<Shape> s);
		virtual ~ViewShape();

		void render();

		//get the x
		float getX() const;
		//get the y
		float getY() const;
		//get the height
		float getH() const;
		//get the width
		float getW() const;
		//set the x
		void setX(float x);
		//set the y
		void setY(float y);

		void changeShape(APT::StrongPointer<Shape> s);

		APT::WeakPointer<Shape> getShape();
	private:
		APT::StrongPointer<Shape> m_shape;
	};
}

#endif