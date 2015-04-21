#ifndef __STOPWATCH_H
#define __STOPWATCH_H

#include "../MVC/MVC.h"

namespace LevelUp
{
    //handy function to have a stopwatch to time something
    //Alex Sabourin April 2015
    class StopWatch : public Model
    {
    public:
        StopWatch();
        virtual ~StopWatch();
        //increment the sopwatch
        void update(double delta);
        //get the current stopwatch time
        double getTime();
        void start();
        //pauses the stop watch
        void pause();
        //returns the time as it stopped
        double stop();
    private:
        double m_currentTime;
        bool m_isPaused;
    };
}

#endif