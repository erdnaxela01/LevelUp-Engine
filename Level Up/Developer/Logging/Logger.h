#ifndef __LVLLOGGER_H
#define __LVLLOGGER_H

#include "../File Streams/OTextFileStream.h"
#include "../../Addons/AutomaticPointers/StrongPointer.h"
#include <deque>
#include <time.h>
#include <string>
#include <ostream>
#include <sstream>

namespace LevelUp
{
	const std::string LOG_PATH = "../Assets/Logs/LogFile ";
	class Logger
	{
	public:
		Logger(std::string fileName = LOG_PATH);
		~Logger();
		template <typename Output>
		void log(Output& obj);

		template<typename Output>
		friend Logger& operator<<(Logger& l, Output obj)
		{
			if (l.m_autoFlush)
			{
				(*l.m_fileStream.getPtr()) << obj << '\n';
			}
			else
			{
				std::stringstream s;
				s << obj;
				l.m_buffer.push_back(s.str());
			}

			return l;
		}

		void setAutoFlush(bool b);
		void flush();
	private:
		APT::StrongPointer<OTextFileStream> m_fileStream;
		bool m_autoFlush;
		std::deque<std::string> m_buffer;
	};


	template<typename Output>
	void Logger::log(Output& obj)
	{
		if (m_autoFlush)
		{
			(*m_fileStream.getPtr()) << obj << '\n';
		}
		else
		{
			std::stringstream s;
			s << obj;
			m_buffer.push_back(s.str());
		}
	}

	extern Logger LOGGER;
}

#endif