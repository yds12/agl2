#ifndef _AGL_JOYSTICK_H
#define _AGL_JOYSTICK_H

#include "agl/support.h"

namespace AGL
{
	/// Joystick class
	class Joystick
	{
		public:
			/// The joystick itself
			SDL_Joystick* sdlJoy;
			
			/// Counts the number of installed joysticks
			///
			/// @return number of installed joysticks
			static int countJoysticks();
			
			/// Gets the name of a installed joystick
			///
			/// @param index index of the installed joystick
			/// @return name of the joystick
			static string getJoystickName(int index);
			
			/// Verifies whether a joystick is opened
			///
			/// @param index index of the installed joystick
			/// @return whether the joystick is opened
			static bool isOpened(int index);
			
			/// Updates the joystick
			///
			/// This method must be called in every game update
			static void update();

			/// Constructor
			///
			/// @param index index of the joystick
			Joystick(int index);

			/// Destructor
			~Joystick();
			
			/// Gets the index of the joystick among the installed joysticks
			///
			/// @return index of the joystick
			int getIndex();
			
			/// Gets the name of the joystick
			///
			/// @return name of the joystick
			string getName();
			
			/// Gets the number of axes this joystick has
			///
			/// Usualy the directional button is made by 2 axes, X axis and y axis
			///
			/// @return number of axes
			int countAxes();
			
			/// Gets the number of buttons this joystick has
			///
			/// Buttons are the common buttons, which has 2 states: pressed and released
			///
			/// @return number of buttons
			int countButtons();
			
			/// Gets the number of balls this joystick has
			///
			/// Balls or track-balls has 2 values associated: x shift and y shift
			///
			/// @return number of balls
			int countBalls();
			
			/// Gets the number of hats this joystick has
			///
			/// Hats or Point-of-Views (POV) can be in 9 states: centered, up, down, left, right and the diagonals
			///
			/// @return number of hats
			int countHats();
			
			/// Gets the state of a button
			///
			/// @param index index of the button (0 is the first button of the joystick, 1 the next, and so on...)
			/// @return true if the button is pressed, false otherwise
			bool getButtonState(int index);
			
			/// Gets the state of an axis
			///
			/// @param index index of the axis (0 is the first axis of the joystick, 1 the next, and so on...). Usualy the directional button has
			/// the axis 0 as the X axis, and 1 as the Y axis
			/// @return a value between -32768 and 32768
			Sint16 getAxisState(int index);
			
			/// Gets the state of a hat
			///
			/// @param index index of the hat (0 is the first hat of the joystick, 1 the next, and so on...)
			/// @return one of the following states: AGL_POSITION_UP, AGL_POSITION_DOWN, AGL_POSITION_LEFT, AGL_POSITION_RIGHT,
			/// AGL_POSITION_CENTER, AGL_POSITION_TOPLEFT, AGL_POSITION_TOPRIGHT, AGL_POSITION_DOWNLEFT, AGL_POSITION_DOWNRIGHT.
			/// Those states represents the possible positions for the hat, the four directions, diagonals and centered.
			Uint8 getHatState(int index);
			
			/// Gets the state of a ball
			///
			/// @param index index of the ball (0 is the first hat of the joystick, 1 the next, and so on...)
			/// @param xShift relative movement of the ball in the X axis
			/// @param yShift relative movement of the ball in the Y axis
			void getBallState(int index, int* xShift, int* yShift);
	};
}

#endif
