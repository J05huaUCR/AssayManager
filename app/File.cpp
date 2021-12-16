/* ===========================================================================
	File Management Object Source Code
	
	@version	0.1.1 - JP
	==========================================================================*/

#include "File.h"

/*	==========================================================================
	Default File constructor
	
	@param 	null		nothing
	@return 	null		nothing
	========================================================================== */
File::File() {
	//init(false, false);
}

/*	==========================================================================
	Default File constructor
	
	@param 	null		nothing
	@return 	null		nothing
	========================================================================== */
File::File(string fn) {
	if (fn == "") fn = "file.txt";
	fileName = const_cast<char*> ( fn.c_str() );
}

/*	==========================================================================
	Default File constructor
	
	@param 	null		nothing
	@return 	null		nothing
	========================================================================== */
File::File(string fn, string contents) {
	if (fn == "") fn = "file.txt";
	fileName = const_cast<char*> ( fn.c_str() );
}

/*	==========================================================================
	Destructor
	
	@param 	null		nothing
	@return 	null		nothing
	========================================================================== */
File::~File() {
	// Code here executed on object deletion
}

/*	==========================================================================
	Parse File
	
	@param 	null		nothing
	@return 	null		nothing
	========================================================================== */
int File::open(string fn) {

	// Input Check
	if (fn == "") return -1; 
	
	empty();
	flushBuffer();
	
	// Init
	int status = 0;
	string line;
	ifstream myReadFile;
	myReadFile.open( fn.c_str() );
	
	if ( !myReadFile.good() ) return -1; 	
	
	//char output[100];
	
	if (myReadFile.is_open()) {
		/* by spaces
		while (!myReadFile.eof()) {
			//myReadFile.getline() >> output;
			myReadFile >> output;
			cout<<output << "\n";
			fileContents.push_back( output);
		}*/
		
		// by line
		while (std::getline(myReadFile, line)) {
			buffer += line;
			//cout << line << "\n";
			fileContents.push_back( line );
		}  
	}

	//cout << "size of fileContents: " << fileContents.size() << ".\n";
	
	myReadFile.close();

	return status;
}

/*	==========================================================================
	Write to file
	
	@param 	null		nothing
	@return 	null		nothing
	========================================================================== */
int File::write() {

	ofstream outputFile;
	outputFile.open(fileName);
	for (unsigned i = 0; i < fileContents.size(); i++) {
		outputFile << fileContents[i] << "\n";
	}
	outputFile.close(); // close output file stream
		
	return 0;
}

/*	==========================================================================
	Write to file
	
	@param 	null		nothing
	@return 	null		nothing
	========================================================================== */
int File::write(string fn) {

	if (fn == "") fn = "file.txt";
	fileName = const_cast<char*> ( fn.c_str() );	

	return write();
}

/*	==========================================================================
	Write to file
	
	@param 	null		nothing
	@return 	null		nothing
	========================================================================== */
int File::write(string fn, string output) {

	if (fn == "") fn = "file.txt";
	fileName = const_cast<char*> ( fn.c_str() );
	empty();
	parse(output);

	return write();
}

/*	==========================================================================
	DESC
	
	@param 	null		nothing
	@return 	null		nothing
	========================================================================== */
int File::empty() {
	while (fileContents.size() > 0) {
		fileContents.erase(fileContents.begin());
	}
	return 0;
}

/*	==========================================================================
	DESC
	
	@param 	null		nothing
	@return 	null		nothing
	========================================================================== */
int File::parse(string contents) {

	char* parsed = const_cast<char*> ( contents.c_str() );
	std::stringstream ss(parsed);
	std::string line;

	if (parsed != NULL) {
		while(std::getline(ss,line,'\n')){
			//cout << line << "\n";
			fileContents.push_back(line);
		}
	}

	return 0;
}

/*	==========================================================================
	DESC
	
	@param 	null		nothing
	@return 	null		nothing
	========================================================================== */
int File::flushBuffer() {
	buffer = "";
	return 0;
}

/*	==========================================================================
	DESC
	
	@param 	null		nothing
	@return 	null		nothing
	========================================================================== */
unsigned File::getLineCount() {
	return fileContents.size();
}

/*	==========================================================================
	DESC
	
	@param 	null		nothing
	@return 	null		nothing
	========================================================================== */
std::string File::getContentsAt(unsigned i) {
	if (i < fileContents.size() ) return fileContents[i];
	return "";
}

/*	==========================================================================
	DESC
	
	@param 	null		nothing
	@return 	null		nothing
	========================================================================== */
std::string File::getContents() {
	std::string contents = "";
	for (unsigned i = 0; i < fileContents.size(); i++) {
		contents += fileContents[i];
	}
	return contents;
}

/*	==========================================================================
	DESC
	
	@param 	null		nothing
	@return 	null		nothing
	========================================================================== */
std::string File::getBuffer() {
	return buffer;
}
