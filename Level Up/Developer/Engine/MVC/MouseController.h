#ifndef __MOUSECONTROLLER_H
#define __MOUSECONTROLLER_H

#include "Controller.h"
#include "../../Services/Math/LevelUpMath.h"
#include <DirectXMath.h>
#include <string>

namespace LevelUp
{
    //controller that follows mouse movement
    //Alex Sabourin April 2015
	class MouseController : public Controller
	{
	public:
		MouseController();
		~MouseController();
        
        //pass the mouse parameters as it moves
		virtual void mouseMove(LVLfloat2 pos) = 0;
        //get the controller's id
		std::string mouseControllerID();
	protected:
		virtual void addToMap();
        virtual void removeFromMap();
	private:
		static int m_numberOfMouseControllers;
	};
}

#endif