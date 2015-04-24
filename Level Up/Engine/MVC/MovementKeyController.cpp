#include "MovementKeyController.h"
#include "MovementModel.h"
#include "MovementSpriteView.h"
namespace LevelUp
{
	MovementKeyController::MovementKeyController(MovementModel* m)
	{
		m_model = m;
        //set the initial movement keys to WASD
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
        //check the movement keys and do what they ask
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
        //if a key is unpressed do something
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
        //set the movement keys
		m_movementKeys[0] = left;
		m_movementKeys[1] = down;
		m_movementKeys[2] = right;
		m_movementKeys[3] = up;
	}
}