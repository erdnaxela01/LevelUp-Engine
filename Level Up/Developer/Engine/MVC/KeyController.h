#ifndef __KEYCONTROLLER_H
#define __KEYCONTROLLER_H

#include "Controller.h"
#include "../../Enums/Keys.h"
#include <string>
namespace LevelUp
{
    //controller that is controlled by key downs and ups
    //Alex Sabourin April 2015
	class KeyController : public Controller
	{
	public:
		KeyController();
		virtual ~KeyController();
        //must be overriden, is used for kjey downs
        virtual void handleKeyDown(LevelUpKeys key) = 0;
        //must be overidden is used for key ups
        virtual void handleKeyUp(LevelUpKeys key) = 0;

		//must be overriden for stuff just pressed
		virtual void justPressed(LevelUpKeys key) = 0;
        //get the controllers id
		std::string keyControllerID() const;
	protected:
        //add it to the map of controllers
		virtual void addToMap();
        //remove it from the map of controllers
        virtual void removeFromMap();
	private:
		static int m_numberOfKeyControllers;
	};
}

#endif