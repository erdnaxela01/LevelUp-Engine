
#include "GameObject.h"
#include <DirectXMath.h>
using namespace DirectX;
namespace LevelUp
{
	void GameObject::setPosition(float x, float y)
	{
		m_position.x = x;
		m_position.y = y;
	}
    void GameObject::setPosition(LVLfloat2& pos)
	{
		m_position = pos;
	}
    LVLfloat2& GameObject::getPosition()
	{
		return m_position;
	}
}