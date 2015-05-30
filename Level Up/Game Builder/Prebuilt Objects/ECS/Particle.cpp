#include"Particle.h"
#include"../../../Developer/Core/StandardTemplates.h"
#include "../../../Developer/Services/Math/MathFunctions.h"

namespace LevelUp
{
    Particle::Particle(float width) : m_canFade(true), m_isActivated(false)
    {
        deActivate();
        m_alpha = 1.0f;
        m_rect = new Rectangle(LVLfloat4(0.25f, 0.25f, 0.25f, 1.0f), width, width);
        m_rect->setPosition(-100.0f, -100.0f);
       
        
    }
    Particle::~Particle()
    {
        //delete the shape
		if (m_rect != nullptr)
		{
			delete m_rect;
			m_rect = nullptr;
		}

    }
    bool Particle::isActive()
    {
        return m_isActivated;
    }
    void Particle::activate()
    {
        m_isActivated = true;
    }
    void Particle::deActivate()
    {
        m_isActivated = false; 
    }

    void Particle::update(double delta)
    {
        if (!m_isActivated)
        {
            m_time.stop();
			return;
        }
        LVLfloat2 velo = MathHelper::CalculateVelocity(m_angle, m_speed);
        //MathHelper::Translate(rect, velo, delta);
        LVLfloat2 position = m_rect->getPosition();
        position += LVLfloat2(velo.x * delta, velo.y * delta);
        m_rect->setPosition(position.x, position.y);

        if (m_time.isItDone())
        {
            deActivate();
            m_time.stop();
            return;
        }

        if (m_canFade)
        {
            m_alpha = (float)(m_time.getTime() / m_time.getStartTime());
            m_rect->setAlpha(m_alpha);
        }

    }
    void Particle::render()
    {
        if (m_isActivated)
        {
            m_rect->render();
        }
    }

    void Particle::setColor(LVLfloat3 c)
    {
        m_rect->setColor(c);
    }
    void Particle::setPosition(LVLfloat2 pos)
    {
        m_rect->setPosition(pos.x , pos.y);
    }
    //emits the particle
    void Particle::emit(float speed, float angle, float lifeSpan, LVLfloat2 pos)
    {
        m_time.start(lifeSpan);
        m_isActivated = true;
        m_speed = speed;
        m_angle = angle;
        m_rect->rotate(angle);
        m_rect->setPosition(pos.x, pos.y);
        m_alpha = 1.0f;
    }

    //chaneg the shape of the particle
    void Particle::setAlpha(float a)
    {
        m_rect->setAlpha(a);
    }
    void Particle::setFade(bool b)
    {
        m_canFade = b;
    }
    float Particle::getX() const
    {
        return m_rect->getPosition().x;
    }
    //get the y
    float Particle::getY() const
    {
        return m_rect->getPosition().y;
    }
    //get the height
    float Particle::getH() const
    {

        return m_rect->getHeight();
    }
    //get the width
    float Particle::getW() const
    {
        return m_rect->getWidth();

    }
    void Particle::setX(float x)
    {
        m_rect->setPosition(x, m_rect->getPosition().y);
    }
    //set the y
    void Particle::setY(float y)
    {
        m_rect->setPosition(m_rect->getPosition().x , y);
    }

}