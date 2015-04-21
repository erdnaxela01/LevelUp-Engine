#include "CountDown.h"

namespace LevelUp
{
    CountDown::CountDown() :m_time(0.0)
    {

    }
    CountDown::~CountDown()
    {

    }
    void CountDown::update(double delta)
    {
        if (m_time > 0.0)
        {
            m_time -= delta;
        }
    }
    void CountDown::start(double startTime)
    {
        m_time = startTime;
    }
    bool CountDown::isItDone()
    {
        if (m_time <= 0.0)
        {
            return true;
        }
        return false;
    }
    void CountDown::stop()
    {
        m_time = 0.0;
    }
    double CountDown::time()
    {
        return m_time;
    }
}