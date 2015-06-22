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
	void ParticleSystem::notifyHasNewComponent(APT::WeakPointer<Entity> e)
    {
        if (e->hasComponent(PARTICLE_COMPONENT_TYPE))
        {
            addEntity(e);
        }
    }
    //notify the system that someone lost a component, he decides what to do with that
	void ParticleSystem::notifyHasLostComponent(APT::WeakPointer<Entity> e)
    {
        for (auto i:m_entities)
        {
            if (i.getPtr() == e.getPtr())
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
        std::vector<APT::WeakPointer<ParticleComponent>> temp;
        for (auto i : m_entities)
        {
            std::vector<APT::WeakPointer<Component>> temp2 = i->getAllComponentsOfType(PARTICLE_COMPONENT_TYPE);
            for (auto j : temp2)
            {
                temp.push_back(dynamic_cast<ParticleComponent*>(j.getPtr()));
            }

        }

        for (auto i : temp)
        {
            updateComponent(delta, i);
        }
    }
	void ParticleSystem::updateComponent(double delta, APT::WeakPointer<ParticleComponent> e)
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
				unsigned int numOfParticles = 1;
				numOfParticles = std::ceil(e->m_elapsed / e->m_frequency);
                for (unsigned int i = 0; i < e->m_particles.size(); i++)
                {
                    if (e->m_particles[i]->isActive() == false)
                    {
                        //get a random angle between set paramteters
						float randomAngle = static_cast<unsigned int>(MathHelper::RandomRange(static_cast<unsigned int>(e->m_minAngle), static_cast<unsigned int>(e->m_maxAngle)));
						float randomSpeed = static_cast<unsigned int>(MathHelper::RandomRange(static_cast<unsigned int>(e->m_minSpeed), static_cast<unsigned int>(e->m_maxSpeed)));
                        //emit the particles and reset the elapsed
                        e->m_particles[i]->emit(randomSpeed, randomAngle, static_cast<float>(e->m_lifeSpan), e->m_position);
                        e->m_elapsed = 0.0;
						if (--numOfParticles == 0)
						{
							break;
						}
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