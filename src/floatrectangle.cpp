#include "agl/floatrectangle.h"

AGL::FloatRectangle::FloatRectangle()
{

}

AGL::FloatRectangle::FloatRectangle(const FloatRectangle &fr)
{
	x = fr.x;
	y = fr.y;
	width = fr.width;
	height = fr.height;
}

AGL::FloatRectangle::FloatRectangle(float x, float y, float width, float height)
{
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
}

bool AGL::FloatRectangle::intersects(AGL::FloatRectangle &rectangle)
{
	if (this->x >= rectangle.x + rectangle.width || rectangle.x >= this->x + this->width)
		return false;
	if (this->y >= rectangle.y + rectangle.height || rectangle.y >= this->y + this->height)
		return false;

	return true;
}

void AGL::FloatRectangle::operator = (FloatRectangle &fr)
{
	x = fr.x;
	y = fr.y;
	width = fr.width;
	height = fr.height;
}
