#ifndef __EVENT_HANDLERS_H
#define __EVENT_HANDLERS_H

#include "Events.h"

namespace LevelUp
{
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