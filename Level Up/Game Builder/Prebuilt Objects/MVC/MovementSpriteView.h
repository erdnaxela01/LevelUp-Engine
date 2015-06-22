#ifndef __MovementSpriteView_H
#define __MovementSpriteView_H

#include "../../../Developer/Engine/MVC/View.h"
#include "../../../Developer/Graphics/AnimatedSprite.h"
#include "../../../Addons/AutomaticPointers/AutomaticPointers.h"

#include <string>
#include <vector>
namespace LevelUp
{
	class MovementModel;
	class MovementSpriteView : public View
	{
	public:
		MovementSpriteView(std::wstring fName, APT::WeakPointer<MovementModel> sm, float z = 1.0f);
		//Adds animations to the animated sprite
		void addAnimation(std::vector<AnimationVals> values);
		//Adds animations to the animated sprite
		void addAnimation(std::string animationName, std::vector<int> frames, float frameRate, bool looped);
		//play a specific animation
		void play(std::string animationName, bool looped = false);
        //set the views sprite
		void setSprite(std::wstring fName);
        //descructior
		virtual ~MovementSpriteView();
        //render the sprite
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

        //rotate the sprite
		void rotate(float angle);
        //set the scale of the sprite
		void setScale(float x, float y);
	private:
		APT::StrongPointer<AnimatedSprite> m_sprite;
		APT::WeakPointer<MovementModel> m_movementModel;

	};
}

#endif