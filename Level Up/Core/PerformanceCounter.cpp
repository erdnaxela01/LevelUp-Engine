#include <Windows.h>
#include "PerformanceCounter.h"

namespace LevelUp
{
	double PerformanceCounter::m_PCFreq = 0.0;
	__int64 PerformanceCounter::m_counterStart = 0;

	bool PerformanceCounter::startCounter()
	{
        //get a windows specific large integer
		LARGE_INTEGER li;
		if (!QueryPerformanceFrequency(&li))
		{
			MessageBox(0, L"Query Performance Frequency Failed ", L"startCounter Error", MB_OK);
			return false;
		}

        //calculate the frequency and get the initial value
		m_PCFreq = (double)(li.QuadPart) / 1000.0;

		QueryPerformanceCounter(&li);
		m_counterStart = li.QuadPart;
		return true;
	}
	double PerformanceCounter::getCounter()
	{
        //return the current delta based on the frequency
		LARGE_INTEGER li;
		QueryPerformanceCounter(&li);
		return (double)(li.QuadPart - m_counterStart) / m_PCFreq;
	}
}
