#ifndef _AGL_SOUND_H
#define _AGL_SOUND_H

#include "SDL/SDL_mixer.h"

#include "agl/support.h"
#include "agl/filemanipulator.h"
#include "agl/ciphers.h"

namespace AGL
{
	class Sound;

	/// Sound Instance class
	class SoundInstance
	{
		private:
			// The sound itself
			Mix_Chunk* mixSound;
				
		public:			
			/// Channel used to play the sound
			int activeChannel;
				
			/// Constructor
			///
			/// @param sound AGL sound object
			SoundInstance(Sound* sound);

			/// Destructor
			~SoundInstance();

			/// Pause this sound instance
			void pause();

			/// Unpause this sound instance
			void unpause();

			/// Stop this sound instance
			void stop();

			/// Play the sound
			void play();

			/// Play the sound
			///
			/// @param volume volume to play (between 0 and 1)
			void play(float volume);

			/// Play the sound repeatedly
			///
			/// @param volume volume to play (between 0 and 1)
			/// @param times times to repeat the sound
			void play(float volume, int times);

			/// Play the sound fading in
			///
			/// @param volume volume to play (between 0 and 1)
			/// @param times times to repeat the sound
			/// @param milliseconds time to the sound become in maximum volume
			void fadeIn(float volume, int times, int milliseconds);

			/// Sets the volume
			///
			/// @param volume volume (between 0 and 1)
			void setVolume(float volume);
	};

	/// Sound Effect class
	class Sound
	{
		public:
			// The sound instances
			static SoundInstance** instances;
			
			/// The sound itself
			Mix_Chunk* mixSound;
			
			/// Initializes the sound system
			static void initialize();
			
			/// Constructor
			///
			/// @param file .wav or .ogg file path
			Sound(char* file);
			
			/// Constructor
			///
			/// @param file .wav or .ogg file path
			Sound(const char* file);
			
			/// Constructor
			///
			/// @param type type of the file between AGL_AGR and AGL_SOUND
			/// @param file .wav or .ogg file path
			Sound(unsigned short type, const char* file);

			/// Destructor
			~Sound();

			/// Don't call this method directly (callback)
			///
			/// @param channel the channel finished
			static void soundFinished(int channel);

			/// Pause all sounds
			static void pauseAll();

			/// Unpause all sounds
			static void unpauseAll();

			/// Play the sound
			void play();

			/// Play the sound
			///
			/// @param volume volume to play (between 0 and 1)
			void play(float volume);

			/// Play the sound repeatedly
			///
			/// @param volume volume to play (between 0 and 1)
			/// @param times times to repeat the sound
			void play(float volume, int times);

			/// Play the sound fading in
			///
			/// @param volume volume to play (between 0 and 1)
			/// @param times times to repeat the sound
			/// @param milliseconds time to the sound become in maximum volume
			void fadeIn(float volume, int times, int milliseconds);

			/// Sets the volume
			///
			/// @param volume volume (between 0 and 1)
			void setVolume(float volume);
	};
}

#endif
