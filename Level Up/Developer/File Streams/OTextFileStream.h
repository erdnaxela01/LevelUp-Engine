#ifndef __OTEXTFILESTREAM_H
#define __OTEXTFILESTREAM_H
#include <string>
#include <vector>
#include <fstream>
namespace LevelUp
{
	class OTextFileStream
	{
	public:
		//opens a text file for i/o
		OTextFileStream(std::string fileName);
		//closes the text file
		virtual ~OTextFileStream();
		//put text into the buffer
		void addTextToWrite(std::string text);
		//put text into the buffer
		void addTextToWrite(std::vector<std::string> allText);
		//write the buffer to the file
		void writeToFile();
		//write text to the file
		void writeToFile(std::string text);
		//get a specific line
	private:
		std::ofstream m_file;
		std::vector<std::string> m_textBuffer;

	};
}

#endif