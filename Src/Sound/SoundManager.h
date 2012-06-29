/*
 * SoundManager.h
 *
 *  Created on: Jun 26, 2012
 *      Author: steindl
 */

#pragma once

#include <iostream>
#include "../Utility/OpenAL.h"
#include "../Utility/MessagedException.h"

#define NUM_BUFFERS 16
#define NUM_SOURCES 16

class SoundManager
{
public:
	SoundManager();
	~SoundManager();
	void loadSoundBuffers();
	void playSound(unsigned int numSound);
	void startMetronome();
	void stopMetronome();
	void setSoundLoop();
	void unsetSoundLoop();
private:
	ALuint buffer_[NUM_BUFFERS];
	ALuint source_[NUM_SOURCES];
	ALint iState_;
	std::string files_[NUM_SOURCES];
	bool playing_;
};

class SoundManagerException : MessagedException
{
public:
	SoundManagerException(std::string message) :
		MessagedException(message)
	{;}
};
