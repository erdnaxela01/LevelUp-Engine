#include "Logger.h"
#include "../Services/Date/Date.h"

namespace LevelUp
{

	Logger LOGGER;

	Logger::Logger(std::string fileName) :m_autoFlush(true)
	{
		DateStamp d = Date::getDate();
		m_fileStream.setPtr(new OTextFileStream(fileName + d.date() + ".log", true));
		std::string s;
		s = "LEVEL UP ENGINE LOG START\n";
		s += "Date: " + d.date() + '\n';
		s += "Start Time: " + std::to_string(d.hour) + ":" + std::to_string(d.minute) + '\n';
		s += "--------------------------------------------";
		log(s);
	}
	Logger::~Logger()
	{
		std::string s;
		s = "--------------------------------------------\n";
		s += "LOG END\n";
		log(s);
		flush();
	}
	void Logger::setAutoFlush(bool b)
	{
		m_autoFlush = b;
	}
	void Logger::flush()
	{
		for (unsigned int i = 0; i < m_buffer.size(); i++)
		{
			(*m_fileStream.getPtr()) << m_buffer.back();
			m_buffer.pop_back();
		}
	}
}