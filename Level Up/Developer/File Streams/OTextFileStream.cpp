#include "OTextFileStream.h"
#include <iostream>
#include <istream>
#include <ostream>

namespace LevelUp
{
	OTextFileStream::OTextFileStream(std::string fileName)
	{
		m_file.open("../Assets/Files/" + fileName, std::ios_base::app);
		//if the file didnt open throw and exception
		if (!m_file.is_open())
		{
			throw (std::runtime_error("Could not open file for read/writing"));
		}
	}

	OTextFileStream::~OTextFileStream()
	{
		//close the file
		m_file.close();
	}

	void OTextFileStream::addTextToWrite(std::string text)
	{
		//add text to the buffer
		m_textBuffer.push_back(text);
	}
	void OTextFileStream::addTextToWrite(std::vector<std::string> allText)
	{
		//push back all the text
		for (auto i : allText)
		{
			m_textBuffer.push_back(i);
		}
	}
	void OTextFileStream::writeToFile()
	{
		//write the buffer to the file
		for (auto i : m_textBuffer)
		{
			m_file << i;
		}
	}
	void OTextFileStream::writeToFile(std::string text)
	{
		//write a line to the file
		m_file << text;
	}
}