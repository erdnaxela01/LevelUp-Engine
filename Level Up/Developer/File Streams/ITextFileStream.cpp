#include "ITextFileStream.h"
#include <iostream>
#include <istream>
#include <ostream>

namespace LevelUp
{
	ITextFileStream::ITextFileStream(std::string fileName, bool overrideDefaultPath)
	{
		if (overrideDefaultPath)
		{
			m_file.open(fileName);
			if (!m_file.is_open())
			{
				throw (std::runtime_error("Could not open " + fileName + " for writing"));
			}
		}
		else
		{
			m_file.open("../Assets/Files/" + fileName);
			if (!m_file.is_open())
			{
				throw (std::runtime_error("Could not open ../Assets/Files/" + fileName + " for reading"));
			}
		}
		//if the file didnt open throw and exception
	}

	ITextFileStream::~ITextFileStream()
	{
		//close the file
		m_file.close();
	}
	std::string ITextFileStream::getLine(int lineNum)
	{
		m_file.clear();
		//set the getter at the start
		m_file.seekg(0, std::ios::beg);
		//go through all the useless lines
		std::string garbage;
		for (int i = 0; i < lineNum; i++)
		{
			std::getline(m_file, garbage);
		}
		//get the line at the specifiec location
		std::string result;
		std::getline(m_file, result);
		return result;
	}
	std::vector<std::string> ITextFileStream::getFileFrom(int lineNum)
	{
		m_file.clear();
		//start at the begining and go all the way to the starting line
		std::vector<std::string> fileLines;
		m_file.seekg(0, std::ios::beg);
		std::string garbage;
		for (int i = 1; i < lineNum; i++)
		{
			std::getline(m_file, garbage);
		}
		//get lines until the end of the file
		std::string line;
		while (std::getline(m_file, line))
		{
			fileLines.push_back(line);
		}
		return fileLines;
	}
	std::vector<std::string> ITextFileStream::getFileFromTo(int lineStart, int lineEnd)
	{
		m_file.clear();
		//start at the beggining and make your way to the line start
		std::vector<std::string> fileLines;
		m_file.seekg(0, std::ios::beg);
		std::string garbage;
		for (int i = 1; i < lineStart; i++)
		{
			std::getline(m_file, garbage);
		}
		std::string line;
		//get the lines from that point to the last line point
		for (int i = 0; i < lineEnd - lineStart + 1; i++)
		{
			//if the file ended return the lines read
			if (std::getline(m_file, line))
			{
				fileLines.push_back(line);
			}
			else
			{
				break;
			}
		}
		return fileLines;
	}
	std::vector<std::string> ITextFileStream::getFileTo(int lineEnd)
	{
		m_file.clear();
		//go to the start
		std::vector<std::string> fileLines;
		m_file.seekg(0, std::ios::beg);
		std::string line;
		//read lines until the end of the line specified
		for (int i = 0; i < lineEnd; i++)
		{
			//if the end of file is reached break and return the lines read
			if (std::getline(m_file, line))
			{
				fileLines.push_back(line);
			}
			else
			{
				break;
			}
		}
		return fileLines;
	}
}