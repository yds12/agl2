#include "agl/sound.h"

AGL::SoundInstance::SoundInstance(Sound* sound)
{
	mixSound = sound->mixSound;
	activeChannel = -1;
}

AGL::SoundInstance::~SoundInstance()
{
	if(activeChannel > -1)
		AGL::Sound::instances[activeChannel] = NULL;
}

void AGL::SoundInstance::pause()
{
	if(activeChannel > -1) Mix_Pause(activeChannel);
}

void AGL::SoundInstance::unpause()
{
	if(activeChannel > -1) Mix_Resume(activeChannel);
}

void AGL::SoundInstance::stop()
{
	if(activeChannel > -1) Mix_HaltChannel(activeChannel);
	activeChannel = -1;
}

void AGL::SoundInstance::play()
{
	for(int i = 0; i < AGL_SOUND_CHANNELS; i++)
		if(!Mix_Playing(i))
		{
			Mix_PlayChannel(i, mixSound, 0);
			activeChannel = i;
			AGL::Sound::instances[i] = this;
			return;
		}

	Mix_PlayChannel(0, mixSound, 0);
	activeChannel = 0;
	
	if(AGL::Sound::instances[0] != NULL) AGL::Sound::instances[0]->activeChannel = -1;
	AGL::Sound::instances[0] = this;
}

void AGL::SoundInstance::play(float volume)
{
	setVolume(volume);

	for(int i = 0; i < AGL_SOUND_CHANNELS; i++)
		if(!Mix_Playing(i))
		{
			Mix_PlayChannel(i, mixSound, 0);
			activeChannel = i;
			AGL::Sound::instances[i] = this;
			return;
		}

	Mix_PlayChannel(0, mixSound, 0);
	activeChannel = 0;
	
	if(AGL::Sound::instances[0] != NULL) AGL::Sound::instances[0]->activeChannel = -1;
	AGL::Sound::instances[0] = this;
}

void AGL::SoundInstance::play(float volume, int times)
{
	setVolume(volume);

	for(int i = 0; i < AGL_SOUND_CHANNELS; i++)
		if(!Mix_Playing(i))
		{
			Mix_PlayChannel(i, mixSound, times - 1);
			activeChannel = i;
			AGL::Sound::instances[i] = this;
			return;
		}

	Mix_PlayChannel(0, mixSound, times - 1);
	activeChannel = 0;
	
	if(AGL::Sound::instances[0] != NULL) AGL::Sound::instances[0]->activeChannel = -1;
	AGL::Sound::instances[0] = this;
}

void AGL::SoundInstance::fadeIn(float volume, int times, int milliseconds)
{
	setVolume(volume);

	for(int i = 0; i < AGL_SOUND_CHANNELS; i++)
		if(!Mix_Playing(i))
		{
			Mix_FadeInChannel(i, mixSound, times - 1, milliseconds);
			activeChannel = i;
			AGL::Sound::instances[i] = this;
			return;
		}

	Mix_FadeInChannel(0, mixSound, times - 1, milliseconds);
	activeChannel = 0;
	
	if(AGL::Sound::instances[0] != NULL) AGL::Sound::instances[0]->activeChannel = -1;
	AGL::Sound::instances[0] = this;
}

void AGL::SoundInstance::setVolume(float volume)
{
	Mix_VolumeChunk(mixSound, volume * MIX_MAX_VOLUME);
}
