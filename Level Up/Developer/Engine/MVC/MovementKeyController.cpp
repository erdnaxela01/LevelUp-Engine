#include "MovementKeyController.h"
#include "MovementModel.h"
#include "MovementSpriteView.h"
namespace LevelUp
{
	MovementKeyController::MovementKeyController(MovementModel* m)
	{
		m_model = m;
        //set the initial movement keys to WASD
        m_movementKeys[0] = LevelUpKeys::KEY_A;
        m_movementKeys[1] = LevelUpKeys::KEY_S;
        m_movementKeys[2] = LevelUpKeys::KEY_D;
        m_movementKeys[3] = LevelUpKeys::KEY_W;

	}
	MovementKeyController::~MovementKeyController()
	{

	}
    void MovementKeyController::handleKeyDown(LevelUpKeys key)
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
    void MovementKeyController::handleKeyUp(LevelUpKeys key)
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

    void  MovementKeyController::setMovementKeys(LevelUpKeys left, LevelUpKeys down, LevelUpKeys right, LevelUpKeys up)
	{
        //set the movement keys
		m_movementKeys[0] = left;
		m_movementKeys[1] = down;
		m_movementKeys[2] = right;
		m_movementKeys[3] = up;
	}
}