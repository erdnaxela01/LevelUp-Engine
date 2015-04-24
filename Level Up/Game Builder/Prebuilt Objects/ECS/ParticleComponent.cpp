#include "ParticleComponent.h"
#include "Particle.h"
#include "ParticleSystem.h"
#include "../../../Developer/Core/StandardTemplates.h"

namespace LevelUp
{
    ParticleComponent::ParticleComponent(unsigned int size, LVLfloat3 color) : m_frequency(0.1f)
    {
        for (unsigned int i = 0; i < size; i++)
        {
            m_particles.push_back(new Particle(10));
        }
        setColor(color);
        MathHelper::RandomizeSeed();
        m_type = PARTICLE_COMPONENT_TYPE;
    }

    ParticleComponent::~ParticleComponent()
    {
        for (auto i : m_particles)
        {
            SafeDelete(i);
        }
    }

    void ParticleComponent::activate(double lifespan, double frequency, float minAngle, float maxAngle, float minSpeed, float maxSpeed)
    {
        m_lifeSpan = lifespan;
        m_frequency = frequency;
        m_minAngle = minAngle;
        m_maxAngle = maxAngle;
        m_minSpeed = minSpeed;
        m_maxSpeed = maxSpeed;
        setIsActivated(true);
        m_paused = false;
        start();

    }
    void ParticleComponent::deactivate()
    {

    }
    void ParticleComponent::setPosition(LVLfloat2 pos)
    {
        m_position = pos;
    }
    std::vector <Particle*> ParticleComponent::getParticles()
    {
        return m_particles;
    }
    void ParticleComponent::trackObject(GameObject* object)
    {
        m_tracking = true;
        m_trackingObject = object;
    }
    void ParticleComponent::setColor(LVLfloat3 c)
    {
        for (unsigned int i = 0; i < m_particles.size(); i++)
        {
            m_particles[i]->setColor(c);
        }
    }
    void ParticleComponent::setMultipleColors(std::vector<LVLfloat3> colors)
    {
        for (unsigned int i = 0; i < m_particles.size(); i++)
        {
            unsigned int num = MathHelper::RandomNumber(colors.size());

            for (unsigned int i = 0; i < m_particles.size(); i++)
            {
                m_particles[i]->setColor(colors[num]);
            }
        }
    }

    void ParticleComponent::setMinSpeed(float min)
    {
        m_minSpeed = min;
    }
    void ParticleComponent::setMaxSpeed(float max)
    {
        m_maxSpeed = max;
    }
    void ParticleComponent::setMaxAngle(float max)
    {
        m_maxAngle = max;
    }
    void ParticleComponent::setMinAngle(float min)
    {
        m_minAngle = min;
    }


    void ParticleComponent::releaseTracking()
    {
        m_tracking = false;
        m_trackingObject = nullptr;
    }
    void ParticleComponent::setAlpha(float a)
    {
        for (unsigned int i = 0; i < m_particles.size(); i++)
        {
            m_particles[i]->setAlpha(a);
        }
    }

    void ParticleComponent::pause()
    {
        m_paused = true;
    }
    //restart emiting
    void ParticleComponent::start()
    {
        m_paused = false;
    }
    bool ParticleComponent::isTracking()
    {
        return m_tracking;
    }

    bool ParticleComponent::isPaused()
    {
        return m_paused;
    }

    double ParticleComponent::getElapsed()
    {
        return m_elapsed;
    }
    void ParticleComponent::setElapsed(double elapsed)
    {
        m_elapsed = elapsed;
    }

    GameObject* ParticleComponent::getGameObject()
    {
        return m_trackingObject;
    }
}