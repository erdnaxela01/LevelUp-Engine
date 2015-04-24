#ifndef __EVENT_HANDLERS_H
#define __EVENT_HANDLERS_H

#include "Events.h"

namespace LevelUp
{
    /*
    Class meant to handle the events sent by the event dispatcher
    -Alex Sabourin April 2015
    */
	class EventHandler
	{
    public:
        EventHandler();
        virtual ~EventHandler();
        //makes sure that the event handler handles the event
        virtual void handleEvent(DispatchEvents e) = 0;
	};
}

#endif