/*	=============================================================================
	Timer Class Source
	
	@version	0.1.1
	@author	JP
	========================================================================== */

#include "Timer.h"
using namespace smhdl;

/*	==========================================================================
	Layout class instantiation
	
	@param 	null		nothing
	@return 	null		nothing
	========================================================================== */
Timer::Timer() {
	init();
}

/*	==========================================================================
	Layout destructor
	
	@param 	null		nothing
	@return 	null		nothing
	========================================================================== */
Timer::~Timer() {
	// do something
}

/*	==========================================================================
	Timer initialize
	
	@param 	null		nothing
	@return 	null		nothing
	========================================================================== */
void Timer::init() {	
	Start = std::clock(); 
	Lap = std::clock(); 
	Duration = std::clock();
	return;
}

/*	==========================================================================
	Delay Timer
	
	@param 	null		nothing
	@return 	null		nothing
	========================================================================== */
void Timer::wait(double s) {	
	Start = std::clock(); 
	double elapsed = 0.0;
	while( elapsed < s ) {
	 	elapsed = ( std::clock() - Start ) / (double) CLOCKS_PER_SEC;
	};
	
	return;
}

/*	==========================================================================
	Start Timer
	
	@param 	null		nothing
	@return 	null		nothing
	========================================================================== */
void Timer::start() {	
	Start = std::clock(); 
	return;
}

/*	==========================================================================
	Stop Timer
	
	@param 	null		nothing
	@return 	null		nothing
	========================================================================== */
void Timer::stop() {	
	Duration = std::clock() - Start;
	return;
}

/*	==========================================================================
	Stop Timer
	
	@param 	null		nothing
	@return 	null		nothing
	========================================================================== */
double Timer::getDuration() {	
	Duration = std::clock() - Start;
	return Duration / (double) CLOCKS_PER_SEC;
}

