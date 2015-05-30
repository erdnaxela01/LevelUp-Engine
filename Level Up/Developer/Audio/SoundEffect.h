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
		//set the volume of the music
		void setVolume(float volume);
		//set the pitch of the music
		void setPitch(float pitch);
		//stop the music
		void stop();
		//play the music
		void play(bool loop = false, float volume = 100.0f);
		//pause the music
		void pause();
		//set the location in the music to play
		void setPlayingOffset(float seconds);
		//get the volume of the music
		float getVolume() const;
		//get the pitch of the music
		float getPitch() const;
		//get the location in the music
		float getPlayingOffset() const;

		//is it playing?
		bool isPlaying() const;
		//is it paused?
		bool isPaused() const;
		//is it stopped?
		bool isStopped() const;
		//set if the music loops
		void setLoop(bool loop);
		//get if the music is looping
		bool getLoop() const;
	private:
		sf::SoundBuffer m_buffer;
		sf::Sound m_sound;

	};
}

#endif