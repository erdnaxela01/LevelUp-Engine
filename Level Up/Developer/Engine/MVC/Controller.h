#ifndef __CONTROLLER_H
#define __CONTROLLER_H

#include <string>

namespace LevelUp
{
	enum controllerType
	{
		KEYCONTROLLER,
		TIMERCONTROLLER,
		MOUSECONTROLLER
	};
    //class to control the model and the view used as a main part of MVC
    //Alex Sabourin April 2015
	class Controller
	{
	public:
		Controller();
		virtual ~Controller();
		//gets the controller's ID
		//use classType:: to remove ambiguouty
		virtual std::string ControllerID();
		//stops the controller from updating
		//use classType:: to remove ambiguouty
		virtual void stopControl();
		//use classType:: to remove ambiguouty
		//restarts the controller if stoped
		virtual void startControl();

		//use classType:: to remove ambiguouty
		virtual bool canControl();

        //get what kind of controller it is
		virtual controllerType getType();

        //add it to the map of controllers
		virtual void addToMap() = 0;
        virtual void removeFromMap() = 0;

	protected:
		std::string m_ID;
		bool m_canControl;
		controllerType m_type;
        std::string m_parentScene;
	};
}

#endif