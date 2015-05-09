#include "TextFileStream.h"
#include <iostream>
#include <istream>
#include <ostream>

namespace LevelUp
{
	TextFileStream::TextFileStream(std::string fileName) : ITextFileStream(fileName), OTextFileStream(fileName)
	{
	}

	TextFileStream::~TextFileStream()
	{
	}
	
}