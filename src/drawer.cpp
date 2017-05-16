#include <iostream>

#include "agl/drawer.h"

using namespace std;

// ####### Constructors
AGL::Drawer::Drawer()
{
	IntVector2 _screenSize(AGL_SCREEN_WIDTH, AGL_SCREEN_HEIGHT);
	basicInitialize(_screenSize);
}

AGL::Drawer::Drawer(IntVector2 &_screenSize)
{
	basicInitialize(_screenSize);
}

AGL::Drawer::Drawer(Uint16 screenWidth, Uint16 screenHeight)
{
	IntVector2 _screenSize(screenWidth, screenHeight);
	basicInitialize(_screenSize);
}

void AGL::Drawer::basicInitialize(IntVector2 &_screenSize)
{
	fullScreen = false;
	
	screenSize = new IntVector2(_screenSize);

	screen = SDL_SetVideoMode(screenSize->x, screenSize->y, 0, SDL_ANYFORMAT | SDL_SWSURFACE);
	if(screen == NULL)
	{
		cout << "Erro ao ajustar resolução de vídeo: " << SDL_GetError() << endl;
		exit(1);
	}
}

// ####### Methods
void AGL::Drawer::updateScreen()
{
	SDL_Flip(screen);
}

void AGL::Drawer::clearScreen()
{
	SDL_Rect r = {0, 0, screenSize->x, screenSize->y};
	SDL_FillRect(screen, &r, SDL_MapRGB(screen->format, 0, 0, 0));
}

void AGL::Drawer::clearScreen(Color color)
{
	SDL_Rect r = {0, 0, screenSize->x, screenSize->y};
	SDL_FillRect(screen, &r, SDL_MapRGB(screen->format, color.red, color.green, color.blue));
}

void AGL::Drawer::draw(AGL::Image* image, IntVector2 &position)
{
	SDL_Rect r = {position.x, position.y, 0, 0};
	SDL_BlitSurface(image->sdlSurface, NULL, screen, &r);
}

void AGL::Drawer::draw(AGL::Image* image, AGL::Rectangle source, IntVector2 &position)
{
	SDL_Rect src = {source.x, source.y, source.width, source.height};
	SDL_Rect r = {position.x, position.y, 0, 0};
	SDL_BlitSurface(image->sdlSurface, &src, screen, &r);
}

void AGL::Drawer::drawText(Font* font, char* text, IntVector2 &position, Color _color)
{
	SDL_Color color = {_color.red, _color.green, _color.blue};
	AGLTexture* src = TTF_RenderUTF8_Blended(font->ttf, text, color);

	SDL_Rect dst = {position.x, position.y, 0, 0};  
	SDL_BlitSurface(src, NULL, screen, &dst);  
	SDL_FreeSurface(src);
}

void AGL::Drawer::drawText(Font* font, const char* text, IntVector2 &position, Color _color)
{
	SDL_Color color = {_color.red, _color.green, _color.blue};
	AGLTexture* src = TTF_RenderUTF8_Blended(font->ttf, text, color);

	SDL_Rect dst = {position.x, position.y, 0, 0};  
	SDL_BlitSurface(src, NULL, screen, &dst);  
	SDL_FreeSurface(src);
}

void AGL::Drawer::drawPixel(Color color, IntVector2 &position)
{
	Uint32 color2 = SDL_MapRGB(screen->format, color.red, color.green, color.blue);

	if (SDL_MUSTLOCK(screen) && SDL_LockSurface(screen) < 0)
		return;

	Uint16 *bufp;
	bufp = (Uint16 *) screen->pixels + position.y * screen->pitch/2 + position.x;
	*bufp = color2;

	if (SDL_MUSTLOCK(screen)) SDL_UnlockSurface(screen);
}

void AGL::Drawer::setScreen(IntVector2 &_screenSize, bool _fullScreen)
{
	fullScreen = _fullScreen;
	
	if(screenSize != NULL) delete(screenSize);	
	screenSize = new IntVector2(_screenSize);

	if(_fullScreen) screen = SDL_SetVideoMode(screenSize->x, screenSize->y, 0, SDL_ANYFORMAT | SDL_SWSURFACE | SDL_FULLSCREEN);
	else screen = SDL_SetVideoMode(screenSize->x, screenSize->y, 0, SDL_ANYFORMAT | SDL_SWSURFACE);
}

void AGL::Drawer::setScreen(Uint16 screenWidth, Uint16 screenHeight, bool _fullScreen)
{
	fullScreen = _fullScreen;
	
	if(screenSize != NULL) delete(screenSize);
	screenSize = new IntVector2(screenWidth, screenHeight);

	if(_fullScreen) screen = SDL_SetVideoMode(screenSize->x, screenSize->y, 0, SDL_ANYFORMAT | SDL_SWSURFACE | SDL_FULLSCREEN);
	else screen = SDL_SetVideoMode(screenSize->x, screenSize->y, 0, SDL_ANYFORMAT | SDL_SWSURFACE);
}
