#ifndef _AGL_MUSIC_H
#define _AGL_MUSIC_H

#include "SDL/SDL_mixer.h"

#include "agl/support.h"
#include "agl/filemanipulator.h"
#include "agl/ciphers.h"

namespace AGL
{
	/// Music class
	class Music
	{
		public:
			/// The sound itself
			Mix_Music* mixMusic;
			
			/// Constructor
			///
			/// @param file .ogg, .mp3, .mod, .s3m, .it or .xm file path
			Music(char* file);
			
			/// Constructor
			///
			/// @param file .ogg, .mp3, .mod, .s3m, .it or .xm file path
			Music(const char* file);
			
			/// Constructor
			///
			/// @param type type of the file between AGL_MUSIC and AGL_AGR
			/// @param file .ogg, .mp3, .mod, .s3m, .it, .xm or .agr file path
			Music(unsigned short type, const char* file);

			/// Destructor
			~Music();

			/// Verifies whether some music is playing now
			///
			/// @return indicates whether some music is playing now
			static bool isPlaying();

			/// Verifies whether some music is paused now
			///
			/// @return indicates whether some music is paused now
			static bool isPaused();

			/// Pause the music
			void pause();

			/// Unpause the music
			void unpause();

			/// Rewind the music (just for .ogg, .mp3 or .mod files)
			void rewind();

			/// Stops the music
			void stop();

			/// Play the music infinitely
			void play();

			/// Play the music once
			void playOnce();

			/// Play the music
			///
			/// @param volume volume to play (between 0 and 1)
			void play(float volume);

			/// Play the music repeatedly
			///
			/// @param volume volume to play (between 0 and 1)
			/// @param times times to repeat the music
			void play(float volume, int times);

			/// Play the music fading in
			///
			/// @param milliseconds time to the music become in maximum volume
			void fadeIn(int milliseconds);

			/// Play the music fading in once
			///
			/// @param milliseconds time to the music become in maximum volume
			void fadeInOnce(int milliseconds);

			/// Fades out the music that is playing
			///
			/// @param milliseconds time to the music stop
			void fadeOut(int milliseconds);

			/// Play the music fading in
			///
			/// @param volume volume to play (between 0 and 1)
			/// @param times times to repeat the music
			/// @param milliseconds time to the music become in maximum volume
			void fadeIn(float volume, int times, int milliseconds);

			/// Sets the volume
			///
			/// @param volume volume (between 0 and 1)
			void setVolume(float volume);

			/// Gets the volume
			///
			/// @return volume of the music (between 0 and 1)
			float getVolume();
	};
}

#endif
