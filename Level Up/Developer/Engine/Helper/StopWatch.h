#ifndef __STOPWATCH_H
#define __STOPWATCH_H

#include "../MVC/Model.h"

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
        virtual double getTime() const;
        //starts the watch from scratch
        void start();
        //pauses the stop watch
        void pause();
        //unpauses the watch
        void unPause();
        //returns the time as it stopped
        double stop();
    private:
        double m_currentTime;
        bool m_isPaused;
    };
}

#endif