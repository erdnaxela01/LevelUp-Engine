#ifndef __ANIMATEDSPRITE_H
#define __ANIMATEDSPRITE_H

#include "Sprite.h"
#include "../Engine/MVC/Model.h"
#include "../Engine/Helper/CountDown.h"
#include <vector>
#include <string>
#include <map>
#include "../../Addons/AutomaticPointers/AutomaticPointers.h"

namespace LevelUp
{
	/*
	Animated sprite to animate a sprite use with game object to work with camera
	Alex Sabourin May 2015
	*/
	struct AnimationVals
	{
		std::string animationName;
		std::vector<int> frames;
		float frameRate;
		bool looped;
	};

	class MVCContainer;
	class AnimatedSprite : public Sprite, public Model
	{
	public:
		//give the sprite fileName, the frame specs
		AnimatedSprite(std::wstring fileName,float widthOfFrame = 0.0f, float heightOfFrame = 0.0f, bool dds = false);
		virtual ~AnimatedSprite();
		//set the sprite sheet values
		void setSpriteSheet(float widthOfFrames, float heightOfFrames);
		//add an animation to this sprite
		void addAnimation(std::string animationName, std::vector<int> frames = {}, float framesPerSecond = 0.0f, bool looped = false);
		//play the animation
		void play(std::string animation, bool looped = false);

		friend MVCContainer;
	protected:
		bool setVertexBuffer(VertexPos vertices[]);
	private:
		//struct to hold animations
		struct AnimationValues
		{
			std::vector<int> frames;
			float framesPerSecond;
			int currentFrame;
			bool isLooped;
			int numberOfFrames;
		};
		//update the animation
		void update(double delta);

		//set the vertices for the animation
		bool setVertices(float halfWidth, float halfHeight, float positionX, float positionY);

		std::map<std::string, AnimationValues> m_animations;
		float m_framesPerSecond;
		LVLfloat2 m_frameSpecs;
		APT::WeakPointer<AnimationValues> m_currentAnimation;
		bool m_isPlaying;
		CountDown m_time;
	};
}

#endif