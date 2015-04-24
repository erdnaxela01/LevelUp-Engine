#ifndef __PERFORMACECOUNTER_H
#define __PERFORMACECOUNTER_H

namespace LevelUp
{
    /*
    class used in order to count the time between frames
    -Alex Sabourin April 2015
    
    */
	class PerformanceCounter
	{
	public:
		//start the performance counter
		static bool startCounter();
		//get the tick count
		static double getCounter();

	private:
		static double m_PCFreq;
		static __int64 m_counterStart;
	};
}

#endif