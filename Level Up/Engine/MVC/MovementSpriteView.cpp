#include "MovementSpriteView.h"
#include "../../Core/StandardTemplates.h"
#include "MovementModel.h"
#include "../TheEngine.h"
#include <string>

namespace LevelUp
{
	MovementSpriteView::MovementSpriteView(std::wstring fName, MovementModel* mm, float z) : View(z)
	{
		m_sprite = new Sprite;
		m_sprite->initialize(fName);
		m_movementModel = mm;
		if (m_movementModel != nullptr)
		{
			m_movementModel->setHeight(m_sprite->getHeight());
			m_movementModel->setWidth(m_sprite->getWidth());
		}
	}
	void MovementSpriteView::setSprite(std::wstring fName)
	{
		SafeDelete(m_sprite);
		m_sprite = new Sprite;
		m_sprite->initialize(fName);
	}

	MovementSpriteView::~MovementSpriteView()
	{
		SafeDelete(m_sprite);
	}
	void MovementSpriteView::render()

	{
		if (m_movementModel != nullptr)
		{
			m_sprite->rotate(m_movementModel->getAngle());
		}
		m_sprite->render();
	}

	float MovementSpriteView::getX()
	{
		if (m_movementModel != nullptr)
		{
			return m_movementModel->getX();
		}
		return 0.0f;
	}
	float MovementSpriteView::getY()
	{
		if (m_movementModel != nullptr)
		{
			return m_movementModel->getY();
		}
		return 0.0f;
	}
	float MovementSpriteView::getH()
	{
		return m_sprite->getHeight();
	}
	float MovementSpriteView::getW()
	{
		return m_sprite->getWidth();
	}

	void MovementSpriteView::render(float x, float y)
	{
        LVLfloat2 pastPos = m_sprite->getPosition();
		m_sprite->setPosition(x, y);
		render();
		m_sprite->setPosition(pastPos.x, pastPos.y);
	}

	void MovementSpriteView::setScale(float x, float y)
	{
		if (m_movementModel != nullptr)
		{
			m_sprite->setScale(x, y);
		}
	}

	void MovementSpriteView::rotate(float angle)
	{
		if (m_movementModel != nullptr)
		{
			m_sprite->rotate(angle);
		}
	}

	void  MovementSpriteView::setX(float x)
	{
		if (m_movementModel != nullptr)
		{
			m_movementModel->setX(x);
		}
	}
	void  MovementSpriteView::setY(float y)
	{
		if (m_movementModel != nullptr)
		{
			m_movementModel->setY(y);
		}
	}
}