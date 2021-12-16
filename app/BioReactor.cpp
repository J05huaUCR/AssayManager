/*	=============================================================================
	BioRector Class Source
	
	@version	0.1.1
	@author	JP
	========================================================================== */

#include "BioReactor.h"

/*	=============================================================================
	BioRector object constructor
	
	@param 	none
	@return 	none
	========================================================================== */
BioReactor::BioReactor() {
	init();
}

/*	=============================================================================
	BioRector object constructor
	
	BioReactor(
			unsigned,		// ID
			std::string,	// Label
			double,			// Container Size unit
			double,			// Container fill target in percentage of fill /container
			double,			// Container fill rate unit/sec
			double,			// Fill tolerance +/- percent of fill /container size
			double,			// Temperature
			double,			// Temperature target
			double,			// Temperature tolerance +/- C
			double,			// Temperature change rate C/sec
			double,			// Pressure in kPa
			double,			// Pressure change rate kPa/sex
			double			// Max Pressure in kPa
			);
	
	@param 	unt			// ID
	@param 	str,			// Label
	
	@param 	dbl,			// Container Size unit
	@param 	dbl,			// Container fill target in percentage of fill /container
	@param 	dbl,			// Container fill rate unit/sec
	@param 	dbl,			// Fill tolerance +/- percent of fill /container size
	
	@param 	dbl,			// Initial Temperature
	@param 	dbl,			// Temperature target
	@param 	dbl,			// Temperature change rate C/sec
	@param 	dbl,			// Temperature tolerance +/- C
	
	@param 	dbl,			// Initial Pressure in kPa
	@param 	dbl,			// Pressure change rate kPa/sex
	@param 	dbl,			// Max Pressure in kPa
	
	@param 	dbl,			// Initial Ph
	@return 	none
	========================================================================== */
BioReactor::BioReactor( unsigned i, std::string l, 
								double c, double f, double r, double o, // Volume
								double t, double g, double s, double q, // Temp
								double p, double k, double m, 			 // Pressure
								double h // Ph 
								) {
	
	// Base Initialization
	init();
	
	// Class
	setID( i );
	setLabel( l);
	
	// Volume
	setContainerVolume( c );
	setFillTarget( f );
	setFillRate( r ); 
	setFillLevelTolerance( o);
	
	// Temperature
	setCurrentTemp( t );
	setTempTarget( g );
	setTempRate( s );
	setTempTolerance( q );
	
	// Pressure
	setCurrentPressure( p );
	setPressureRate( k );
	setMaxPressure( m );// kPa
	
	// Ph
	setCurrentPh( h );
}

/*	=============================================================================
	BioRector object destructor
	
	@param 	none
	@return 	none
	========================================================================== */
BioReactor::~BioReactor() {
	//
}

/*	=============================================================================
	(Re)Initialize BioReactor object with default values
	
	@param 	none
	@return 	none
	========================================================================== */
void BioReactor::init() {
	
	// Class
	setID( 0 );
	setLabel( "<default>" );
	setTotalTime( 0.0 );
	
	// Volume
	setContainerVolume(15.0);
	setFillLevel( 0.0 );
	setFillTarget( 0.0 );
	setFillPercentage( 0.0 );
	setFillRate( 0.0 ); 
	setFillLevelTolerance( 1.0 );
	
	// Temperature
	setCurrentTemp( 22.0 );
	setTempTarget( 0.0 );
	setTempTolerance( 1.0 );
	setTempRate( 0.0 );
	
	// Pressure
	setCurrentPressure( 100.1 );
	setPressureRate( 0.0 );
	setMaxPressure( 1.0 );// kPa
	
	// Ph
	setCurrentPh( 7.0 );
	setPhMin(7.0);
	setPhMax(7.0);

	// Valves
	InputValveOpen = false;
	OutputValveOpen = false;
	
	// Initial State
	Status = IDLE;
	
	return;
}

/*	=============================================================================
	desc
	
	@param 	none
	@return 	none
	========================================================================== */
int BioReactor::setID(unsigned id) {
	ID = id;
	return 0;
}

/*	=============================================================================
	desc
	
	@param 	none
	@return 	none
	========================================================================== */
unsigned BioReactor::getID() {
	return ID;
}

/*	=============================================================================
	desc
	
	@param 	none
	@return 	none
	========================================================================== */
int BioReactor::setLabel(std::string s) {
	Label = s;
	return 0;
}

/*	=============================================================================
	desc
	
	@param 	none
	@return 	none
	========================================================================== */
std::string BioReactor::getLabel() {
	return Label;
}

/*	=============================================================================
	desc
	
	@param 	none
	@return 	none
	========================================================================== */
int BioReactor::setTotalTime(double t) {
	TotalTime = t;
	return 0;
}

/*	=============================================================================
	desc
	
	@param 	none
	@return 	none
	========================================================================== */
double BioReactor::getTotalTime() {
	return TotalTime;
}

/*	=============================================================================
	desc
	
	@param 	none
	@return 	none
	========================================================================== */
int BioReactor::setCurrentTemp(double t) {
	CurrentTemp = t;
	return 0;
}

/*	=============================================================================
	desc
	
	@param 	none
	@return 	none
	========================================================================== */
double BioReactor::getCurrentTemp() {
	return CurrentTemp;
}

/*	=============================================================================
	desc
	
	@param 	none
	@return 	none
	========================================================================== */
int BioReactor::setTempTarget(double t) {
	TempTarget = t;
	return 0;
}

/*	=============================================================================
	desc
	
	@param 	none
	@return 	none
	========================================================================== */
double BioReactor::getTempTarget() {
	return TempTarget;
}

/*	=============================================================================
	desc
	
	@param 	none
	@return 	none
	========================================================================== */
int BioReactor::setTempRate(double t) {
	TempRate = t;
	return 0;
}

/*	=============================================================================
	desc
	
	@param 	none
	@return 	none
	========================================================================== */
double BioReactor::getTempRate() {
	return TempRate;
}

/*	=============================================================================
	desc
	
	@param 	none
	@return 	none
	========================================================================== */
int BioReactor::setTempMin(double t) {
	TempMin = t;
	return 0;
}

/*	=============================================================================
	desc
	
	@param 	none
	@return 	none
	========================================================================== */
double BioReactor::getTempMin() {
	return TempMin;
}

/*	=============================================================================
	desc
	
	@param 	none
	@return 	none
	========================================================================== */
int BioReactor::setTempMax(double t) {
	TempMax = t;
	return 0;
}

/*	=============================================================================
	desc
	
	@param 	none
	@return 	none
	========================================================================== */
double BioReactor::getTempMax() {
	return TempMax;
}

/*	=============================================================================
	desc
	
	@param 	none
	@return 	none
	========================================================================== */
int BioReactor::setCurrentPressure(double p) {
	CurrentPressure = p;
	return 0;
}

/*	=============================================================================
	desc
	
	@param 	none
	@return 	none
	========================================================================== */
double BioReactor::getCurrentPressure() {
	return CurrentPressure;
}

/*	=============================================================================
	desc
	
	@param 	none
	@return 	none
	========================================================================== */
int BioReactor::setPressureRate(double p) {
	PressureRate = p;
	return 0;
}

/*	=============================================================================
	desc
	
	@param 	none
	@return 	none
	========================================================================== */
double BioReactor::getPressureRate() {
	return PressureRate;
}

/*	=============================================================================
	desc
	
	@param 	none
	@return 	none
	========================================================================== */
int BioReactor::setPressureMin(double p) {
	PressureMin = p;
	return 0;
}

/*	=============================================================================
	desc
	
	@param 	none
	@return 	none
	========================================================================== */
double BioReactor::getPressureMin() {
	return PressureMin;
}

/*	=============================================================================
	desc
	
	@param 	none
	@return 	none
	========================================================================== */
int BioReactor::setPressureMax(double p) {
	PressureMax = p;
	return 0;
}

/*	=============================================================================
	desc
	
	@param 	none
	@return 	none
	========================================================================== */
double BioReactor::getPressureMax() {
	return PressureMax;
}

/*	=============================================================================
	desc
	
	@param 	none
	@return 	none
	========================================================================== */
int BioReactor::setCurrentPh(double ph) {
	CurrentPh = ph;
	return 0;
}

/*	=============================================================================
	desc
	
	@param 	none
	@return 	none
	========================================================================== */
double BioReactor::getCurrentPh() {
	return CurrentPh;
}

/*	=============================================================================
	desc
	
	@param 	none
	@return 	none
	========================================================================== */
int BioReactor::setPhMin(double p) {
	PhMin = p;
	return 0;
}

/*	=============================================================================
	desc
	
	@param 	none
	@return 	none
	========================================================================== */
double BioReactor::getPhMin() {
	return PhMin;
}

/*	=============================================================================
	desc
	
	@param 	none
	@return 	none
	========================================================================== */
int BioReactor::setPhMax(double p) {
	PhMax = p;
	return 0;
}

/*	=============================================================================
	desc
	
	@param 	none
	@return 	none
	========================================================================== */
double BioReactor::getPhMax() {
	return PhMax;
}

/*	=============================================================================
	desc
	
	@param 	none
	@return 	none
	========================================================================== */
int BioReactor::setTempRange() {

	if ( RunningTemp.size() == 1 ) {
		setPhMin( RunningTemp.at(8) );
		setPhMax( RunningTemp.at(8) );
	} else {
		double min = INFINITY;
		double max = -INFINITY;
		
		for ( unsigned i = 0; i < RunningTemp.size(); i++) {
			if ( RunningTemp.at(i) < min ) min = RunningTemp.at(i);
			if ( RunningTemp.at(i) > max ) max = RunningTemp.at(i);
		}
		
		setPhMin(min);
		setPhMax(max);
	}
	return 0;
}

/*	=============================================================================
	desc
	
	@param 	none
	@return 	none
	========================================================================== */
int BioReactor::setPressureRange() {

	if ( RunningPressure.size() == 1 ) {
		setPhMin( RunningPressure.at(8) );
		setPhMax( RunningPressure.at(8) );
	} else {
		double min = INFINITY;
		double max = -INFINITY;
		
		for ( unsigned i = 0; i < RunningPressure.size(); i++) {
			if ( RunningPressure.at(i) < min ) min = RunningPressure.at(i);
			if ( RunningPressure.at(i) > max ) max = RunningPressure.at(i);
		}
		
		setPhMin(min);
		setPhMax(max);
	}
	return 0;
}

/*	=============================================================================
	desc
	
	@param 	none
	@return 	none
	========================================================================== */
int BioReactor::setPhRange() {
	
	if ( RunningPh.size() == 1 ) {
		setPhMin( RunningPh.at(8) );
		setPhMax( RunningPh.at(8) );
	} else {
		double min = INFINITY;
		double max = -INFINITY;
		
		for ( unsigned i = 0; i < RunningPh.size(); i++) {
			if ( RunningPh.at(i) < min ) min = RunningPh.at(i);
			if ( RunningPh.at(i) > max ) max = RunningPh.at(i);
		}
		
		setPhMin(min);
		setPhMax(max);
	}
	
	return 0;
}

/*	=============================================================================
	desc
	
	@param 	none
	@return 	none
	========================================================================== */
int BioReactor::setContainerVolume(double cv) {
	ContainerVolume = cv;
	return 0;
}

/*	=============================================================================
	desc
	
	@param 	none
	@return 	none
	========================================================================== */
double BioReactor::getContainerVolume() {
	return ContainerVolume;
}

/*	=============================================================================
	desc
	
	@param 	none
	@return 	none
	========================================================================== */
int BioReactor::setFillTarget(double v) {
	if ( v <   0.0 ) v = 0.0;
	if ( v > 100.0 ) v = 100.0;
	FillTarget = v;
	return 0;
}

/*	=============================================================================
	desc
	
	@param 	none
	@return 	none
	========================================================================== */
double BioReactor::getFillTarget() {
	return FillTarget;
}

/*	=============================================================================
	desc
	
	@param 	none
	@return 	none
	========================================================================== */
int BioReactor::setFillLevel(double f) {
	FillLevel = f;
	if ( f > 0.0 ) ( setFillPercentage( getContainerVolume() / f ) * 100.0);
	return 0;
}

/*	=============================================================================
	desc
	
	@param 	none
	@return 	none
	========================================================================== */
double BioReactor::getFillLevel() {
	return FillLevel;
}

/*	=============================================================================
	desc
	
	@param 	none
	@return 	none
	========================================================================== */
int BioReactor::setFillRate(double f) {
	if ( f > 100.0 ) f = 100.0;
	FillRate = f;
	return 0;
}

/*	=============================================================================
	desc
	
	@param 	none
	@return 	none
	========================================================================== */
double BioReactor::getFillRate() {
	return FillRate;
}

/*	=============================================================================
	desc
	
	@param 	none
	@return 	none
	========================================================================== */
int BioReactor::setFillPercentage(double f) {
	FillPercentage = f;
	return 0;
}

/*	=============================================================================
	desc
	
	@param 	none
	@return 	none
	========================================================================== */
double BioReactor::getFillPercentage() {
	return FillPercentage;
}

/*	=============================================================================
	desc
	
	@param 	none
	@return 	none
	========================================================================== */
int BioReactor::setFillLevelTolerance(double f) {
	if ( f <   0.0 ) f = 0.0;
	if ( f > 100.0 ) f = 100.0;
	FillLevelTolerance = f;
	return 0;
}

/*	=============================================================================
	desc
	
	@param 	none
	@return 	none
	========================================================================== */
double BioReactor::getFillLevelTolerance() {
	return FillLevelTolerance;
}

/*	=============================================================================
	desc
	
	@param 	none
	@return 	none
	========================================================================== */
int BioReactor::setVolumeState(RANGE s) {
	VolumeState = s;
	return 0;
}

/*	=============================================================================
	desc
	
	@param 	none
	@return 	none
	========================================================================== */
RANGE BioReactor::getVolumeState() {
	return VolumeState;
}

/*	=============================================================================
	desc
	
	@param 	none
	@return 	none
	========================================================================== */
std::string BioReactor::getVolumeStateAsString() {
	std::string results = "";
	
	switch( getVolumeState() ) {
		case BELOW:
			results = "BELOW";
		break;
		
		case ABOVE:
			results = "ABOVE";
		break;
		
		case OK:
			results = "OK";
		break;
	
		default:
			results = "<no state>";
		break;
	}
	
	return results;
}

/*	=============================================================================
	desc
	
	@param 	none
	@return 	none
	========================================================================== */
int BioReactor::setTemperatureState(RANGE s) {
	TemperatureState = s;
	return 0;
}

/*	=============================================================================
	desc
	
	@param 	none
	@return 	none
	========================================================================== */
RANGE BioReactor::getTemperatureState() {
	return TemperatureState;
}

/*	=============================================================================
	desc
	
	@param 	none
	@return 	none
	========================================================================== */
std::string BioReactor::getTemperatureStateAsString() {
	std::string results = "";
	
	switch( getTemperatureState() ) {
		case BELOW:
			results = "BELOW";
		break;
		
		case ABOVE:
			results = "ABOVE";
		break;
		
		case OK:
			results = "OK";
		break;
	
		default:
			results = "<no state>";
		break;
	}
	
	return results;
}

/*	=============================================================================
	desc
	
	@param 	none
	@return 	none
	========================================================================== */
int BioReactor::setPressureState(RANGE s) {
	PressureState = s;
	return 0;
}

/*	=============================================================================
	desc
	
	@param 	none
	@return 	none
	========================================================================== */
RANGE BioReactor::getPressureState() {
	return PressureState;
}

/*	=============================================================================
	desc
	
	@param 	none
	@return 	none
	========================================================================== */
std::string BioReactor::getPressureStateAsString() {
	std::string results = "";
	
	switch( getPressureState() ) {
		case BELOW:
			results = "BELOW";
		break;
		
		case ABOVE:
			results = "ABOVE";
		break;
		
		case OK:
			results = "OK";
		break;
	
		default:
			results = "<no state>";
		break;
	}
	
	return results;
}

/*	=============================================================================
	desc
	
	@param 	none
	@return 	none
	========================================================================== */
int BioReactor::setTempTolerance(double f) {
	if ( f <   0.0 ) f = 0.0;
	if ( f > 100.0 ) f = 100.0;
	TempTolerance = f;
	return 0;
}

/*	=============================================================================
	desc
	
	@param 	none
	@return 	none
	========================================================================== */
double BioReactor::getTempTolerance() {
	return TempTolerance;
}

/*	=============================================================================
	desc
	
	@param 	none
	@return 	none
	========================================================================== */
int BioReactor::setMaxPressure(double f) {
	MaxPressure = f;
	return 0;
}

/*	=============================================================================
	desc
	
	@param 	none
	@return 	none
	========================================================================== */
double BioReactor::getMaxPressure() {
	return MaxPressure;
}

/*	=============================================================================
	desc
	
	@param 	none
	@return 	none
	========================================================================== */
void BioReactor::closeInputValve() {
	InputValveOpen = false;
}

/*	=============================================================================
	desc
	
	@param 	none
	@return 	none
	========================================================================== */
void BioReactor::openInputValve() {
	InputValveOpen = true;
}

/*	=============================================================================
	desc
	
	@param 	none
	@return 	none
	========================================================================== */
bool BioReactor::isInputValveOpen() {
	return InputValveOpen;
}

/*	=============================================================================
	desc
	
	@param 	none
	@return 	none
	========================================================================== */
void BioReactor::closeOutputValve() {
	OutputValveOpen = false;
}

/*	=============================================================================
	desc
	
	@param 	none
	@return 	none
	========================================================================== */
void BioReactor::openOutputValve() {
	OutputValveOpen = true;
}

/*	=============================================================================
	desc
	
	@param 	none
	@return 	none
	========================================================================== */
bool BioReactor::isOutputValveOpen() {
	return OutputValveOpen;
}

/*	=============================================================================
	desc
	
	@param 	none
	@return 	none
	========================================================================== */
int BioReactor::run() {
	int status = 0;

	exportConfig();
	setState(RUNNING);
	std::cout << "Running...\n";
	while ( getState() == RUNNING ) {
		ticks.wait(10);
		importConfig(); // for updating valves
		setState(DONE);	
	}
	
	std::cout << "Running...DONE!\n";
	setState(DONE);
	return status;
}

/*	=============================================================================
	desc
	
	@param 	none
	@return 	none
	========================================================================== */
int BioReactor::reset() {
	int status = 0;
	return status;
}

/*	=============================================================================
	desc
	
	@param 	none
	@return 	none
	========================================================================== */
std::string BioReactor::getInfo() {
	std::string output = "";
	output += "ID: " + toString( getID() ) + "\n";
	output += "Label: " + getLabel() + "\n";
	
	// Volume
	output += "Volume: " + toString( getFillLevel() );
	output += " / " + toString( getContainerVolume() );
	output += " units (" + toString( getFillPercentage() ) + "% +/-";
	output += toString( getFillLevelTolerance() ) + "), ";
	output += "Fill rate: " + toString( getFillRate() ) + " units/sec\n";
	
	// Temperature
	output += "Temperature: " + toString( getCurrentTemp() ) + " C,";
	output += ", target: " + toString( getTempTarget() ) + " C +/-";
	output += toString( getTempTolerance() ) + ", ";
	output += "temp rate of change: " + toString( getTempRate() ) + " C/sec\n";
	
	// Pressure 
	output += "Pressure: " + toString( getCurrentPressure() );
	output += " / " + toString( getMaxPressure() ) + " kPa, ";
	output += "pressure change rate: " + toString( getPressureRate() ) + " kPa/sec\n";
	
	// Ph
	output += "Ph: " + toString( getCurrentPh() ) + "\n";
	
		
	output += "Input valve is ";
	if ( isInputValveOpen() ) output += "OPEN\n"; else output += "CLOSED, "; 
	output += "Output valve is ";
	if ( isOutputValveOpen() ) output += "OPEN\n"; else output += "CLOSED\n"; 
	return output;
}

/*	=============================================================================
	desc
	
	@param 	none
	@return 	none
	========================================================================== */
void BioReactor::print() {
	std::cout << getInfo();
	return;
}

/*	=============================================================================
	desc
	
	enum STATE = {IDLE, RUNNING, ERRORED, STALLED, DONE};
	
	@param 	none
	@return 	none
	========================================================================== */
int BioReactor::setState(STATES s) {
	Status = s;
	return 0;
}

/*	=============================================================================
	desc
	
	enum STATE = {IDLE, RUNNING, ERRORED, STALLED, DONE};
	
	@param 	none
	@return 	none
	========================================================================== */
STATES BioReactor::getState() {
	return Status;
}

/*	=============================================================================
	desc
	
	enum STATE = {IDLE, RUNNING, ERRORED, STALLED, DONE};
	
	@param 	none
	@return 	none
	========================================================================== */
std::string BioReactor::getStateAsString() {
	std::string results = "";
	
	switch(Status) {
		case IDLE:
			results = "IDLE";
		break;
		
		case RUNNING:
			results = "RUNNING";
		break;
		
		case ERRORED:
			results = "ERRORED";
		break;
		
		case STALLED:
			results = "STALLED";
		break;
		
		case DONE:
			results = "DONE";
		break;
		
		default:
			results = "<no value>";
	}
	return results;
}

/*	=============================================================================
	desc
	
	Fill-level – Percentage
	pH
	Pressure – kPa
	Temperature – degrees Celsius
	
	@param 	none
	@return 	none
	========================================================================== */
std::string BioReactor::getStatus() {

	// Initialize
	json::Object parameters;
	
	// Set Parameters
	parameters["ID"] = getID();
	parameters["Label"] = getLabel();
	parameters["Status"] = getStateAsString();
	parameters["FillLevelPercentage"] = getFillPercentage();
	parameters["Ph"] = getCurrentPh();
	parameters["Pressure"] = getCurrentPressure();
	parameters["Temperature"] = getCurrentTemp();
	
	// Serialize
	std::string status = json::Serialize(parameters);
	
	// Write out
	File* outputResults = new File();
	outputResults->write(REPORT_DIR + toString( getID() ) + STATUS_SUFFIX, status);
	
	return status;
}

/*	=============================================================================
	desc
	
	Whether the batch was considered successful
	Actual fill level reached in the vessel
	Temperature range during the process
	pH range during the process
	Pressure range during the process
	Total time for the process
	Whether the CPP of +/- 2% for vessel fill level was met
	Whether the CPP of +/- 1 degree Celsius for maximum temperature was met
	Whether the CPP of pressure held below 200 kPa was met
	
	@param 	none
	@return 	none
	========================================================================== */
std::string BioReactor::getReport() {

	// Build Object
	json::Object parameters;
	parameters["ID"] = getID();
	parameters["Label"] = getLabel();
	parameters["FillLevel"] = getFillLevel();
	parameters["VolumeState"] = getVolumeStateAsString();
	parameters["TempMin"] = getTempMin();
	parameters["TempMax"] = getTempMax();
	parameters["TemperatureState"] = getTemperatureStateAsString();
	parameters["PressureMin"] = getPressureMin();
	parameters["PressureMax"] = getPressureMax();
	parameters["PressureState"] = getPressureStateAsString();
	parameters["PhMin"] = getPhMin();
	parameters["PhMax"] = getPhMax();
	parameters["InputValveOpen"] = isInputValveOpen();
	parameters["OutputValveOpen"] = isOutputValveOpen();
	parameters["TotalTime"] = getTotalTime();
	parameters["Successful"] = getStateAsString();
	
	// Serialize
	std::string report = json::Serialize(parameters);
	
	// Write out
	File* outputResults = new File();
	outputResults->write(REPORT_DIR + toString( getID() ) + REPORT_SUFFIX, report);

	// Return Serialized JSON
	return report;
}

/*	=============================================================================
	desc
	
	@param 	none
	@return 	none
	========================================================================== */
int BioReactor::importConfig() {

	// Init
	int status = 0;
	std::string p = ""; // JSON string
	
	// Open Config File
	File* inputFile = new File();
	status += inputFile->open(CONFIG_DIR + toString( getID() ) + CONFIG_SUFFIX);
	p = inputFile->getContentsAt(0);
	
	// Null Check
	if (p == "") return -1;

	// Reconstitute JSON
	json::Value inputJSONvalue = json::Deserialize(p);
	
	// Build Object
	json::Object parameters;
	parameters = inputJSONvalue.ToObject();
	
	// Retrieve Values
	//status += setID(parameters["ID"].ToUnt());
	if (parameters["InputValveOpen"].ToBool()) openInputValve(); else closeInputValve();
	if (parameters["OutputValveOpen"].ToBool()) openOutputValve(); else closeOutputValve();

	return status;
}

/*	=============================================================================
	desc
	
	@param 	none
	@return 	none
	========================================================================== */
int BioReactor::exportConfig() {

	// Build Object
	json::Object parameters;
	parameters["ID"] = getID();
	parameters["InputValveOpen"] = isInputValveOpen();
	parameters["OutputValveOpen"] = isOutputValveOpen();
	
	// Serialize
	std::string config = json::Serialize(parameters);
	
	// Write out
	File* outputResults = new File();
	outputResults->write(CONFIG_DIR + toString( getID() ) + CONFIG_SUFFIX, config);

	// Return Serialized JSON
	return 0;
}

/*	=============================================================================
	DESC
	
	@param 	none
	@return 	none
	========================================================================== */
void BioReactor::setBaseIndent(unsigned b) {
	if ( b > MAX_TABS ) b = MAX_TABS;
	BaseIndent = b;
	return;
}

/*	=============================================================================
	DESC
	
	@param 	none
	@return 	none
	========================================================================== */
unsigned BioReactor::getBaseIndent() {
	return BaseIndent;
}

/*	=============================================================================
	DESC
	
	@param 	none
	@return 	none
	========================================================================== */
int BioReactor::setDebugMode(unsigned d) {
	DebugMode = d;
	return 0;
}

/*	=============================================================================
	DESC
	
	@param 	none
	@return 	none
	========================================================================== */
unsigned BioReactor::getDebugMode() {
	return DebugMode;
}
