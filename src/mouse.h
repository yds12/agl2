#ifndef _AGL_MOUSE_H
#define _AGL_MOUSE_H

#include <stdlib.h>
#include "SDL/SDL.h"

#include "agl/support.h"
#include "agl/intvector2.h"

#define MOUSE_HELD_DELAY 35
#define DOUBLECLICK_DELAY 10

namespace AGL
{
	/// Class to manipulate the mouse
	class Mouse
	{
		private:
			bool leftPressed;
			bool rightPressed;
			bool leftPrevPressed;
			bool rightPrevPressed;
			bool leftDoubleChecking;
			bool rightDoubleChecking;

			unsigned short leftHeldTimer;
			unsigned short rightHeldTimer;
			short leftDoubleTimer;
			short rightDoubleTimer;

			unsigned short heldDelay;
			unsigned short doubleClickDelay;
			
		public:
			/// Mouse position
			AGL::IntVector2* position;

			/// Creates a new instance of the Mouse class
			Mouse();

			/// Creates a new instance of the Mouse class
			///
			/// @param _heldDelay Number of "updates" to consider that the button is held
			/// @param _doubleClickDelay Maximum number of "updates" between two clicks to consider that it was a double-click
			Mouse(Uint16 _heldDelay, Uint16 _doubleClickDelay);

			/// Returns whether the left button is pressed now, and was not pressed in the moment before
			/// @return whether the left button is pressed now, and was not pressed in the moment before
			bool isLeftButtonPressed();

			/// Returns whether the right button is pressed now, and was not pressed in the moment before
			/// @return whether the right button is pressed now, and was not pressed in the moment before
			bool isRightButtonPressed();

			/// Returns whether the left button was double clicked in the last "update"
			/// @return whether the left button was double clicked in the last "update"
			bool isLeftButtonDoubleClicked();

			/// Returns whether the right button was double clicked in the last "update"
			/// @return whether the right button was double clicked in the last "update"
			bool isRightButtonDoubleClicked();

			/// Returns whether the left button has been pressed for a multiple of a specified interval
			/// @return whether the left button has been pressed for a multiple of a specified interval
			bool isLeftButtonHeld();

			/// Returns whether the right button has been pressed for a multiple of a specified interval
			/// @return whether the right button has been pressed for a multiple of a specified interval
			bool isRightButtonHeld();

			/// Returns whether the left button was released now
			/// @return whether the left button was released now
			bool isLeftButtonReleased();

			/// Returns whether the right button was released now
			/// @return whether the right button was released now
			bool isRightButtonReleased();

			/// Returns whether the left button is not down and was not released now
			/// @return whether the left button is not down and was not released now
			bool isLeftButtonInactive();

			/// Returns whether the right button is not down and was not released now
			/// @return whether the right button is not down and was not released now
			bool isRightButtonInactive();

			/// Returns whether the left button is pressed now
			/// @return whether the left button is pressed now
			bool isLeftButtonDown();

			/// Returns whether the right button is pressed now
			/// @return whether the right button is pressed now
			bool isRightButtonDown();

			/// Returns whether the left button is pressed now and the right don't
			/// @return whether the left button is pressed now and the right don't
			bool isOnlyLeftButtonDown();

			/// Returns whether the right button is pressed now and the right don't
			/// @return whether the right button is pressed now and the right don't
			bool isOnlyRightButtonDown();

			/// Updates the Mouse instance. It is necessary to call this method for each "update"
			void update();

			/// Returns whether the cursor is over an specified area
			///
			/// @param area The area to check if the cursor is over
			/// @return Returns whether the cursor is over an specified area
			bool isCursorOver(Rectangle area);
			
			/// Moves the mouse cursor to the specified position
			///
			/// @param x the x coordinate of the new position
			/// @param y the y coordinate of the new position
			void setPosition(int x, int y);
			
			/// Moves the mouse cursor to the specified position
			///
			/// @param position an IntVector2 representing the new position
			void setPosition(IntVector2& position);
	};
}

#endif
