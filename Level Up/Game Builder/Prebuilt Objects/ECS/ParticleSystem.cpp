#include "ParticleSystem.h"
#include "../../../Developer/Engine/ECS/Entity.h"
#include "ParticleComponent.h"
#include "../../../Developer/Engine/BasicLevelObject/BaseLevelObject.h"

namespace LevelUp
{
	ParticleSystem::~ParticleSystem()
	{
	}
    //notify the system that someone has a new component check if he wants it
    void ParticleSystem::notifyHasNewComponent(Entity* e)
    {
        if (e->hasComponent(PARTICLE_COMPONENT_TYPE))
        {
            addEntity(e);
        }
    }
    //notify the system that someone lost a component, he decides what to do with that
    void ParticleSystem::notifyHasLostComponent(Entity* e)
    {
        for (auto i:m_entities)
        {
            if (i == e)
            {
                if (!e->hasComponent(PARTICLE_COMPONENT_TYPE))
                {
                    removeEntity(e);
                }
            }
        }
    }

    void ParticleSystem::update(double delta)
    {
        std::vector<ParticleComponent*> temp;
        for (auto i : m_entities)
        {
            std::vector<Component*> temp2 = i->getAllComponentsOfType(PARTICLE_COMPONENT_TYPE);
            for (auto j : temp2)
            {
                temp.push_back(dynamic_cast<ParticleComponent*>(j));
            }

        }

        for (auto i : temp)
        {
            updateComponent(delta, i);
        }
    }
    void ParticleSystem::updateComponent(double delta, ParticleComponent* e)
    {
        if (e->m_paused)
        {
            return;
        }
        if (e->m_tracking)
        {
            e->setPosition(e->m_trackingObject->getPosition());
        }
        if (e->m_paused == false)
        {
            e->m_elapsed += delta;

            if (e->m_elapsed > e->m_frequency && e->m_frequency != 0.0)
            {
                for (unsigned int i = 0; i < e->m_particles.size(); i++)
                {
                    if (e->m_particles[i]->isActive() == false)
                    {
                        //get a random angle between set paramteters
                        float randomAngle = MathHelper::RandomRange(e->m_minAngle, e->m_maxAngle);
                        float randomSpeed = MathHelper::RandomRange(e->m_minSpeed, e->m_maxSpeed);
                        //emit the particles and reset the elapsed
                        e->m_particles[i]->emit(randomSpeed, randomAngle, e->m_lifeSpan, e->m_position);
                        e->m_elapsed = 0.0;
                        break;
                    }
                }
            }
        }
		for (unsigned int i = 0; i < e->m_particles.size(); i++)
		{
			e->m_particles[i]->update(delta);
		}
    }
}