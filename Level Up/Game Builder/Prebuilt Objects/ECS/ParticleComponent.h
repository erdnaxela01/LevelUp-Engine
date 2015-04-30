#ifndef __PARTICLECOMPONENT_H
#define __PARTICLECOMPONENT_H

#include "../../../Developer/Engine/ECS/Component.h"
#include "../../../Developer/Services/Math/DataTypes.h"
#include "Particle.h"
#include <vector>
#include <string>

namespace LevelUp
{
    const std::string PARTICLE_COMPONENT_TYPE = "ParticleComponentType";

    class ParticleSystem;
	class BaseLevelObject;

    class ParticleComponent : public Component
    {
    public:
        ParticleComponent(unsigned int size = 0, LVLfloat3 color = LVLfloat3(0.25f, 0.75f, 0.30f));
        ~ParticleComponent();
        void activate(double lifespan = 2.0, double frequency = 0.1, float minAngle = 0.0f, float maxAngle = 360.0f, float minSpeed = 10.0f, float maxSpeed = 300.0f);
        void deactivate();
        void setPosition(LVLfloat2 pos);
        std::vector <Particle*> getParticles();
        void trackObject(BaseLevelObject* object);
        void setColor(LVLfloat3 c);
        void setMultipleColors(std::vector<LVLfloat3> colors);

        void setMinSpeed(float min);
        void setMaxSpeed(float max);
        void setMaxAngle(float max);
        void setMinAngle(float min);

        virtual void releaseTracking();
        void setAlpha(float a);

		void setCanFade(bool b);

        bool isTracking();
        bool isPaused();

        double getElapsed();
        void setElapsed(double elapsed);

		BaseLevelObject* getBLO();

        void pause();
        //restart emiting
        void start();
        friend ParticleSystem;
    private:
        float m_minAngle;
        float m_maxAngle;
        float m_minSpeed;
        float m_maxSpeed;
        double m_frequency;
        double m_elapsed;
        double m_lifeSpan;
 
        bool m_tracking;
        bool m_paused;
        std::vector <Particle*> m_particles;

        LVLfloat2 m_position;
		BaseLevelObject* m_trackingObject;

    };
}

#endif