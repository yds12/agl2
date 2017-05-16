#include <sstream>
#include <string>

#include "agl/vector2.h"

using namespace std;

AGL::Vector2::Vector2()
{
	x = 0;
	y = 0;
}

AGL::Vector2::Vector2(float _x, float _y)
{
	x = _x;
	y = _y;
}

AGL::Vector2::Vector2(AGL::IntVector2 &p)
{
	x = p.x;
	y = p.y;
}

AGL::Vector2::Vector2(const AGL::Vector2 &p)
{
	x = p.x;
	y = p.y;
}

AGL::Vector2::Vector2(AGL::Vector2 &p)
{
	x = p.x;
	y = p.y;
}

AGL::Vector2 AGL::Vector2::zero()
{
	AGL::Vector2 v(0, 0);
	return v;
}

float AGL::Vector2::distance(Vector2 &v1, Vector2 &v2)
{
	return sqrt((v1.x - v2.x)*(v1.x - v2.x) + (v1.y - v2.y)*(v1.y - v2.y));
}

float AGL::Vector2::distance(Vector2 &v)
{
	return sqrt((x - v.x)*(x - v.x) + (y - v.y)*(y - v.y));
}

AGL::Vector2 AGL::Vector2::operator + (Vector2 &v)
{
	Vector2 result;
	result.x = x + v.x;
	result.y = y + v.y;

	return result;
}

void AGL::Vector2::operator += (Vector2 &v)
{
	x = x + v.x;
	y = y + v.y;
}

AGL::Vector2 AGL::Vector2::operator - (Vector2 &v)
{
	Vector2 result;
	result.x = x - v.x;
	result.y = y - v.y;

	return result;
}

void AGL::Vector2::operator = (Vector2 &v)
{
	x = v.x;
	y = v.y;
}

bool AGL::Vector2::operator == (Vector2 &v)
{
	return x == v.x && y == v.y;
}

bool AGL::Vector2::operator != (Vector2 &v)
{
	return x != v.x || y != v.y;
}

AGL::Vector2 AGL::Vector2::operator * (float k)
{
	Vector2 result;
	result.x = x * k;
	result.y = y * k;

	return result;
}

AGL::Vector2 AGL::Vector2::operator / (float k)
{
	Vector2 result;
	result.x = x / k;
	result.y = y / k;

	return result;
}

AGL::Vector2 AGL::Vector2::rotate(float radians)
{
     float seno = sin(radians);     
     float cosseno = cos(radians);
                        
     float newX = cosseno * x - seno * y;
     float newY = seno * x + cosseno * y;
     
     Vector2 v(newX, newY);
     return v;
}

string AGL::Vector2::toString()
{
	stringstream sst;
	int i;
	sst << x << ", " << y;
	return sst.str();
}

AGL::IntVector2 AGL::Vector2::toIntVector2()
{
	IntVector2 v(ROUND(x), ROUND(y));
	return v;
}
