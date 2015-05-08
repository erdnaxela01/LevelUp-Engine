#ifndef __AUDIO_H
#define __AUDIO_H
#include <SFML/Audio.hpp>
#include <string>
namespace LevelUp
{
	class Audio
	{
	public:
		//set the filename of the file
		Audio(std::string fName);
		virtual ~Audio() {};

		//sets the volume of the audio
		virtual void setVolume(float volume) = 0;
		//set the pitch of the audio WILL ALTER SPEED
		virtual void setPitch(float pitch) = 0;
		//stops the audio and rewinds
		virtual void stop() = 0;
		//starts the audio
		virtual void play(bool loop = false, float volume = 100.0f) = 0;
		//pauses the audio
		virtual void pause() = 0;
		//plays the audio at a specific location
		virtual void setPlayingOffset(float seconds) = 0;
		//get the volume
		virtual float getVolume() = 0;
		//get the pitch
		virtual float getPitch() = 0;
		//get the playing offset in seconds
		virtual float getPlayingOffset() = 0;
		//check if it's playing
		virtual bool isPlaying() = 0;
		//check if its stopped
		virtual bool isStopped() = 0;
		//check if its paused
		virtual bool isPaused() = 0;
		//set if the audio loops
		virtual void setLoop(bool loop) = 0;
		//get if the audio loops
		virtual bool getLoop() = 0;
	protected:
		std::string m_fileName;
	};
}

#endif