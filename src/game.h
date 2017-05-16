#ifndef _AGL_GAME_H
#define _AGL_GAME_H

#include <stdlib.h>
#include "SDL/SDL.h"

#include "agl/support.h"
#include "agl/keyboard.h"
#include "agl/mouse.h"
#include "agl/joystick.h"
#include "agl/timer.h"
#include "agl/sound.h"

/// @mainpage AGL - Aleva Game Library
/// @section Libraries
/// AGL Libraries
/// - agl: main AGL Library.
/// - <a href="agl-graphics/html/index.html">agl-graphics: AGL Graphics Library.</a>
/// - <a href="agl-mapping/html/index.html">agl-mapping: AGL Mapping Library.</a>
/// - <a href="agl-motion/html/index.html">agl-motion: AGL Motion Library.</a>
/// - <a href="agl-text/html/index.html">agl-text: AGL Text Library.</a>
/// - <a href="agl-forms/html/index.html">agl-forms: AGL Forms Library.</a>
/// - <a href="agl-net/html/index.html">agl-net: AGL Net Library.</a>

namespace AGL
{
	/// Controls the AGL game
	class Game
	{
		private:
			AGL::Timer* timer;
			float updateTime;
			float cumulativeCycleTime;
			void basicInitialize(const char* windowTitle);
			void updateGameTime();
			bool quit;

		public:
			/// Timer that starts in the game beginning
			AGL::Timer* gameTimer;
				
			/// The number of updates per cycle (the cycle time is measured)
			int cycleSize;

			/// Time ellapsed in the last cycle (a specified number of updates)
			float cycleTime;

			/// Count the number of updates from the beginning of the game until 60, then return to zero
			unsigned int gameCounter;

			/// Tells AGL that the game must quit from the main loop
			///
			/// @param mustQuit indicates if the game must end
			void setQuit(bool mustQuit);
			
			/// Constructor of the Game class
			Game();

			/// Constructor of the Game class
			/// 
			/// @param windowTitle title of the game window
			Game(const char* windowTitle);
			
			/// Runs the game calling update and draw by callback, with fixed frame rate
			///
			/// @param updateMethod callback function to update the game
			/// @param drawMethod callback function to draw the game
			/// @param fps fixed frame rate in frames per second (FPS)
			void runFixedFps(void (*updateMethod)(), void (*drawMethod)(), unsigned short fps);

			/// Get the time ellapsed in the last update (in seconds)
			///
			/// @return the time ellapsed in the last update (in seconds)
			float getUpdateTime();

			/// Get the average Frames per Second (FPS) rate in the last updates
			///
			/// @param updatesPerDraw how many updates occurs between each draw
			/// @return the average Frames per Second (FPS) rate in the last updates
			float getFps(float updatesPerDraw);

			/// Closes all AGL systems
			void end();

			/// Updates the game
			void update();

			/// Updates the game (including keyboard)
			///
			/// @param keyboard pointer to an object of the Keyboard class
			void update(Keyboard* keyboard);

			/// Updates the game (including mouse)
			///
			/// @param mouse pointer to an object of the Mouse class
			void update(Mouse* mouse);

			/// Updates the game (including keyboard and mouse)
			///
			/// @param keyboard pointer to an object of the Keyboard class
			/// @param mouse pointer to an object of the Mouse class
			void update(Keyboard* keyboard, Mouse* mouse);

			/// Updates the game (including keyboard, mouse and joystick)
			///
			/// @param keyboard pointer to an object of the Keyboard class
			/// @param mouse pointer to an object of the Mouse class
			/// @param updateJoysticks whether the joysticks must be updated
			void update(Keyboard* keyboard, Mouse* mouse, bool updateJoysticks);

			/// Make a pause
			///
			/// @param milliseconds time to wait (in milliseconds)
			void wait(int milliseconds);

			/// Sets the window title
			///
			/// @param title title of the window
			void setWindowTitle(const char* title);

			/// Sets whether the mouse must be shown or not
			///
			/// @param show whether the mouse cursor must be shown
			void showMouse(bool show);
	};
}

#endif
