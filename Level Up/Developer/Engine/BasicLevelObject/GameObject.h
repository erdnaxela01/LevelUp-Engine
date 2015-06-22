#ifndef __GAMEOBJECT_H
#define __GAMEOBJECT_H

#include "../MVC/MVC.h"
#include "BaseLevelObject.h"
#include "../../Graphics/AnimatedSprite.h"
#include "../../../Addons/AutomaticPointers/AutomaticPointers.h"
#include <string>

namespace LevelUp
{
	class Camera;
	/*
	Gameobject meanth to be inherited from is built for rapid construction with minimum hassle
	Alex Sabourin April 2015
	*/

	class GameObject : public Model, public View, public BaseLevelObject
	{
	public:
		GameObject(std::wstring fName, float widthOfFrame = 0.0f, float heightOfFrame = 0.0f);
		virtual ~GameObject();

		//empty update can be overiden
		virtual void update(double delta);
		//renders the sprite
		virtual void render();
		//sets the position of the sprite
		virtual void setPosition(float x, float y);
		//sets the position of the sprite
		virtual void setPosition(LVLfloat2 pos);
		//gets the position of the sprite
		virtual LVLfloat2 getPosition() const;
		
		virtual float getZ() const;
		void setZ(float z);

		virtual float getH() const;
		virtual float getW() const;
		virtual float getX() const;
		virtual float getY() const;
		void setX(float x);
		void setY(float y);

		void addAnimation(std::string animationName, std::vector<int> frames = {}, float framesPerSecond = 0.0f, bool looped = false);

		void play(std::string animationName, bool looped = false);

		//changes the sprite
		virtual void setSprite(std::wstring fName, float widthOfFrame = 0.0f, float heightOfFrame = 0.0f);
		friend Camera;
	private:
		APT::StrongPointer<AnimatedSprite> m_sprite;
	};
}

#endif