#ifndef _AGL_GRAPHICS_H
#define _AGL_GRAPHICS_H

#include <stdlib.h>
#include "SDL/SDL.h"

#include "agl/support.h"
#include "agl/intvector2.h"
#include "agl/image.h"
#include "agl/drawer.h"

#define AGL_TRIANGLE_TOPLEFT 0
#define AGL_TRIANGLE_TOPRIGHT 1
#define AGL_TRIANGLE_BOTTOMLEFT 2
#define AGL_TRIANGLE_BOTTOMRIGHT 3

#define AGL_PI 3.1415926f

/// @mainpage AGL - Aleva Game Library
/// @section Libraries
/// AGL Libraries
/// - <a href="../../index.html">agl: main AGL Library.</a>
/// - agl-graphics: AGL Graphics Library.
/// - <a href="../../agl-mapping/html/index.html">agl-mapping: AGL Mapping Library.</a>
/// - <a href="../../agl-motion/html/index.html">agl-motion: AGL Motion Library.</a>
/// - <a href="../../agl-text/html/index.html">agl-text: AGL Text Library.</a>
/// - <a href="../../agl-forms/html/index.html">agl-forms: AGL Forms Library.</a>
/// - <a href="../../agl-net/html/index.html">agl-net: AGL Net Library.</a>

namespace AGL
{
	/// Provides easy image manipulation and processing
	class Graphics
	{
		private:
			/// Gets the SDL-color of a pixel in a SDL-surface
			//Uint32 getPixel(SDL_Surface *surface, int x, int y);

			/// Sets the SDL-color of a pixel in a SDL-surface
			//void setPixel(SDL_Surface *surface, int x, int y, Uint8 r, Uint8 g, Uint8 b, Uint8 a);

			/// Creates an empty SDL-surface
			//SDL_Surface* createSurface(int width, int height);

			/// Rounds a float to the nearest even integer
			static int roundToEven(float f);

			/// Sets a circle outline to a surface
			static void setCircleOutline(int radius, Color color, Image* image, Uint8 alpha);

			static void rotatePoint(float* x, float* y, float angle);

		public:
			/// Interpolates two colors (LERP means Linear Interpolation)
			///
			/// @param color1 the first color
			/// @param color2 the second color
			/// @param gradientPosition weight of the second color (which determines the position in the gradient between the two colors)
			/// @return the resulting color
			static Color lerp(Color color1, Color color2, float gradientPosition);

			/// Interpolates two colors considering alpha (LERP means Linear Interpolation)
			///
			/// @param color1 the first color
			/// @param color2 the second color
			/// @param alpha1 alpha of the first color
			/// @param alpha2 alpha of the second color
			/// @param resultingAlpha variable that will receive the value of the resulting alpha
			/// @param gradientPosition weight of the second color (which determines the position in the gradient between the two colors)
			/// @return the resulting color
			static Color lerp(Color color1, Color color2, Uint8 alpha1, Uint8 alpha2, Uint8* resultingAlpha, float gradientPosition);

			/// Creates and returns a horizontal line
			///
			/// @param size size of the line in pixels
			/// @param color color of the line
			/// @return the line Image
			static Image* getHorizontalLine(int size, Color color);

			/// Creates and returns a horizontal line
			///
			/// @param size size of the line in pixels
			/// @param color color of the line
			/// @param alpha alpha of the image
			/// @return the line Image
			static Image* getHorizontalLine(int size, Color color, Uint8 alpha);

			/// Creates and returns a vertical line
			///
			/// @param size size of the line in pixels
			/// @param color color of the line
			/// @return the line Image
			static Image* getVerticalLine(int size, Color color);

			/// Creates and returns a vertical line
			///
			/// @param size size of the line in pixels
			/// @param color color of the line
			/// @param alpha alpha of the image
			/// @return the line Image
			static Image* getVerticalLine(int size, Color color, Uint8 alpha);

			/// Creates and returns a diagonal line
			///
			/// @param size size of the square that contains the line (in pixels)
			/// @param color color of the line
			/// @param defaultDirection determines whether the diagonal follows or whether the diagonal is opposed to the X and Y axes
			/// @return the line Image
			static Image* getDiagonalLine(int size, Color color, bool defaultDirection);

			/// Creates and returns a diagonal line
			///
			/// @param size size of the square that contains the line (in pixels)
			/// @param color color of the line
			/// @param alpha alpha of the image
			/// @param defaultDirection determines whether the diagonal follows or whether the diagonal is opposed to the X and Y axes
			/// @return the line Image
			static Image* getDiagonalLine(int size, Color color, Uint8 alpha, bool defaultDirection);

			/// Draws a 1-pixel-wide line between two points, defined by (x1,y1) and (x2,y2)
			///
			/// @param drawer the Drawer object to be used
			/// @param x1 x-coordinate of the first point
			/// @param y1 y-coordinate of the first point
			/// @param x2 x-coordinate of the second point
			/// @param y2 y-coordinate of the second point
			/// @param color color of the line
			static void drawLine(Drawer *drawer, int x1, int y1, int x2, int y2, Color color);

			/// Draws a 1-pixel-wide line between two points, p1 and p2
			///
			/// @param drawer the Drawer object to be used
			/// @param p1 IntVector2 representing the first point
			/// @param p2 IntVector2 representing the second point
			/// @param color color of the line
			static void drawLine(Drawer *drawer, IntVector2& p1, IntVector2& p2, Color color);

			/// Creates and returns a rectangle
			///
			/// @param width width of the rectangle in pixels
			/// @param height height of the rectangle in pixels
			/// @param color color of the rectangle
			/// @return the rectangle Image
			static Image* getRectangle(int width, int height, Color color);

			/// Creates and returns a rectangle
			///
			/// @param width width of the rectangle in pixels
			/// @param height height of the rectangle in pixels
			/// @param color color of the rectangle
			/// @param alpha alpha of the image
			/// @return the rectangle Image
			static Image* getRectangle(int width, int height, Color color, Uint8 alpha);

			/// Creates and returns an outlined rectangle
			///
			/// @param width width of the rectangle in pixels
			/// @param height height of the rectangle in pixels
			/// @param color color of the rectangle
			/// @param alpha alpha of the image
			/// @return the outlined rectangle image
			static Image* getRectangleOutline(int width, int height, Color color, Uint8 alpha);

			/// Creates and returns an outlined and filled rectangle
			///
			/// @param width width of the rectangle in pixels
			/// @param height height of the rectangle in pixels
			/// @param fillColor color of the rectangle fill
			/// @param outlineColor color of the rectangle outline
			/// @param alpha alpha of the image
			/// @return the outlined rectangle image
			static Image* getCompleteRectangle(int width, int height, Color fillColor, Color outlineColor, Uint8 alpha);

			/// Creates and returns an gradient filled rectangle
			///
			/// @param width width of the rectangle in pixels
			/// @param height height of the rectangle in pixels
			/// @param color1 first color of the gradient
			/// @param color2 second color of the gradient
			/// @param alpha1 first alpha of the gradient
			/// @param alpha2 second alpha of the gradient
			/// @param vertical whether the gradient is vertical
			/// @return the outlined rectangle image
			static Image* getGradientRectangle(int width, int height, Color color1, Color color2, Uint8 alpha1, Uint8 alpha2, bool vertical);

			/// Creates and returns an gradient filled rectangle
			///
			/// @param width width of the rectangle in pixels
			/// @param height height of the rectangle in pixels
			/// @param color1 first color of the gradient
			/// @param color2 second color of the gradient
			/// @param outlineColor color of the outline
			/// @param alpha1 first alpha of the gradient
			/// @param alpha2 second alpha of the gradient
			/// @param vertical whether the gradient is vertical
			/// @return the outlined rectangle image
			static Image* getGradientCompleteRectangle(int width, int height, Color color1, Color color2, Color outlineColor,
				Uint8 alpha1, Uint8 alpha2, bool vertical);

			/// Creates and returns a circle outline
			///
			/// @param radius radius of the circle in pixels
			/// @param color color of the circle outline
			/// @param alpha alpha of the image
			/// @return the circle outline image
			static Image* getCircleOutline(int radius, Color color, Uint8 alpha);

			/// Creates and returns a filled circle
			///
			/// @param radius radius of the circle in pixels
			/// @param color color of the circle
			/// @param alpha alpha of the image
			/// @return the circle image
			static Image* getCircle(int radius, Color color, Uint8 alpha);

			/// Creates and returns a filled and outlined circle
			///
			/// @param radius radius of the circle in pixels
			/// @param fillColor color of the circle fill
			/// @param outlineColor color of the circle outline
			/// @param alpha alpha of the image
			/// @return the circle image
			static Image* getCompleteCircle(int radius, Color fillColor, Color outlineColor, Uint8 alpha);

			/// Creates and returns a triangle outline
			///
			/// @param size size of the triangle in pixels
			/// @param color color of the triangle outline
			/// @param type one of the following values, AGL_TRIANGLE_TOPLEFT, AGL_TRIANGLE_TOPRIGHT, AGL_TRIANGLE_BOTTOMLEFT, AGL_TRIANGLE_BOTTOMRIGHT,
			/// indicating the position of the right angle
			/// @param alpha alpha of the image
			/// @return the triangle image
			static Image* getTriangleOutline(int size, Color color, char type, Uint8 alpha);

			/// Creates and returns a triangle
			///
			/// @param size size of the triangle in pixels
			/// @param color color of the triangle
			/// @param type one of the following values, AGL_TRIANGLE_TOPLEFT, AGL_TRIANGLE_TOPRIGHT, AGL_TRIANGLE_BOTTOMLEFT, AGL_TRIANGLE_BOTTOMRIGHT,
			/// indicating the position of the right angle
			/// @param alpha alpha of the image
			/// @return the triangle image
			static Image* getTriangle(int size, Color color, char type, Uint8 alpha);

			/// Creates and returns a filled and outlined triangle
			///
			/// @param size size of the triangle in pixels
			/// @param fillColor color of the triangle fill
			/// @param outlineColor color of the triangle outline
			/// @param type one of the following values, AGL_TRIANGLE_TOPLEFT, AGL_TRIANGLE_TOPRIGHT, AGL_TRIANGLE_BOTTOMLEFT, AGL_TRIANGLE_BOTTOMRIGHT,
			/// indicating the position of the right angle
			/// @param alpha alpha of the image
			/// @return the triangle image
			static Image* getCompleteTriangle(int size, Color fillColor, Color outlineColor, char type, Uint8 alpha);

			/// Creates and returns a rectangle with rounded corners
			///
			/// @param width width of the rectangle in pixels
			/// @param height height of the rectangle in pixels
			/// @param radius radius of the corners
			/// @param color color of the rectangle
			/// @return the rectangle Image
			static Image* getRoundedRectangle(int width, int height, int radius, Color color);

			/// Inverts the colors of an image
			///
			/// @param image the image to have the colors inverted
			static void invertColors(Image* image);

			/// Applies a filter with the specified color
			///
			/// @param image the image to have the colors inverted
			/// @param color color of the filter
			static void applyColorFilter(Image* image, Color color);

			/// Applies a filter with the specified color
			///
			/// @param image the image to have the colors inverted
			/// @param color color of the filter
			/// @param alpha alpha of the filter
			static void applyColorFilter(Image* image, Color color, Uint8 alpha);
			
			/// Adjusts the saturation of the given image by the specified amount and returns a new image
			///
			/// @param amount a number from 0 to 1 indicating saturation. 0 is for grayscale, while 1 leaves the image unchanged
			/// @return the resulting image
			static Image* saturation(Image *image, float amount);
			
			/// Adjusts the lightness of the given image by the specified amount and returns a new image
			///
			/// @param amount a number from -1 to 1 indicating lightness. -1 is completely black, 1, completely white, and 0 leaves the image unchanged
			/// @return the resulting image
			static Image* lightness(Image *image, float amount);

			/// Overlap two images, returning a new image
			///
			/// @param backImage the base image
			/// @param frontImage the image that will be placed over the base image
			/// @param relativePosition position of the front image relatively to the back image
			/// @return the resulting image
			static Image* overlapImages(Image* backImage, Image* frontImage, IntVector2 &relativePosition);

			/// Overlap two images, returning a new image
			///
			/// @param backImage the base image
			/// @param frontImage the image that will be placed over the base image
			/// @param relativePosition position of the front image relatively to the back image
			/// @param considerAlpha whether the overlapping should consider the alpha of the frontImage, letting the underlying image appear when a pixel is not opaque
			/// @return the resulting image
			static Image* overlapImages(Image* backImage, Image* frontImage, IntVector2 &relativePosition, bool considerAlpha);

			/// Crops an image
			///
			/// @param image the base image
			/// @param x top-left X coordinate
			/// @param y top-left Y coordinate
			/// @param width width of the cropping
			/// @param height height of the cropping
			/// @return the resulting cropping of the image
			static Image* crop(Image* image, int x, int y, int width, int height);

			/// Replaces a color with another (respecting tones' variations)
			///
			/// @param image the base image
			/// @param oldColor the color to be replaced
			/// @param newColor the replacing color
			static void replaceGradient(Image* image, Color oldColor, Color newColor);

			/// Replaces a color with another (respecting tones' variations)
			///
			/// @param image the base image
			/// @param oldColor the color to be replaced
			/// @param newColor the replacing color
			/// @param tolerance a number from 0 to 255 (recommended 20)
			static void replaceGradient(Image* image, Color oldColor, Color newColor, float tolerance);

			/// Replaces a color with another (respecting tones' variations)
			///
			/// @param image the base image
			/// @param oldColor1 the first color of the gradient to be replaced
			/// @param oldColor2 the second color of the gradient to be replaced
			/// @param newColor1 the first color of the replacing gradient
			/// @param newColor2 the second color of the replacing gradient
			/// @param tolerance a number from 0 to 255 (recommended 20)
			static void replaceGradient(Image* image, Color oldColor1, Color oldColor2, Color newColor1, Color newColor2, float tolerance);

			/// Flips an image
			///
			/// @param image the base image
			/// @param horizontal whether the image should be flipped horizontally (false for vertical)
			static void flip(Image* image, bool horizontal);

			/// Resizes an image
			///
			/// @param image the base image
			/// @param width the new width
			/// @param height the new height
			static void resize(Image* image, int width, int height);

			/// Rotates an image by the specified angle
			///
			/// @param image the image to be rotated
			/// @param angle the angle in degrees
			static void rotate(Image* image, float angle);

			/// Draws an image with the specified rotation
			///
			/// @param drawer the Drawer object to be used
			/// @param image the image to be rotated
			/// @param position position where the rotation origin will be drawn (top left corner)
			/// @param angle the angle in degrees
			static void drawRotated(Drawer* drawer, Image* image, IntVector2& position, float angle);

			/// Inclines an image by the specified amount of pixels, horizontally or vertically
			///
			/// @param image the image to be skewed
			/// @param vertical true for vertical inclination (horizontal otherwise)
			/// @param amount difference between the edges of the inclination in pixels
			static void incline(Image *image, bool vertical, short amount);

			/// Performs a gaussian blur in the image, with the specified radius
			///
			/// @param image the image to be blurred
			/// @param radius range of the blurring in pixels. If less than or equal to zero, the function does nothing
			static Image* blur(Image *image, short radius);

			/// Creates and returns the outline of a regular polygon with the specified number of edges
			///
			/// @param edges number of edges of the polygon
			/// @param edgeSize length of each edge in pixels
			/// @param color color of the outline
			static Image* getPolygonOutline(short edges, short edgeSize, Color color);
	};
}

#endif
