#include "Date.h"

namespace LevelUp
{
	DateStamp& Date::getDate()
	{
		time_t t = time(0);
		tm* now = new tm();
		localtime_s(now, &t);
		DateStamp date;
		date.day = now->tm_mday;
		date.year = now->tm_year + CURRENT_MILLENIA;
		date.month = now->tm_mon + 1;
		date.hour = now->tm_hour;
		date.minute = now->tm_min;

		return date;
	}
}
