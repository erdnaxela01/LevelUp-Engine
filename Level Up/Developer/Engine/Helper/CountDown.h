#ifndef __COUNTDOWN_H
#define __COUNTDOWN_H

namespace LevelUp
{
    /*
    Handy class for countdowns instead of having to make code over and over
    -Alex Sabourin April 2015
    */
    class CountDown
    {
    public:
        CountDown();
        virtual ~CountDown();
        //takes down the time
        void update(double delta);
        //starts the count down
        void start(double startTime);
        //check if it is done
        bool isItDone();
        //stop it and set the time to 0
        void stop();
        //checks the current time
        double getTime();

        double getStartTime();
    private:
        double m_time;
        double m_startTime;
    };
}

#endif