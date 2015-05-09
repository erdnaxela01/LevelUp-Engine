#include "Listener.h"

namespace LevelUp
{
	void Listener::setVolume(float volume)
	{
		sf::Listener::setGlobalVolume(volume);
	}
	void Listener::setPosition(LVLfloat3 pos)
	{
		sf::Listener::setPosition(pos.x, pos.y, pos.z);
	}
	LVLfloat3 Listener::getPosition()
	{
		LVLfloat3 pos;
		pos.x = sf::Listener::getPosition().x;
		pos.y = sf::Listener::getPosition().y;
		pos.z = sf::Listener::getPosition().z;
		return pos;
	}
	float Listener::getVolume()
	{
		return sf::Listener::getGlobalVolume();
	}
}