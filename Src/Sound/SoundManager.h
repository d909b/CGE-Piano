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

#define NUM_BUFFERS 3
#define NUM_SOURCES 3

class SoundManager
{
public:
	SoundManager();
	~SoundManager();
	void loadSoundBuffers(std::string file[]);
	void playSound(unsigned int numSound);
private:
	ALuint buffer_[NUM_BUFFERS];
	ALuint source_[NUM_SOURCES];
	ALint iState_;
};

class SoundManagerException : MessagedException
{
public:
	SoundManagerException(std::string message) :
		MessagedException(message)
	{;}
};
