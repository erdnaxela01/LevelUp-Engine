#include "EventDispatcher.h"
#include "EventHandler.h"

namespace LevelUp
{
    EventDispatcher::EventDispatcher()
    {
        m_handlers = {};
    }
    EventDispatcher::~EventDispatcher()
    {

    }

    void EventDispatcher::addHandler(EventHandler* h)
    {
        //add a handler
        m_handlers.push_back(h);
    }
    void EventDispatcher::dispatchEvent(DispatchEvents e)
    {
        for (auto i : m_handlers)
        {
            //send a notification to all your handlers
            i->handleEvent(e);
        }
    }
}