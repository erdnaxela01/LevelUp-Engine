#include "TextFileStream.h"
#include <iostream>
#include <istream>
#include <ostream>

namespace LevelUp
{
	TextFileStream::TextFileStream(std::string fileName, bool overrideDefaultPath) : ITextFileStream(fileName, overrideDefaultPath), OTextFileStream(fileName, overrideDefaultPath)
	{
	}

	TextFileStream::~TextFileStream()
	{
	}
	
}