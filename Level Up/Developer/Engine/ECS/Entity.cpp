#include "Entity.h"
#include "ECSTypes.h"
#include "../../Core/StandardTemplates.h"


namespace LevelUp
{
	Entity::Entity()
	{

	}
	Entity::~Entity()
	{
        for (auto i : m_components)
        {
            //safely delete all the components
            SafeDelete(i);
        }
	}
	std::vector<Component*> Entity::getAllComponentsOfType(std::string s)
	{
        //loop through the components
		std::vector<Component*> enty;
		for (auto i : m_components)
		{
			if (i->isType(s))
			{
				enty.push_back(i);
			}
            //if the component is also an entity look into it too
			if (i->isECSType(ECSType::ECSTYPE_ENTITY))
			{
				std::vector<Component*> temp;
                //kindof recursion, we must go deeper
				temp = getAllComponentsOfType(s);
				for (auto j : temp)
				{
					enty.push_back(j);
				}
			}

		}
		return enty;

	}
	bool Entity::isECSType(ECSType t)
	{
		return t == ECSType::ECSTYPE_ENTITY;
	}
    void Entity::addComponent(Component* c)
    {
        m_components.push_back(c);
    }
    void Entity::removeAllComponentsOfType(std::string s)
    {
        //get all the components
        std::vector<Component*> comp = getAllComponentsOfType(s);

        for (auto i : comp)
        {
            //safely delete all the components and remove them from the vector
            m_components.erase(std::find(m_components.begin(), m_components.end(), i));
            SafeDelete(i);
        }
    }
}