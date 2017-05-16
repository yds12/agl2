#ifndef _AGL_IMAGEFONT_H
#define _AGL_IMAGEFONT_H

#include "SDL/SDL.h"

#include "agl/support.h"
#include "agl/image.h"

/// @mainpage AGL - Aleva Game Library
/// @section Libraries
/// AGL Libraries
/// - <a href="../../index.html">agl: main AGL Library.</a>
/// - <a href="../../agl-graphics/html/index.html">agl-graphics: AGL Graphics Library.</a>
/// - <a href="../../agl-mapping/html/index.html">agl-mapping: AGL Mapping Library.</a>
/// - <a href="../../agl-motion/html/index.html">agl-motion: AGL Motion Library.</a>
/// - agl-text: AGL Text Library.
/// - <a href="../../agl-forms/html/index.html">agl-forms: AGL Forms Library.</a>
/// - <a href="../../agl-net/html/index.html">agl-net: AGL Net Library.</a>

namespace AGL
{
	/// Writes text creating images
	class ImageFont
	{
		private:
			short getCharIndex(char ch);
			
			short getCharIndex(wchar_t ch);
			
			void blitChar(Image* image, short x, short y, Rectangle rect);
			
			void basicInitialize(Image* _spriteSheet, short lines, string _chars);
			
			void basicInitialize(Image* _spriteSheet, short lines, wstring _chars);
			
			Image* spriteSheet;
			
			string chars;
			
			wstring wchars;
			
			Rectangle* rects;
			
			short ssLines;

		public:
			/// Width in pixels of the blank space
			short blankSpaceWidth;

			/// Spacing between chars, in pixels
			short charSpacing;

			/// Spacing between lines, in pixels
			short lineSpacing;
			
			/// Height of the characters of this font, in pixels
			short charHeight;
			
			/// Destructor
			~ImageFont();
		
			/// Builds a new instance of the ImageFont class
			///
			/// @param _spriteSheet image with the characters of the font, with black pixels separating each one
			/// @param lines number of lines in the spritesheet
			/// @param _chars characters of the image font, in the same order they appear in the spritesheet
			ImageFont(Image* _spriteSheet, short lines, string _chars);
		
			/// Builds a new instance of the ImageFont class
			///
			/// @param _spriteSheet image with the characters of the font, with black pixels separating each one
			/// @param lines number of lines in the spritesheet
			/// @param _chars characters of the image font, in the same order they appear in the spritesheet
			ImageFont(Image* _spriteSheet, short lines, wstring _chars);
			
			/// Builds a new instance of the ImageFont class (considering lower and upper case letters (and with accents), numbers and punctuation
			///
			/// @param _spriteSheet image with the characters of the font, with black pixels separating each one
			/// @param lines number of lines in the spritesheet
			ImageFont(Image* _spriteSheet, short lines);
			
			/// Sets font options like characters and line spacing
			///
			/// @param charSpacing Space between each character (in pixels)
			/// @param lineSpacing Space between each line (in pixels)
			/// @param blankWidth width of the blank spaces (in pixels)
			void setOptions(short charSpacing, short lineSpacing, short blankWidth);
			
			/// Returns the width, in pixels, of a given char in this font
			///
			/// @param ch The char of which the width will be returned
			/// @return Width of the char
			short getCharWidth(char ch);
			
			/// Returns the width, in pixels, of a given char in this font
			///
			/// @param ch The char of which the width will be returned
			/// @return Width of the char
			short getCharWidth(wchar_t ch);
			
			/// Writes a line and returns its image
			///
			/// @param text text to be written
			/// @return the text image
			Image* writeLine(string text);
			
			/// Writes a line and returns its image
			///
			/// @param text text to be written
			/// @return the text image
			Image* writeLine(wstring text);
			
			/// Writes a line centered and returns its image
			///
			/// @param text text to be written
			/// @param width size of the image where the text must be centered
			/// @return the text image
			Image* writeCenteredLine(string text, short width);
			
			/// Writes a line centered and returns its image
			///
			/// @param text text to be written
			/// @param width size of the image where the text must be centered
			/// @return the text image
			Image* writeCenteredLine(wstring text, short width);
			
			/// Writes text breaking lines and returns its image
			///
			/// @param text text to be written
			/// @param width maximum size of the line where the text must be written
			/// @return the text image
			Image* writeBreaking(string text, short width);
			
			/// Writes text breaking lines and returns its image
			///
			/// @param text text to be written
			/// @param width maximum size of the line where the text must be written
			/// @return the text image
			Image* writeBreaking(wstring text, short width);
			
			/// Writes justified text breaking lines and returns its image
			///
			/// @param text text to be written
			/// @param width maximum size of the line where the text must be written
			/// @return the text image
			Image* writeJustified(string text, short width);
			
			/// Writes justified text breaking lines and returns its image
			///
			/// @param text text to be written
			/// @param width maximum size of the line where the text must be written
			/// @return the text image
			Image* writeJustified(wstring text, short width);
	};
}

#endif

