/*	=============================================================================
	Timer Class Definition
	
	@version	0.1.1
	@author	JP
	========================================================================== */

#ifndef TIMER_H_
#define TIMER_H_

#include <chrono>
#include <ctime>
#include <iostream>					// input, output 

#include <stdio.h>      			// printf, scanf, NULL 
#include <stdlib.h>     			// malloc, free, rand
#include <sstream>					// number to string conversion
#include <string>						// C++ String Class
#include <vector>						// C++ Arrays
#include <map>							// C++ Associative Array

#include <math.h>						// Standard Math library

namespace smhdl {

	class Timer {

		public:
		
			 Timer();									// Instantiate Timer object
			~Timer();
			void init();									// Initialize Timer object
				
			/* ==================================================================== */	
			// Modifiers
			/* ==================================================================== */	
			// reset();
			// start();
			
			/* ==================================================================== */	
			// Retrievers
			/* ==================================================================== */	
			// now();
			// stop();
			// lap();
			

			/* ==================================================================== */	
			// TODO
			/* ==================================================================== */	
			void wait(
				double);		// Time in Seconds
			
			// Reset Lap time
			//Lap = std::clock(); 
			
			// Lap Time
			//myTrial.time = ( std::clock() - lap ) / (double) CLOCKS_PER_SEC;
			
			// Duration
			//duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
		
		private:	
			//std::time_t current_time;
			// time( &current_time ) 
			std::clock_t Start;
			std::clock_t Lap;
			std::clock_t Duration;
			
	};

}

#endif 
