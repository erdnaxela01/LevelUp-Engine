#ifndef __TIMERCONTROLLER_H
#define __TIMERCONTROLLER_H

#include "Controller.h"
#include <string>
namespace LevelUp
{
    //controller that gets activated as time passes
	class TimerController : public Controller
	{
	public:
		TimerController();
		virtual ~TimerController();
		virtual void timeElapsed(double delta) = 0;
		std::string TimerControllerID();

	protected:
		double m_elapsed;
		virtual void addToMap();
        virtual void removeFromMap();
	private:
		static int m_numberOfTimerControllers;
	};
}

#endif