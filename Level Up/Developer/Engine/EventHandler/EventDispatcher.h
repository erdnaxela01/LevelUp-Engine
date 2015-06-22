#ifndef __EVENT_DISPATCHER_H
#define __EVENT_DISPACTHER_H

#include <vector>
#include "Events.h"
#include "../../../Addons/AutomaticPointers/AutomaticPointers.h"

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
		void addHandler(APT::WeakPointer<EventHandler> h);
        //tell all handlers about an eventr
		void dispatchEvent(DispatchEvents e);
		//remove an event handler
		void removeHandler(APT::WeakPointer<EventHandler> h);
	private: 
		std::vector<APT::WeakPointer<EventHandler>> m_handlers;
	};
}

#endif