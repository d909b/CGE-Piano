/*
 * SoundManager.cpp
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
}

SoundManager::~SoundManager()
{
	alDeleteSources(NUM_SOURCES, source_);
	alDeleteBuffers(NUM_BUFFERS, buffer_);
	alutExit();
}

void SoundManager::loadSoundBuffers(std::string file[])
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
		std::cout << file[i] << std::endl;
		buffer_[i] = alutCreateBufferFromFile(file[i].c_str());
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
}


void SoundManager::playSound(unsigned int numSound)
{
	alSourcePlay(source_[numSound]);
/*
	do
	{
		usleep(100);
		alGetSourcei(source_[numSound], AL_SOURCE_STATE, &iState_);
	} while (iState_ == AL_PLAYING);
*/
}
