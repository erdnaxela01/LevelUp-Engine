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
            SafeDelete(i);
        }
	}
	std::vector<Component*> Entity::getAllComponentsOfType(std::string s)
	{
		std::vector<Component*> enty;
		for (auto i : m_components)
		{
			if (i->isType(s))
			{
				enty.push_back(i);
			}
			if (i->isECSType(ECSType::ECSTYPE_ENTITY))
			{
				std::vector<Component*> temp;
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
        std::vector<Component*> comp = getAllComponentsOfType(s);
        for (auto i : comp)
        {
            SafeDelete(i);
        }
    }
}