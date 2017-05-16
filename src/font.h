#ifndef _AGL_FONT_H
#define _AGL_FONT_H

#include "SDL/SDL_ttf.h"

#include "agl/support.h"

namespace AGL
{
	/// Represents a true-type font
	class Font
	{
		public:
			/// Font style
			bool italic, bold, underline;

			/// The font itself
			TTF_Font* ttf;

			/// Size of the font
			int size;

			/// Constructor of the Font class
			///
			/// @param file path and name of the ttf file
			/// @param _size size of the font
			Font(const char* file, int _size);

			/// Constructor of the Font class
			///
			/// @param file path and name of the ttf file
			/// @param _size size of the font
			/// @param _italic whether the font is italic
			/// @param _bold whether the font is bold
			/// @param _underline whether the font is underlined
			Font(const char* file, int _size, bool _italic, bool _bold, bool _underline);

			/// Destructor
			~Font();
	};
}

#endif
