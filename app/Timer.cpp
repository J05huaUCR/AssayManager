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
	Layout initialize
	
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
	Layout initialize
	
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

