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
        //if its paused dont do anything
        if (m_isPaused)
        {
            return;
        }
        //add time to the stopwatch
        m_currentTime += delta;
    }
    double StopWatch::getTime()
    {
        //get the current time
        return m_currentTime;
    }
    void StopWatch::start()
    {
        //start it if it isnt paused
        m_currentTime = 0.0;
        m_isPaused = false;
    }
    void StopWatch::pause()
    {
        m_isPaused = true;
    }

    void StopWatch::unPause()
    {
        m_isPaused = false;
    }
    double StopWatch::stop()
    {
        //get the current time
        double time = m_currentTime;
        //pause it
        m_isPaused = true;
        //reset the current time
        m_currentTime = 0.0;
        //return the time
        return time;
    }
}