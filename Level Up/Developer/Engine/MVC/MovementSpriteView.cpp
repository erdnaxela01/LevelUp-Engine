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
        //initialize the sprite
		m_sprite->initialize(fName);
		m_movementModel = mm;
		if (m_movementModel != nullptr)
		{
            //set the width and height if a model was passed
			m_movementModel->setHeight(m_sprite->getHeight());
			m_movementModel->setWidth(m_sprite->getWidth());
		}
	}
	void MovementSpriteView::setSprite(std::wstring fName)
	{
        //get a new sprite
		SafeDelete(m_sprite);
		m_sprite = new Sprite;
		m_sprite->initialize(fName);
	}

	MovementSpriteView::~MovementSpriteView()
	{
        //delete the sprite
		SafeDelete(m_sprite);
	}
	void MovementSpriteView::render()
	{
        //render the sprite
		if (m_movementModel != nullptr)
		{
            //if there is a model rotate the sprite according to the angle
			m_sprite->rotate(m_movementModel->getAngle());
            //m_sprite->setPosition(m_movementModel->getX(), m_movementModel->getY());
		}
        //render the sprite
		m_sprite->render();
	}

	float MovementSpriteView::getX()
	{
        //if thre is a movement model then get that x if not get the sprites x
		if (m_movementModel != nullptr)
		{
			return m_movementModel->getX();
		}
		return m_sprite->getPosition().x;
	}
	float MovementSpriteView::getY()
	{
        //if thre is a movement model then get that y if not get the sprites y
		if (m_movementModel != nullptr)
		{
			return m_movementModel->getY();
		}
        return m_sprite->getPosition().y;
	}
	float MovementSpriteView::getH()
	{
        //get the sprites height
		return m_sprite->getHeight();
	}
	float MovementSpriteView::getW()
	{
        //get the sprites width
		return m_sprite->getWidth();
	}

	void MovementSpriteView::render(float x, float y)
	{
        //render the sprite at a specific positions
        LVLfloat2 pastPos = m_sprite->getPosition();
		m_sprite->setPosition(x, y);
		render();
		m_sprite->setPosition(pastPos.x, pastPos.y);
	}

	void MovementSpriteView::setScale(float x, float y)
	{
		m_sprite->setScale(x, y);
	}

	void MovementSpriteView::rotate(float angle)
	{
		m_sprite->rotate(angle);
	}

	void  MovementSpriteView::setX(float x)
	{
        //set the x if there is ammovement model set that x
		if (m_movementModel != nullptr)
		{
			m_movementModel->setX(x);
		}
        m_sprite->setPosition(x, m_sprite->getPosition().y);
	}
	void  MovementSpriteView::setY(float y)
	{
        //set the y if there is ammovement model set that y
		if (m_movementModel != nullptr)
		{
			m_movementModel->setY(y);
		}
        m_sprite->setPosition(m_sprite->getPosition().x, y);

	}
}