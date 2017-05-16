#include "agl/music.h"

AGL::Music::Music(char* file)
{
	mixMusic = Mix_LoadMUS(file);
}

AGL::Music::Music(const char* file)
{
	mixMusic = Mix_LoadMUS(file);
}

AGL::Music::Music(unsigned short type, const char* file)
{
	if(type == AGL_MUSIC)
		mixMusic = Mix_LoadMUS(file);
	else if(type == AGL_AGR)
	{
		FileManipulator fr(file);
		int fileSize = 0;
		char* data = fr.readAll(fileSize);
		Ciphers cph;
		cph.revert(data, fileSize);
	
		SDL_RWops *rw = SDL_RWFromMem(data, fileSize); 
		mixMusic = Mix_LoadMUS_RW(rw);
	}
}

AGL::Music::~Music()
{
	Mix_FreeMusic(mixMusic);
}

bool AGL::Music::isPlaying()
{
	return Mix_PlayingMusic();
}

bool AGL::Music::isPaused()
{
	return Mix_PausedMusic();
}

void AGL::Music::pause()
{
	Mix_PauseMusic();
}

void AGL::Music::unpause()
{
	Mix_ResumeMusic();
}

void AGL::Music::rewind()
{
	Mix_RewindMusic();
}

void AGL::Music::stop()
{
	Mix_HaltMusic();
}

void AGL::Music::play()
{
	Mix_PlayMusic(mixMusic, -1);
}

void AGL::Music::playOnce()
{
	Mix_PlayMusic(mixMusic, 0);
}

void AGL::Music::play(float volume)
{
	setVolume(volume);
	Mix_PlayMusic(mixMusic, -1);
}

void AGL::Music::play(float volume, int times)
{
	setVolume(volume);
	Mix_PlayMusic(mixMusic, times - 1);
}

void AGL::Music::fadeIn(int milliseconds)
{
	Mix_FadeInMusic(mixMusic, -1, milliseconds);
}

void AGL::Music::fadeInOnce(int milliseconds)
{
	Mix_FadeInMusic(mixMusic, 0, milliseconds);
}

void AGL::Music::fadeOut(int milliseconds)
{
	Mix_FadeOutMusic(milliseconds);
}

void AGL::Music::fadeIn(float volume, int times, int milliseconds)
{
	
}

void AGL::Music::setVolume(float volume)
{
	Mix_VolumeMusic(volume * MIX_MAX_VOLUME); 
}

float AGL::Music::getVolume()
{
	return (float)Mix_VolumeMusic(-1)/128.0f; 
}
