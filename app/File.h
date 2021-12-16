/* ===========================================================================
	File Management Object Header
	
	@version	0.1.1 - JP
	==========================================================================*/
#ifndef FILE_H_
#define FILE_H_

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class File {
	
	public:
		 File(); 						// Constructor
		 File(							// Constructor with
		 	std::string); 				// 	this Filename
		 File(							// Constructor with
		 	std::string,				//		this filename
		 	std::string); 				//		these contents
		~File(); 						// Destructor

		// Modifiers
		int empty();					// dump contents
		int open(
			std::string);				// File Name
		int write();					// Write contents to file name
		int write(
			std::string);				// Write with specified filename and contents
		int write(
			std::string, 				// Specify File name
			std::string);				// and File contents
		int parse(
			std::string);				// Splits string by new line
		int flushBuffer();	
		
		// Retrievers
		unsigned getLineCount();	// Gets the line count of the file
		string getContentsAt(
			unsigned);
		

		// <<<<<<<<<<<<<<<<<<<<<<<<<  TO DO  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>	
		string getContents();
		string getBuffer();

		// <<<<<<<<<<<<<<<<<<<<<<<<<  TO DO  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
		
	private:
		vector< std::string > fileContents;
		std::string buffer = "";
		char* fileName;
};

#endif /* FILE */
