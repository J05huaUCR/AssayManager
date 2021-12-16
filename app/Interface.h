/*	=============================================================================
	Interface Class Definition
	
	@version	0.1.0 - JP
	========================================================================== */

#ifndef INTERFACE_H_
#define INTERFACE_H_

#include <stdio.h>      /* printf, scanf, NULL */
#include <iostream>		/* input, output */
#include "string.h"			/* string library */
#include "MenuTree.h"
#include "Structs.h"		//
#include "Utilities.h"
#include <map>

#define ANSI_COLOR_BLACK   "\x1b[30m"
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_WHITE   "\x1b[37m"
#define ANSI_COLOR_RESET   "\x1b[0m"

namespace smhdl {

	class Interface {
		
		public:
			Interface();
			~Interface();
			void init();
			
			/* ==================================================================== */	
			// Modifiers
			/* ==================================================================== */	
			void setBaseIndent(unsigned);
			int setDebugMode(unsigned);
			int setTestMode(unsigned);
			int processArgs(int, const char*[] );	
			int buildMenu();
			int setMenuOption(std::string);
			std::string toUpper(std::string);
			
			/* ==================================================================== */	
			// Retrievers
			/* ==================================================================== */	
			std::string getMenuOption();
			void clearScreen();
			void printMenu();
			unsigned getBaseIndent();
			unsigned getDebugMode();
			unsigned getTestMode();
			parameter getParameter(std::string);
			void printParameters();
			
			
			/* ==================================================================== */	
			// TO DO
			/* ==================================================================== */	
			
			
			
			
		private:
			/* Object identifier <id> */
			std::string input;
			std::string ErrorMsg = "";
			bool ErrorPresent = false;
			
			/* Associative array to hold parameters */
			std::map<std::string, smhdl::parameter> Parameters;
			std::map<std::string, smhdl::parameter>::iterator p_itr;
			
			
			unsigned DebugMode = 0;		// Debug mode
			unsigned TestMode = 0;		// Test Mode
			unsigned BaseIndent = 0;	
			
			/* Navigation */
			MenuTree* Menu;
			bool MenuBuilt = false;

	};

} // end namespace

#endif 
