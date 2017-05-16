#include "agl/sound.h"

AGL::SoundInstance** AGL::Sound::instances;

void AGL::Sound::initialize()
{
	AGL::Sound::instances = new AGL::SoundInstance*[AGL_SOUND_CHANNELS];
	
	for(int i = 0; i < AGL_SOUND_CHANNELS; i++)
		AGL::Sound::instances[i] = NULL;
		
	Mix_ChannelFinished(soundFinished);
}

void AGL::Sound::soundFinished(int channel)
{
	if(AGL::Sound::instances[channel] != NULL)
		AGL::Sound::instances[channel]->activeChannel = -1;
}

AGL::Sound::Sound(char* file)
{
	mixSound = Mix_LoadWAV(file);
}

AGL::Sound::Sound(const char* file)
{
	mixSound = Mix_LoadWAV(file);
}

AGL::Sound::Sound(unsigned short type, const char* file)
{
	if(type == AGL_SOUND)
		mixSound = Mix_LoadWAV(file);
	else if(type == AGL_AGR)
	{
		FileManipulator fr(file);
		int fileSize = 0;
		char* data = fr.readAll(fileSize);
		Ciphers cph;
		cph.revert(data, fileSize);
	
		SDL_RWops *rw = SDL_RWFromMem(data, fileSize); 
		mixSound = Mix_LoadWAV_RW(rw, 1);
	}
}

AGL::Sound::~Sound()
{
	Mix_FreeChunk(mixSound);
}

void AGL::Sound::pauseAll()
{
	Mix_Pause(-1);
}

void AGL::Sound::unpauseAll()
{
	Mix_Resume(-1);
}

void AGL::Sound::play()
{
	for(int i = 0; i < AGL_SOUND_CHANNELS; i++)
		if(!Mix_Playing(i))
		{
			Mix_PlayChannel(i, mixSound, 0);
			return;
		}

	Mix_PlayChannel(0, mixSound, 0);	
	if(AGL::Sound::instances[0] != NULL) AGL::Sound::instances[0]->activeChannel = -1;
}

void AGL::Sound::play(float volume)
{
	setVolume(volume);

	for(int i = 0; i < AGL_SOUND_CHANNELS; i++)
		if(!Mix_Playing(i))
		{
			Mix_PlayChannel(i, mixSound, 0);
			return;
		}

	Mix_PlayChannel(0, mixSound, 0);
	if(AGL::Sound::instances[0] != NULL) AGL::Sound::instances[0]->activeChannel = -1;
}

void AGL::Sound::play(float volume, int times)
{
	setVolume(volume);

	for(int i = 0; i < AGL_SOUND_CHANNELS; i++)
		if(!Mix_Playing(i))
		{
			Mix_PlayChannel(i, mixSound, times - 1);
			return;
		}

	Mix_PlayChannel(0, mixSound, times - 1);
	if(AGL::Sound::instances[0] != NULL) AGL::Sound::instances[0]->activeChannel = -1;
}

void AGL::Sound::fadeIn(float volume, int times, int milliseconds)
{
	setVolume(volume);

	for(int i = 0; i < AGL_SOUND_CHANNELS; i++)
		if(!Mix_Playing(i))
		{
			Mix_FadeInChannel(i, mixSound, times - 1, milliseconds);
			return;
		}

	Mix_FadeInChannel(0, mixSound, times - 1, milliseconds);
	if(AGL::Sound::instances[0] != NULL) AGL::Sound::instances[0]->activeChannel = -1;
}

void AGL::Sound::setVolume(float volume)
{
	Mix_VolumeChunk(mixSound, volume * MIX_MAX_VOLUME);
}
