#ifndef _AGL_IMAGE_H
#define _AGL_IMAGE_H

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "agl/support.h"
#include "agl/intvector2.h"
#include "agl/filemanipulator.h"
#include "agl/ciphers.h"

#define AGL_BITS_PER_PIXEL 32
#define AGL_RED_MASK 255
#define AGL_GREEN_MASK 65280
#define AGL_BLUE_MASK 16711680
#define AGL_ALPHA_MASK 4278190080

namespace AGL
{
	/// Image class
	class Image
	{
		private:			
			void optimize();
			
			void optimizeBMP();
			
			Uint32 getPixel(int x, int y);
		
		public:		
			/// The image itself
			SDL_Surface* sdlSurface;

			/// Size of the image
			AGL::IntVector2* size;
			
			/// Constructor
			Image();
			
			/// Copy Constructor
			///
			/// @param image image to copy
			Image(Image* image);
			
			/// Constructor
			///
			/// @param file image file
			Image(char* file);
			
			/// Constructor
			///
			/// @param file image file
			Image(const char* file);
			
			/// Constructor
			///
			/// @param imageType type of the image (AGL_IMAGE_PNG, AGL_IMAGE_BMP or AGL_IMAGE_AGR)
			/// @param file image file
			Image(unsigned short imageType, const char* file);
			
			/// Constructor
			///
			/// @param file image file
			/// @param bitmap whether the image is a bitmap
			Image(char* file, bool bitmap);
			
			/// Constructor
			///
			/// @param file image file
			/// @param bitmap whether the image is a bitmap
			Image(const char* file, bool bitmap);
			
			/// Constructor (creates a blank image with the specified size)
			///
			/// @param width image width
			/// @param height image height
			Image(unsigned short width, unsigned short height);

			/// Destructor
			~Image();

			/// Get the color of a given pixel of the image (must lock the image)
			///
			/// @param x x coordinate of the pixel
			/// @param y y coordinate of the pixel
			/// @param r red color component
			/// @param g green color component
			/// @param b blue color component
			/// @param a alpha color component
			void getPixel(int x, int y, Uint8* r, Uint8* g, Uint8* b, Uint8* a);

			/// Set the color of a given pixel of the image (must lock the image)
			///
			/// @param x x coordinate of the pixel
			/// @param y y coordinate of the pixel
			/// @param r red color component
			/// @param g green color component
			/// @param b blue color component
			/// @param a alpha color component
			void setPixel(int x, int y, Uint8 r, Uint8 g, Uint8 b, Uint8 a);

			/// Lock the image to allow pixel manipulation
			void lock();

			/// Unlock the image after pixel manipulation
			void unlock();

			/// Loads image from file
			///
			/// @param file file name
			void loadImage(char* file);

			/// Loads image from file
			///
			/// @param file file name
			void loadImage(const char* file);

			/// Loads image from file
			///
			/// @param file bitmap file name
			void loadBitmap(char* file);

			/// Loads image from file
			///
			/// @param file bitmap file name
			void loadBitmap(const char* file);
	};
}

#endif
