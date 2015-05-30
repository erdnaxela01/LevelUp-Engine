#ifndef __PARTICLESYSTEM_H
#define __PARTICLESYSTEM_H

#include "../../../Developer/Engine/ECS/System.h"
#include "../../../Developer/Engine/MVC/Model.h"
#include "../../../Developer/Engine/MVC/View.h"

namespace LevelUp
{
    class ParticleComponent;
    class ParticleSystem : public System, public Model
    {
    public:
        ParticleSystem() {};

		virtual ~ParticleSystem();
        //notify the system that someone has a new component check if he wants it
        void notifyHasNewComponent(Entity* e);
        //notify the system that someone lost a component, he decides what to do with that
        void notifyHasLostComponent(Entity* e);

        void update(double delta);

        void updateComponent(double delta, ParticleComponent* e);
    private:


    };
}

#endif