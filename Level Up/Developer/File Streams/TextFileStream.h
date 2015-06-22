#ifndef __TEXTFILESTREAM_H
#define __TEXTFILESTREAM_H

#include "OTextFileStream.h"
#include "ITextFileStream.h"
#include <string>
#include <vector>

namespace LevelUp
{
	/*
	Helper class to read/write to a text file
	Alex Sabourin May 2015
	*/
	class TextFileStream : public OTextFileStream, public ITextFileStream
	{
	public:
		//opens a text file for i/o
		TextFileStream(std::string fileName, bool overrideDefaultPath = false);
		//closes the text file
		virtual ~TextFileStream();
	};
}

#endif