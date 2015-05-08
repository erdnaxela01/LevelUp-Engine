#ifndef __MUSIC_H
#define __MUSIC_H

#include "Audio.h"

namespace LevelUp
{
	class Music : public Audio
	{
	public:
		Music(std::string fName);
		virtual ~Music() {};
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
		sf::Music m_music;
	};
}

#endif