#ifndef __GAMEOBJECT_H
#define __GAMEOBJECT_H

#include "../MVC/MVC.h"
#include "BaseLevelObject.h"
#include <string>

namespace LevelUp
{
	class Sprite;
	class Camera;
	/*
	Gameobject meanth to be inherited from is built for rapid construction with minimum hassle
	Alex Sabourin April 2015
	*/

	class GameObject : public Model, public View, public BaseLevelObject
	{
	public:
		GameObject(std::wstring fName);
		~GameObject();

		//empty update can be overiden
		virtual void update(double delta);
		//renders the sprite
		virtual void render();
		//sets the position of the sprite
		virtual void setPosition(float x, float y);
		//sets the position of the sprite
		virtual void setPosition(LVLfloat2 pos);
		//gets the position of the sprite
		virtual LVLfloat2 getPosition();

		//changes the sprite
		virtual void setSprite(std::wstring fName);
		friend Camera;
	private:
		//renders the object in a different place for the camera
		virtual void render(float x, float y);
		Sprite* m_sprite;
	};
}

#endif