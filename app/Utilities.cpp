/*	=============================================================================
	Utilities Class Source
	
	@version	0.1.1
	@author	JP
	========================================================================== */

#include "Utilities.h"
using namespace smhdl;

/*	=============================================================================
	Calculates the distance between 2 points
	
	@param 	coords		
	@param 	coords		
	@return 	dbl		
	========================================================================== */
double deltaDistance(coords p1, coords p2) {
	return sqrt( pow( (p2.x - p1.x), 2) + pow( (p2.y - p1.y), 2) );
}

/*	=============================================================================
	Calculates the distance between 2 points
	
	@param 	coords		
	@param 	coords		
	@return 	dbl		
	========================================================================== */
double deltaDistance(double x1, double y1, double x2, double y2) {
	return sqrt( pow( (x2 - x1), 2) + pow( (y2 - y1), 2) );
}

/*	=============================================================================
	Rotate point about another point for the specified angle in degrees
	
	@param 	coords		
	@param 	coords		
	@return 	dbl		
	========================================================================== */
coords rotatePoint(double angle_deg, coords p, coords o) {
	return rotatePoint(angle_deg, p.x, p.y, o.x, o.y);
}

/*	=============================================================================
	Rotate point about another point for the specified angle in degrees
	
	http://stackoverflow.com/questions/2259476/rotating-a-point-about-another-point-2d
	

	POINT rotate_point(float cx,float cy,float angle,POINT p)
	{
		cx, cy is the pivot point
		p is what is to be rotate
	  // rotate point
	  float xnew = ( ( (p.x - cx) * cos(angle) ) - ( (p.y - cy) * sin(angle) ) ) + cx;
	  float ynew = ( ( (p.x - cx) * sin(angle) ) + ( (p.y - cy) * cos(angle) ) ) + cy;
	}

	If you rotate point (px, py) around point (ox, oy) by angle theta you'll get:

	p'x = ( ( cos(theta) * (px-ox) ) - ( sin(theta) * (py-oy) ) ) + ox
	p'y = ( ( sin(theta) * (px-ox) ) + ( cos(theta) * (py-oy) ) ) + oy
	
	@param 	dbl		angle of rotation in degrees
	@param 	dbl		x-coord
	@param 	dbl		y-coord
	@param 	dbl		Rotation x-coord
	@param 	dbl		Rotation x-coord
	@return 	coords	the coords that you get after transformation
	========================================================================== */
coords rotatePoint(double angle_deg, double x, double y, double ox, double oy) {

	bool DebugMode = false;

	if ( DebugMode ) {
		std::cout << TAB1 << "^ Utilities::rotatePoint() called...\n";
		std::cout << TAB2 << "Angle (degrees): " << angle_deg << "\n";
		std::cout << TAB2 << "Point being rotated: (" << x << "," << y << ")\n";
		std::cout << TAB2 << "Around: (" << ox << "," << oy << ")\n";
	}

	// convert to radians for calculation
	double angle_rad = deg2rad(angle_deg); 
	
	// Return object
	coords point;

	// Rotate point
	//p'x = cos(theta) * (px-ox) - sin(theta) * (py-oy) + ox
	//p'y = sin(theta) * (px-ox) + cos(theta) * (py-oy) + oy
	point.x = ( cos( angle_rad ) * ( x - ox ) ) - 
				 ( sin( angle_rad ) * ( y - oy ) ) + ox;
	point.y = ( sin( angle_rad ) * ( x - ox ) ) + 
				 ( cos( angle_rad ) * ( y - oy ) ) + oy;

	// Round to desired decimal places (to guarantee return to 0
	point.x = roundTo( point.x, DECIMAL_PLACES);
	point.y = roundTo( point.y, DECIMAL_PLACES);
				 
	if ( DebugMode ) {
		std::cout << TAB2 << "New point (" << point.x << "," << point.y << ")\n";
		std::cout << TAB1 << "v Utilities::rotatePoint() called...DONE\n";
	}
	return point;
}

/*	=============================================================================
	Returns a point midway between 2 points
	
	@param 	coords		p1
	@param 	coords		p2
	@return 	coords		mid point
	========================================================================== */
coords midPoint(coords p1, coords p2) {
	coords midpoint;
	midpoint.x = p1.x + ( (p2.x - p1.x) * 0.5 );
	midpoint.y = p1.y + ( (p2.y - p1.y) * 0.5 );
	return midpoint;
}

/*	=============================================================================
	Rounds to specific decimal places
	
	@param 	dbl		number to round	
	@param 	unt		number of places
	@return 	dbl		rounded number
	========================================================================== */
double roundTo(double num, unsigned x) {

	bool DebugMode = false;
	double output = ERROR_DBL;
	
	if (DebugMode) {
		std::cout << TAB1 << "^ Utilities::roundTo() called...\n";
		std::cout << TAB2 << "Number to be rounded:|" << num << "|\n";
		std::cout << TAB2 << "Number of places:|" << x << "|\n";
	}
	
	output = round( ( num * pow( 10,x ) ) ) / pow( 10,x );
	
	if (DebugMode) {
		std::cout << TAB2 << "Rounded number:|" << output << "|\n";
		std::cout << TAB1 << "v Utilities::roundTo() called...DONE.\n";
	}
	return output;
}

/*	=============================================================================
	Converts angle from degrees to radians
	
	@param 	dbl		angle in degrees
	@return 	dbl		angle in radians
	========================================================================== */
double deg2rad(double angleDegrees ) {
	return ( angleDegrees * LARGE_PI / 180 );
}

/*	=============================================================================
	Converts Radians to degrees
	
	@param 	dbl		radians	
	@return 	dbl		degress
	========================================================================== */
double rad2deg(double angleRads) {
	return ( angleRads * 180 / LARGE_PI );
}

/*	=============================================================================
	Calculates the angle between 2 given points
	
	@param 	dbl		radians	
	@return 	dbl		degress
	========================================================================== */
double thetaAngleRad(coords p1, coords p2) {

	double thetaAngleRad = 0.0;
	double tempX = 0.0;
	double tempY = 0.0;
	
	// Check for axis and set angle in radians
	if ( isEqual(p1.x, p2.x) ) {
		if (p2.y > p1.y) thetaAngleRad = PI_2_RAD; else thetaAngleRad = PI_3_2_RAD; // angle is 90 or 270
	} else if ( isEqual(p2.y, p1.y) ) {
		if (p2.x > p1.x) thetaAngleRad = 0.0; else thetaAngleRad = LARGE_PI; // angle is 0 or 180
	} else { 
		// calculate angle (radians)
		tempY = p2.y - p1.y;
		tempX = p2.x - p1.x;
		thetaAngleRad = atan( tempY / tempX ); 
		
		// Adjust angle by quadrant
		if (tempX < 0.0 && tempY > 0) { 
			// Q2, theta negative, add PI to get proper angle
			thetaAngleRad += LARGE_PI;
		} else if (tempX < 0.0 && tempY < 0) {
			// Q3, theta positive, but in Q3
			thetaAngleRad += LARGE_PI;
		} else if (tempX > 0.0 && tempY < 0) {
			// Q4, theta negative, add 2PI
			thetaAngleRad += LARGE_2_PI;
		} 				
	}
	
	return thetaAngleRad;
}

/*	=============================================================================
	Checks whether or not two doubles are "equal"
	
	@param 	dbl		
	@param 	dbl		
	@return 	bool		
	========================================================================== */
bool isEqual(float var1, float var2 ) {
	double dvar1 = 0.0 + var1;
	double dvar2 = 0.0 + var2;
	return isEqual(dvar1, dvar2, TOLERANCE);
}

/*	=============================================================================
	Checks whether or not two doubles are "equal"
	
	@param 	dbl		
	@param 	dbl		
	@return 	bool		
	========================================================================== */
bool isEqual(float var1, float var2, float tolerance ) {
	if (fabs(var1 - var2) < tolerance) return true; else return false;
}

/*	=============================================================================
	Checks whether or not two doubles are "equal"
	
	@param 	dbl		
	@param 	dbl		
	@return 	bool		
	========================================================================== */
bool isEqual(double var1, double var2 ) {
	return isEqual(var1, var2, TOLERANCE);
}

/*	=============================================================================
	Checks whether or not two doubles are "equal"
	
	@param 	dbl		
	@param 	dbl		
	@return 	bool		
	========================================================================== */
bool isEqual(double var1, double var2, double tolerance ) {
	if (fabs(var1 - var2) < tolerance) return true; else return false;
}

/*	=============================================================================
	Checks whether or not two coordinates are "equal"
	
	@param 	dbl		
	@param 	dbl		
	@return 	bool		
	========================================================================== */
bool isEqual(coords p1, coords p2 ) {
	return isEqual(p1, p2, POINT_MATCH_TOLERANCE);
}

/*	=============================================================================
	Checks whether or not two coordinates are "equal"
	
	@param 	dbl		
	@param 	dbl		
	@return 	bool		
	========================================================================== */
bool isEqual(coords p1, coords p2, double tolerance ) {

	bool flag = false;
	bool equal = false;
	
	if ( flag ) {
		std::cout << "isEqual called...\n";
		std::cout << TAB1 << "p1:(" << p1.x << "," << p1.y << ") ";
		std::cout << "p2:(" << p2.x << "," << p2.y << ")\n";
	}

	if ( (fabs(p2.x - p1.x) < tolerance) &&
		  (fabs(p2.y - p1.y) < tolerance) ) {
		equal = true; 
		if (flag) std::cout << TAB1 << "p1 EQUAL to p2\n";
	} else {
		if (flag) std::cout << TAB1 << "p1 NOT EQUAL to p2\n";
	}
	
	if (flag) {
		std::cout << "isEqual called...DONE\n";
	}
	
	return equal;
}

/*	=============================================================================
	gets intersection point on circle given x,y, radius, and angle
	
	//X = X0 + Cos(Theta)*r
	//Y = Y0 + Sin(Theta)*r
	
	@param 	coords	center of circle	
	@param 	dble		radius
	@param	dbl		angle		
	@return 	bool		
	========================================================================== */
coords pointOnCircle(coords origin, double r, double theta) {
	coords p;
	
	p.x = origin.x + (r * cos(theta) );
	p.y = origin.y + (r * sin(theta) );
	
	return p;
}

/*	=============================================================================
	Outpus error message
	
	@param 	int		Error Code		
	@param 	str		Class::method	
	@param 	str		function called
	@return 	int		-1
	========================================================================== */
int outputError(int errorCode, std::string classMethod, std::string function) {
	return outputError(errorCode, classMethod, function, 0);					 
}
		

/*	=============================================================================
	Outpus error message
	
	@param 	int		Error Code		
	@param 	str		Class::method	
	@param 	str		function called
	@param 	unt		Number of tabs
	@return 	int		-1
	========================================================================== */
int outputError(int errorCode, std::string classMethod, std::string function,	
					 unsigned tabCount) {
	
	for (unsigned i = 0; i < tabCount; ++i) {
		std::cout << TAB1;
	}
	
	std::cout << "ERROR(" << errorCode << ": " << classMethod;
	std::cout << "() did not successfully complete " << function << "()\n";
	
	return -1;					 
}

/*	=============================================================================
	Converts bool to string value
	
	@param 	bool				
	@return 	str		
	========================================================================== */
std::string toString(bool b) {
	if ( b ) return "true";
	return "false";					 
}	
					 
/*	=============================================================================
	Converts int to string value
	
	@param 	int				
	@return 	str		
	========================================================================== */
std::string toString(int n) {

	std::ostringstream ss;
	ss << n;
	std::string result = ss.str();
	ss.str("");

	return result;					 
}		

/*	=============================================================================
	Converts unsigned to string value
	
	@param 	unt				
	@return 	str		
	========================================================================== */
std::string toString(unsigned n) {

	std::ostringstream ss;
	ss << n;
	std::string result = ss.str();
	ss.str("");

	return result;					 
}		

/*	=============================================================================
	Converts unsigned to string value
	
	@param 	unt				
	@return 	str		
	========================================================================== */
std::string toString(unsigned long long n) {

	std::ostringstream ss;
	ss << n;
	std::string result = ss.str();
	ss.str("");

	return result;					 
}	

/*	=============================================================================
	Converts int to string value
	
	@param 	int				
	@return 	str		
	========================================================================== */
std::string toString(double n) {

	std::ostringstream ss;
	ss << n;
	std::string result = ss.str();
	ss.str("");

	return result;					 
}		

/*	=============================================================================
	Converts char string to string
	
	@param 	int				
	@return 	str		
	========================================================================== */
std::string toString(const char* s) {

	std::ostringstream ss;
	ss << s;
	std::string result = ss.str();
	ss.str("");

	return result;					 
}	

/*	=============================================================================
	Converts object type to string
	
	enum objTYPES {UNDEFINED, // 0
						LAYOUT, // 1
						ND_TREE, // 2
						SUBSTRATE, // 3
						SUBSTANCE, // 4
						SCALE, // 5
						LAYER_REGISTRY, // 6
						COLOR, // 7
						DEVICE, // 8
						COMPONENT, // 9
						PRIMITIVE // 10
						};
	
	@param 	objType				
	@return 	str		
	========================================================================== */
std::string toString(objTYPES o) {

	std::string results = "";

	switch (o) {
	
		case 1:
			results = "LAYOUT";
		break;
		
		case 2:
			results = "ND_TREE";
		break;
		
		case 3:
			results = "SUBSTRATE";
		break;

		case 4:
			results = "SUBSTANCE";
		break;
		
		case 5:
			results = "SCALE";
		break;
		
		case 6:
			results = "LAYER_REGISTRY";
		break;
		
		case 7:
			results = "COLOR";
		break;
	
		case 8:
			results = "DEVICE";
		break;
		
		case 9:
			results = "COMPONENT";
		break;
		
		case 10:
			results = "PRIMITIVE";
		break;
		
		default:
			results = "UNDEFINED";
		break;
	}

	return results;					 
}		

/*	=============================================================================
	Converts object type to string
	
	FluidicMultiplexer
	FoldingCard
	FourChanneluPAD
	ImmunoSensor
	LateralFlowTest
	OnButtons
	Titration
	enum devTYPES {DEFAULTDEV, // 0
						BULLSEYE, // 1
						RACEWAY, // 2
						RFA, // 3
						REGISTRATION // 4
						};
	
	@param 	objType				
	@return 	str		
	========================================================================== */
std::string toString(devTYPES o) {

	std::string results = "";

	switch (o) {
	
		case 1:
			results = "BULLSEYE";
		break;
		
		case 2:
			results = "RACEWAY";
		break;
		
		case 3:
			results = "RFA";
		break;

		case 4:
			results = "REGISTRATION";
		break;
				
		default:
			results = "DEFAULTDEV";
		break;
	}

	return results;					 
}	

/*	=============================================================================
	Converts object type to string
	
	FluidicMultiplexer
	FoldingCard
	FourChanneluPAD
	ImmunoSensor
	LateralFlowTest
	OnButtons
	Titration
	enum devTYPES {DEFAULTDEV, // 0
						BULLSEYE, // 1
						RACEWAY, // 2
						RFA, // 3
						REGISTRATION // 4
						};
	
	@param 	objType				
	@return 	str		
	========================================================================== */
std::string toString(smhdl::dimTYPES t) {

	std::string results = "";

	switch (t) {
	
		case 0:
			results = "UNDEFINED";
		break;
	
		case 1:
			results = "UNSIGNED";
		break;
		
		case 2:
			results = "INTEGER";
		break;
		
		case 3:
			results = "FLOAT";
		break;

		case 4:
			results = "DOUBLE";
		break;
				
		default:
			results = "UNKNOWN";
		break;
	}

	return results;					 
}	

/*	=============================================================================
	Converts span type to string
	
	// Span Types
	enum dimSpanTypes {
		VALUE, 			// 0: one value
		DISCRETE, 		// 1: one discrete value
		SPAN				// 2: spans 2 values
	};
	
	@param 	objType				
	@return 	str		
	========================================================================== */
std::string toString(smhdl::dimSpanTypes t) {

	std::string results = "";

	switch (t) {
	
		case 0:
			results = "DISCRETE";
		break;
	
		case 1:
			results = "VALUE";
		break;
		
		case 2:
			results = "SPAN";
		break;

		default:
			results = "UNKNOWN";
		break;
	}

	return results;					 
}	

/*	=============================================================================
	Converts optimization type to string
	
	// Optimization Mode Types
	enum dimModeTypes {
		NEUTRAL, 		// 0: Neutral, not optimizing
		MINIMIZE, 		// 1: Seek miniminum value
		MAXIMIZE, 		// 2: Seek maximum value
		ACCRUE,			// 3: Sum values as added
		DOMINATE			//	4:	This dimension dominates non-dominant dimensions
	};
	
	@param 	objType				
	@return 	str		
	========================================================================== */
std::string toString(smhdl::dimModeTypes t) {

	std::string results = "";

	switch (t) {
	
		case 0:
			results = "NEUTRAL";
		break;
	
		case 1:
			results = "MINIMIZE";
		break;
		
		case 2:
			results = "MAXIMUM";
		break;
		
		case 3:
			results = "ACCRUE";
		break;

		case 4:
			results = "DOMINATE";
		break;
		
		case 5:
			results = "GROUP";
		break;
				
		default:
			results = "UNKNOWN";
		break;
	}

	return results;					 
}	


/*	=============================================================================
	Converts char string to integer
	
	@param 	int				
	@return 	str		
	========================================================================== */
int toInt(const char* s) {

	if (s == NULL) return ERROR_INT;

	int i = atoi (s);

	return i;					 
}	

/*	=============================================================================
	Converts char string to integer
	
	@param 	int				
	@return 	str		
	========================================================================== */
unsigned toUnsigned(const char* value) {

	if (value == NULL) return ERROR_INT;

	std::stringstream strValue;
	strValue << value;
	unsigned result;
	strValue >> result;

	return result;						 
}	

/*	=============================================================================
	Converts char string to integer
	
	@param 	int				
	@return 	str		
	========================================================================== */
double toDouble(const char* value) {

	if (value == NULL) return ERROR_INT;

	std::stringstream strValue;
	strValue << value;
	double result;
	strValue >> result;

	return result;						 
}	
		 
/*	=============================================================================
	Calculates Washburn length
	
	@param 	dbl	k: substrate properties coefficient
	@param 	dbl	delta: surface tension
	@param 	dbl	mu: viscosity of liquid
	@param	dbl	t: time 				
	@return 	str		
	========================================================================== */
double washburnLength(double k, double delta, double mu, double t) {

	double l = 0.0;
	l = k * (pow( ( delta / mu * t), 0.5) );

	return l;					 
}			
		 				 
/*	=============================================================================
	Gets offset for point p to move distance r from point f
	
	@param 	coords		point to move
	@param 	dbl			distance to move
	@return 	coords		point to move from
	========================================================================== */
coords moveAwayFrom(coords p, double r, coords f) {

	bool Debug = false;

	if ( Debug ) {
		std::cout << "Utilities::moveAwayFrom called...\n";
		std::cout << TAB1 << "p: (" << p.x << "," << p.y << ")\n";
		std::cout << TAB1 << "f: (" << f.x << "," << f.y << ")\n";
		std::cout << TAB1 << "r: " << r << "\n";
	}
	
	double distance = deltaDistance(p, f);
	double theta = thetaAngleRad(f,p);
	double newR = distance + r;
	double newX = newR * cos(theta) + f.x;
	double newY = newR * sin(theta) + f.y;
	coords delta;
	delta.x = newX - p.x;
	delta.y = newY - p.y;
	
	if ( Debug ) {
		std::cout << TAB1 << "distance between points: " << distance << "\n";
		std::cout << TAB1 << "theta angle: " << rad2deg(theta) << "\n";
		std::cout << TAB1 << "new r: " << newR << "\n";
		std::cout << TAB1 << "new point: (" << newX << "," << newY << ")\n";
		std::cout << TAB1 << "delta: (" << delta.x << "," << delta.y << ")\n";
		std::cout << "Utilities::moveAwayFrom called...DONE.\n";
	}
	
	return delta;
}
		 				 
/*	=============================================================================
	Get point from a given point along a certain angle and distance
	
	x = r * cos(theta) + x0
	y = r * sin(theta) + y0
	
	@param 	coords		origin point
	@param	dbl			angle in degrees
	@param 	dbl			distance to move
	@return 	coords		point calculated
	========================================================================== */
coords getPointFrom(coords o, double theta, double r) {
	return getPointFromRad(o, deg2rad(theta), r);
}

/*	=============================================================================
	Get point from a given point along a certain angle and distance
	
	x = r * cos(theta) + x0
	y = r * sin(theta) + y0
	
	@param 	coords		origin point
	@param	dbl			angle in degrees
	@param 	dbl			distance to move
	@return 	coords		point calculated
	========================================================================== */
coords getPointFromRad(coords o, double theta, double r) {
	bool flag = false;
	coords p;
	
	if (flag) {
		std::cout << "^ Utilities::getPointFromRad() called...\n";
		std::cout << TAB1 << "origin point:(" << o.x << "," << o.y << ")\n";
		std::cout << TAB1 << "Angle(Degs):|" << rad2deg(theta) << "|\n";
		std::cout << TAB1 << "Angle(Rads):|" << theta << "|\n";
		std::cout << TAB1 << "Distance:|" << r << "|\n";
	}
	
	p.x = r * cos( theta ) + o.x; 
	p.y = r * sin( theta ) + o.y; 
	
	if (flag) {
		std::cout << TAB1 << "p:(" << p.x << "," << p.y << ")\n";
		std::cout << "v Utilities::getPointFromRad() called...DONE.\n";
	}
	
	return p;
}

/*	=============================================================================
	Calculates the roots of a polynomial and stores in vector	
	
	@param 	vct	vector of polynomial coefficients
	@param 	vct	vector to store roots in
	@return 	int	status: 0 = no error, <0 = errored		
	========================================================================== */
int getRoots(std::vector<double>& p, std::vector<double>& r) {
	int status = 0;
	double a, b, c, d, m1, m2;
	
	// empty roots vector
	while (r.size() > 0) r.erase( r.begin() );
	
	if (p.size() == 3) { // quadratic roots
		a = p.at(0);
		b = p.at(1);
		c = p.at(2);
		d = a - (2 * b) + c;
		
		if (!isEqual(d, 0) ) {
			m1 = (-1) * sqrt( (b * b) - (a * c) );
			m2 = ( (-1) * a) + b;
			r.push_back( -( m1+m2)/d );
			r.push_back( -(-m1+m2)/d );
		} else if ( !isEqual(b, c) && isEqual(d,0) ) {
			r.push_back( (2*b-c)/(2*(b-c)) );
		}
   	/* 
	  if(d!==0) {
	    var m1 = -sqrt(b*b-a*c),
	        m2 = -a+b,
	        v1 = -( m1+m2)/d,
	        v2 = -(-m1+m2)/d;
	    return [v1, v2];
	  } else if (b!==c && d===0) {
	    return [ (2*b-c)/(2*(b-c)) ];
	  }
	  return [];*/
   } else if (p.size() == 2) { // linear roots 
   	a = p.at(0);
		b = p.at(1);
		if ( !isEqual(a, b) ) {
			r.push_back( ( a / (a - b) ) );
		}
		/*
		var a = p[0], b = p[1];
		if(a!==b) { return [a/(a-b)]; }
		return [];
		*/
   }

	return status;
}

/*	=============================================================================
	determine angle from 3 points:	
	
	POMAX
	var dx1 = v1.x - o.x,
		 dy1 = v1.y - o.y,
		 dx2 = v2.x - o.x,
		 dy2 = v2.y - o.y,
		 cross = dx1 * dy2 - dy1 * dx2,
		 dot = dx1 * dx2 + dy1 * dy2;
	return atan2(cross, dot);
	
	@param 	dbl	origin
	@param 	dbl	vertex 1
	@param 	dbl	vertex 2
	@return 	dbl	resulting angle in radians	
	========================================================================== */
double getAngleUsing(coords o, coords v1, coords v2) {

	bool flag = false;

	if (flag) {
		std::cout << "^ Algorithms::getAngleUsing(3 points) called...\n";
		std::cout << TAB1 << "pivot point: (" << o.x << "," << o.y << ")\n";
		std::cout << TAB1 << "v1 point: (" << v1.x << "," << v1.y << ")\n";
		std::cout << TAB1 << "v2 point: (" << v2.x << "," << v2.y << ")\n";
	}
	double dx1, dy1, dx2, dy2, cross, dot, results;
	dx1 = v1.x - o.x,
	dy1 = v1.y - o.y,
	dx2 = v2.x - o.x,
	dy2 = v2.y - o.y,
	cross = dx1 * dy2 - dy1 * dx2,
	dot = dx1 * dx2 + dy1 * dy2;
	results = atan2(cross, dot);
	if (results < 0.0) results += 2 * LARGE_PI;
	
	if (flag) {
		std::cout << TAB1 << "Angle:|" << results << " radians|, |" << rad2deg(results) << " degrees|.\n";
		std::cout << "v Algorithms::getAngleUsing(3 points) called...DONE\n";
	}
	return results;
}

/*	=============================================================================
	determine angle from 3 points:	
	
	POMAX
	var dx1 = v1.x - o.x,
		 dy1 = v1.y - o.y,
		 dx2 = v2.x - o.x,
		 dy2 = v2.y - o.y,
		 cross = dx1 * dy2 - dy1 * dx2,
		 dot = dx1 * dx2 + dy1 * dy2;
	return atan2(cross, dot);
	
	@param 	dbl	origin
	@param 	dbl	vertex 1
	@param 	dbl	vertex 2
	@return 	dbl	resulting angle in radians	
	========================================================================== */
double getAngle(coords o, coords v1, coords v2) {

	bool flag = false;

	if (flag) {
		std::cout << "^ Algorithms::getAngle(3 points) called...\n";
		std::cout << TAB1 << "pivot point: (" << o.x << "," << o.y << ")\n";
		std::cout << TAB1 << "v1 point: (" << v1.x << "," << v1.y << ")\n";
		std::cout << TAB1 << "v2 point: (" << v2.x << "," << v2.y << ")\n";
	}
	double dx1, dy1, dx2, dy2, cross, dot, results;
	dx1 = v1.x - o.x,
	dy1 = v1.y - o.y,
	dx2 = v2.x - o.x,
	dy2 = v2.y - o.y,
	cross = dx1 * dy2 - dy1 * dx2,
	dot = dx1 * dx2 + dy1 * dy2;
	results = atan2(cross, dot);
	
	//if (results < 0.0) results += 2 * LARGE_PI;
	
	if (flag) {
		std::cout << TAB1 << "Angle:|" << results << "|\n";
		std::cout << "v Algorithms::getAngle(3 points) called...DONE\n";
	}
	return results;
}

/*	=============================================================================
	Calculates the angle from 0 using 2 points in radians
	
	https://math.stackexchange.com/questions/1201337/finding-the-angle-between-two-points
	
	@param	coords	source coordinates
	@param	coords	Test coordinates
	@return	double	angle between them
	========================================================================== */
double getAngle(coords p1, coords p2) {
	double theta = atan2( (p2.y - p1.y), (p2.x - p1.x) );
	if (theta < 0) theta = theta + (2.0 * LARGE_PI);
	return theta;
}

/* =============================================================================
	Used to find equally spaced angles around circle

	@param  unsigned     number of angles
	@param  double       current angle that we want ex: 1 = 1st, 2 = 2nd,...
	@return     double   angle
	========================================================================== */
double findAngle(unsigned angles, double current) {
	return (180.0 / (angles + 1.0) ) * current;
}

/*	=============================================================================
	Returns the distnace from a point to line by = ax + c, c, a, and b are passed in
	
	Slope intercept converted to ax + by + c = 0:
	ax - by + c = 0
	
	distance = \ a * p.x + b * p.y + c \ / sqrt( a^2 + b^2 )
	
	@param 	dbl	y co-efficient (b)
	@param 	dbl	x co-efficient (a)
	@param 	dbl	y offest
	@return 	dbl	resulting angle in radians	
	========================================================================== */
double distancePointToLine(coords p, double yCo, double xCo, double yInt) {

	bool flag = false;

	if (flag) {
		std::cout << "^ Algorithms::distanceToLine() called...\n";
		std::cout << TAB1 << "point: (" << p.x << "," << p.y << ")\n";
		std::cout << TAB1 << "xCo: " << xCo << ", yCo: " << yCo << ", yInt: " << yInt << "\n";
	}

	// Flip sign for slop intercept re-arrange
	yCo = -1.0 * yCo;
	
	double numerator = abs ( (xCo * p.x) + (yCo * p.y) + yInt );
	double denominator = sqrt( pow(xCo,2) + pow(yCo ,2) );
	double results = ERROR_DBL;
	
	if (flag) {
		std::cout << TAB1 << "numerator: " << numerator << "\n";
	}
	
	if ( isEqual(denominator, 0.0) ) {
		if (flag) {
			std::cout << TAB1 << "denominator is 0\n";
			std::cout << "v Algorithms::distanceToLine() called...DONE:|-1|\n";
		}
		return ERROR_DBL;	
	}
	
	results = numerator / denominator;
	
	if (flag) {
		std::cout << TAB1 << "Result is: " << results << ".\n";
		std::cout << "v Algorithms::distanceToLine() called...DONE:|0|\n";
	}
	
	return results;
}

/*	=============================================================================
	Returns the distnace from a point to line defined by 2 points
	
	https://en.wikipedia.org/wiki/Distance_from_a_point_to_a_line
	distance = | ( (y_2 - y1) * x_0 ) - ( (x_2 - x_1) * y_0 ) + (x_2 * y_1) - (y_2 * x_1))| 
					/ sqrt( (y_2 - y1)^2 + (x_2 - x_1)^2)
	
	@param 	coords	point to evaluate
	@param 	coords	line source
	@param 	coords	line destination
	@return 	dbl		distance
	========================================================================== */
double distancePointToLine(coords p, coords source, coords destination) {

	bool flag = false;

	if (flag) {
		std::cout << "^ Algorithms::distanceToLine(coords, coords, coords) called...\n";
		std::cout << TAB1 << "point: (" << p.x << "," << p.y << ")\n";
		std::cout << TAB1 << "source: (" << source.x << "," << source.y << ")\n";
		std::cout << TAB1 << "destination: (" << destination.x << "," << destination.y << ")\n";
	}

	double distance = ERROR_DBL;
	double slopeNum = destination.y - source.y;
	double slopeDenom = destination.x - source.x;
	
	if ( isEqual(slopeDenom, 0.0) ) {
	
		// line is vertical
		distance = p.x - source.x; // negative to the left of line, positive to right
		
	} else if ( isEqual(slopeNum, 0.0) ) {
	
		// line is horizonatal
		distance = p.y - source.y; // negative underneath line, positive above
		
	} else {
		// distance = | ( (y_2 - y1) * x_0 ) - ( (x_2 - x_1) * y_0 ) + (x_2 * y_1) - (y_2 * x_1))| 
		//			/ sqrt( (y_2 - y1)^2 + (x_2 - x_1)^2)
		// NOT USING ABSOLUTE VALUE TO BE ABLE TO KNOW IF ABOVE/BELOW/LEFT/RIGHT
		distance =  ( (destination.y - source.y) * p.x ) - 
						( (destination.x - source.x) * p.y ) + 
						( destination.x * source.y ) - 
						( destination.y * source.x ) 
					  	/
						sqrt( pow( (destination.y - source.y), 2) + 
							   pow( (destination.x - source.x), 2) );
	}
	
	if (flag) {
		std::cout << TAB1 << "Distance:|" << distance << "\n";
		std::cout << "v Algorithms::distanceToLine(coords, coords, coords) called...";
		std::cout << "DONE:|0|\n";
	}
	return distance;
}

/*	=============================================================================
	Linear interpolation at some ratio point r between vertex1 and vertex 2
	
	POMAX
	lerp: function(r, v1, v2) {
      var ret = {
        x: v1.x + r * (v2.x - v1.x),
        y: v1.y + r * (v2.y - v1.y)
      };
      if (!!v1.z && !!v2.z) {
        ret.z = v1.z + r * (v2.z - v1.z);
      }
      return ret;
    }
	
	@param 	dbl		ratio
	@param 	coords	vertex 1
	@param 	coords	vertex 2
	@return 	coords	resulting point
	========================================================================== */
coords lerp(double r, coords v1, coords v2) {
	coords point;
	point.x = v1.x + ( r * (v2.x - v1.x) );
   point.y = v1.y + ( r * (v2.y - v1.y) );
	return point;
}

/*	=============================================================================
	POMAX
	
	x1 = p1.x, y1 = p1.y,
	x2 = p2.x, y2 = p2.y,
	x3 = p3.x, y3 = p3.y,
	x4 = p4.x, y4 = p4.y;
	
	lli8: function(x1, y1, x2, y2, x3, y3, x4, y4) {
	var 
		nx = (x1 * y2 - y1 * x2) * (x3 - x4) - (x1 - x2) * (x3 * y4 - y3 * x4),
		ny = (x1 * y2 - y1 * x2) * (y3 - y4) - (y1 - y2) * (x3 * y4 - y3 * x4),
		 d = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4);
	if (d == 0) {
		return false;
	} else {
		return { x: nx / d, y: ny / d };
	}
	
	@param 	coords	
	@param 	coords	
	@param 	coords	
	@param 	coords	
	@return 	bool		results
	========================================================================== */
coords lli4(coords p1, coords p2, coords p3, coords p4) {

	bool DebugMode = false;
	coords result;
	
	if ( DebugMode ) {
		std::cout << "^ Utilities::lli4() called...\n";
		std::cout << TAB1 << "p1: (" << p1.x << "," << p1.y << ")\n";
		std::cout << TAB1 << "p2: (" << p2.x << "," << p2.y << ")\n";
		std::cout << TAB1 << "p3: (" << p3.x << "," << p3.y << ")\n";
		std::cout << TAB1 << "p4: (" << p4.x << "," << p4.y << ")\n";
	}
	double  d = (p1.x - p2.x) * (p3.y - p4.y) - (p1.y - p2.y) * (p3.x - p4.x);
	if ( DebugMode ) {
		std::cout << TAB1 << "d = " << d << "\n";
	}
	if ( isEqual(d, 0.0) ) {
		if ( DebugMode ) {
			std::cout << TAB1 << "ERROR: cannot divide by 0\n";
			std::cout << "v Utilities::lli4() called...DONE|-1|\n";
		}
		return result;
	}
	
	double nx = (p1.x * p2.y - p1.y * p2.x) * (p3.x - p4.x) - (p1.x - p2.x) * (p3.x * p4.y - p3.y * p4.x);
	double ny = (p1.x * p2.y - p1.y * p2.x) * (p3.y - p4.y) - (p1.y - p2.y) * (p3.x * p4.y - p3.y * p4.x);
	
	result.x = nx / d;
	result.y = ny / d;
	
	if ( DebugMode ) {
		std::cout << TAB1 << "Result: (" << result.x << "," << result.y << ")\n";
		std::cout << "v Utilities::lli4() called...DONE|0|\n";
	}
	
	return result;
}

/*	=============================================================================
	Returns the cubic root of a number
	
	@param 	dbl	value
	@return 	dbl	cubic root
	========================================================================== */
double cubicRoot(double v) {
	double value = 0.0;
	if( v < 0 ) {\
		value = (-1.0) * pow( (-1.0 * v) , (1.0/3.0) );
	} else {
  		value = pow(v, (1.0/3.0) );
  	}
	return value;
}

/*	=============================================================================
	Checks it 0.0 <= t <= 1.0
	
	@param 	dbl	t-value
	@return 	bool	valid or not
	========================================================================== */
bool validT(double t) {

	if ( t < 0.0 || t > 1.0) return false;
	
	if ( ( t > 0.0 || isEqual(t, 0.0) ) && ( t < 1.0 || isEqual(t, 1.0) ) ) {
		return true;
	}
	return false;
}

/*	=============================================================================
	Checks it 0.0 <= t <= 1.0
	
	@param 	dbl	t-value
	@return 	bool	valid or not
	========================================================================== */
void printPoint(coords p) {
	
	std::cout << "(" << p.x << "," << p.y << ")";
	return;
}

/*	=============================================================================
	Checks if point p is on the line segement created by points s and d
	
	http://www.geeksforgeeks.org/how-to-check-if-a-given-point-lies-inside-a-polygon/
	
	@param	coords	t: test Point
	@param	coords	s: line source
	@param	coords	d: line sink
	@return	bool		t/f
	========================================================================== */
bool pointOnLine(coords p, coords s, coords d) {

	double ynum = d.y - s.y;
	double xdenom = d.x - s.x;

	if ( isEqual(ynum, 0.0) ) {
		
		double xMin, xMax;
		if ( d.x < s.x ) {
			xMin = d.x;
			xMax = s.x;
		} else {
			xMin = s.x;
			xMax = d.x;
		}
	
		// if ynum == 0, check if point is on horizontal line between s and d
		if ( isEqual(p.y, s.y) &&
			  ( ( xMin < p.x ) || isEqual( xMin, p.x) ) &&
			  ( ( xMax > p.x ) || isEqual( xMax, p.x) ) ) {
			return true;	  
		}
		
	} else if ( isEqual(xdenom, 0.0) ) {
	
		double yMin, yMax;
		if ( d.y < s.y ) {
			yMin = d.y;
			yMax = s.y;
		} else {
			yMin = s.y;
			yMax = d.y;
		}
	
		// else if xdenom == 0. check if point is on vertical line between s and d
		if ( isEqual(p.x, s.x) &&
			  ( ( yMin < p.y ) || isEqual( yMin, p.y) ) &&
			  ( ( yMax > p.y ) || isEqual( yMax, p.y) ) ) {
			return true;	  
		}
		
	} else {
	
		// else slope intercept check
		// y = mx + b
		// m = y2-y1 / x2 - x1
		double m = ynum / xdenom;
		double b = s.y - (m * s.x);
		double mxb = (m * p.x) + b;
		if ( isEqual( p.y, mxb) ) return true;
		
	}
	
	
	
	/* old
	if ( ( p.x < getMax(s.x, d.x) || isEqual(p.x, getMax(s.x, d.x) ) ) && 
		  ( p.x > getMin(s.x, d.x) || isEqual(p.x, getMin(s.x, d.x) ) ) && 
		  ( p.y < getMax(s.y, d.y) || isEqual(p.y, getMax(s.y, d.y) ) ) && 
		  ( p.y > getMin(s.y, d.y) || isEqual(p.y, getMin(s.y, d.y) ) )  
		) {
		return true;
	}
	*/

	return false;
}

/*	=============================================================================
	Checks if point p is on the line segement 
	
	http://www.geeksforgeeks.org/how-to-check-if-a-given-point-lies-inside-a-polygon/
	
	@param	coords	p: test Point
	@param	line		l: line
	@return	bool		t/f
	========================================================================== */
bool pointOnLine(coords p, line l) {
	
	
	if ( ( p.x < getMax(l.x1, l.x2) || isEqual(p.x, getMax(l.x1, l.x2) ) ) && 
		  ( p.x > getMin(l.x1, l.x2) || isEqual(p.x, getMin(l.x1, l.x2) ) ) && 
		  ( p.y < getMax(l.y1, l.y2) || isEqual(p.y, getMax(l.y1, l.y2) ) ) && 
		  ( p.y > getMin(l.y1, l.y2) || isEqual(p.y, getMin(l.y1, l.y2) ) )  
		) {
		return true;
	}
	

	return false;
}


/*	=============================================================================
	Get Indent
		
	@param 	unt		number of tabs
	@return	str		Indent space
	========================================================================== */
std::string getIndent(unsigned t) {
	std::string tab = "";
	
	switch(t) {
		case 1:
			tab = TAB1;
		break;
		
		case 2:
			tab = TAB2;
		break;
		
		case 3:
			tab = TAB3;
		break;
		
		case 4:
			tab = TAB4;
		break;
		
		case 5:
			tab = TAB5;
		break;
		
		case 6:
			tab = TAB6;
		break;
		
		case 7:
			tab = TAB7;
		break;
		
		case 8:
			tab = TAB8;
		break;
		
		case 9:
			tab = TAB9;
		break;
		
		case 10:
			tab = TAB10;
		break;
		
		case 11:
			tab = TAB10 ;
			tab += TAB1;
		break;
		
		case 12:
			tab = TAB10 ;
			tab += TAB2;
		break;
		
		case 13:
			tab = TAB10 ;
			tab += TAB3;
		break;
		
		case 14:
			tab = TAB10 ;
			tab += TAB4;
		break;
		
		case 15:
			tab = TAB10 ;
			tab += TAB5;
		break;
		
		case 16:
			tab = TAB10 ;
			tab += TAB6;
		break;
		
		case 17:
			tab = TAB10 ;
			tab += TAB7;
		break;
		
		case 18:
			tab = TAB10 ;
			tab += TAB8;
		break;
		
		case 19:
			tab = TAB10 ;
			tab += TAB9;
		break;
		
		case 20:
			tab = TAB10 ;
			tab += TAB10;
		break;
		
		default:
		
		break;
	}
	
	return tab;
}

/*	=============================================================================
	DESC
	
	@param	coords	p: test Point
	@param	line		l: line
	@return	bool		t/f
	========================================================================== */
void printpIntersect(pIntersect pI, unsigned tabCount) {
	std::string indent = getIndent(tabCount);
	
	std::cout << indent << "p: (" << pI.p.x << "," << pI.p.y << "), ";
	std::cout << "i_s: " << pI.i_s << ", t_s: " << pI.t_s << ", ";
	std::cout << "i_d: " << pI.i_d << ", t_d: " << pI.t_d << "\n";

	return;
}


/*	=============================================================================
	Print out MBR
		
	@param 	bounds	MBR
	@return	none		nothing
	========================================================================== */
void printMBR(bounds MBR, unsigned tabCount) {

	std::string indent = getIndent(tabCount);
	/*
	double x1 = 0.0;
		double y1 = 0.0;
		double x2 = 0.0;
		double y2 = 0.0;
		double r = 0.0;
		double width = x2 - x1;
		double height = y2 - y1;
		double centerX = x2 - x1;
		double centerY = y2 - y1;
		double area = (x2 - x1) * (y2 - y1);
		double radialArea = LARGE_PI * r * r; 
		unsigned id = 0;
		*/
	std::cout << indent << "From";
	std::cout << "(" << MBR.x1 << "," << MBR.y1 << ")";
	std::cout << " to ";
	std::cout << "(" << MBR.x2 << "," << MBR.y2 << ")";
	std::cout << "\n";
	std::cout << indent << "Width: " << MBR.width << ", height: " << MBR.height << "\n";
	std::cout << indent << "Centerpoint: ";
	std::cout << "(" << MBR.centerX << "," << MBR.centerY << ")\n";
	std::cout << indent << "Area: " << MBR.area << "\n";
	
	return;
}

/*	=============================================================================
	DESC
	
	@param	bounds	mbr1
	@param	bounds	mbr2
	@return	bool		t/f
	========================================================================== */
bool mbrOverlap(bounds mbr1, bounds mbr2) {

	if ( mbr1.x1 > mbr2.x2 || mbr1.x2 < mbr2.x1 ||
		  mbr1.y1 > mbr2.y2 || mbr1.y2 < mbr2.y1) {
		return false;	 
	}

	return true;
}

/*	=============================================================================
	DESC
	
	@param	dbl		val1
	@param	dbl		val2
	@param	dbl		val3
	@return	dbl		max value
	========================================================================== */
double getMax(double x, double y) {
	if ( y > x ) return y;
	return x;
}

/*	=============================================================================
	DESC
	
	@param	dbl		val1
	@param	dbl		val2
	@param	dbl		val3
	@return	dbl		max value
	========================================================================== */
double getMax(double x, double y, double z) {

	double max = x;

	if ( y > x ) {
		if ( y > z ) max = y; else max = z;
	} else if (z > x) {
		if ( z > y ) max = z; else max = y;
	}

	return max;
}

/*	=============================================================================
	DESC
	
	@param	dbl		val1
	@param	dbl		val2
	@param	dbl		val3
	@return	dbl		max value
	========================================================================== */
double getMin(double x, double y) {
	if ( y < x ) return y;
	return x;
}

/*	=============================================================================
	DESC
	
	@param	dbl		val1
	@param	dbl		val2
	@param	dbl		val3
	@return	dbl		max value
	========================================================================== */
double getMin(double x, double y, double z) {

	double min = x;

	if ( y < x ) {
		if ( y < z ) min = y; else min = z;
	} else if (z < x) {
		if ( z < y ) min = z; else min = y;
	}

	return min;
}

/*	=============================================================================
	DESC
	
	@param	unt		Number of tabs
	@return	str		String of tabs
	========================================================================== */
std::string indent(unsigned tabCount) {

	//std::cout << "indent() called with tabCount = " << tabCount << "\n";

	switch ( tabCount ) {
	
		case 1:
			return TAB1;
		break;
		
		case 2:
			return TAB2;
		break;
		
		case 3:
			return TAB3;
		break;
		
		case 4:
			return TAB4;
		break;
		
		case 5:
			return TAB5;
		break;
		
		case 6:
			return TAB6;
		break;
		
		case 7:
			return TAB7;
		break;
		
		case 8:
			return TAB8;
		break;
		
		case 9:
			return TAB9;
		break;
		
		case 10:
			return TAB10;
		break;
		
		case 11:
			return TAB11;
		break;
		
		case 12:
			return TAB12;
		break;
		
		case 13:
			return TAB13;
		break;
		
		case 14:
			return TAB14;
		break;
		
		case 15:
			return TAB15;
		break;
		
		case 16:
			return TAB16;
		break;
		
		default:
			return "";
		break;
	}
	
	return "";
	
}

/*	=============================================================================
	DESC
	
	@param	unt		Number of tabs
	@return	str		String of tabs
	========================================================================== */
unsigned toDigit( std::string s ) {

	unsigned digit = ERROR_UNT;
	
	if ( s.length() < 1 ) return digit;
	
	std::string c = s.substr(0,1);
	
	if ( c == "0" ) digit = 0;
	if ( c == "1" ) digit = 1;
	if ( c == "2" ) digit = 2;
	if ( c == "3" ) digit = 3;
	if ( c == "4" ) digit = 4;
	if ( c == "5" ) digit = 5;
	if ( c == "6" ) digit = 6;
	if ( c == "7" ) digit = 7;
	if ( c == "8" ) digit = 8;
	if ( c == "9" ) digit = 9;
	
	
	return digit;
}

/*	=============================================================================
	DESC
	
	@param	unt		Number of tabs
	@return	str		String of tabs
	========================================================================== */
double toDbl( std::string s ) {

	std::cout << "toDbl(" << s << ")\n";
	
	double result = 0.0;
	std::string c = "";
	unsigned digit = ERROR_UNT;
	bool isNegative = false;
	bool decimalFound = false;
	bool numberFound = false;
	bool numberTerminated = false;
	std::vector<unsigned>preDecimalDigits;
	std::vector<unsigned>postDecimalDigits;
	// 0-9 48-57
	// - 45
	// . 46
	
	// traverse string looking for hyphen, period, numbers
	for ( unsigned i = 0; i < s.length(); ++i ) {
	
		c = s.substr( i, 1 );
		//std::cout << "c = " << c << "\n";
		digit = toDigit( c );
		
		if ( digit != ERROR_UNT ) {
			numberFound = true;
		}
		
		if ( c == "-" && !numberFound ) {
			//std::cout << "Negative number.\n";
			isNegative = true;
		}
		
		if ( c == "." ) {
			//std::cout << "Decimal Found.\n";
			decimalFound = true;
		}
		
		// anything other than a number or 1 decimal point
		if ( digit == ERROR_UNT && numberFound) {
			//std::cout << "Number terminated.\n";
			numberTerminated = true;
		} 
		
		// Check for
		if ( !numberTerminated ) {
			if ( !decimalFound ) {
				if ( digit != ERROR_UNT ) preDecimalDigits.push_back( digit );
			} else {
				if ( digit != ERROR_UNT ) postDecimalDigits.push_back( digit );
			}
		}
	}
	
	// No number,
	if ( !numberFound ) {
		std::cout << "Double:|" << ERROR_DBL << "|\n";
		return ERROR_DBL;
	}
	
	// Process pre-decimal
	for (unsigned i = 0; i < preDecimalDigits.size(); ++i ) {
		//std::cout << preDecimalDigits.at(i) * pow(10, (preDecimalDigits.size() - (i+1) ) ) << "\n";
		result += preDecimalDigits.at(i) * pow(10, (preDecimalDigits.size() - (i+1) ) );
	}
	
	// Process post-decimal
	for (unsigned i = 0; i < postDecimalDigits.size(); ++i ) {
		//std::cout << postDecimalDigits.at(i) / pow(10, (i+1) ) << "\n";
		result += postDecimalDigits.at(i) / pow(10, (i+1) );
	}

	if ( isNegative ) result *= -1.0;
	
	std::cout << "toDbl(" << s << ") returns:|" << result << "|\n";
	
	return result;
}

/*	=============================================================================
	DESC
	
	@param	unt		Number of tabs
	@return	str		String of tabs
	========================================================================== */
int toInteger( std::string s ) {
	
	std::cout << "toInt(" << s << ")\n";
	
	int result = 0;
	std::string c = "";
	unsigned digit = ERROR_UNT;
	bool isNegative = false;
	bool numberFound = false;
	bool numberTerminated = false;
	std::vector<unsigned>preDecimalDigits;
	
	// traverse string looking for hyphen, period, numbers
	for ( unsigned i = 0; i < s.length(); ++i ) {
	
		c = s.substr( i, 1 );
		//std::cout << "c = " << c << "\n";
		digit = toDigit( c );
		
		if ( digit != ERROR_UNT ) {
			numberFound = true;
		}
		
		if ( c == "-" && !numberFound ) {
			//std::cout << "Negative number.\n";
			isNegative = true;
		}
			
		// anything other than a number or 1 decimal point
		if ( digit == ERROR_UNT && numberFound) {
			//std::cout << "Number terminated.\n";
			numberTerminated = true;
		} 
		
		// Check for
		if ( !numberTerminated ) {
			if ( digit != ERROR_UNT ) preDecimalDigits.push_back( digit );
		}
	}
	
	// No number,
	if ( !numberFound ) {
		return ERROR_INT;
	}
	
	// Process pre-decimal
	for (unsigned i = 0; i < preDecimalDigits.size(); ++i ) {
		result += preDecimalDigits.at(i) * pow(10, (preDecimalDigits.size() - (i+1) ) );
	}

	if ( isNegative ) result *= -1.0;
	
	std::cout << "toInt(" << s << ") returns:|" << result << "|\n";
	
	return result;
}

/*	=============================================================================
	DESC
	
	@param	unt		Number of tabs
	@return	str		String of tabs
	========================================================================== */
unsigned toUnt( std::string s ) {

	std::cout << "toUnt(" << s << ")\n";
	
	unsigned result = 0;
	std::string c = "";
	unsigned digit = ERROR_UNT;
	bool numberFound = false;
	bool numberTerminated = false;
	std::vector<unsigned>preDecimalDigits;
	
	// traverse string looking for hyphen, period, numbers
	for ( unsigned i = 0; i < s.length(); ++i ) {
	
		c = s.substr( i, 1 );
		digit = toDigit( c );
		
		if ( digit != ERROR_UNT ) {
			numberFound = true;
		}
			
		// anything other than a number or 1 decimal point
		if ( digit == ERROR_UNT && numberFound) {
			numberTerminated = true;
		} 
		
		// Check for
		if ( !numberTerminated ) {
			if ( digit != ERROR_UNT ) preDecimalDigits.push_back( digit );
		}
	}
	
	// No number,
	if ( !numberFound ) {
		return ERROR_UNT;
	}
	
	// Process pre-decimal
	for (unsigned i = 0; i < preDecimalDigits.size(); ++i ) {
		result += preDecimalDigits.at(i) * pow(10, (preDecimalDigits.size() - (i+1) ) );
	}
	
	
	std::cout << "toUnt(" << s << ") returns:|" << result << "|\n";

	return result;
}

/*	=============================================================================
	DESC
	
	@param	unt		Number of tabs
	@return	str		String of tabs
	========================================================================== */
std::string toUpperCase( std::string str ) {
	std::locale loc;
	for (std::string::size_type i=0; i<str.length(); ++i) {
   	str[i] = std::toupper(str[i],loc);
   }
	return str;
}

/*	=============================================================================
	DESC
	
	@param	unt		Number of tabs
	@return	str		String of tabs
	========================================================================== */
std::string toLowerCase( std::string str ) {
	std::locale loc;
	for (std::string::size_type i=0; i<str.length(); ++i) {
   	str[i] = std::tolower(str[i],loc);
   }
	return str;
}
