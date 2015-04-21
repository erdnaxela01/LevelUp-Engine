#ifndef __MODEL_H
#define __MODEL_H

#include <string>
namespace LevelUp
{
    //used for the logic of an object used for MVC
    //Alex Sabourin April 2015
	class Model
	{
	public:
		Model();
		virtual ~Model();
		std::string ModelID();
        //can it update?
		void setCanUpdate(bool b);
        //must be overriden for the logic of the object
		virtual void update(double delta) = 0;
		bool canUpdate();
	protected:
		virtual void addToMap();
        virtual void removeFromMap();
	private:
		std::string m_ID;
		static int m_numberOfModels;
		bool m_canUpdate;
	};
}

#endif