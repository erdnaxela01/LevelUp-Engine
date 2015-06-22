#ifndef __ITEXTFILESTREAM_H
#define __ITEXTFILESTREAM_H

#include <string>
#include <vector>
#include <fstream>

namespace LevelUp
{
	class ITextFileStream
	{
	public:
		//opens a text file for i/o
		ITextFileStream(std::string fileName, bool overrideDefaultPath = false);
		//closes the text file
		virtual ~ITextFileStream();
		std::string getLine(int lineNum);
		//read the file from a line number
		std::vector<std::string> getFileFrom(int lineNum);
		//read the file from a line to a line
		std::vector<std::string> getFileFromTo(int lineStart, int lineEnd);
		//read to a line from the start
		std::vector<std::string> getFileTo(int lineEnd);

		template<typename T>
		friend ITextFileStream& operator>> (ITextFileStream& i, T obj)
		{
			i.m_file << obj;
		}
	private:
		std::ifstream m_file;

	};
}

#endif