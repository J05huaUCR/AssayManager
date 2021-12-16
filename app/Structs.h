/*	=============================================================================
	Structs Header
	
	@version	0.1.1
	@author	JP
	========================================================================== */

#ifndef STRUCTS_H_
#define STRUCTS_H_

#include <string>						// C++ String Class
#include <math.h>						// Math functions

// Important constants
#define TOLERANCE 0.00000001		// Degree of accurary
#define POINT_MATCH_TOLERANCE 0.000001		// Degree of accurary
#define LARGE_PI 3.141592653589793 // PI for precision
#define PI_2_RAD 1.570796327		// PI/2 Radians
#define PI_3_2_RAD 4.71238898		// PI*(3/2) Radians
#define LARGE_2_PI 6.283185307179586 // 2* PI
#define DEG_2_RAD 0.0174532925 	// converting degrees into radians
#define DECIMAL_PLACES 6			// Decimal places (resolution)
#define ERROR_INT -2147483647		// Error size of signed int
#define ERROR_UNT  2147483647		// Error size of unsigned int
#define ERROR_FLT -9999.9			// Error size of float
#define ERROR_DBL -9999.9			// Error size of double
#define ERROR_STR "ERROR"			// Error string
#define MIN_UNT 0						// Max Unsigned value
#define MIN_INT -2147483647		// Max Integer value
#define MIN_FLT -2147483647.00	// Max Double value
#define MIN_DBL -2147483647.00	// Max Double value
#define MAX_UNT 2147483647			// Max Unsigned value
#define MAX_INT 2147483647			// Max Integer value
#define MAX_FLT 2147483647.00		// Max Double value
#define MAX_DBL 2147483647.00		// Max Double value
#define MAX_VERTICES 32768			// arbitrary max number of vertices in polygon
#define MAX_BOUNDARY 1000000.0	// arbitrary max value
#define ARC_DIVISIONS 100			// Used for approximating Bezier length
#define KAPPA 0.5522847498			// Converting circles l = r * k
#define DIV_BY_0 0.000000000001	// Used when a divisor calculates to zero (avoid NaN in calculations)
#define ABS_ZERO_C -273
#define ABS_ZERO_K 0
#define ABS_ZERO_F 773
#define MAX_C 450
#define MAX_K 450
#define MAX_F 450
#define INIT_HUMID 85
#define INIT_SCALE 'C'
#define INIT_TEMP 23.0
#define INIT_PRESSURE 168.15
#define MAX_CURVE_TO_LINES 16		// The amount of subdivisions when converting
											// a Bezier curve to approximate lines

// Names
#define FILE_NAME_OUTPUT			"InfoDump"

#define LAYOUT_LABEL_DEFAULT		"<Layout>"
#define LAYOUT_ID_DEFAULT 			"layout0"
#define SUBSTRATE_LABEL_DEFAULT	"<Substrate>"
#define PAGE_LABEL_DEFAULT			"<Page>"
#define PAGE_ID_DEFAULT 			"page0"
#define PAGE_WIDTH_DEFAULT  		200
#define PAGE_HEIGHT_DEFAULT 		123
#define DEVICE_LABEL_DEFAULT		"<Device>"
#define DEVICE_ID_DEFAULT 			"dev0"
#define COMPONENT_LABEL_DEFAULT	"<Component>"
#define COMPONENT_ID_DEFAULT 		"_comp0"
#define PRIMITIVE_LABEL_DEFAULT	"<Primitive>"
#define PRIMITIVE_ID_DEFAULT 		"_prim0"
#define PATH_LABEL_DEFAULT			"<Path>"
#define PATH_ID_DEFAULT 			"_path0"
#define LAYER_LABEL_DEFAULT		"<Layer>"
#define LAYER_ID_DEFAULT 			"_layer0"
#define LAYER_ID_BORDER 			"border"
#define LAYER_ID_OBJECT 			"object"
#define LAYER_NAME_MBR 				"MBRs"
#define LAYER_NAME_MBC 				"MBCs"
#define LAYER_LABEL_REGISTRATION "<Registration Marks>"
#define LAYER_ID_REGISTRATION 	"_registration"
#define LAYER_NAME_REGISTRY 		"<LayerRegistry>"
#define LAYER_NAME_OUTLINES 		"<Outlines>"

#define X_POS							"X_POS"
#define Y_POS							"Y_POS"
#define X_NEG							"X_NEG"
#define Y_NEG							"Y_NEG"
#define X_MAX							"X_MAX"
#define Y_MAX							"Y_MAX"
#define X_MIN							"X_MIN"
#define Y_MIN							"Y_MIN"

// Prefixes
#define PREFIX_LAYOUT_ID 			"layout"
#define PREFIX_PAGE_ID	 			"page"
#define PREFIX_SUBSTRATE_ID		"_substrate"
#define PREFIX_LAYER_ID	 			"_layer"
#define PREFIX_DEVICE 				"dev"
#define PREFIX_COMPONENT			"_comp"
#define PREFIX_PRIMITIVE			"_prim"
#define PREFIX_PATH 					"_path"
#define PREFIX_SEG 					"_segment"
#define PREFIX_ARC 					"_arc"
#define PREFIX_LINE 					"_line"
#define PREFIX_MBR_ID	 			"mbr"
#define PREFIX_MBC_ID	 			"mbc"
#define PREFIX_PORT_ID				"_port"
#define PREFIX_PORT_IN 				"_in"
#define PREFIX_PORT_OUT 			"_out"

// Postfixes
#define POSTFIX_REGISTRY   		"_registry"
#define POSTFIX_OUTLINE    		"_outline"
#define POSTFIX_SCALE  			   "_scale"
#define POSTFIX_BOUNDS				"_bounds"
#define POSTFIX_COLOR				"_color"
#define POSTFIX_FILL					"_fill"
#define POSTFIX_STROKE				"_stroke"
#define POSTFIX_VALUE				"_VALUE"
#define POSTFIX_MIN					"_MIN"
#define POSTFIX_MAX					"_MAX"

// TABs
#define MAX_TABS 15
#define TAB1  "   "
#define TAB2  "      "
#define TAB3  "         "
#define TAB4  "            "
#define TAB5  "               "
#define TAB6  "                  "
#define TAB7  "                     "
#define TAB8  "                        "
#define TAB9  "                           "
#define TAB10 "                              "
#define TAB11 "                                 "
#define TAB12 "                                    "
#define TAB13 "                                       "
#define TAB14 "                                          "
#define TAB15 "                                             "
#define TAB16 "                                                "

// Structures for Class
namespace smhdl {

	// Primitive Types
	enum pTYPES {
		UNDEF, // 0
		ARC, // 1
		LINE, // 2
		CIRCLE, // 3
		POLYGON, // 4
		PATH, // 5
		ELLIPSE, // 6
		BLOB, // 7
		RECTANGLE, // 8
		TEXT // 9
	};
	
	// Object Types
	enum objTYPES {
		UNDEFINED, // 0
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

	/*
	FluidicMultiplexer
	FoldingCard
	FourChanneluPAD
	ImmunoSensor
	LateralFlowTest
	OnButtons
	Titration
	*/
	
	// Device Types
	enum devTYPES {
		DEFAULTDEV, 	// 0
		BULLSEYE, 		// 1
		RACEWAY, 		// 2
		RFA, 				// 3
		REGISTRATION 	// 4
	};
	
	/*
	RegPoint
	Ticks
	VariTimer
	*/			
	// Component Types
	enum cmpTYPES {
		DEFAULTCMP, 	// 0
		CHANNEL, 		// 1
		WELL, 			// 2
		VARESISTOR, 	// 3
		VIA 				// 4
	};
	
	// Dimension Types
	enum dimTYPES {
		UNDEF_DIM, 		// 0
		UNSIGNED, 		// 1
		INTEGER,			// 2
		FLOAT, 			// 3
		DOUBLE 			// 4
	};
	
	// Span Types
	enum dimSpanTypes {
		DISCRETE, 		// 0: one immutable discrete value
		VALUE, 			// 1: one mutable value
		SPAN				// 2: spans 2 mutable values
	};
	
	// Optimization Mode Types
	enum dimModeTypes {
		NEUTRAL, 		// 0: Neutral, not optimizing
		MINIMIZE, 		// 1: Seek miniminum value
		MAXIMIZE, 		// 2: Seek maximum value
		ACCRUE,			// 3: Sum values as added
		DOMINATE,		//	4:	This dimension dominates non-dominant dimensions
		GROUP				//	5:	After dominants, groups gather other dimensions together
	};
						
	struct area {
		double w = 0.0;
		double h = 0.0;
	};
	
	struct bounds {
		double x1 				= 0.0;
		double y1 				= 0.0;
		double z1 				= 0.0;
		double x2 				= 0.0;
		double y2 				= 0.0;
		double z2 				= 0.0;
		double r 				= 0.0;
		double width 			= x2 - x1;
		double height 			= y2 - y1;
		double depth 			= z2 - z1;
		double centerX 		= x1 + (width * 0.5);
		double centerY 		= y1 + (height * 0.5);
		double centerZ 		= z1 + (depth * 0.5);
		double area 			= width * height;
		double volume 			= width * height * depth;
		double radialArea 	= LARGE_PI * r * r; 
		double radialVolume 	= LARGE_PI * r * r * r; 
		unsigned id 			= 0;
	};
	
	struct coords {
		double x 	= ERROR_DBL;		// x-value
		double y 	= ERROR_DBL;		// y-value
		double z 	= ERROR_DBL;		// z-value
		double t 	= ERROR_DBL;		// Parametric value for Bezier curve
		unsigned i 	= ERROR_UNT;		// Useful for index or id's
	};
	
	struct connectPoint {
		std::string id;				// connection id
		
		std::string idSource;		// id of Component source component
		std::string portSource;		// id of Source Port
		double sourceWidth;			// Width of port at source
		coords pSource;				// Location of the source
		
		std::string idSink;			// id of Component sink component
		std::string portSink;		// id of Sink Port
		double sinkWidth;				// Width of port at sink
		coords pSink;					//	Location of the sink
	};
	
	struct curve {
		bool startSmooth = false;
		bool endSmooth = false;
		coords source;
		coords sourceHandle;
		coords dest;
		coords destHandle;
	};

	struct line {
		double x1 = 0.0;				// soure x
		double y1 = 0.0;				// soure y
		double x2 = 0.0;				// sink x
		double y2 = 0.0;				// sink y
		double width = 0.0;
		double length = sqrt( 
							 pow((x2 - x1),2) + 
							 pow((x2 - x1),2) 
							 );			// delta x, delta y
		double angle = 0.0;   		// angle of rotation
	};
	
	struct volume {
		double width  = 0.0;
		double height = 0.0;
		double depth  = 0.0;
	};

	struct aperature {
		double thetaAlphaStart	= 0.0;
		double thetaAlphaEnd 	= 360.0;
		double thetaOmegaStart	= 0.0;
		double thetaOmegaEnd		= 360.0;
	};
	
	struct pIntersect {
		unsigned i_s 	= ERROR_UNT; 	// Segment Index into Source
		unsigned i_d 	= ERROR_UNT; 	// Segment Index into Destination
		double t_s 		= ERROR_DBL;	// t value on Source
		double t_d 		= ERROR_DBL;	// t value on Destination
		coords p;							// Intersection Point on source
		coords p_d;							// Intersection Point on test
		bool overlap 	= false;			// Is this intersection coincident
	};
	
	struct quadTuple {
		double d1 = 0.0;
		double d2 = 0.0;
		double d3 = 0.0;
		double d4 = 0.0;
		
		// assignment operator modifies object, therefore non-const
		quadTuple& operator=(const quadTuple& a) {
			d1=a.d1;
			d2=a.d2;
			d3=a.d3;
			d4=a.d4;
			return *this;
		}
		
		bool operator < (const quadTuple& o) {
			return o.d1 < d1;
		} 
	};
	
	struct parameter {
		unsigned val_type 	= 0; 				// 0 = ERROR, not set
		std::string val_str 	= ""; 			// 1
		bool val_bool 			= false;		 	// 2
		double val_dbl 		= ERROR_DBL; 	// 3
		unsigned val_unt 		= ERROR_UNT; 	// 4
		int val_int 			= ERROR_INT; 	// 5
	};
}

using namespace smhdl;

#endif
