#include "EventHandler.h"
#include "../TheEngine.h"

namespace LevelUp
{
    EventHandler::EventHandler()
    {
        //add the handler to the dispatcher
        getEngine()->addEventHandler(this);
    }
    EventHandler::~EventHandler()
    {
		getEngine()->removeEventHandler(this);
    }
}