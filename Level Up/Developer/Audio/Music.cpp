#include "Music.h"

namespace LevelUp
{
	Music::Music(std::string fName) : Audio(fName)
	{
		if (m_music.openFromFile(m_fileName))
		{
			throw (std::runtime_error("Could not open music file in Assets/Audio"));
		}
	}
	void Music::setVolume(float volume)
	{
		m_music.setVolume(volume);
	}
	void Music::setPitch(float pitch)
	{
		m_music.setPitch(pitch);
	}
	void Music::stop()
	{
		m_music.stop();
	}
	void Music::play(bool loop, float volume)
	{
		m_music.setLoop(loop);
		m_music.setVolume(volume);
		m_music.play();
	}
	void Music::pause()
	{
		m_music.pause();
	}
	void Music::setPlayingOffset(float seconds)
	{
		m_music.setPlayingOffset(sf::seconds(seconds));
	}
	float Music::getVolume()
	{
		return m_music.getVolume();
	}
	float Music::getPitch()
	{
		return m_music.getPitch();
	}
	float Music::getPlayingOffset()
	{
		return m_music.getPlayingOffset().asSeconds();
	}
	bool Music::isPlaying()
	{
		return m_music.getStatus() == m_music.Playing;
	}
	bool Music::isPaused()
	{
		return m_music.getStatus() == m_music.Paused;
	}
	bool Music::isStopped()
	{
		return m_music.getStatus() == m_music.Stopped;
	}
	void Music::setLoop(bool loop)
	{
		m_music.setLoop(loop);
	}
	bool Music::getLoop()
	{
		return m_music.getLoop();
	}
}