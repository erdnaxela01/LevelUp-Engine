#ifndef __PARTICLE_H
#define __PARTICLE_H

#include "../../../Developer/Services/Math/DataTypes.h"
#include "../../../Developer/Engine/Helper/CountDown.h"
#include "../../../Developer/Graphics/Rectangle.h"
#include "../../../Developer/Engine/MVC/View.h"

namespace LevelUp
{
    class Particle : public View
    {
    public:
        Particle(float width);
        virtual ~Particle();


        void update(double delta);
        void render();

        void setColor(LVLfloat3 c);
        void setPosition(LVLfloat2 pos);
        //emits the particle
        void emit(float speed, float angle, float lifeSpan, LVLfloat2 pos);

        //chaneg the shape of the particle
        void setAlpha(float a);
        void setFade(bool b);

        bool isActive();
        void activate();
        void deActivate();

        float getX() const;
        //get the y
        float getY() const;
        //get the height
        float getH() const;
        //get the width
        float getW() const;
        void setX(float x);
        //set the y
        void setY(float y);
    private:
        CountDown m_time;
        float m_alpha;
        bool m_canFade;

        float m_angle;
        float m_speed;
        Rectangle* m_rect;
        bool m_isActivated;

    };
}

#endif