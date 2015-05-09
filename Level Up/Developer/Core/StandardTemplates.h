#ifndef __STANDARD_TEMPLATES_H
#define __STANDARD_TEMPLATES_H

//safely delete raw pointers
namespace LevelUp
{
	template<typename T>
	void SafeDelete(T*& t)
	{
		if (t != nullptr)
		{
			delete t;
			t = nullptr;
		}
	}
}

#endif