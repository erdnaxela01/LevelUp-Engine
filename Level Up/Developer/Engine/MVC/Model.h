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
        //get the model's ID
		std::string ModelID() const;
        //can it update? you decide
		void setCanUpdate(bool b);
        //must be overriden for the logic of the object
		virtual void update(double delta) = 0;
        //check if it can update
		bool canUpdate() const;

		bool operator==(const Model& rhs)
		{
			if (m_ID == rhs.m_ID)
			{
				return true;
			}
			return false;
		}
	protected:
		virtual void addToMap();
        virtual void removeFromMap();
	private:
		std::string m_ID;
		static int m_numberOfModels;
		bool m_canUpdate;
        std::string m_parentScene;
	};
}

#endif