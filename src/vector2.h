#ifndef _AGL_VECTOR2_H
#define _AGL_VECTOR2_H

#include <string>
#include <math.h>

#include "agl/support.h"
#include "agl/intvector2.h"

namespace AGL
{
	/// Vector2 class
	class Vector2
	{
		public:
			float x, y;

			/// Creates a new instance of the Vector2 class
			Vector2();

			/// Creates a new instance of the Vector2 class
			/// 
			/// @param _x value of the X coordinate
			/// @param _y value of the Y coordinate
			Vector2(float _x, float _y);

			/// Creates a new instance of the Vector2 class
			/// 
			/// @param p Vector to copy
			Vector2(Vector2 &p);
			
			/// Copy constructor
			///
			/// @param p a Vector2 to copy
			Vector2(const Vector2 &p);
			
			/// Creates a new instance of the Vector2 class
			/// 
			/// @param p IntVector to transform into vector
			Vector2(IntVector2 &p);

			/// Returns the vector zero
			/// 
			/// @return the vector zero
			static Vector2 zero();

			/// Calculates and returns the distance between two vectors
			/// 
			/// @param v1 a vector
			/// @param v2 another vector
			/// @return the euclidian distance between the two vectors
			static float distance(Vector2 &v1, Vector2 &v2);

			/// Calculates and returns the distance between this vector and another
			/// 
			/// @param v another vector
			/// @return the euclidian distance between the two vectors
			float distance(Vector2 &v);

			/// Sums this vector with another
			/// 
			/// @param v another vector
			/// @return a vector that is the sum of the vectors
			Vector2 operator + (Vector2 &v);

			/// Sums this vector with another (and assign)
			/// 
			/// @param v another vector
			void operator += (Vector2 &v);

			/// Subtract another vector from this
			/// 
			/// @param v another vector
			/// @return a vector that is the subtraction of the vectors
			Vector2 operator - (Vector2 &v);

			/// Assignment
			/// 
			/// @param v another vector
			void operator = (Vector2 &v);

			/// Verifies whether two vectors are equal
			/// 
			/// @param v another vector
			/// @return a value indicating whether the two vectors are equal
			bool operator == (Vector2 &v);

			/// Verifies whether two vectors are not equal
			/// 
			/// @param v another vector
			/// @return a value indicating whether the two vectors are not equal
			bool operator != (Vector2 &v);

			/// Multiply this vector by a constant
			/// 
			/// @param k a constant
			/// @return a vector that is this vector multiplied by a constant
			Vector2 operator * (float k);

			/// Divide this vector by a constant
			/// 
			/// @param k a constant
			/// @return a vector that is this vector divided by a constant
			Vector2 operator / (float k);

			/// Rotates a vector
			///
			/// @param radians how many radians the vector must be rotated
			/// @return a vector rotated
			Vector2 rotate(float radians);

			/// Return a string representing this vector
			/// 
			/// @return a string representing this vector
			std::string toString();

			/// Return a toIntVector corresponding to this vector (with rounded values)
			/// 
			/// @return a toIntVector corresponding to this vector
			IntVector2 toIntVector2();
	};
}

#endif
