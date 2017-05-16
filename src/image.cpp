#include "agl/image.h"

AGL::Image::Image()
{

}

AGL::Image::Image(Image* image)
{
	sdlSurface = SDL_ConvertSurface(image->sdlSurface, image->sdlSurface->format, SDL_SWSURFACE | SDL_SRCALPHA);
	size = new IntVector2(sdlSurface->w, sdlSurface->h);		
}

AGL::Image::Image(char* file)
{
	sdlSurface = IMG_Load(file);
	size = new IntVector2(sdlSurface->w, sdlSurface->h);
	optimize();
}

AGL::Image::Image(const char* file)
{
	sdlSurface = IMG_Load(file);
	size = new IntVector2(sdlSurface->w, sdlSurface->h);
	optimize();
}

AGL::Image::Image(unsigned short imageType, const char* file)
{
	if(imageType == AGL_PNG)
	{ 
		sdlSurface = IMG_Load(file);
		optimize();
	}
	else if(imageType == AGL_AGR)
	{
		FileManipulator fr(file);
		int fileSize = 0;
		char* data = fr.readAll(fileSize);
		Ciphers cph;
		cph.revert(data, fileSize);
	
		SDL_RWops *rw = SDL_RWFromMem(data, fileSize); 
		sdlSurface = IMG_Load_RW(rw, 1);
		optimize();
	}
	else if(imageType == AGL_BMP)
	{
		sdlSurface = SDL_LoadBMP(file);
		optimizeBMP();
	}
	size = new IntVector2(sdlSurface->w, sdlSurface->h);
}

AGL::Image::Image(char* file, bool bitmap)
{
	if(bitmap)
	{ 
		sdlSurface = SDL_LoadBMP(file);
		optimizeBMP();
	}
	else 
	{
		sdlSurface = IMG_Load(file);
		optimize();
	}
	size = new IntVector2(sdlSurface->w, sdlSurface->h);
}

AGL::Image::Image(const char* file, bool bitmap)
{
	if(bitmap)
	{ 
		sdlSurface = SDL_LoadBMP(file);
		optimizeBMP();
	}
	else 
	{
		sdlSurface = IMG_Load(file);
		optimize();
	}
	size = new IntVector2(sdlSurface->w, sdlSurface->h);
}

AGL::Image::Image(unsigned short width, unsigned short height)
{
	sdlSurface = SDL_CreateRGBSurface(SDL_SWSURFACE | SDL_SRCALPHA, width, height, 
		AGL_BITS_PER_PIXEL, AGL_RED_MASK, AGL_GREEN_MASK, AGL_BLUE_MASK, AGL_ALPHA_MASK);
	size = new IntVector2(sdlSurface->w, sdlSurface->h);
	optimize();
}

AGL::Image::~Image()
{
	SDL_FreeSurface(sdlSurface);
}

Uint32 AGL::Image::getPixel(int x, int y)
{
	int bpp = sdlSurface->format->BytesPerPixel;
	Uint8 *p = (Uint8 *)sdlSurface->pixels + y * sdlSurface->pitch + x * bpp;

	switch (bpp) {
		case 1:
			return *p;

		case 2:
			return *(Uint16 *)p;

		case 3:
			if (SDL_BYTEORDER == SDL_BIG_ENDIAN)
				return p[0] << 16 | p[1] << 8 | p[2];
			else
				return p[0] | p[1] << 8 | p[2] << 16;

		case 4:
			return *(Uint32 *)p;

		default:
			return 0;
	}
}

void AGL::Image::getPixel(int x, int y, Uint8* r, Uint8* g, Uint8* b, Uint8* a)
{
	return SDL_GetRGBA(getPixel(x, y), sdlSurface->format, r, g, b, a);
}

void AGL::Image::setPixel(int x, int y, Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
	Uint32 pixel = SDL_MapRGBA(sdlSurface->format, r, g, b, a);

	int bpp = sdlSurface->format->BytesPerPixel;
	Uint8 *p = (Uint8 *)sdlSurface->pixels + y * sdlSurface->pitch + x * bpp;

	switch (bpp) {
		case 1:
			*p = pixel;
			break;

		case 2:
			*(Uint16 *)p = pixel;
			break;

		case 3:
			if (SDL_BYTEORDER == SDL_BIG_ENDIAN) {
				p[0] = (pixel >> 16);// & 0xff;
				p[1] = (pixel >> 8);// & 0xff;
				p[2] = pixel;// & 0xff;
			}
			else {
				p[0] = pixel;// & 0xff;
				p[1] = (pixel >> 8);// & 0xff;
				p[2] = (pixel >> 16);// & 0xff;
			}
			break;

		case 4:
			*(Uint32 *)p = pixel;
			break;

		default:
			break;
	}
}

void AGL::Image::lock()
{
	if(SDL_MUSTLOCK(sdlSurface)) SDL_LockSurface(sdlSurface);
}

void AGL::Image::unlock()
{
	if(SDL_MUSTLOCK(sdlSurface)) SDL_UnlockSurface(sdlSurface);
}

void AGL::Image::optimizeBMP()
{
	SDL_Surface *opt = SDL_DisplayFormat(sdlSurface);
   if (opt)
   {
       SDL_FreeSurface(sdlSurface);
       sdlSurface = opt;
   }
}

void AGL::Image::optimize()
{
	SDL_Surface *opt = SDL_DisplayFormatAlpha(sdlSurface);
   if (opt)
   {
       SDL_FreeSurface(sdlSurface);
       sdlSurface = opt;
   }
	SDL_SetAlpha(sdlSurface, SDL_RLEACCEL | SDL_SRCALPHA, SDL_ALPHA_OPAQUE); // SDL_ALPHA_OPAQUE = 255
}

void AGL::Image::loadBitmap(char* file)
{
	sdlSurface = SDL_LoadBMP(file);
	size->x = sdlSurface->w;
	size->y = sdlSurface->h;
	optimizeBMP();
}

void AGL::Image::loadBitmap(const char* file)
{
	sdlSurface = SDL_LoadBMP(file);
	size->x = sdlSurface->w;
	size->y = sdlSurface->h;
	optimizeBMP();
}

void AGL::Image::loadImage(char* file)
{
	sdlSurface = IMG_Load(file);
	size->x = sdlSurface->w;
	size->y = sdlSurface->h;
	optimize();
}

void AGL::Image::loadImage(const char* file)
{
	sdlSurface = IMG_Load(file);
	size->x = sdlSurface->w;
	size->y = sdlSurface->h;
	optimize();
}

