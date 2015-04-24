
#include "GameObject.h"
#include <DirectXMath.h>
namespace LevelUp
{

    GameObject::GameObject()
    {
        //set the initial position to 0,0
        m_position = (LVLfloat2(0.0f, 0.0f));
    }
	void GameObject::setPosition(float x, float y)
	{
        //sets the position values
		m_position.x = x;
		m_position.y = y;
	}
    void GameObject::setPosition(LVLfloat2& pos)
	{
        //also sets the position values
		m_position = pos;
	}
    LVLfloat2& GameObject::getPosition()
	{
        //return the objects position
		return m_position;
	}
}