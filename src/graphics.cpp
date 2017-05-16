#include <iostream>
#include <cmath>

#include "graphics.h"

using namespace std;

int AGL::Graphics::roundToEven(float f)
{
	int round = floor(f + 0.5);
	if (round % 2 == 1)
	{
		if (f > round) round++;
		else round--;
	}
	return round;
}

AGL::Color AGL::Graphics::lerp(AGL::Color color1, AGL::Color color2, float gradientPosition)
{
	int minR = color1.red < color2.red ? color1.red : color2.red;
	int maxR = color1.red > color2.red ? color1.red : color2.red;
	int minG = color1.green < color2.green ? color1.green : color2.green;
	int maxG = color1.green > color2.green ? color1.green : color2.green;
	int minB = color1.blue < color2.blue ? color1.blue : color2.blue;
	int maxB = color1.blue > color2.blue ? color1.blue : color2.blue;

	AGL::Color result;
	result.red = color1.red < color2.red ? (maxR - minR) * gradientPosition + minR : maxR - (maxR - minR) * gradientPosition;
	result.green = color1.green < color2.green ? (maxG - minG) * gradientPosition + minG : maxG - (maxG - minG) * gradientPosition;
	result.blue = color1.blue < color2.blue ? (maxB - minB) * gradientPosition + minB : maxB - (maxB - minB) * gradientPosition;

	return result;
}

AGL::Color AGL::Graphics::lerp(AGL::Color color1, AGL::Color color2, Uint8 alpha1, Uint8 alpha2, Uint8* resultingAlpha, float gradientPosition)
{
	int minR = color1.red < color2.red ? color1.red : color2.red;
	int maxR = color1.red > color2.red ? color1.red : color2.red;
	int minG = color1.green < color2.green ? color1.green : color2.green;
	int maxG = color1.green > color2.green ? color1.green : color2.green;
	int minB = color1.blue < color2.blue ? color1.blue : color2.blue;
	int maxB = color1.blue > color2.blue ? color1.blue : color2.blue;
	int minA = alpha1 < alpha2 ? alpha1 : alpha2;
	int maxA = alpha1 > alpha2 ? alpha1 : alpha2;

	AGL::Color result;
	result.red = color1.red < color2.red ? (maxR - minR) * gradientPosition + minR : maxR - (maxR - minR) * gradientPosition;
	result.green = color1.green < color2.green ? (maxG - minG) * gradientPosition + minG : maxG - (maxG - minG) * gradientPosition;
	result.blue = color1.blue < color2.blue ? (maxB - minB) * gradientPosition + minB : maxB - (maxB - minB) * gradientPosition;
	*resultingAlpha = alpha1 < alpha2 ? (maxA - minA) * gradientPosition + minA : maxA - (maxA - minA) * gradientPosition;

	return result;
}

AGL::Image* AGL::Graphics::getHorizontalLine(int size, Color color)
{
	return getHorizontalLine(size, color, 255);
}

AGL::Image* AGL::Graphics::getHorizontalLine(int size, Color color, Uint8 alpha)
{
	Image* image = new Image(size, 1);

	for(int i = 0; i < image->size->x; i++)
		image->setPixel(i, 0, color.red, color.green, color.blue, alpha);

	return image;
}

AGL::Image* AGL::Graphics::getVerticalLine(int size, Color color)
{
	return getVerticalLine(size, color, 255);
}

AGL::Image* AGL::Graphics::getVerticalLine(int size, Color color, Uint8 alpha)
{
	Image* image = new Image(1, size);

	for(int i = 0; i < image->size->y; i++)
		image->setPixel(0, i, color.red, color.green, color.blue, alpha);

	return image;
}

AGL::Image* AGL::Graphics::getDiagonalLine(int size, Color color, bool defaultDirection)
{
	return getDiagonalLine(size, color, 255, defaultDirection);
}

AGL::Image* AGL::Graphics::getDiagonalLine(int size, Color color, Uint8 alpha, bool defaultDirection)
{
	Image* image = new Image(size, size);

	if(defaultDirection)
		for(int i = 0; i < image->size->x; i++)
			image->setPixel(i, i, color.red, color.green, color.blue, alpha);
	else
		for(int i = 0; i < image->size->x; i++)
			image->setPixel(i, size - i - 1, color.red, color.green, color.blue, alpha);

	return image;
}

void AGL::Graphics::drawLine(AGL::Drawer *drawer, int x1, int y1, int x2, int y2, Color color)
{
	int minX = x1 > x2 ? x2 : x1, maxX = x1 > x2 ? x1 : x2, minY = y1 > y2 ? y2 : y1, maxY = y1 > y2 ? y1 : y2;
	IntVector2 pos(minX, minY);

	AGL::Image *line = NULL;
	if (minX == maxX)
		line = getVerticalLine(maxY - minY + 1, color);
	else if (minY == maxY)
		line = getHorizontalLine(maxX - minX + 1, color);
	else if ((maxY - minY) / (maxX - minX) > 1)
	{
		line = getVerticalLine(maxY - minY + 1, color);
		bool negative = ((minX == x1 && minY == y1) || (minX == x2 && minY == y2));
		incline(line, false, negative ? minX - maxX : maxX - minX);
	}
	else
	{
		line = getHorizontalLine(maxX - minX + 1, color);
		bool negative = ((minX == x1 && minY == y1) || (minX == x2 && minY == y2));
		incline(line, true, negative ? minY - maxY : maxY - minY);
	}
	drawer->draw(line, pos);
	delete line;
}

void AGL::Graphics::drawLine(AGL::Drawer *drawer, AGL::IntVector2& p1, AGL::IntVector2& p2, Color color)
{
	drawLine(drawer, p1.x, p1.y, p2.x, p2.y, color);
}

AGL::Image* AGL::Graphics::getRectangle(int width, int height, Color color)
{
	return getRectangle(width, height, color, 255);
}

AGL::Image* AGL::Graphics::getRectangle(int width, int height, Color color, Uint8 alpha)
{
	Image* image = new Image(width, height);

	for(int i = 0; i < image->size->y; i++)
		for(int j = 0; j < image->size->x; j++)
			image->setPixel(j, i, color.red, color.green, color.blue, alpha);

	return image;
}

AGL::Image* AGL::Graphics::getRectangleOutline(int width, int height, Color color, Uint8 alpha)
{
	Image* image = new Image(width, height);

	for(int i = 0; i < image->size->y; i++)
	{
		image->setPixel(0, i, color.red, color.green, color.blue, alpha);
		image->setPixel(image->size->x - 1, i, color.red, color.green, color.blue, alpha);
	}

	for(int i = 0; i < image->size->x; i++)
	{
		image->setPixel(i, 0, color.red, color.green, color.blue, alpha);
		image->setPixel(i, image->size->y - 1, color.red, color.green, color.blue, alpha);
	}

	return image;
}

AGL::Image* AGL::Graphics::getCompleteRectangle(int width, int height, Color fillColor, Color outlineColor, Uint8 alpha)
{
	Image* image = new Image(width, height);

	for(int i = 0; i < image->size->y; i++)
	{
		image->setPixel(0, i, outlineColor.red, outlineColor.green, outlineColor.blue, alpha);
		image->setPixel(image->size->x - 1, i, outlineColor.red, outlineColor.green, outlineColor.blue, alpha);
	}

	for(int i = 0; i < image->size->x; i++)
	{
		image->setPixel(i, 0, outlineColor.red, outlineColor.green, outlineColor.blue, alpha);
		image->setPixel(i, image->size->y - 1, outlineColor.red, outlineColor.green, outlineColor.blue, alpha);
	}

	for(int i = 1; i < image->size->y - 1; i++)
		for(int j = 1; j < image->size->x - 1; j++)
			image->setPixel(j, i, fillColor.red, fillColor.green, fillColor.blue, alpha);

	return image;
}

AGL::Image* AGL::Graphics::getGradientRectangle(int width, int height, AGL::Color color1, AGL::Color color2,
	Uint8 alpha1, Uint8 alpha2, bool vertical)
{
	Image* image = new Image(width, height);

	if(vertical)
	{
		for (int i = 0; i < height; i++)
			for (int j = 0; j < width; j++)
			{
				float gp = (float)i / (float)height;
				AGL::Color c = lerp(color1, color2, gp);
				Uint8 a = alpha1 < alpha2 ? alpha1 + gp * (alpha2 - alpha1) : alpha1 - gp * (alpha1 - alpha2);
				image->setPixel(j, i, c.red, c.green, c.blue, a);
			}
	}
	else
	{
		for (int i = 0; i < height; i++)
			for (int j = 0; j < width; j++)
			{
				float gp = (float)j / (float)width;
				AGL::Color c = lerp(color1, color2, gp);
				Uint8 a = alpha1 < alpha2 ? alpha1 + gp * (alpha2 - alpha1) : alpha1 - gp * (alpha1 - alpha2);
				image->setPixel(j, i, c.red, c.green, c.blue, a);
			}
	}

	return image;
}

AGL::Image* AGL::Graphics::getGradientCompleteRectangle(int width, int height, AGL::Color color1, AGL::Color color2, AGL::Color outlineColor, Uint8 alpha1, Uint8 alpha2, bool vertical)
{
	Image* image = new Image(width, height);

	for(int i = 0; i < image->size->y; i++)
	{
		Uint8 a1 = alpha1;
		Uint8 a2 = alpha2;
		float gp = (float)i / (float)height;

		if(vertical) a1 = a2 = alpha1 < alpha2 ? alpha1 + gp * (alpha2 - alpha1) : alpha1 - gp * (alpha1 - alpha2);

		image->setPixel(0, i, outlineColor.red, outlineColor.green, outlineColor.blue, a1);
		image->setPixel(image->size->x - 1, i, outlineColor.red, outlineColor.green, outlineColor.blue, a2);
	}

	for(int i = 0; i < image->size->x; i++)
	{
		Uint8 a1 = alpha1;
		Uint8 a2 = alpha2;
		float gp = (float)i / (float)width;

		if(!vertical) a1 = a2 = alpha1 < alpha2 ? alpha1 + gp * (alpha2 - alpha1) : alpha1 - gp * (alpha1 - alpha2);

		image->setPixel(i, 0, outlineColor.red, outlineColor.green, outlineColor.blue, a1);
		image->setPixel(i, image->size->y - 1, outlineColor.red, outlineColor.green, outlineColor.blue, a2);
	}

	if(vertical)
	{
		for (int i = 1; i < height - 1; i++)
			for (int j = 1; j < width - 1; j++)
			{
				float gp = (float)i / (float)height;
				AGL::Color c = lerp(color1, color2, gp);
				Uint8 a = alpha1 < alpha2 ? alpha1 + gp * (alpha2 - alpha1) : alpha1 - gp * (alpha1 - alpha2);
				image->setPixel(j, i, c.red, c.green, c.blue, a);
			}
	}
	else
	{
		for (int i = 1; i < height - 1; i++)
			for (int j = 1; j < width - 1; j++)
			{
				float gp = (float)j / (float)width;
				AGL::Color c = lerp(color1, color2, gp);
				Uint8 a = alpha1 < alpha2 ? alpha1 + gp * (alpha2 - alpha1) : alpha1 - gp * (alpha1 - alpha2);
				image->setPixel(j, i, c.red, c.green, c.blue, a);
			}
	}

	return image;
}

void AGL::Graphics::setCircleOutline(int radius, AGL::Color color, Image* image, Uint8 alpha)
{
	int diameter = 2 * radius;
	for (int i = 0; i < radius; i++)
	{
		float c = cos(asin((float)i / (float)radius));
		int lineSize = roundToEven(2 * c * radius);
		if (i == radius - 1)
			for (int j = (diameter - lineSize) / 2; j < (diameter + lineSize) / 2; j++)
			{
				image->setPixel(j, radius - i - 1, color.red, color.green, color.blue, alpha);
				image->setPixel(j, radius + i, color.red, color.green, color.blue, alpha);
			}
		else
		{
			c = cos(asin((float)(i + 1) / (float)radius));
			int lineSize2 = roundToEven(2 * c * radius);
			if (lineSize == lineSize2)
			{
				image->setPixel((diameter - lineSize) / 2, radius - i - 1, color.red, color.green, color.blue, alpha);
				image->setPixel((diameter + lineSize) / 2 - 1, radius - i - 1, color.red, color.green, color.blue, alpha);
				image->setPixel((diameter - lineSize) / 2, radius + i, color.red, color.green, color.blue, alpha);
				image->setPixel((diameter + lineSize) / 2 - 1, radius + i, color.red, color.green, color.blue, alpha);
			}
			else
			{
				for (int j = (diameter - lineSize) / 2; j < (diameter - lineSize2) / 2; j++)
				{
					image->setPixel(j, radius - i - 1, color.red, color.green, color.blue, alpha);
					image->setPixel(j, radius + i, color.red, color.green, color.blue, alpha);
				}
				for (int j = (diameter + lineSize2) / 2; j < (diameter + lineSize) / 2; j++)
				{
					image->setPixel(j, radius - i - 1, color.red, color.green, color.blue, alpha);
					image->setPixel(j, radius + i, color.red, color.green, color.blue, alpha);
				}
			}
		}
	}
}

AGL::Image* AGL::Graphics::getCircleOutline(int radius, AGL::Color color, Uint8 alpha)
{
	// Creating the surface
	int diameter = 2 * radius;
	Image* image = new Image(diameter, diameter);

	// Creating the circle
	setCircleOutline(radius, color, image, alpha);

	return image;
}

AGL::Image* AGL::Graphics::getCircle(int radius, AGL::Color color, Uint8 alpha)
{
	// Creating the surface
	int diameter = 2 * radius;
	Image* image = new Image(diameter, diameter);

	// Creating the circle
	for (int i = 0; i < radius; i++)
	{
		float c = cos(asin((float)i / (float)radius));
		int lineSize = roundToEven(2 * c * radius);
		for (int j = (diameter - lineSize) / 2; j < (diameter + lineSize) / 2; j++)
		{
			image->setPixel(j, radius - i - 1, color.red, color.green, color.blue, alpha);
			image->setPixel(j, radius + i, color.red, color.green, color.blue, alpha);
		}
	}

	return image;
}

AGL::Image* AGL::Graphics::getCompleteCircle(int radius, AGL::Color fillColor, AGL::Color outlineColor, Uint8 alpha)
{
	// Creating the surface
	int diameter = 2 * radius;
	Image* image = new Image(diameter, diameter);

	// Creating the circle
	for (int i = 0; i < radius; i++)
	{
		float c = cos(asin((float)i / (float)radius));
		int lineSize = roundToEven(2 * c * radius);
		for (int j = (diameter - lineSize) / 2; j < (diameter + lineSize) / 2; j++)
		{
			image->setPixel(j, radius - i - 1, fillColor.red, fillColor.green, fillColor.blue, alpha);
			image->setPixel(j, radius + i, fillColor.red, fillColor.green, fillColor.blue, alpha);
		}
	}
	setCircleOutline(radius, outlineColor, image, alpha);

	return image;
}

AGL::Image* AGL::Graphics::getTriangleOutline(int size, AGL::Color color, char type, Uint8 alpha)
{
	// Creating the surface
	Image* image = new Image(size, size);

	// Creating the triangle
	if (type == AGL_TRIANGLE_TOPLEFT || type == AGL_TRIANGLE_TOPRIGHT)
		for(int i = 0; i < size; i++)
			image->setPixel(i, 0, color.red, color.green, color.blue, alpha);
	else
		for(int i = 0; i < size; i++)
			image->setPixel(i, size - 1, color.red, color.green, color.blue, alpha);

	if (type == AGL_TRIANGLE_TOPLEFT || type == AGL_TRIANGLE_BOTTOMLEFT)
		for(int i = 0; i < size; i++)
			image->setPixel(0, i, color.red, color.green, color.blue, alpha);
	else
		for(int i = 0; i < size; i++)
			image->setPixel(size - 1, i, color.red, color.green, color.blue, alpha);

	if (type == AGL_TRIANGLE_TOPRIGHT || type == AGL_TRIANGLE_BOTTOMLEFT)
		for(int i = 0; i < size; i++)
			image->setPixel(i, i, color.red, color.green, color.blue, alpha);
	else
		for(int i = 0; i < size; i++)
			image->setPixel(i, size - i - 1, color.red, color.green, color.blue, alpha);

	return image;
}

AGL::Image* AGL::Graphics::getTriangle(int size, AGL::Color color, char type, Uint8 alpha)
{
	// Creating the surface
	Image* image = new Image(size, size);

	// Creating the triangle
	int line = (type == AGL_TRIANGLE_TOPLEFT || type == AGL_TRIANGLE_TOPRIGHT) ? size : 1;
	for (int i = 0; i < size; i++)
	{
		int lineStart = (type == AGL_TRIANGLE_TOPRIGHT || type == AGL_TRIANGLE_BOTTOMRIGHT) ? size - line : 0;
		for (int j = lineStart; j < line + lineStart; j++)
			image->setPixel(j, i, color.red, color.green, color.blue, alpha);
		line += (type == AGL_TRIANGLE_TOPLEFT || type == AGL_TRIANGLE_TOPRIGHT) ? -1 : 1;
	}

	return image;
}

AGL::Image* AGL::Graphics::getCompleteTriangle(int size, AGL::Color fillColor, AGL::Color outlineColor, char type, Uint8 alpha)
{
	// Creating the surface
	Image* image = new Image(size, size);

	// fill
	int line = (type == AGL_TRIANGLE_TOPLEFT || type == AGL_TRIANGLE_TOPRIGHT) ? size : 1;
	for (int i = 0; i < size; i++)
	{
		int lineStart = (type == AGL_TRIANGLE_TOPRIGHT || type == AGL_TRIANGLE_BOTTOMRIGHT) ? size - line : 0;
		for (int j = lineStart; j < line + lineStart; j++)
			image->setPixel(j, i, fillColor.red, fillColor.green, fillColor.blue, alpha);
		line += (type == AGL_TRIANGLE_TOPLEFT || type == AGL_TRIANGLE_TOPRIGHT) ? -1 : 1;
	}

	// outline
	if (type == AGL_TRIANGLE_TOPLEFT || type == AGL_TRIANGLE_TOPRIGHT)
		for(int i = 0; i < size; i++)
			image->setPixel(i, 0, outlineColor.red, outlineColor.green, outlineColor.blue, alpha);
	else
		for(int i = 0; i < size; i++)
			image->setPixel(i, size - 1, outlineColor.red, outlineColor.green, outlineColor.blue, alpha);

	if (type == AGL_TRIANGLE_TOPLEFT || type == AGL_TRIANGLE_BOTTOMLEFT)
		for(int i = 0; i < size; i++)
			image->setPixel(0, i, outlineColor.red, outlineColor.green, outlineColor.blue, alpha);
	else
		for(int i = 0; i < size; i++)
			image->setPixel(size - 1, i, outlineColor.red, outlineColor.green, outlineColor.blue, alpha);

	if (type == AGL_TRIANGLE_TOPRIGHT || type == AGL_TRIANGLE_BOTTOMLEFT)
		for(int i = 0; i < size; i++)
			image->setPixel(i, i, outlineColor.red, outlineColor.green, outlineColor.blue, alpha);
	else
		for(int i = 0; i < size; i++)
			image->setPixel(i, size - i - 1, outlineColor.red, outlineColor.green, outlineColor.blue, alpha);

	return image;
}

AGL::Image* AGL::Graphics::getRoundedRectangle(int width, int height, int radius, AGL::Color color)
{
	// Creating the surface
	AGL::Image* circle = getCircle(radius, color, 255);
	IntVector2 v1(width - 2 * radius, 0);
	IntVector2 v2(0, height - 2 * radius);
	IntVector2 v3(width - 2 * radius, height - 2 * radius);
	AGL::Image* rectangle = overlapImages(circle, circle, v1);
	rectangle = overlapImages(rectangle, circle, v2);
	rectangle = overlapImages(rectangle, circle, v3);
	delete(circle);

	AGL::Image* rect1 = getRectangle(width - 2 * radius, height, color);
	AGL::Image* rect2 = getRectangle(width, height - 2 * radius, color);
	IntVector2 v4(radius, 0);
	IntVector2 v5(0, radius);
	rectangle = overlapImages(rectangle, rect1, v4);
	rectangle = overlapImages(rectangle, rect2, v5);
	delete(rect1);
	delete(rect2);

	// returning the image
	return rectangle;
}

void AGL::Graphics::invertColors(AGL::Image* image)
{
	image->lock();

	for(int i = 0; i < image->size->y; i++)
	{
		for(int j = 0; j < image->size->x; j++)
		{
			int offset = i * image->size->x + j;
			Uint8 r2,g2,b2,a2;
			image->getPixel(j, i, &r2, &g2, &b2, &a2);

			r2 = 255 - r2;
			g2 = 255 - g2;
			b2 = 255 - b2;

			image->setPixel(j, i, r2, g2, b2, a2);
		}
	}

	image->unlock();
}

void AGL::Graphics::applyColorFilter(AGL::Image* image, AGL::Color color)
{
	// If color is white, all original colors are kept.
	if (color.red == 255 && color.blue == 255 && color.green == 255)
		return;

	image->lock();

	for(int i = 0; i < image->size->y; i++){
		for(int j = 0; j < image->size->x; j++){
			int offset = i * image->size->x + j;
			Uint8 r2,g2,b2,a2;
			image->getPixel(j, i, &r2, &g2, &b2, &a2);

			r2 = r2 * (color.red/255.0);
			g2 = g2 * (color.green/255.0);
			b2 = b2 * (color.blue/255.0);

			image->setPixel(j, i, r2, g2, b2, a2);
		}
	}

	image->unlock();
}

void AGL::Graphics::applyColorFilter(Image* image, Color color, Uint8 alpha)
{
	// If color is white, all original colors are kept.
	if (color.red == 255 && color.blue == 255 && color.green == 255 && alpha == 255)
		return;

	image->lock();

	for(int i = 0; i < image->size->y; i++){
		for(int j = 0; j < image->size->x; j++){
			Uint8 r2,g2,b2,a2;
			image->getPixel(j, i, &r2, &g2, &b2, &a2);

			r2 = r2 * (color.red/255.0);
			g2 = g2 * (color.green/255.0);
			b2 = b2 * (color.blue/255.0);
			a2 = a2 * (alpha/255.0);

			image->setPixel(j, i, r2, g2, b2, a2);
		}
	}

	image->unlock();
}

AGL::Image* AGL::Graphics::saturation(AGL::Image *image, float amount)
{
	if (amount < 0.0f || amount > 1.000001f) return NULL;
	if (amount == 1.0f) return new AGL::Image(image);

	AGL::Image *result = new AGL::Image(image->size->x, image->size->y);
	image->lock();
	result->lock();
	for (short i = 0; i < image->size->x; i++)
		for (short j = 0; j < image->size->y; j++)
		{
			Uint8 r, g, b, a, r2, g2, b2;
			image->getPixel(i, j, &r, &g, &b, &a);
			float avg = (float(r) + g + b) / 3;
			r2 = Uint8(avg + amount * (r - avg));
			g2 = Uint8(avg + amount * (g - avg));
			b2 = Uint8(avg + amount * (b - avg));
			result->setPixel(i, j, r2, g2, b2, a);
		}
	result->unlock();
	image->unlock();
	return result;
}

AGL::Image* AGL::Graphics::lightness(AGL::Image *image, float amount)
{
	if (amount < -1.000001f || amount > 1.000001f) return NULL;
	if (amount == 0.0f) return new AGL::Image(image);

	AGL::Image *result = new AGL::Image(image->size->x, image->size->y);
	image->lock();
	result->lock();
	for (short i = 0; i < image->size->x; i++)
		for (short j = 0; j < image->size->y; j++)
		{
			Uint8 r, g, b, a, r2, g2, b2;
			image->getPixel(i, j, &r, &g, &b, &a);
			if (amount > 0)
			{
				r2 = Uint8(r + amount * (255 - r));
				g2 = Uint8(g + amount * (255 - g));
				b2 = Uint8(b + amount * (255 - b));
			}
			else
			{
				r2 = Uint8(r * (amount + 1));
				g2 = Uint8(g * (amount + 1));
				b2 = Uint8(b * (amount + 1));
			}
			result->setPixel(i, j, r2, g2, b2, a);
		}
	result->unlock();
	image->unlock();
	return result;
}

AGL::Image* AGL::Graphics::overlapImages(AGL::Image* backImage, AGL::Image* frontImage, AGL::IntVector2 &relativePosition)
{
	return overlapImages(backImage, frontImage, relativePosition, true);
}

AGL::Image* AGL::Graphics::overlapImages(AGL::Image* backImage, AGL::Image* frontImage, AGL::IntVector2 &relativePosition, bool considerAlpha)
{
	// creating the surface
	int width, height;

	int minX = relativePosition.x < 0 ? relativePosition.x : 0;
	int maxX = relativePosition.x + frontImage->size->x < backImage->size->x ? backImage->size->x : relativePosition.x + frontImage->size->x;
	int minY = relativePosition.y < 0 ? relativePosition.y : 0;
	int maxY = relativePosition.y + frontImage->size->y < backImage->size->y ? backImage->size->y : relativePosition.y + frontImage->size->y;

	Image* image = new Image(maxX - minX, maxY - minY);

	// overlaping
	for(int i = 0; i < image->size->y; i++)
		for(int j = 0; j < image->size->x; j++)
		{
			if(j >= abs(minX) && j < abs(minX) + backImage->size->x && i >= abs(minY) && i < abs(minY) + backImage->size->y) // tem ponto da back image
			{
				if(j >= abs(minX) + relativePosition.x && j < abs(minX) + relativePosition.x + frontImage->size->x &&
					i >= abs(minY) + relativePosition.y && i < abs(minY) + relativePosition.y + frontImage->size->y) // tem ponto da front image
				{
					if (considerAlpha)
					{
						AGL::Color c1, c2;
						Uint8 alpha1, alpha2;

						backImage->getPixel(j - abs(minX), i - abs(minY), &c1.red, &c1.green, &c1.blue, &alpha1);
						frontImage->getPixel(j - (abs(minX) + relativePosition.x), i - (abs(minY) + relativePosition.y),
														&c2.red, &c2.green, &c2.blue, &alpha2);

						AGL::Color c = lerp(c1, c2, alpha2 / 255.0);
						image->setPixel(j, i, c.red, c.green, c.blue, (alpha1 + alpha2 > 255 ? 255 : alpha1 + alpha2));
					}
					else
					{
						Uint8 r, g, b, a;
						frontImage->getPixel(j - (abs(minX) + relativePosition.x), i - (abs(minY) + relativePosition.y), &r, &g, &b, &a);
						image->setPixel(j, i, r, g, b, a);
					}
				}
				else
				{
					AGL::Color c1;
					Uint8 alpha1;

					backImage->getPixel(j - abs(minX), i - abs(minY), &c1.red, &c1.green, &c1.blue, &alpha1);

					image->setPixel(j, i, c1.red, c1.green, c1.blue, alpha1);
				}
			}
			else if(j >= abs(minX) + relativePosition.x && j < abs(minX) + relativePosition.x + frontImage->size->x &&
					  i >= abs(minY) + relativePosition.y && i < abs(minY) + relativePosition.y + frontImage->size->y)
			{
				AGL::Color c2;
				Uint8 alpha2;

				frontImage->getPixel(j - (abs(minX) + relativePosition.x), i - (abs(minY) + relativePosition.y),
												&c2.red, &c2.green, &c2.blue, &alpha2);

				image->setPixel(j, i, c2.red, c2.green, c2.blue, alpha2);
			}
		}

	return image;
}

AGL::Image* AGL::Graphics::crop(AGL::Image* image, int x, int y, int width, int height)
{
	// Creating the surface
	Image* result = new Image(width, height);

	// Cropping
	for(int i = y; i < y + height; i++)
		for(int j = x; j < x + width; j++)
		{
			AGL::Color c;
			Uint8 alpha;

			image->getPixel(j, i, &c.red, &c.green, &c.blue, &alpha);
			result->setPixel(j - x, i - y, c.red, c.green, c.blue, alpha);
		}

	return result;
}

void AGL::Graphics::replaceGradient(AGL::Image* image, AGL::Color oldColor, AGL::Color newColor)
{
	AGL::Color black = {0, 0, 0};
	replaceGradient(image, oldColor, black, newColor, black, 20);
}

void AGL::Graphics::replaceGradient(AGL::Image* image, AGL::Color oldColor, AGL::Color newColor, float tolerance)
{
	AGL::Color black = {0, 0, 0};
	replaceGradient(image, oldColor, black, newColor, black, tolerance);
}

void AGL::Graphics::replaceGradient(AGL::Image* image, AGL::Color oldColor1, AGL::Color oldColor2, AGL::Color newColor1,
	AGL::Color newColor2, float tolerance)
{
	short rvar = abs(oldColor2.red - oldColor1.red);
	short gvar = abs(oldColor2.green - oldColor1.green);
	short bvar = abs(oldColor2.blue - oldColor1.blue);

	char maj;
	if(gvar > rvar)
	{
		if(bvar > gvar) maj = 'b';
		else maj = 'g';
	}
	else if(bvar > rvar) maj = 'b';
	else maj = 'r';

	bool c1max = (maj == 'r' && oldColor1.red > oldColor2.red) ||
					 (maj == 'g' && oldColor1.green > oldColor2.green) ||
					 (maj == 'b' && oldColor1.blue > oldColor2.blue);

	short min;

	if(c1max)
	{
		if(maj == 'r') min = oldColor2.red;
		else if(maj == 'g') min = oldColor2.green;
		else if(maj == 'b') min = oldColor2.blue;
	}
	else
	{
		if(maj == 'r') min = oldColor1.red;
		else if(maj == 'g') min = oldColor1.green;
		else if(maj == 'b') min = oldColor1.blue;
	}

	image->lock();

	for(int i = 0; i < image->size->y; i++){
		for(int j = 0; j < image->size->x; j++){
			Uint8 r, g, b, a;
			image->getPixel(j, i, &r, &g, &b, &a);

			AGL::Color c2;

			if(c1max)
				c2 = lerp(oldColor2, oldColor1, (float)((maj == 'r' ? r : (maj == 'g' ? g : b)) - min) / (maj == 'r' ? rvar : (maj == 'g' ? gvar : bvar)));
			else
				c2 = lerp(oldColor1, oldColor2, (float)((maj == 'r' ? r : (maj == 'g' ? g : b)) - min) / (maj == 'r' ? rvar : (maj == 'g' ? gvar : bvar)));

			if((maj == 'r' && c2.green <= (short)g + tolerance && c2.green >= (short)g - tolerance
								&& c2.blue <= (short)b + tolerance && c2.blue >= (short)b - tolerance) ||
				(maj == 'g' && c2.red <= (short)r + tolerance && c2.red >= (short)r - tolerance
								&& c2.blue <= (short)b + tolerance && c2.blue >= (short)b - tolerance) ||
				(maj == 'b' && c2.green <= (short)g + tolerance && c2.green >= (short)g - tolerance
								&& c2.red <= (short)r + tolerance && c2.red >= (short)r - tolerance))
			{
				AGL::Color c1;

				if(c1max)
					c1 = lerp(newColor2, newColor1,
						(float)((maj == 'r' ? r : (maj == 'g' ? g : b)) - min) / (maj == 'r' ? rvar : (maj == 'g' ? gvar : bvar)));
				else
					c1 = lerp(newColor1, newColor2,
						(float)((maj == 'r' ? r : (maj == 'g' ? g : b)) - min) / (maj == 'r' ? rvar : (maj == 'g' ? gvar : bvar)));

				image->setPixel(j, i, c1.red, c1.green, c1.blue, a);
			}
		}
	}

	image->unlock();
}

void AGL::Graphics::flip(AGL::Image* image, bool horizontal)
{
	image->lock();

	if (horizontal) {
		for(int i = 0; i < image->size->y; i++) {
			for(int j = 0; j < image->size->x / 2; j++) {
				Uint8 r, g, b, a, r2, g2, b2, a2;
				image->getPixel(j, i, &r, &g, &b, &a);
				image->getPixel(image->size->x - j - 1, i, &r2, &g2, &b2, &a2);
				image->setPixel(image->size->x - j - 1, i, r, g, b, a);
				image->setPixel(j, i, r2, g2, b2, a2);
			}
		}
	} else {
		for(int i = 0; i < image->size->y / 2; i++) {
			for(int j = 0; j < image->size->x; j++) {
				Uint8 r, g, b, a, r2, g2, b2, a2;
				image->getPixel(j, i, &r, &g, &b, &a);
				image->getPixel(j, image->size->y - i - 1, &r2, &g2, &b2, &a2);
				image->setPixel(j, image->size->y - i - 1, r, g, b, a);
				image->setPixel(j, i, r2, g2, b2, a2);
			}
		}
	}

	image->unlock();
}

void AGL::Graphics::resize(AGL::Image* image, int width, int height)
{
	Image* result = new Image(width, height);

	image->lock();
	result->lock();

	if (width >= image->size->x && height >= image->size->y) {
		for(int i = 0; i < image->size->y - 1; i++) {
			for(int j = 0; j < image->size->x - 1; j++) {
				// Pegando os 4 pixels
				Uint8 r1, g1, b1, a1, r2, g2, b2, a2, r3, g3, b3, a3, r4, g4, b4, a4;
				image->getPixel(j, i, &r1, &g1, &b1, &a1);
				image->getPixel(j + 1, i, &r2, &g2, &b2, &a2);
				image->getPixel(j, i + 1, &r3, &g3, &b3, &a3);
				image->getPixel(j + 1, i + 1, &r4, &g4, &b4, &a4);

				// Colocando na imagem maior
				int j1 = (int)(((float)j/(image->size->x - 1)) * (width - 1) + 0.5f),
					i1 = (int)(((float)i/(image->size->y - 1)) * (height - 1) + 0.5f),
					j2 = (int)(((float)(j+1)/(image->size->x - 1)) * (width - 1) + 0.5f),
					i2 = (int)(((float)(i+1)/(image->size->y - 1)) * (height - 1) + 0.5f);

				result->setPixel(j1, i1, r1, g1, b1, a1);
				result->setPixel(j2, i1, r2, g2, b2, a2);
				result->setPixel(j1, i2, r3, g3, b3, a3);
				result->setPixel(j2, i2, r4, g4, b4, a4);

				// Calculando os gradientes
				Uint8 a, ab, ac;
				AGL::Color c1 = {r1, g1, b1}, c2 = {r2, g2, b2}, c3 = {r3, g3, b3}, c4 = {r4, g4, b4};
				for (int k = j1 + 1; k < j2; k++) {
					AGL::Color c = lerp(c1, c2, a1, a2, &a, (float)(k - j1) / (j2 - j1));
					AGL::Color cb = lerp(c3, c4, a3, a4, &ab, (float)(k - j1) / (j2 - j1));
					result->setPixel(k, i1, c.red, c.green, c.blue, a);
					result->setPixel(k, i2, cb.red, cb.green, cb.blue, ab);
					for (int l = i1 + 1; l < i2; l++) {
						AGL::Color cc = lerp(c, cb, a, ab, &ac, (float)(l - i1) / (i2 - i1));
						result->setPixel(k, l, cc.red, cc.green, cc.blue, ac);
					}
				}
				for (int k = i1 + 1; k < i2; k++) {
					AGL::Color c = lerp(c1, c3, a1, a3, &a, (float)(k - i1) / (i2 - i1));
					AGL::Color cb = lerp(c2, c4, a2, a4, &ab, (float)(k - i1) / (i2 - i1));
					result->setPixel(j1, k, c.red, c.green, c.blue, a);
					result->setPixel(j2, k, cb.red, cb.green, cb.blue, ab);
				}
			}
		}
	} else if (width < image->size->x) {
		if (height < image->size->y) {
			float propX = (float)image->size->x / width,
				propY = (float)image->size->y / height;
			for (int i = 0; i < height; i++) {
				for (int j = 0; j < width; j++) {
					int j1 = (int)((float)j * propX + 0.5f),
						i1 = (int)((float)i * propY + 0.5f),
						j2 = (int)((float)(j + 1) * propX + 0.5f),
						i2 = (int)((float)(i + 1) * propY + 0.5f);
					int r = 0, g = 0, b = 0, a = 0;
					for (int k = j1; k < j2; k++) {
						for (int l = i1; l < i2; l++) {
							Uint8 r1, g1, b1, a1;
							image->getPixel(k, l, &r1, &g1, &b1, &a1);
							r += r1;
							g += g1;
							b += b1;
							a += a1;
						}
					}
					int n = (j2 - j1) * (i2 - i1);
					r /= n;
					g /= n;
					b /= n;
					a /= n;
					result->setPixel(j, i, r, g, b, a);
				}
			}
		} else {
			float propX = (float)image->size->x / width;
			for (int i = 0; i < image->size->y; i++) {
				for (int j = 0; j < width; j++) {
					int j1 = (int)((float)j * propX + 0.5f),
						j2 = (int)((float)(j + 1) * propX + 0.5f);
					int r = 0, g = 0, b = 0, a = 0;
					for (int k = j1; k < j2; k++) {
						Uint8 r1, g1, b1, a1;
						image->getPixel(k, i, &r1, &g1, &b1, &a1);
						r += r1;
						g += g1;
						b += b1;
						a += a1;
					}
					int n = (j2 - j1);
					r /= n;
					g /= n;
					b /= n;
					a /= n;
					image->setPixel(j, i, r, g, b, a);
				}
			}
			for(int i = 0; i < image->size->y - 1; i++) {
				for(int j = 0; j < width; j++) {
					Uint8 r1, g1, b1, a1, r2, g2, b2, a2;
					image->getPixel(j, i, &r1, &g1, &b1, &a1);
					image->getPixel(j, i + 1, &r2, &g2, &b2, &a2);

					// Colocando na imagem maior
					int i1 = (int)(((float)i/(image->size->y - 1)) * (height - 1) + 0.5f),
						i2 = (int)(((float)(i+1)/(image->size->y - 1)) * (height - 1) + 0.5f);

					result->setPixel(j, i1, r1, g1, b1, a1);
					result->setPixel(j, i2, r2, g2, b2, a2);

					// Calculando os gradientes
					Uint8 a;
					AGL::Color c1 = {r1, g1, b1}, c2 = {r2, g2, b2};
					for (int k = i1 + 1; k < i2; k++) {
						AGL::Color c = lerp(c1, c2, a1, a2, &a, (float)(k - i1) / (i2 - i1));
						result->setPixel(j, k, c.red, c.green, c.blue, a);
					}
				}
			}
		}
	} else {
		float propY = (float)image->size->y / height;
		for (int j = 0; j < image->size->x; j++) {
			for (int i = 0; i < height; i++) {
				int i1 = (int)((float)i * propY + 0.5f),
					i2 = (int)((float)(i + 1) * propY + 0.5f);
				int r = 0, g = 0, b = 0, a = 0;
				for (int k = i1; k < i2; k++) {
					Uint8 r1, g1, b1, a1;
					image->getPixel(j, k, &r1, &g1, &b1, &a1);
					r += r1;
					g += g1;
					b += b1;
					a += a1;
				}
				int n = (i2 - i1);
				r /= n;
				g /= n;
				b /= n;
				a /= n;
				image->setPixel(j, i, r, g, b, a);
			}
		}
		for(int i = 0; i < height; i++) {
			for(int j = 0; j < image->size->x - 1; j++) {
				Uint8 r1, g1, b1, a1, r2, g2, b2, a2;
				image->getPixel(j, i, &r1, &g1, &b1, &a1);
				image->getPixel(j + 1, i, &r2, &g2, &b2, &a2);

				// Colocando na imagem maior
				int j1 = (int)(((float)j/(image->size->x - 1)) * (width - 1) + 0.5f),
					j2 = (int)(((float)(j+1)/(image->size->x - 1)) * (width - 1) + 0.5f);

				result->setPixel(j1, i, r1, g1, b1, a1);
				result->setPixel(j2, i, r2, g2, b2, a2);

				// Calculando os gradientes
				Uint8 a;
				AGL::Color c1 = {r1, g1, b1}, c2 = {r2, g2, b2};
				for (int k = j1 + 1; k < j2; k++) {
					AGL::Color c = lerp(c1, c2, a1, a2, &a, (float)(k - j1) / (j2 - j1));
					result->setPixel(k, i, c.red, c.green, c.blue, a);
				}
			}
		}
	}

	image->unlock();
	result->unlock();

	SDL_FreeSurface(image->sdlSurface);
	image->sdlSurface = result->sdlSurface;
	image->size->x = width; image->size->y = height;
}

void AGL::Graphics::rotate(AGL::Image *image, float angle)
{
	// If rotation is zero, nothing needs to be done.
	if (angle == 0) return;

	// find the new image size
	float x[4], y[4];
	x[0] = 0; y[0] = 0;
	x[1] = image->size->x - 1; y[1] = 0;
	x[2] = image->size->x - 1; y[2] = image->size->y - 1;
	x[3] = 0; y[3] = image->size->y - 1;

	rotatePoint(&x[0], &y[0], angle);
	rotatePoint(&x[1], &y[1], angle);
	rotatePoint(&x[2], &y[2], angle);
	rotatePoint(&x[3], &y[3], angle);

	float minX = 1000000, minY = 1000000, maxX = -1000000, maxY = -1000000;
	for (short i = 0; i < 4; i++)
	{
		if (x[i] < minX) minX = x[i];
		if (x[i] > maxX) maxX = x[i];

		if (y[i] < minY) minY = y[i];
		if (y[i] > maxY) maxY = y[i];
	}

	int width = (int)(maxX - minX + 1.5f);
	int height = (int)(maxY - minY + 1.5f);

	Image* result = new Image(width + 2, height + 2);
	image->lock();
	result->lock();

	for (int j = 0; j < image->size->y; j++)
	{
		for (int i = 0; i < image->size->x; i++)
		{
			float newX = i + 0.5f, newY = j + 0.5f;
			rotatePoint(&newX, &newY, angle);
			int defX = (int)(newX - minX), defY = (int)(newY - minY);
			float difX = ((newX - minX) - defX), difY = ((newY - minY) - defY),
				absX = abs(difX - 0.5f), absY = abs(difY - 0.5f),
				w1 = absX * absY, w2 = (1 - absX) * absY, w3 = absX * (1 - absY), w4 = (1 - absX) * (1 - absY);
			bool xLess = difX <= 0.5f, yLess = difY <= 0.5f;
			Uint8 r, g, b, a, r1, g1, b1, a1, a2;
			AGL::Color c;
			image->getPixel(i, j, &r, &g, &b, &a);

			result->getPixel(defX + (xLess ? 0 : 2), defY + (yLess ? 0 : 2), &r1, &g1, &b1, &a1);
			if (a1 == 0) { c.red = r; c.green = g; c.blue = b; a2 = w1 * a; }
			else { c = lerp({r1, g1, b1}, {r, g, b}, w1); short a3 = a1 + w1 * a; a2 = a3 > 255 ? 255 : a3; }
			result->setPixel(defX + (xLess ? 0 : 2), defY + (yLess ? 0 : 2), c.red, c.green, c.blue, a2);

			result->getPixel(defX + 1, defY + (yLess ? 0 : 2), &r1, &g1, &b1, &a1);
			if (a1 == 0) { c.red = r; c.green = g; c.blue = b; a2 = w2 * a; }
			else { c = lerp({r1, g1, b1}, {r, g, b}, w2); short a3 = a1 + w2 * a; a2 = a3 > 255 ? 255 : a3; }
			result->setPixel(defX + 1, defY + (yLess ? 0 : 2), c.red, c.green, c.blue, a2);

			result->getPixel(defX + (xLess ? 0 : 2), defY + 1, &r1, &g1, &b1, &a1);
			if (a1 == 0) { c.red = r; c.green = g; c.blue = b; a2 = w3 * a; }
			else { c = lerp({r1, g1, b1}, {r, g, b}, w3); short a3 = a1 + w3 * a; a2 = a3 > 255 ? 255 : a3; }
			result->setPixel(defX + (xLess ? 0 : 2), defY + 1, c.red, c.green, c.blue, a2);

			result->getPixel(defX + 1, defY + 1, &r1, &g1, &b1, &a1);
			if (a1 == 0) { c.red = r; c.green = g; c.blue = b; a2 = w4 * a; }
			else { c = lerp({r1, g1, b1}, {r, g, b}, w4); short a3 = a1 + w4 * a; a2 = a3 > 255 ? 255 : a3; }
			result->setPixel(defX + 1, defY + 1, c.red, c.green, c.blue, a2);
		}
	}

	image->unlock();
	result->unlock();

	SDL_FreeSurface(image->sdlSurface);
	image->sdlSurface = result->sdlSurface;
	image->size->x = width + 2; image->size->y = height + 2;
}

void AGL::Graphics::drawRotated(AGL::Drawer* drawer, AGL::Image* image, AGL::IntVector2& position, float angle)
{
	// if rotation is zero, no rotation needs to be done.
	if (angle == 0)
	{
		drawer->draw(image, position);
		return;
	}

	// find the new image size
	float x[4], y[4];
	x[0] = 0; y[0] = 0;
	x[1] = image->size->x - 1; y[1] = 0;
	x[2] = image->size->x - 1; y[2] = image->size->y - 1;
	x[3] = 0; y[3] = image->size->y - 1;

	rotatePoint(&x[0], &y[0], angle);
	rotatePoint(&x[1], &y[1], angle);
	rotatePoint(&x[2], &y[2], angle);
	rotatePoint(&x[3], &y[3], angle);

	float minX = 1000000, minY = 1000000, maxX = -1000000, maxY = -1000000;
	for (short i = 0; i < 4; i++)
	{
		if (x[i] < minX) minX = x[i];
		if (x[i] > maxX) maxX = x[i];

		if (y[i] < minY) minY = y[i];
		if (y[i] > maxY) maxY = y[i];
	}

	int width = (int)(maxX - minX + 1.5f);
	int height = (int)(maxY - minY + 1.5f);

	Image* result = new Image(width + 2, height + 2);
	image->lock();
	result->lock();

	for (int j = 0; j < image->size->y; j++)
	{
		for (int i = 0; i < image->size->x; i++)
		{
			float newX = i + 0.5f, newY = j + 0.5f;
			rotatePoint(&newX, &newY, angle);
			int defX = (int)(newX - minX), defY = (int)(newY - minY);
			float difX = ((newX - minX) - defX), difY = ((newY - minY) - defY),
				absX = abs(difX - 0.5f), absY = abs(difY - 0.5f),
				w1 = absX * absY, w2 = (1 - absX) * absY, w3 = absX * (1 - absY), w4 = (1 - absX) * (1 - absY);
			bool xLess = difX <= 0.5f, yLess = difY <= 0.5f;
			Uint8 r, g, b, a, r1, g1, b1, a1, a2;
			AGL::Color c;
			image->getPixel(i, j, &r, &g, &b, &a);

			result->getPixel(defX + (xLess ? 0 : 2), defY + (yLess ? 0 : 2), &r1, &g1, &b1, &a1);
			if (a1 == 0) { c.red = r; c.green = g; c.blue = b; a2 = w1 * a; }
			else { c = lerp({r1, g1, b1}, {r, g, b}, w1); short a3 = a1 + w1 * a; a2 = a3 > 255 ? 255 : a3; }
			result->setPixel(defX + (xLess ? 0 : 2), defY + (yLess ? 0 : 2), c.red, c.green, c.blue, a2);

			result->getPixel(defX + 1, defY + (yLess ? 0 : 2), &r1, &g1, &b1, &a1);
			if (a1 == 0) { c.red = r; c.green = g; c.blue = b; a2 = w2 * a; }
			else { c = lerp({r1, g1, b1}, {r, g, b}, w2); short a3 = a1 + w2 * a; a2 = a3 > 255 ? 255 : a3; }
			result->setPixel(defX + 1, defY + (yLess ? 0 : 2), c.red, c.green, c.blue, a2);

			result->getPixel(defX + (xLess ? 0 : 2), defY + 1, &r1, &g1, &b1, &a1);
			if (a1 == 0) { c.red = r; c.green = g; c.blue = b; a2 = w3 * a; }
			else { c = lerp({r1, g1, b1}, {r, g, b}, w3); short a3 = a1 + w3 * a; a2 = a3 > 255 ? 255 : a3; }
			result->setPixel(defX + (xLess ? 0 : 2), defY + 1, c.red, c.green, c.blue, a2);

			result->getPixel(defX + 1, defY + 1, &r1, &g1, &b1, &a1);
			if (a1 == 0) { c.red = r; c.green = g; c.blue = b; a2 = w4 * a; }
			else { c = lerp({r1, g1, b1}, {r, g, b}, w4); short a3 = a1 + w4 * a; a2 = a3 > 255 ? 255 : a3; }
			result->setPixel(defX + 1, defY + 1, c.red, c.green, c.blue, a2);
		}
	}

	image->unlock();
	result->unlock();

	float centerX = image->size->x / 2, centerY = image->size->y / 2,
		newCenterX = centerX, newCenterY = centerY;
	rotatePoint(&newCenterX, &newCenterY, angle);

	AGL::IntVector2 v(position.x + minX + (centerX - newCenterX), position.y + minY + (centerY - newCenterY));
	drawer->draw(result, v);

	delete result;
}

void AGL::Graphics::rotatePoint(float* x, float* y, float angle)
{
	float radians = TORADIANS(angle);
	float oldX = *x;
	*x = cos(radians) * oldX - sin(radians) * (*y);
	*y = sin(radians) * oldX + cos(radians) * (*y);
}

void AGL::Graphics::incline(Image *image, bool vertical, short amount)
{
	if (amount == 0) return;

	short width = vertical ? image->size->x : image->size->x + abs(amount),
		height = vertical ? image->size->y + abs(amount) : image->size->y;
	Image *result = new Image(width, height);

	image->lock();
	result->lock();

	if (vertical)
	{
		if (amount < 0)
		{
			// Copia a primeira coluna
			for (int j = 0; j < image->size->y; j++)
			{
				Uint8 r, g, b, a;
				image->getPixel(0, j, &r, &g, &b, &a);
				result->setPixel(0, j, r, g, b, a);
			}

			// Inclina a partir da segunda
			float f = -((float)amount / width);
			for (int i = 1; i < width; i++)
			{
				int first = floor(i * f);
				float offset = 1 - ((i * f) - first);

				Uint8 r1, g1, b1, a1, r2, g2, b2, a2, a3;
				image->getPixel(i, 0, &r1, &g1, &b1, &a1);
				Color c = lerp({r1, g1, b1}, {r1, g1, b1}, 0, a1, &a3, offset);
				result->setPixel(i, first, c.red, c.green, c.blue, a3);
				for (int j = 1; j < image->size->y; j++)
				{
					image->getPixel(i, j - 1, &r1, &g1, &b1, &a1);
					image->getPixel(i, j, &r2, &g2, &b2, &a2);
					c = lerp({r1, g1, b1}, {r2, g2, b2}, a1, a2, &a3, offset);
					result->setPixel(i, first + j, c.red, c.green, c.blue, a3);
				}
				image->getPixel(i, image->size->y - 1, &r1, &g1, &b1, &a1);
				c = lerp({r1, g1, b1}, {r1, g1, b1}, a1, 0, &a3, offset);
				result->setPixel(i, first + image->size->y, c.red, c.green, c.blue, a3);
			}
		}
		else
		{
			// Copia a última coluna
			for (int j = 0; j < image->size->y; j++)
			{
				Uint8 r, g, b, a;
				image->getPixel(width - 1, j, &r, &g, &b, &a);
				result->setPixel(width - 1, j, r, g, b, a);
			}

			// Inclina da primeira à penúltima
			float f = (float)amount / width;
			for (int i = 0; i < width - 1; i++)
			{
				int first = floor((width - 1 - i) * f);
				float offset = 1 - (((width - 1 - i) * f) - first);

				Uint8 r1, g1, b1, a1, r2, g2, b2, a2, a3;
				image->getPixel(i, 0, &r1, &g1, &b1, &a1);
				Color c = lerp({r1, g1, b1}, {r1, g1, b1}, 0, a1, &a3, offset);
				result->setPixel(i, first, c.red, c.green, c.blue, a3);
				for (int j = 1; j < image->size->y; j++)
				{
					image->getPixel(i, j - 1, &r1, &g1, &b1, &a1);
					image->getPixel(i, j, &r2, &g2, &b2, &a2);
					c = lerp({r1, g1, b1}, {r2, g2, b2}, a1, a2, &a3, offset);
					result->setPixel(i, first + j, c.red, c.green, c.blue, a3);
				}
				image->getPixel(i, image->size->y - 1, &r1, &g1, &b1, &a1);
				c = lerp({r1, g1, b1}, {r1, g1, b1}, a1, 0, &a3, offset);
				result->setPixel(i, first + image->size->y, c.red, c.green, c.blue, a3);
			}
		}
	}
	else
	{
		if (amount < 0)
		{
			// Copia a primeira linha
			for (int i = 0; i < image->size->x; i++)
			{
				Uint8 r, g, b, a;
				image->getPixel(i, 0, &r, &g, &b, &a);
				result->setPixel(i, 0, r, g, b, a);
			}

			// Inclina a partir da segunda
			float f = -((float)amount / height);
			for (int j = 1; j < height; j++)
			{
				int first = floor(j * f);
				float offset = 1 - ((j * f) - first);

				Uint8 r1, g1, b1, a1, r2, g2, b2, a2, a3;
				image->getPixel(0, j, &r1, &g1, &b1, &a1);
				Color c = lerp({r1, g1, b1}, {r1, g1, b1}, 0, a1, &a3, offset);
				result->setPixel(first, j, c.red, c.green, c.blue, a3);
				for (int i = 1; i < image->size->x; i++)
				{
					image->getPixel(i - 1, j, &r1, &g1, &b1, &a1);
					image->getPixel(i, j, &r2, &g2, &b2, &a2);
					c = lerp({r1, g1, b1}, {r2, g2, b2}, a1, a2, &a3, offset);
					result->setPixel(first + i, j, c.red, c.green, c.blue, a3);
				}
				image->getPixel(image->size->x - 1, j, &r1, &g1, &b1, &a1);
				c = lerp({r1, g1, b1}, {r1, g1, b1}, a1, 0, &a3, offset);
				result->setPixel(first + image->size->x, j, c.red, c.green, c.blue, a3);
			}
		}
		else
		{
			// Copia a última linha
			for (int i = 0; i < image->size->x; i++)
			{
				Uint8 r, g, b, a;
				image->getPixel(i, image->size->y - 1, &r, &g, &b, &a);
				result->setPixel(i, image->size->y - 1, r, g, b, a);
			}

			// Inclina da primeira à penúltima
			float f = (float)amount / height;
			for (int j = 0; j < height - 1; j++)
			{
				int first = floor((height - 1 - j) * f);
				float offset = 1 - (((height - 1 - j) * f) - first);

				Uint8 r1, g1, b1, a1, r2, g2, b2, a2, a3;
				image->getPixel(0, j, &r1, &g1, &b1, &a1);
				Color c = lerp({r1, g1, b1}, {r1, g1, b1}, 0, a1, &a3, offset);
				result->setPixel(first, j, c.red, c.green, c.blue, a3);
				for (int i = 1; i < image->size->x; i++)
				{
					image->getPixel(i - 1, j, &r1, &g1, &b1, &a1);
					image->getPixel(i, j, &r2, &g2, &b2, &a2);
					c = lerp({r1, g1, b1}, {r2, g2, b2}, a1, a2, &a3, offset);
					result->setPixel(first + i, j, c.red, c.green, c.blue, a3);
				}
				image->getPixel(image->size->x - 1, j, &r1, &g1, &b1, &a1);
				c = lerp({r1, g1, b1}, {r1, g1, b1}, a1, 0, &a3, offset);
				result->setPixel(first + image->size->x, j, c.red, c.green, c.blue, a3);
			}
		}
	}

	image->unlock();
	result->unlock();

	SDL_FreeSurface(image->sdlSurface);
	image->sdlSurface = result->sdlSurface;
	image->size->x = width; image->size->y = height;
}

AGL::Image* AGL::Graphics::blur(AGL::Image *image, short radius)
{
	if (radius <= 0) return new AGL::Image(image->size->x, image->size->y);

	short diam = 2 * radius + 1;
	float r1, g1, b1, a1;
	Uint8 r2, g2, b2, a2;

	// Building the blur matrix, using standard deviation = 1/6 diam
	float *matrix = new float[diam];
	float inv2SigmaSq = 18.0f / (diam * diam), invSqrt2piSigmaSq = sqrt(inv2SigmaSq / AGL_PI);
	for (short i = 0; i < diam; i++)
	{
		short x = radius - i;
		matrix[i] = exp(-(float(x * x) * inv2SigmaSq)) * invSqrt2piSigmaSq;
	}

	// Building intermediate image
	AGL::Image *inter = new AGL::Image(image->size->x + diam - 1, image->size->y);
	image->lock();
	inter->lock();
	for (short i = 0; i < inter->size->y; i++)
	{
		for (short j = -radius; j < inter->size->x - radius; j++)
		{
			r1 = 0; g1 = 0; b1 = 0; a1 = 0;
			for (short k = 0; k < diam; k++)
			{
				short x = j - radius + k;
				if (x < 0 || x >= image->size->x) {
					r2 = g2 = b2 = 255;
					a2 = 0;
				}
				else image->getPixel(x, i, &r2, &g2, &b2, &a2);
				r1 += r2 * matrix[k];
				g1 += g2 * matrix[k];
				b1 += b2 * matrix[k];
				a1 += a2 * matrix[k];
			}
			if (r1 > 255) r1 = 255;
			if (g1 > 255) g1 = 255;
			if (b1 > 255) b1 = 255;
			if (a1 > 255) a1 = 255;
			inter->setPixel(j + radius, i, (Uint8)(r1 + 0.5f), (Uint8)(g1 + 0.5f), (Uint8)(b1 + 0.5f), (Uint8)(a1 + 0.5f));
		}
	}

	AGL::Image *result = new AGL::Image(inter->size->x, image->size->y + diam - 1);
	for (short i = -radius; i < result->size->y - radius; i++)
	{
		for (short j = 0; j < result->size->x; j++)
		{
			r1 = 0; g1 = 0; b1 = 0; a1 = 0;
			for (short k = 0; k < diam; k++)
			{
				short y = i - radius + k;
				if (y < 0 || y >= inter->size->y) {
					r2 = g2 = b2 = 255;
					a2 = 0;
				}
				else inter->getPixel(j, y, &r2, &g2, &b2, &a2);
				r1 += r2 * matrix[k];
				g1 += g2 * matrix[k];
				b1 += b2 * matrix[k];
				a1 += a2 * matrix[k];
			}
			if (r1 > 255) r1 = 255;
			if (g1 > 255) g1 = 255;
			if (b1 > 255) b1 = 255;
			if (a1 > 255) a1 = 255;
			result->setPixel(j, i + radius, (Uint8)(r1 + 0.5f), (Uint8)(g1 + 0.5f), (Uint8)(b1 + 0.5f), (Uint8)(a1 + 0.5f));
		}
	}

	delete inter;
	result->unlock();
	image->unlock();

	return result;
}

AGL::Image* AGL::Graphics::getPolygonOutline(short edges, short edgeSize, AGL::Color color)
{
	if (edges < 3) return NULL;
	if (edges == 4) return getRectangleOutline(edgeSize, edgeSize, color, 255);

	AGL::Image *a1 = getHorizontalLine(edgeSize, color), *result = new AGL::Image(a1);

	float rotation = 360.0f / edges;
	AGL::IntVector2 last(edgeSize, 0);
	for (int i = 1; i < edges; i++)
	{
		float thisRot = i * rotation;
		AGL::Image *newAresta = new AGL::Image(a1);
		rotate(newAresta, thisRot);
		if (thisRot >= 90 && thisRot < 270) last.x -= newAresta->size->x - 2;
		if (thisRot >= 180) last.y -= newAresta->size->y - 2;
		result = overlapImages(result, newAresta, last);
		if (thisRot < 90 || thisRot >= 270) last.x += newAresta->size->x - 2;
		if (thisRot >= 180 && thisRot < 270) last.x = 0;
		else if (thisRot < 180) last.y += newAresta->size->y - 2;
		delete newAresta;
	}

	delete a1;
	return result;
}
