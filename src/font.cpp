#include "SDL/SDL_ttf.h"

#include "agl/font.h"

AGL::Font::Font(const char* file, int _size)
{
	size = _size;
	ttf = TTF_OpenFont(file, _size);
}

AGL::Font::Font(const char* file, int _size, bool _italic, bool _bold, bool _underline)
{
	size = _size;
	ttf = TTF_OpenFont(file, _size);

	int style = 0;
	
	if(_italic)
	{
		if(_bold)
		{
			if(_underline) style = TTF_STYLE_BOLD | TTF_STYLE_ITALIC |  TTF_STYLE_UNDERLINE;
			else style = TTF_STYLE_BOLD | TTF_STYLE_ITALIC;
		}
		else if(_underline) style = TTF_STYLE_ITALIC |  TTF_STYLE_UNDERLINE;
		else style = TTF_STYLE_ITALIC;
	}
	else if(_bold)
	{
		if(_underline) style = TTF_STYLE_BOLD |  TTF_STYLE_UNDERLINE;
		else style = TTF_STYLE_BOLD;
	}
	else if(_underline) style = TTF_STYLE_UNDERLINE;
	else return;

	TTF_SetFontStyle(ttf, style);
}

AGL::Font::~Font()
{
	TTF_CloseFont(ttf);
}
