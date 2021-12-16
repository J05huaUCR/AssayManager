/*	=============================================================================
	Interface Class Source
	
	@version	0.1.0 - JP
	========================================================================== */

#include "Interface.h"
using namespace smhdl;

/*	=============================================================================
	Interface object constructor
	
	@param 	none
	@return 	none
	========================================================================== */
Interface::Interface() {
	init();
}

/*	=============================================================================
	Interface object destructor
	
	@param 	none
	@return 	none
	========================================================================== */
Interface::~Interface() {
	//
}

/*	=============================================================================
	(Re)Initialize Interface object with default values
	
	@param 	none
	@return 	none
	========================================================================== */
void Interface::init() {
	input = "1";
	Menu = new MenuTree();
}

/*	=============================================================================
	DESC
	
	@param 	none
	@return 	none
	========================================================================== */
int Interface::processArgs(int argc, const char* argv[] ) {

	if ( getDebugMode() > 0 ) {
		std::cout << indent( getBaseIndent() + 0 );
		std::cout << "^ Interface::processArgs() called...\n";
	}

	// Parameters
	parameter p;
	int status = 0;
	std::string flag = "";
	std::string p_str = "";
	std::size_t found;
	std::string fileName = toString(argv[0]);

	// Handle parameters passed ins
	for (int i = 1; i < argc; ++i) {
	
		flag = toString( argv[i] );
		
		if ( getDebugMode() > 1 ) {
			std::cout << indent( getBaseIndent() + 1 );
			std::cout << "Parameter " << i << ": " << flag << "\n"; 
		}
		
		// Interpret Flag and its parameters
		if ( flag.substr (0,1) == "-" ) {
		
			flag = toUpper( flag.substr(1,1) );
			if ( getDebugMode() > 1 ) std::cout << TAB3 << "Flag: " << flag << "\n";
			
			//if ( flag == "T" ) setTestMode(1);
			//if ( flag == "D" ) setDebugMode(1);
					
			// Retrieve flag value
			i++;
			p_str = toString( argv[i] );
			
			// String test
			if ( argv[i][0] >= 'A' && argv[i][0] <= 'z') {
			
				p.val_type = 1;
				p.val_str = p_str;
				
			} else {
			
				// Decimal Check
				found = p_str.find('.');
	 			if (found != std::string::npos) {
	 			
		 			if ( getDebugMode() > 1 ) {
		 				std::cout << indent( getBaseIndent() + 2 );
		 				std::cout << "Decimal found at: " << found << "\n";
		 			}
		 			p.val_dbl = toDouble( argv[i] );
		 			p.val_type = 3;
		 			
		 		} else { // integer
		 		
		 			if ( getDebugMode() > 1 ) {
		 				std::cout << indent( getBaseIndent() + 2 );
		 				std::cout << "No decimal, must be integer" << "\n";
		 			}
		 			
		 			// Positivity Check
			 		found = p_str.find('-');
			 		if (found != std::string::npos) {
			 		
			 			if ( getDebugMode() > 1 ) {
			 				std::cout << indent( getBaseIndent() + 2 );
			 				std::cout << "Negative number\n";
			 			}
			 			
			 			p.val_int = toInt( argv[i] );
			 			p.val_type = 5;
			 			
			 		} else {
			 		
			 			if ( getDebugMode() > 1) {
			 				std::cout << indent( getBaseIndent() + 2 );
			 				std::cout << "Positive number\n";
			 			}
			 			
			 			p.val_unt = toUnsigned( argv[i] );
			 			p.val_type = 4;
			 			
			 		}
		 		}
    		}
    
			if ( getDebugMode() > 1 ) {
				std::cout << indent( getBaseIndent() + 2 );
				std::cout << "Value: " << p_str << "\n";
			}
			Parameters[flag] = p;
		}
	}
	
	//setDebugMode( Parameters['D'] );
	
	if (  getDebugMode() > 0 ) {
		std::cout << indent( getBaseIndent() + 1 );
		std::cout << "For program: " << fileName << ", ";
		std::cout << "you have passed in " << (argc - 1) << " arguments:" << "\n"; 
		std::cout << indent( getBaseIndent() + 2 );
		std::cout << "Number of Parameters: " << Parameters.size() << "\n";
		printParameters();
		std::cout << indent( getBaseIndent() + 0 );
		std::cout << "v Interface::processArgs() called...DONE\n";
	}
	
	return status;
}

/*	=============================================================================
	(desc)
	
	@param 	none
	@return 	string
	========================================================================== */
std::string Interface::toUpper(std::string s) {
	char c = s[0];
	c = toupper(c);
	s[0] = c;
	return s;
}

/*	=============================================================================
	(desc)
	
	@param 	none
	@return 	string
	========================================================================== */
void Interface::printMenu() {

	if ( getDebugMode() > 0) {
		std::cout << TAB1 << "^ Interface::printMenu() called...\n";
		if ( Menu == NULL ) {
			std::cout << TAB2 << "No MenuTree Instantiated.\n";
		} else {
			std::cout << TAB2 << "MenuTree Instantiated.\n";
		}
	}
	
	if ( !MenuBuilt ) buildMenu();

	std::string MenuValues = Menu->getMenu();
	
	clearScreen();
	printf("======================================================\n");
	printf("BioReactor Framework v0.1.0                     E[x]it\n");
	printf("======================================================\n");
	std::cout << MenuValues;
	
	//Menu->printTree();
	if ( ErrorPresent) {
		printf("------------------------------------------------------\n");
		printf(ANSI_COLOR_YELLOW     "ERROR: "     ANSI_COLOR_RESET);
		std::cout << ErrorMsg << "\n";
	}
	
	printf("------------------------------------------------------\n");
	printf("Your selection? ");
	
	if ( getDebugMode() > 0) {
		std::cout << TAB1 << "v Interface::printMenu() called...DONE\n";
	}
	
	return;
}

/*	=============================================================================
	(desc)
	
	@param 	none
	@return 	string
	========================================================================== */
std::string Interface::getMenuOption() {
	return input;
}

/*	=============================================================================
	(desc)
	
	@param 	none
	@return 	string
	========================================================================== */
int Interface::setMenuOption(std::string s) {
	int status = 0;
	ErrorPresent = false;
	
	// check for exit
	if (s == "x") return 0;
	
	// Check Menu options
	status += Menu->selectMenu(s);
	if ( status < 0) {
		ErrorMsg = "\"" + s + "\" is not a valid option.";
		ErrorPresent = true;
	}
	return status;
}

/*	=============================================================================
	@brief Utilizes an escape character sequence to clear the screen
	
	@param 	none
	@return 	string
	========================================================================== */
void Interface::clearScreen() {
	std::cout << "\n"  << "\033c";
	return;
}

/*	=============================================================================
	DESC
	
	@param 	none
	@return 	none
	========================================================================== */
int Interface::buildMenu() {
	int status = 0;
	
	if ( getDebugMode() > 0) {
		std::cout << TAB1 << "^ Interface::buildMenu() called...\n";
	}
	
	MenuTree* Menu = new MenuTree();
	MenuBuilt = true;
	Menu->setDebugMode( getDebugMode() );
	
	if ( getDebugMode() > 1) {
		Menu->printTree();
		std::cout << TAB2 << "MENU is ";
		if ( Menu == NULL ) std::cout << "NOT ";
		std::cout << "present.\n";
	}
	
	if ( getDebugMode() > 0) {
		std::cout << TAB1 << "v Interface::buildMenu() called...";
		std::cout << "DONE:|" << status << "|\n";
	}
	
	return status;
}

/*	=============================================================================
	DESC
	
	@param 	none
	@return 	none
	========================================================================== */
void Interface::setBaseIndent(unsigned b) {
	if ( b > MAX_TABS ) b = MAX_TABS;
	BaseIndent = b;
	return;
}

/*	=============================================================================
	DESC
	
	@param 	none
	@return 	none
	========================================================================== */
unsigned Interface::getBaseIndent() {
	return BaseIndent;
}

/*	=============================================================================
	DESC
	
	@param 	none
	@return 	none
	========================================================================== */
int Interface::setDebugMode(unsigned d) {
	DebugMode = d;
	if ( Menu != NULL) Menu->setDebugMode(d);
	return 0;
}

/*	=============================================================================
	DESC
	
	@param 	none
	@return 	none
	========================================================================== */
unsigned Interface::getDebugMode() {
	return DebugMode;
}

/*	=============================================================================
	DESC
	
	@param 	none
	@return 	none
	========================================================================== */
int Interface::setTestMode(unsigned t) {
	TestMode = t;
	return 0;
}

/*	=============================================================================
	DESC
	
	@param 	none
	@return 	none
	========================================================================== */
unsigned Interface::getTestMode() {
	return TestMode;
}

/*	=============================================================================
	DESC
	
	@param 	none
	@return 	none
	========================================================================== */
parameter Interface::getParameter(std::string key) {
	parameter p;
	
	// If key present, return Parameter
	p_itr = Parameters.find(key);
  	if (p_itr != Parameters.end() ) return Parameters[key];
  	
	return p;
}

/*	=============================================================================
	DESC
	
	@param 	none
	@return 	none
	========================================================================== */
void Interface::printParameters() {
	for (p_itr = Parameters.begin(); p_itr != Parameters.end(); p_itr++) {
		std::cout << TAB3 << p_itr->first << ": ";
		switch( p_itr->second.val_type ) {
			case 1:
				std::cout << p_itr->second.val_str << " (string)\n";
			break;
			
			case 2:
				if ( p_itr->second.val_bool ) 
					std::cout << "true";
				else 
					std::cout << "false";
				std::cout << " (bool)\n";
			break;
			
			case 3:
				std::cout << p_itr->second.val_dbl << " (double)\n";
			break;
			
			case 4:
				std::cout << p_itr->second.val_unt << " (unsigned)\n";
			break;
			
			case 5:
				std::cout << p_itr->second.val_int << " (integer)\n";
			break;
			
			default:
				std::cout << p_itr->second.val_str << " (ERROR)\n";
			break;
		} // end switch
	}
	return;
}
