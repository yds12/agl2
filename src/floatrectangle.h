#ifndef _AGL_FLOATRECTANGLE_H
#define _AGL_FLOATRECTANGLE_H

namespace AGL
{
	/// Represents a rectangle with float values
	class FloatRectangle
	{
		private:
		public:
			float x;
			float y;
			float width;
			float height;
		
			/// Creates a new instance of the FloatRectangle class
			FloatRectangle();
		
			/// Copy Constructor
			///
			/// @param fr rectangle to copy
			FloatRectangle(const FloatRectangle &fr);
		
			/// Creates a new instance of the FloatRectangle class
			FloatRectangle(float x, float y, float width, float height);
			
			/// Check whether this rectangle intersects another
			///
			/// @param rectangle another rectangle
			/// @return whether the two vectors intersects
			bool intersects(FloatRectangle &rectangle);
			
			/// Assigment
			///
			/// @param fr another rectangle
			void operator = (FloatRectangle &fr);
	};
}

#endif

