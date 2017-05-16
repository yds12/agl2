#ifndef _AGL_INTVECTOR2_H
#define _AGL_INTVECTOR2_H

#include <string>
#include <math.h>

#include "agl/support.h"

namespace AGL
{
	/// IntVector2 class
	class IntVector2
	{
		public:
			int x, y;

			/// Creates a new instance of the Vector2 class
			IntVector2();

			/// Creates a new instance of the Vector2 class
			/// 
			/// @param _x value of the X coordinate
			/// @param _y value of the Y coordinate
			IntVector2(int _x, int _y);

			/// Creates a new instance of the Vector2 class
			/// 
			/// @param v the vector to copy
			IntVector2(IntVector2 &v);

			/// Copy constructor
			/// 
			/// @param v the vector to copy
			IntVector2(const IntVector2 &v);

			/// Returns the vector zero
			/// 
			/// @return the vector zero
			static IntVector2 zero();

			/// Calculates and returns the distance between two vectors
			/// 
			/// @param v1 a vector
			/// @param v2 another vector
			/// @return the euclidian distance between the two vectors
			static float distance(IntVector2 &v1, IntVector2 &v2);

			/// Calculates and returns the distance between this vector and another
			/// 
			/// @param v another vector
			/// @return the euclidian distance between the two vectors
			float distance(IntVector2 &v);

			/// Sums this vector with another
			/// 
			/// @param v another vector
			/// @return a vector that is the sum of the vectors
			IntVector2 operator + (IntVector2 &v);

			/// Sums this vector with another (and assign)
			/// 
			/// @param v another vector
			void operator += (IntVector2 &v);

			/// Subtract another vector from this
			/// 
			/// @param v another vector
			/// @return a vector that is the subtraction of the vectors
			IntVector2 operator - (IntVector2 &v);

			/// Assigment
			/// 
			/// @param v another vector
			void operator = (IntVector2 &v);

			/// Verifies whether two vectors are equal
			/// 
			/// @param v another vector
			/// @return a value indicating whether the two vectors are equal
			bool operator == (IntVector2 &v);

			/// Verifies whether two vectors are not equal
			/// 
			/// @param v another vector
			/// @return a value indicating whether the two vectors are not equal
			bool operator != (IntVector2 &v);

			/// Multiply this vector by a constant
			/// 
			/// @param k a constant
			/// @return a vector that is this vector multiplied by a constant
			IntVector2 operator * (float k);

			/// Divide this vector by a constant
			/// 
			/// @param k a constant
			/// @return a vector that is this vector divided by a constant
			IntVector2 operator / (float k);

			/// Return a string representing this vector
			/// 
			/// @return a string representing this vector
			std::string toString();
	};
}

#endif
