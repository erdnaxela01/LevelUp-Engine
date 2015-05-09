#include "EventDispatcher.h"
#include "EventHandler.h"
#include <algorithm>

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

	void EventDispatcher::removeHandler(EventHandler* h)
	{
		m_handlers.erase(std::find(m_handlers.begin(), m_handlers.end(), h));
	}
    void EventDispatcher::dispatchEvent(DispatchEvents e)
    {
        for (auto i : m_handlers)
        {
            //send a notification to all your handlers
            dynamic_cast<EventHandler*>(i)->handleEvent(e);
        }
    }
}