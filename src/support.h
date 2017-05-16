#ifndef _AGL_SUPPORT_H
#define _AGL_SUPPORT_H

#include <stdlib.h>
#include "SDL/SDL.h"

#include "agl/format.h"

#define AGLTexture SDL_Surface

#define AGL_SCREEN_WIDTH 800
#define AGL_SCREEN_HEIGHT 600
#define AGL_WINDOW_TITLE "AGL Game"
#define AGL_SOUND_CHANNELS 10
#define AGL_SOUND_FREQUENCY 44100
#define AGL_SOUND_MODE 2
#define AGL_SOUND_BUFFER 4096

#define AGL_POSITION_UP SDL_HAT_UP
#define AGL_POSITION_DOWN SDL_HAT_DOWN
#define AGL_POSITION_LEFT SDL_HAT_LEFT
#define AGL_POSITION_RIGHT SDL_HAT_RIGHT
#define AGL_POSITION_CENTER SDL_HAT_CENTERED
#define AGL_POSITION_TOPLEFT SDL_HAT_LEFTUP
#define AGL_POSITION_TOPRIGHT SDL_HAT_RIGHTUP
#define AGL_POSITION_DOWNLEFT SDL_HAT_LEFTDOWN
#define AGL_POSITION_DOWNRIGHT SDL_HAT_RIGHTDOWN

#define AGL_PNG 0
#define AGL_BMP 1
#define AGL_AGR 2
#define AGL_MUSIC 3
#define AGL_SOUND 4

#define PI 3.14159265f
#define TORADIANS(d) (d / 360) * 2 * PI
#define ROUND(n) ((int)(n + 0.5))
#define COLOREQUAL(a,b) (a.red == b.red && a.green == b.green && a.blue == b.blue)
#define SETCOLOR(c, r, g, b) { c.red = r; c.green = g; c.blue = b; }
#define DELETE2(a) { delete a; a = NULL; }

namespace AGL
{
	/// [deprecated] Represents a boolean
	enum aglboolean 
	{ 
		FALSE = 0,
		TRUE = 1
	};

	/// [deprecated] Type to use in place of booleans
	typedef enum aglboolean bit;

	/// [deprecated] Represents a point
	///
	//struct Point
	//{
	//	Uint16 x;
	//	Uint16 y;
	//};

	/// Represents a rectangle
	struct Rectangle
	{
		Uint16 x;
		Uint16 y;
		Uint16 width;
		Uint16 height;
	};

	/// Represents a rectangle with float values
	//struct FloatRectangle
	//{
	//	float x;
	//	float y;
	//	float width;
	//	float height;
	//};

	/// Represents a color
	///
	struct Color
	{
		Uint8 red;
		Uint8 green;
		Uint8 blue;
	};
}

#endif
