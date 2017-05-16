#include <sstream>
#include <string>

#include "agl/intvector2.h"

using namespace std;

AGL::IntVector2::IntVector2()
{
	x = 0;
	y = 0;
}

AGL::IntVector2::IntVector2(int _x, int _y)
{
	x = _x;
	y = _y;
}

AGL::IntVector2::IntVector2(AGL::IntVector2 &v)
{
	x = v.x;
	y = v.y;
}

AGL::IntVector2::IntVector2(const AGL::IntVector2 &v)
{
	x = v.x;
	y = v.y;
}

AGL::IntVector2 AGL::IntVector2::zero()
{
	IntVector2 v(0, 0);
	return v;
}

float AGL::IntVector2::distance(IntVector2 &v1, IntVector2 &v2)
{
	return sqrt((float)((v1.x - v2.x)*(v1.x - v2.x) + (v1.y - v2.y)*(v1.y - v2.y)));
}

float AGL::IntVector2::distance(IntVector2 &v)
{
	return sqrt((float)((x - v.x)*(x - v.x) + (y - v.y)*(y - v.y)));
}

AGL::IntVector2 AGL::IntVector2::operator + (IntVector2 &v)
{
	IntVector2 result;
	result.x = x + v.x;
	result.y = y + v.y;

	return result;
}

void AGL::IntVector2::operator += (IntVector2 &v)
{
	x = x + v.x;
	y = y + v.y;
}

AGL::IntVector2 AGL::IntVector2::operator - (IntVector2 &v)
{
	IntVector2 result;
	result.x = x - v.x;
	result.y = y - v.y;

	return result;
}

void AGL::IntVector2::operator = (IntVector2 &v)
{
	x = v.x;
	y = v.y;
}

bool AGL::IntVector2::operator == (IntVector2 &v)
{
	return x == v.x && y == v.y;
}

bool AGL::IntVector2::operator != (IntVector2 &v)
{
	return x != v.x || y != v.y;
}

AGL::IntVector2 AGL::IntVector2::operator * (float k)
{
	IntVector2 result;
	result.x = ((float)x) * k;
	result.y = ((float)y) * k;

	return result;
}

AGL::IntVector2 AGL::IntVector2::operator / (float k)
{
	IntVector2 result;
	result.x = ((float)x) / k;
	result.y = ((float)y) / k;

	return result;
}

string AGL::IntVector2::toString()
{
	stringstream sst;
	int i;
	sst << x << ", " << y;
	return sst.str();
}

