#ifndef __MOVEMENTKEYCONTROLLER_H
#define __MOVEMENTKEYCONTROLLER_H

#include "KeyController.h"
namespace LevelUp
{
	class MovementModel;
    //pre built class for spaceship like movement where side movement is the angle rotation and front and back move
    //Alex Sabourin April 2015
	class MovementKeyController : public KeyController
	{
	public:
		MovementKeyController(MovementModel* m);
		virtual ~MovementKeyController();
		void handleKeyDown(unsigned int key);
		void handleKeyUp(unsigned int key);
        //you can change the keys
		void setMovementKeys(unsigned int left = 'A', unsigned int down = 'S', unsigned int right = 'D', unsigned int up = 'W');
	private:
		MovementModel* m_model;
		unsigned int m_movementKeys[4];
	};
}

#endif