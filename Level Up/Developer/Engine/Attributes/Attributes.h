#ifndef __ATTRIBUTES_H
#define __ATTRIBUTES_H

#include <string>

namespace LevelUp
{
	class BaseLevelObject;


	/*
	Attributes are like components however they are not acted on by a system and they are rather more freeflowing and can be checked at any time
	Attributes may also do things unlike components
	-Alex Sabourin April 2015
	
	*/
	class Attribute
	{
	public:
		Attribute();
		virtual ~Attribute();

		//check the type of the attribute
		bool isType(std::string t);
		//get the parent of the attribute
		BaseLevelObject* getParent() const;

		bool hasID(std::string ID);

		//base level object is friend to access setParent and removeParent
		friend BaseLevelObject;
	protected:
		BaseLevelObject* m_parent;
		std::string m_type;
	private:
		static int m_numberOfAttributes;
		std::string m_ID;

		//only base level objects should be able to add themselves to an attribute
		void setParent(BaseLevelObject* blo);

		//removes the parent, only base level objects can do this
		void resetParent();

	};

}

#endif