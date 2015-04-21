#include "EventHandler.h"
#include "../TheEngine.h"

namespace LevelUp
{
    EventHandler::EventHandler()
    {
        TheEngine::getInstance()->addEventHandler(this);
    }
    EventHandler::~EventHandler()
    {
    }
}