/*	=============================================================================
	AssayManager Main routine
	
	@version	0.1.1
	@author	JP
	========================================================================== */

#include "app/App.h"
#include "string.h"

using namespace smhdl;

int main( int argc, const char* argv[] ) {

	// Init
	//std::string menuInput = "";
	Interface* interface = new Interface();
	interface->setDebugMode(0);
	interface->clearScreen();

	// Process Arguments if passed in
	if (argc > 1) interface->processArgs(argc, argv);
	
	// Flag D: Debugging
	unsigned Debug = 0;
	if (interface->getParameter("D").val_unt != ERROR_UNT) {	
		Debug = interface->getParameter("D").val_unt;
	} 
	
	// Flag I: ID
	unsigned i = 0;
	if (interface->getParameter("I").val_unt != ERROR_UNT) {
		i = interface->getParameter("I").val_unt;
	}
	
	// Flag I: Label
	std::string l = "<no label>";
	if (interface->getParameter("L").val_str != ERROR_STR) {
		l = interface->getParameter("L").val_str;
	}

	// Flag C: Container Volume
	double c = 0.0;
	if (interface->getParameter("C").val_dbl != ERROR_DBL) {
		c = interface->getParameter("C").val_dbl;
	}
	
	// Flag F: Target Volume in percentage
	double f = 100.0;
	if (interface->getParameter("F").val_dbl != ERROR_DBL) {
		f = interface->getParameter("F").val_dbl;
	}
	
	// Flag R: Fill rate in units/sec
	double r = 1.0;
	if (interface->getParameter("R").val_dbl != ERROR_DBL) {
		r = interface->getParameter("R").val_dbl;
	}
	
	// Flag O: FillTarget Tolerance +/- percentage
	double o = 2.0;
	if (interface->getParameter("O").val_dbl != ERROR_DBL) {
		o = interface->getParameter("O").val_dbl;
	}

	// Flag T: Initial Temp in Celsius
	double t = 17.0;
	if (interface->getParameter("T").val_dbl != ERROR_DBL) {
		t = interface->getParameter("T").val_dbl;
	}
	
	// Flag G: Target Temperature in Celsius
	double g = 70.0;
	if (interface->getParameter("G").val_dbl != ERROR_DBL) {
		g = interface->getParameter("G").val_dbl;
	}
	
	// Flag S: Temperature change rate in Celsius /sec
	double s = 70.0;
	if (interface->getParameter("S").val_dbl != ERROR_DBL) {
		s = interface->getParameter("S").val_dbl;
	}
	
	// Flag Q: Temperature Target Tolerance +/- percentage
	double q = 1.0;
	if (interface->getParameter("Q").val_dbl != ERROR_DBL) {
		q = interface->getParameter("Q").val_dbl;
	}
	
	// Flag P: Initial Pressure in kPa
	double p = 101.0;
	if (interface->getParameter("P").val_dbl != ERROR_DBL) {
		p = interface->getParameter("P").val_dbl;
	}
	
	// Flag K: Rate of pressure change in kPa /sec
	double k = 5.0;
	if (interface->getParameter("K").val_dbl != ERROR_DBL) {
		k = interface->getParameter("K").val_dbl;
	}
	
	// Flag M: Maximum Pressure in kPa
	double m = 200.0;
	if (interface->getParameter("M").val_dbl != ERROR_DBL) {
		m = interface->getParameter("M").val_dbl;
	}
		
	// Flag H: Initla Ph
	double h = 7.0;
	if (interface->getParameter("H").val_dbl != ERROR_DBL) {
		h = interface->getParameter("H").val_dbl;
	}

	BioReactor* br1 = new BioReactor(i,l,c,f,r,o,t,g,s,q,p,k,m,h);
	br1->run();
	br1->exportStatus();
	br1->exportReport();
	if (Debug) {
		br1->setDebugMode(Debug);
		std::cout << "INFO ====================================\n";
		br1->print();
		br1->run();
		std::cout << "INFO ====================================\n";
		br1->print();
		std::cout << "STATUS ====================================\n";
		std::cout << br1->getStatus() << endl;
		std::cout << "BATCH RECORD ====================================\n";
		std::cout << br1->getReport() << endl;
	}
	return 0;
}


