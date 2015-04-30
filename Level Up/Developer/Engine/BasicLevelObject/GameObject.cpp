#include "GameObject.h"
#include "../../Graphics/Sprite.h"
#include "../../Core/StandardTemplates.h"

namespace LevelUp
{
	GameObject::GameObject(std::wstring fName)
	{
		m_sprite->initialize(fName);
	}
	GameObject::~GameObject()
	{
		SafeDelete(m_sprite);
	}

	void GameObject::setSprite(std::wstring fName)
	{
		//get a new sprite
		SafeDelete(m_sprite);
		m_sprite = new Sprite;
		m_sprite->initialize(fName);
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
	LVLfloat2 GameObject::getPosition()
	{
		return m_sprite->getPosition();
	}

	void GameObject::render(float x, float y)
	{
		LVLfloat2 pastPos = m_sprite->getPosition();
		m_sprite->setPosition(x, y);
		render();
		m_sprite->setPosition(pastPos.x, pastPos.y);
	}
}