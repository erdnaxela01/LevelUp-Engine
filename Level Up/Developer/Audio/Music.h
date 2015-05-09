#ifndef __MUSIC_H
#define __MUSIC_H

#include "Audio.h"

namespace LevelUp
{
	/*
	Music class meant to play music in OGG vorbis format
	-Alex Sabourin May 2015
	*/
	class Music : public Audio
	{
	public:
		//pass the filename of the music with OGG vorbis format
		Music(std::string fName);
		virtual ~Music() {};
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
		float getVolume();
		//get the pitch of the music
		float getPitch();
		//get the location in the music
		float getPlayingOffset();

		//is it playing?
		bool isPlaying();
		//is it paused?
		bool isPaused();
		//is it stopped?
		bool isStopped();
		//set if the music loops
		void setLoop(bool loop);
		//get if the music is looping
		bool getLoop();
	private:
		sf::Music m_music;
	};
}

#endif