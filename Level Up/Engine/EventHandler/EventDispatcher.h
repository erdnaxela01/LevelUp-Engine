#ifndef __EVENT_DISPATCHER_H
#define __EVENT_DISPACTHER_H

#include <vector>
#include "Events.h"

namespace LevelUp
{

	class EventHandler;

    /*
    Handy function to dispatch events to multiple people at once in case of noteworthy events
    -Alex Sabourin April 2015
    */
	class EventDispatcher
	{
	public:
        EventDispatcher();
        virtual ~EventDispatcher();
        //add an event handler
		void addHandler(EventHandler* h);
        //tell all handlers about an eventr
		void dispatchEvent(DispatchEvents e);
	private: 
		std::vector<EventHandler*> m_handlers;
	};
}

#endif