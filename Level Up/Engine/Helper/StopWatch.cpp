#include "StopWatch.h"

namespace LevelUp
{
    StopWatch::StopWatch() : m_currentTime(0.0)
    {

    }
    StopWatch::~StopWatch()
    {

    }
    void StopWatch::update(double delta)
    {
        if (m_isPaused)
        {
            return;
        }
        m_currentTime += delta;
    }
    double StopWatch::getTime()
    {
        return m_currentTime;
    }
    void StopWatch::start()
    {
        m_isPaused = false;
    }
    void StopWatch::pause()
    {
        m_isPaused = true;
    }
    double StopWatch::stop()
    {
        double time = m_currentTime;
        m_isPaused = false;
        m_currentTime = 0.0;
        return time;
    }
}