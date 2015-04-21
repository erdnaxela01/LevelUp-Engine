#include "MovementKeyController.h"
#include "MovementModel.h"
#include "MovementSpriteView.h"
namespace LevelUp
{
	MovementKeyController::MovementKeyController(MovementModel* m)
	{
		m_model = m;
		m_movementKeys[0] = 'A';
		m_movementKeys[1] = 'S';
		m_movementKeys[2] = 'D';
		m_movementKeys[3] = 'W';

	}
	MovementKeyController::~MovementKeyController()
	{

	}
	void MovementKeyController::handleKeyDown(unsigned int key)
	{
		if (key == m_movementKeys[0])
		{
			m_model->setIsRotatingLeft(true);
		}
		else if (key == m_movementKeys[2])
		{
			m_model->setIsRotatingRight(true);
		}
		if (key == m_movementKeys[1])
		{
			m_model->setCanMoveBack(true);
		}
		else if (key == m_movementKeys[3])
		{
			m_model->setCanMoveForward(true);
		}
	}
	void MovementKeyController::handleKeyUp(unsigned int key)
	{
		if (key == m_movementKeys[0])
		{
			m_model->setIsRotatingLeft(false);
		}
		else if (key == m_movementKeys[2])
		{
			m_model->setIsRotatingRight(false);
		}
		if (key == m_movementKeys[1])
		{
			m_model->setCanMoveBack(false);
		}
		else if (key == m_movementKeys[3])
		{
			m_model->setCanMoveForward(false);
		}
	}

	void  MovementKeyController::setMovementKeys(unsigned int left, unsigned int down, unsigned int right, unsigned int up)
	{
		m_movementKeys[0] = left;
		m_movementKeys[1] = down;
		m_movementKeys[2] = right;
		m_movementKeys[3] = up;
	}
}