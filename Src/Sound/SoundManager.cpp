/*
 * SoundManager.cpp
 *
 *	To Create the Sounds the following Tutorial was used for inspiration:
 *		http://www.edenwaith.com/products/pige/tutorials/openal.php
 *
 *  Created on: Jun 26, 2012
 *      Author: steindl
 */

#include "SoundManager.h"

SoundManager::SoundManager()
{
	alutInit(0,NULL);
	if(alutGetError() != ALUT_ERROR_NO_ERROR)
	{
		throw SoundManagerException("Error at init of alut\n");
	}

	files_[0] = "Resources/Sounds/MetronomeSounds/tick.wav";
	files_[1] = "Resources/Sounds/PianoSounds/1.wav";
	files_[2] = "Resources/Sounds/PianoSounds/2.wav";
	files_[3] = "Resources/Sounds/PianoSounds/3.wav";
	files_[4] = "Resources/Sounds/PianoSounds/4.wav";
	files_[5] = "Resources/Sounds/PianoSounds/5.wav";
	files_[6] = "Resources/Sounds/PianoSounds/6.wav";
	files_[7] = "Resources/Sounds/PianoSounds/7.wav";
	files_[8] = "Resources/Sounds/PianoSounds/8.wav";
	files_[9] = "Resources/Sounds/PianoSounds/9.wav";
	files_[10] = "Resources/Sounds/PianoSounds/10.wav";
	files_[11] = "Resources/Sounds/PianoSounds/11.wav";
	files_[12] = "Resources/Sounds/PianoSounds/12.wav";
	files_[13] = "Resources/Sounds/PianoSounds/13.wav";
	files_[14] = "Resources/Sounds/PianoSounds/intro1.wav";
	files_[15] = "Resources/Sounds/PianoSounds/intro2.wav";
}

SoundManager::~SoundManager()
{
	alDeleteSources(NUM_SOURCES, source_);
	alDeleteBuffers(NUM_BUFFERS, buffer_);
	alutExit();
}

void SoundManager::loadSoundBuffers()
{
	ALfloat listenerPos[] = {0.0,0.0,4.0};
	ALfloat listenerVel[] = {0.0,0.0,0.0};
	ALfloat listenerOri[] = {0.0,0.0,1.0, 0.0,1.0,0.0};

	alListenerfv(AL_POSITION, listenerPos);
	alListenerfv(AL_VELOCITY, listenerVel);
	alListenerfv(AL_ORIENTATION, listenerOri);
	if(alGetError() != AL_NO_ERROR)
	{
		std::cerr << "Error while creating sound listeners\n";
	}

	//generate the sound buffer
	alGenBuffers(NUM_BUFFERS, buffer_);
	if(alGetError() != AL_NO_ERROR)
	{
		std::cerr << "Error while creating sound buffers\n";
	}

	alGenSources(NUM_SOURCES, source_);
	if(alGetError() != AL_NO_ERROR)
	{
		std::cerr << "Error while creating sound sources\n";
	}

	for(int i=0; i<NUM_BUFFERS;i++)
	{
		std::cout << "Loading sound " << files_[i] << "." << std::endl;
		buffer_[i] = alutCreateBufferFromFile(files_[i].c_str());
		if(alutGetError() != ALUT_ERROR_NO_ERROR)
		{
			std::cerr << "Error when creating the buffer for the sound\n";
		}

		alSourcef(source_[i], AL_PITCH, 1.0f);
		alSourcef(source_[i], AL_GAIN, 1.0f);

		alSourcei(source_[i], AL_BUFFER, buffer_[i]);
		if(alGetError() != AL_NO_ERROR)
		{
			std::cerr << "Error while applying the sound source to the buffer\n";
		}

		alSourcei(source_[i], AL_LOOPING, AL_FALSE);
	}

	//repeat metronome klick
	alSourcei(source_[0], AL_LOOPING, AL_TRUE);
}


void SoundManager::playSound(unsigned int numSound)
{
	alSourcePlay(source_[numSound]);
}

void SoundManager::startMetronome()
{
	alSourcePlay(source_[0]);
}

void SoundManager::stopMetronome()
{
	alSourceStop(source_[0]);
}
