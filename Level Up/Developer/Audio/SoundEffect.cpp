#include "SoundEffect.h"

namespace LevelUp
{
	SoundEffect::SoundEffect(std::string fName) : Audio(fName)
	{
		if (!m_buffer.loadFromFile(m_fileName))
		{
			throw (std::runtime_error("Could not open sound effect file in Assets/Audio"));
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
	float SoundEffect::getVolume() const
	{
		return m_sound.getVolume();
	}
	float SoundEffect::getPitch() const
	{
		return m_sound.getPitch();
	}
	float SoundEffect::getPlayingOffset() const
	{
		return m_sound.getPlayingOffset().asSeconds();
	}
	bool SoundEffect::isPlaying() const
	{
		return m_sound.getStatus() == m_sound.Playing;
	}
	bool SoundEffect::isPaused() const
	{
		return m_sound.getStatus() == m_sound.Paused;
	}
	bool SoundEffect::isStopped() const
	{
		return m_sound.getStatus() == m_sound.Stopped;
	}
	void SoundEffect::setLoop(bool loop)
	{
		m_sound.setLoop(loop);
	}
	bool SoundEffect::getLoop() const
	{
		return m_sound.getLoop();
	}
}