#ifndef __ANIMATEDSPRITE_H
#define __ANIMATEDSPRITE_H

#include "Sprite.h"
#include "../Engine/MVC/Model.h"
#include "../Engine/Helper/CountDown.h"
#include <vector>
#include <map>

namespace LevelUp
{
	class AnimatedSprite : public Sprite, public Model
	{
	public:
		AnimatedSprite(std::wstring fileName,float widthOfFrame, float heightOfFrame, bool dds = false);
		virtual ~AnimatedSprite();
		void setSpriteSheet(float widthOfFrames, float heightOfFrames);
		void addAnimation(std::string animationName, std::vector<int> frames = {}, float framesPerSecond = 0.0f, bool looped = false);
		void play(std::string animation, bool looped = false);

		void update(double delta);

		bool setVertices(float halfWidth, float halfHeight, float positionX, float positionY);
	private:
		struct AnimationValues
		{
			std::vector<int> frames;
			int framesPerSecond;
			int currentFrame;
			bool isLooped;
			int numberOfFrames;
		};

		std::map<std::string, AnimationValues> m_animations;
		float m_framesPerSecond;
		LVLfloat2 m_frameSpecs;
		AnimationValues* m_currentAnimation;
		bool m_isPlaying;
		CountDown m_time;
	};
}

#endif