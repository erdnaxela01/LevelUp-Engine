#include "SoundEffect.h"

namespace LevelUp
{
	SoundEffect::SoundEffect(std::string fName) : Audio(fName)
	{
		if (!m_buffer.loadFromFile(m_fileName))
		{
			throw (std::runtime_error("Could not open sound effect file"));
		}
		m_sound.setBuffer(m_buffer);
	}
	void SoundEffect::setVolume(float volume)
	{
		m_sound.setVolume(volume);
	}
	void SoundEffect::setPitch(float pitch)
	{
		m_sound.setPitch(pitch);
	}
	void SoundEffect::stop()
	{
		m_sound.stop();
	}
	void SoundEffect::play(bool loop, float volume)
	{
		m_sound.setLoop(loop);
		m_sound.setVolume(volume);
		m_sound.play();
	}
	void SoundEffect::pause()
	{
		m_sound.pause();
	}
	void SoundEffect::setPlayingOffset(float seconds)
	{
		m_sound.setPlayingOffset(sf::seconds(seconds));
	}
	float SoundEffect::getVolume()
	{
		return m_sound.getVolume();
	}
	float SoundEffect::getPitch()
	{
		return m_sound.getPitch();
	}
	float SoundEffect::getPlayingOffset()
	{
		return m_sound.getPlayingOffset().asSeconds();
	}
	bool SoundEffect::isPlaying()
	{
		return m_sound.getStatus() == m_sound.Playing;
	}
	bool SoundEffect::isPaused()
	{
		return m_sound.getStatus() == m_sound.Paused;
	}
	bool SoundEffect::isStopped()
	{
		return m_sound.getStatus() == m_sound.Stopped;
	}
	void SoundEffect::setLoop(bool loop)
	{
		m_sound.setLoop(loop);
	}
	bool SoundEffect::getLoop()
	{
		return m_sound.getLoop();
	}
}