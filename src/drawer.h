#ifndef _AGL_DRAWER_H
#define _AGL_DRAWER_H

#include <stdlib.h>
#include "SDL/SDL.h"
#include "SDL/SDL_ttf.h"

#include "agl/font.h"
#include "agl/support.h"
#include "agl/intvector2.h"
#include "agl/image.h"

namespace AGL
{
	/// Controls the graphics device, changing screen resolution and drawing objects
	class Drawer
	{
		private:
			void basicInitialize(IntVector2 &_screenSize);

		public:
			/// Indicates whether the game is in full screen mode
			bool fullScreen;

			/// Represents the screen data
			SDL_Surface* screen;

			/// Represents the screen size
			IntVector2* screenSize;

			/// Constructor of the Drawer class
			Drawer();

			/// Constructor of the Drawer class
			///
			/// @param _screenSize size of the screen (width and height) 
			Drawer(IntVector2 &_screenSize);

			/// Constructor of the Drawer class
			///
			/// @param screenWidth width of tehe screen (in pixels)
			/// @param screenHeight height of tehe screen (in pixels)
			Drawer(Uint16 screenWidth, Uint16 screenHeight);

			/// Draws an image on the screen
			///
			/// @param image image
			/// @param position position on the screen to draw
			void draw(Image* image, IntVector2 &position);

			/// Draws an image on the screen
			///
			/// @param image image
			/// @param source portion of the image to draw
			/// @param position position on the screen to draw
			void draw(Image* image, Rectangle source, IntVector2 &position);

			/// Draws a text
			///
			/// @param font font used to draw the text
			/// @param text text to draw
			/// @param position position on the screen to draw
			/// @param _color color of the text
			void drawText(Font* font, char* text, IntVector2 &position, Color _color);

			/// Draws a text
			///
			/// @param font font used to draw the text
			/// @param text text to draw
			/// @param position position on the screen to draw
			/// @param _color color of the text
			void drawText(Font* font, const char* text, IntVector2 &position, Color _color);

			/// Updates the screen with the buffered data
			void updateScreen();

			/// Clear the screen
			void clearScreen();

			/// Clear the screen with a color
			///
			/// @param color color used to clear the screen
			void clearScreen(Color color);

			/// Draw a single pixel in the screen
			///
			/// @param color color of the pixel 
			/// @param position position of the pixel in the screen
			void drawPixel(Color color, IntVector2 &position);

			/// Sets video resolution and fullscreen
			///
			/// @param screenWidth width of the screen
			/// @param screenHeight height of the screen
			/// @param _fullScreen whether fullscreen will be used
			void setScreen(Uint16 screenWidth, Uint16 screenHeight, bool _fullScreen);

			/// Sets video resolution and fullscreen
			///
			/// @param _screenSize size of the screen (width and height) 
			/// @param _fullScreen whether fullscreen will be used
			void setScreen(IntVector2 &_screenSize, bool _fullScreen);
	};
}

#endif

