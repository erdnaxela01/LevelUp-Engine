#include "CountDown.h"

namespace LevelUp
{
    CountDown::CountDown() :m_time(0.0), m_startTime(0.0)
    {

    }
    CountDown::~CountDown()
    {

    }
    void CountDown::update(double delta)
    {
        //if the time is over 0.0 countdown
        if (m_time > 0.0)
        {
            m_time -= delta;
        }
    }
    void CountDown::start(double startTime)
    {
        //start the countdown

        m_time = startTime;
        m_startTime = startTime;
    }
    bool CountDown::isItDone()
    {
        //if the time is under or equal to 0.0 the countdown is done
        if (m_time <= 0.0)
        {
            return true;
        }
        return false;
    }
    void CountDown::stop()
    {
        //stop the countdown
        m_time = 0.0;
    }
    double CountDown::getTime()
    {
        return m_time;
    }
    double CountDown::getStartTime()
    {
        return m_startTime;
    }
}