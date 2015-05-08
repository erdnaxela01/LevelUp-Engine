#include "AnimatedSprite.h"

namespace LevelUp
{
	AnimatedSprite::AnimatedSprite(std::wstring fileName, float widthOfFrame, float heightOfFrame, bool dds) :m_currentAnimation(nullptr), m_isPlaying(false), Sprite(dds)
	{
		//initialize the sprite
		initialize(fileName);
		setSpriteSheet(widthOfFrame, heightOfFrame);
	}
	AnimatedSprite::~AnimatedSprite()
	{

	}
	void AnimatedSprite::setSpriteSheet(float widthOfFrames, float heightOfFrames)
	{
		//set the sprite sheets values
		m_frameSpecs.x = widthOfFrames;
		m_frameSpecs.y = heightOfFrames;

	}
	void AnimatedSprite::addAnimation(std::string animationName, std::vector<int> frames, float framesPerSecond, bool looped)
	{
		//if there are too many frames throw
		if (frames.size() * m_frameSpecs.x > m_width)
		{
			throw (std::runtime_error("Too many frames in animated sprite"));
		}
		//set all the values
		m_animations[animationName].frames = frames;
		m_animations[animationName].framesPerSecond = framesPerSecond;
		m_animations[animationName].currentFrame = 0;
		m_animations[animationName].isLooped = looped;
		m_animations[animationName].numberOfFrames = frames.size();
	}
	void AnimatedSprite::play(std::string animation, bool looped)
	{
		//play the animation named by the string
		m_currentAnimation = &(m_animations[animation]);
		m_currentAnimation->currentFrame = 0;
		m_currentAnimation->isLooped = looped;
		m_isPlaying = true;
	}

	void AnimatedSprite::update(double delta)
	{
		//if the animation isnt playing
		if (!m_isPlaying)
		{
			return;
		}

		//update the timer
		m_time.update(delta);

		//if the timer is done
		if (m_time.isItDone())
		{
			//reset the timer
			m_time.start(1.0 / m_currentAnimation->framesPerSecond);
			//increment the frame
			m_currentAnimation->currentFrame++;
			//if over the number of frames and it can loop lloop it back to 0
			if (m_currentAnimation->currentFrame >= m_currentAnimation->numberOfFrames && m_currentAnimation->isLooped)
			{
				m_currentAnimation->currentFrame = 0;
			}
			//if its over but it cant loop keep it at the max number of frames
			else if (m_currentAnimation->currentFrame >= m_currentAnimation->numberOfFrames - 1 && m_currentAnimation->isLooped == false)
			{
				m_currentAnimation->currentFrame = m_currentAnimation->numberOfFrames - 1;
			}

			//set the vertices to make the animation
			setVertices(m_frameSpecs.x * 0.5f, m_frameSpecs.y * 0.5f,
				((m_frameSpecs.x / m_width) * m_currentAnimation->frames[m_currentAnimation->currentFrame]),
				(m_height / 2.0f));

		}

	}

	bool AnimatedSprite::setVertices(float halfWidth, float halfHeight, float positionX, float positionY)
	{
		//set the vertices
		float percentageX = (halfWidth * 2) / m_width;
		float percentageY = (halfHeight * 2) / m_height;

		VertexPos vertices[] =
		{
			{ LVLfloat3(halfWidth, halfHeight, 1.0f), LVLfloat2(positionX + percentageX, 0.0f) },
			{ LVLfloat3(halfWidth, -halfHeight, 1.0f), LVLfloat2(positionX + percentageX, 1.0f) },
			{ LVLfloat3(-halfWidth, -halfHeight, 1.0f), LVLfloat2(positionX, 1.0f) },

			{ LVLfloat3(-halfWidth, -halfHeight, 1.0f), LVLfloat2(positionX, 1.0f) },
			{ LVLfloat3(-halfWidth, halfHeight, 1.0f), LVLfloat2(positionX, 0.0f) },
			{ LVLfloat3(halfWidth, halfHeight, 1.0f), LVLfloat2(positionX + percentageX, 0.0f) }
		};

		bool result = setVertexBuffer(vertices);
		if (!result)
		{
			return false;
		}
		return true;
	}
}