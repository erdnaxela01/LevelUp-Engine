#include "EventHandler.h"
#include "../TheEngine.h"

namespace LevelUp
{
    EventHandler::EventHandler()
    {
        //add the handler to the dispatcher
        TheEngine::getInstance()->addEventHandler(this);
    }
    EventHandler::~EventHandler()
    {
    }
}