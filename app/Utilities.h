/*	=============================================================================
	Utilities Class Definition
	
	@version	0.1.1
	@author	JP
	========================================================================== */

#ifndef UTILITIES_H_
#define UTILITIES_H_

// App-wide Libraries
#include <stdio.h>      			// printf, scanf, NULL 
#include <stdlib.h>     			// malloc, free, rand
#include <iostream>					// input, output 
#include <sstream>					// number to string conversion
#include <string>						// C++ String Class
#include <locale>        			// std::locale, std::toupper
#include <math.h>						// Standard Math library
#include <vector>
#include <algorithm>    			// std::max
#include <map>							// Associative Array
#include <set>
#include <list>						// List LIbrary
#include <queue>						// Queue Library

// App
#include "Structs.h"

using namespace smhdl;

double deltaDistance(			// Calculates the distance between 
	coords, 							// 	this point p1
	coords);							// 	and this point p2
double deltaDistance(			// Calculates the distance between 
	double, double,				// 	this point (x1, y1) 
	double, double);				// 	and this point (x2, y2) 		
coords rotatePoint(				// Rotate
	double, 							// 	by this angle in degrees
	coords,			 				// 	this point p1
	coords);							// 	about this point p2
coords rotatePoint(				// Rotate 
	double, 							//		by this angle in degrees
	double, double, 				// 	this point (x1,y1)
	double, double);				// 	about this point (x2,y2)
coords midPoint(					// Returns a point midway between 2 points
	coords, 			 				// 	this point p1
	coords);			 				// 	and this point p2
double rad2deg(
	double);							// Converts radians to degrees
double deg2rad(
	double);							// Converts degrees to radians
double thetaAngleRad(			// Calculates the angle between 2 points
	coords, 
	coords); 	
double getAngleUsing(			// determine angle from 3 points:
	coords, 							// 	origin,
	coords, 							// 	point 1,
	coords);							// 	point 2
double getAngle(					// determine angle from 3 points:
	coords, 							// 	origin,
	coords, 							// 	point 1,
	coords);							// 	point 2
double getAngle(					// determine angle from 2 points:
	coords, 										// origin, vertex 1, vertex 2
	coords);					
double findAngle(					// Used to find equally spaced angles around circle
	unsigned, 
	double);
double roundTo(					// Rounds a double to a specified places
	double, 
	unsigned);
bool isEqual(						// Checks to see if 2 values are "equal" using default tolerance
	float,   						//		value 1
	float); 							//		and value 2
bool isEqual(						// Checks to see if 2 values are "equal"
	float,   						//		value 1
	float, 							//		and value 2
	float);							//		with this tolerance
bool isEqual(						// Checks to see if 2 values are "equal" using default tolerance
	double,   						//		value 1
	double); 						//		and value 2
bool isEqual(						// Checks to see if 2 values are "equal"
	double,   						//		value 1
	double, 							//		and value 2
	double);							//		with this tolerance
bool isEqual(						// Checks to see if 2 points are "equal" using default tolerance
	coords,  						//		point 1
	coords);							//		and point 2
bool isEqual(						// Checks to see if 2 points are "equal"
	coords, 							//		point 1
	coords, 							//		and point 2
	double);							//		with this tolerance
coords pointOnCircle(
	coords, 							// gets intersection point on circle at angle
	double, 
	double);							// radius, angle
int outputError(
	int, 								// Error Code
	std::string, 					// Class::method, 
	std::string);					// function called
int outputError(
	int, 								// Error Code
	std::string, 					// Class::method, 
	std::string,					// function called
	unsigned);						// Number of tabs

// Converters
std::string toString(
	bool);
std::string toString(
	int);
std::string toString(
	unsigned);
std::string toString(
	unsigned long long);
std::string toString(
	double);
std::string toString(
	const char*);	
std::string toString(
	smhdl::objTYPES);
std::string toString(
	smhdl::devTYPES);
std::string toString(
	smhdl::dimTYPES);
std::string toString(
	smhdl::dimSpanTypes);
std::string toString(
	smhdl::dimModeTypes);
int toInt(
	const char*);	
unsigned toUnsigned(
	const char*);	
double toDouble(
	const char*);	
unsigned toDigit(
	std::string);
double toDbl(
	std::string);
int toInteger(
	std::string);
unsigned toUnt(
	std::string);
std::string toUpperCase(
	std::string);
std::string toLowerCase(
	std::string);

double washburnLength(			// Returns Washburn length
	double, 							// 	k, 
	double,							// 	delta, 
	double, 							// 	mu,
	double);							// 	t
coords moveAwayFrom(				// Gets offset 
	coords,							// 	to move this point
	double, 							// 	this distance
	coords);							// 	from this point
coords getPointFrom(				// Get point 
	coords, 							//		from this point
	double,  						//		at this angle (degrees) 
	double);							//		and distance
coords getPointFromRad(			// Get point 
	coords, 							//		from this point
	double, 							//		at this angle (radians) 
	double);							//		and distance
int getRoots( 						// Calculates the roots
	std::vector<double>&, 		// 	of a polynomial
	std::vector<double>&);		// 	and stores in vector
double distancePointToLine(	// Returns the distnace from this point
	coords,			 
	double, 
	double, 
	double);							// to line cy = ax + b, c, a, and b are passed in
double distancePointToLine(
	coords,							// Returns the distnace from this point 
	coords, 
	coords);							// to line source, destination
coords lerp(
	double, 
	coords, 
	coords);							// Linear Interpolation at point r between v1 and v2
coords lli4(
	coords, 
	coords, 							// POMAX
	coords, 
	coords);
double cubicRoot(
	double);							// returns the cube root of a number
bool validT(
	double);							// Checks it 0.0 <= t <= 1.0
void printPoint(
	coords);
bool pointOnLine(
	coords, 
	coords, 
	coords);							// (test, start, end) is test on line (start->end)?
bool pointOnLine(
	coords, 
	line);							// (test, line) is test on line?
std::string getIndent(
	unsigned);
std::string indent(
	unsigned);						// Returns number of indents
void printpIntersect(
	pIntersect, 
	unsigned);		
void printMBR(
	bounds, 
	unsigned);	
bool mbrOverlap(
	bounds, 
	bounds);							// Checks to see if 2 MBR's overlap
double getMax(						// Returns the largest of 2 values
	double, 							//		Value 1
	double);							// 	Value 2
double getMax(						// Returns the largest of 3 values
	double, 							//		Value 1
	double,							//		Value 2 
	double);							//		Value 3
double getMin(						// Returns the smallest of 2 values
	double, 							//		Value 1
	double); 						//		Value 2
double getMin(						// Returns the smallest of 2 values
	double, 							//		Value 1
	double, 							//		Value 2
	double);							//		Value 3



#endif 
