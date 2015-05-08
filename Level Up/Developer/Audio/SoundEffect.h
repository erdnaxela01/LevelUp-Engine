#ifndef __SOUNDEFFECT_H
#define __SOUNDEFFECT_H

#include "Audio.h"
#include <SFML/Audio.hpp>

namespace LevelUp
{
	class SoundEffect :public Audio
	{
	public:
		SoundEffect(std::string fName);
		virtual ~SoundEffect() {};
		void setVolume(float volume);
		void setPitch(float pitch);
		void stop();
		void play(bool loop = false, float volume = 100.0f);
		void pause();
		void setPlayingOffset(float seconds);
		float getVolume();
		float getPitch();
		float getPlayingOffset();
		bool isPlaying();
		bool isPaused();
		bool isStopped();
		void setLoop(bool loop);
		bool getLoop();
	private:
		sf::SoundBuffer m_buffer;
		sf::Sound m_sound;

	};
}

#endif