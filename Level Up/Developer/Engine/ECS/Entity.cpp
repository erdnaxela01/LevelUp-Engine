#include "Entity.h"
#include "ECSTypes.h"
#include "../../Core/StandardTemplates.h"
#include "../../Engine/TheEngine.h"


namespace LevelUp
{
	Entity::Entity()
	{

	}
	Entity::~Entity()
	{
 
	}
	std::vector<APT::WeakPointer<Component>> Entity::getAllComponentsOfType(std::string s)
	{
        //loop through the components
		std::vector<APT::WeakPointer<Component>> enty;
		for (unsigned int i = 0; i < m_components.size(); i++)
		{
			if (m_components[i]->isType(s))
			{
				enty.push_back(m_components[i]);
			}
            //if the component is also an entity look into it too
			if (m_components[i]->isECSType(ECSType::ECSTYPE_ENTITY))
			{
				std::vector<APT::WeakPointer<Component>> temp;
                //kindof recursion, we must go deeper
				temp = ((Entity*)(m_components[i].getPtr()))->getAllComponentsOfType(s);
				for (auto j : temp)
				{
					enty.push_back(j);
				}
			}

		}
		return enty;

	}

	std::vector<APT::StrongPointer<Component>> Entity::getAllComponentsOfTypeStrong(std::string s)
	{
		//loop through the components
		std::vector<APT::StrongPointer<Component>> enty;
		for (unsigned int i = 0; i < m_components.size(); i++)
		{
			if (m_components[i]->isType(s))
			{
				enty.push_back(m_components[i].releasePtr());
			}
			//if the component is also an entity look into it too
			if (m_components[i]->isECSType(ECSType::ECSTYPE_ENTITY))
			{
				std::vector<APT::StrongPointer<Component>> temp;
				//kindof recursion, we must go deeper
				temp = ((Entity*)(m_components[i].getPtr()))->getAllComponentsOfTypeStrong(s);
				for (unsigned int j = 0; j < temp.size(); j++)
				{
					enty.push_back(temp[j].releasePtr());
				}
			}

		}
		return enty;

	}
	bool Entity::isECSType(ECSType t)
	{
		return t == ECSType::ECSTYPE_ENTITY;
	}
	void Entity::addComponent(APT::WeakPointer<Component> c)
    {
        m_components.push_back(c.getPtr());
        getEngine()->getSystems()->addedComponent(this);
    }
    void Entity::removeAllComponentsOfType(std::string s)
    {
        //get all the components
		std::vector<APT::StrongPointer<Component>> comp = getAllComponentsOfTypeStrong(s);

		for (unsigned int i = 0; i < comp.size(); i++)
        {
            //safely delete all the components and remove them from the vector
			m_components.erase(std::find(m_components.begin(), m_components.end(), comp[i]));
        }
        getEngine()->getSystems()->removedComponent(this);
    }
    bool Entity::isActive()
    {
        return m_isActive;
    }
    //set if the entity is active
    void Entity::setIsActive(bool b)
    {
        m_isActive = b;
    }
    bool Entity::hasComponent(std::string s)
    {
        std::vector<APT::WeakPointer<Component>> enty;
		for (unsigned int i = 0; i < m_components.size(); i++)
        {
			if (m_components[i]->isType(s))
            {
                return true;
            }
            //if the component is also an entity look into it too
			if (m_components[i]->isECSType(ECSType::ECSTYPE_ENTITY))
            {
				std::vector<APT::WeakPointer<Component>> temp;
                //kindof recursion, we must go deeper
				if (((Entity*)(m_components[i].getPtr()))->hasComponent(s))
                {
                    return true; 
                }
            }


        }
        return false;
    }
}