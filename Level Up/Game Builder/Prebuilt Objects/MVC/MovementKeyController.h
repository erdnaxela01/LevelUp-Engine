#ifndef __MOVEMENTKEYCONTROLLER_H
#define __MOVEMENTKEYCONTROLLER_H

#include "../../../Developer/Engine/MVC/KeyController.h"
#include "../../../Developer/Enums/Keys.h"
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
        //handle key down events
        void handleKeyDown(LevelUpKeys key);
        //handle key up events
        void handleKeyUp(LevelUpKeys key);
        //you can change the keys
        void setMovementKeys(LevelUpKeys left = LevelUpKeys::KEY_A, LevelUpKeys down = LevelUpKeys::KEY_S, LevelUpKeys right = LevelUpKeys::KEY_D, LevelUpKeys up = LevelUpKeys::KEY_W);
	private:
		MovementModel* m_model;
        LevelUpKeys m_movementKeys[4];
	};
}

#endif