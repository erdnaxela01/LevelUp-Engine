#include "GameObject.h"
#include "../../Graphics/AnimatedSprite.h"
#include "../../Core/StandardTemplates.h"

namespace LevelUp
{
	GameObject::GameObject(std::wstring fName, float widthOfFrame, float heightOfFrame) :Model(), View(), BaseLevelObject()
	{
		m_sprite = (new AnimatedSprite(fName, widthOfFrame, heightOfFrame));
	}
	GameObject::~GameObject()
	{
		if (m_sprite != nullptr)
		{
			delete m_sprite;
			m_sprite = nullptr;
		}
	}

	void GameObject::setSprite(std::wstring fName, float widthOfFrame, float heightOfFrame)
	{
		//get a new sprite
		if (m_sprite != nullptr)
		{
			delete m_sprite;
			m_sprite = nullptr;
		}
		m_sprite = (new AnimatedSprite(fName, widthOfFrame, heightOfFrame));
	}

	void GameObject::update(double delta)
	{

	}
	void GameObject::render()
	{
		m_sprite->render();
	}
	void GameObject::setPosition(float x, float y)
	{
		m_sprite->setPosition(x, y);
	}
	void GameObject::setPosition(LVLfloat2 pos)
	{
		m_sprite->setPosition(pos.x, pos.y);
	}
	LVLfloat2 GameObject::getPosition() const
	{
		return m_sprite->getPosition();
	}
	void GameObject::addAnimation(std::string animationName, std::vector<int> frames, float framesPerSecond, bool looped)
	{
		m_sprite->addAnimation(animationName, frames, framesPerSecond, looped);
	}
	void GameObject::play(std::string animationName, bool looped)
	{
		m_sprite->play(animationName, looped);
	}
	float GameObject::getZ() const
	{
		return View::getZ();
	}
	void GameObject::setZ(float z)
	{
		View::setZ(z);
	}

	float GameObject::getH() const
	{
		return m_sprite->getHeight();
	}
	float GameObject::getW() const
	{
		return m_sprite->getWidth();
	}
	float GameObject::getX() const
	{
		return m_sprite->getPosition().x;
	}
	float GameObject::getY() const
	{
		return m_sprite->getPosition().y;
	}
	void GameObject::setX(float x)
	{
		m_sprite->setPosition(x, m_sprite->getPosition().y);
	}
	void GameObject::setY(float y)
	{
		m_sprite->setPosition(m_sprite->getPosition().x, y);
	}
}