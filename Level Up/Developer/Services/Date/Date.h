#ifndef __DATE_H
#define __DATE_H

#include <time.h>
#include <string>

#define CURRENT_MILLENIA 1900

namespace LevelUp
{
	struct DateStamp
	{
		std::string date()
		{
			return std::to_string(year) + '-' + std::to_string(month) + '-' + std::to_string(day);
		}
		unsigned int year;
		unsigned int day;
		unsigned int month;
		unsigned int hour;
		unsigned int minute;
	};

	struct Date
	{
		static DateStamp& getDate();
	};
}

#endif