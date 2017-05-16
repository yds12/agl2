#ifndef _H_TIMER
#define _H_TIMER

#include "SDL/SDL.h"
#include <time.h>

namespace AGL
{
	/// Classe para medição de tempo
	class Timer
	{
		private:		
			/// Time when the chronometer started
			clock_t t1;
			int milliseconds;

		public:
			/// Constructor
			Timer();
		
			/// Starts the timer for real time
			void start();

			/// Stops the timer, returning the ellapsed time (in seconds)
			///
			/// @return float with the ellapsed time between the start and stop of the timer (in seconds)
			float stop();
			
			/// Stops the timer, returning the ellapsed time (in ms)
			///
			/// @return float with the ellapsed time between the start and stop of the timer (in milliseconds)
			int stopMs();
			
			/// Starts the timer for machine time
			void startMachineTimer();

			/// Stops the machine-timer, returning the ellapsed time (in seconds)
			///
			/// @return float with the ellapsed time between the start and stop of the machine-timer (in seconds)
			float stopMachineTimer();
	};
}

#endif
