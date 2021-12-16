/*	=============================================================================
	BioRector Class Definition
	
	@version	0.1.1
	@author	JP
	========================================================================== */

#ifndef BIOREACTOR_H_
#define BIOREACTOR_H_

// App-wide Libraries

#include <stdio.h>      			// printf, scanf, NULL 
#include <stdlib.h>     			// malloc, free, rand
#include <iostream>					// input, output 
#include <string>						// String Class
#include <vector>						// Vector STL
/*
#include <sstream>					// number to string conversion
#include <locale>        			// std::locale, std::toupper
#include <math.h>						// Standard Math library
#include <algorithm>    			// std::max
#include <map>							// Associative Array
#include <set>
#include <list>						// List LIbrary
#include <queue>						// Queue Library
*/

// App
#include "File.h"
#include "Structs.h"
#include "Timer.h"
#include "Utilities.h"
#include "JSON.h"

#define CONFIG_DIR "configs/"
#define REPORT_DIR "reports/"
#define CONFIG_SUFFIX "_config.json"
#define STATUS_SUFFIX "_status.json"
#define REPORT_SUFFIX "_report.json"

namespace smhdl {

	enum STATES {IDLE, RUNNING, ERRORED, STALLED, DONE};
	enum RANGE { BELOW, OK, ABOVE };

class BioReactor {

	public:
		BioReactor();
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
			double,			// Max Pressure in kPa
			double			// Initial Ph
			);
		~BioReactor();
		
		
		std::string getInfo();
		int setState(
			STATES);
		STATES getState();
		std::string getStateAsString();
		void print();
		
		// GET / SET
		void setBaseIndent(unsigned);
		unsigned getBaseIndent();
		int setDebugMode(unsigned);
		unsigned getDebugMode();
		
		
		// Parameters
		int setID(
			unsigned);
		unsigned getID();
		int setLabel(
			std::string);
		std::string getLabel();
		
		// Volume
		int setContainerVolume(
			double);
		double getContainerVolume();
		int setFillLevel(
			double);
		double getFillLevel();
		int setFillTarget(					
			double);								// 0 <= v <= 100.0
		double getFillTarget();
		int setFillRate(
			double);								// v <= 100.0
		double getFillRate();	
		int setFillPercentage(
			double);								// 0 <= v <= 100.0
		double getFillPercentage();	
		int setFillLevelTolerance(
			double);								// 0 <= v <= 100.0
		double getFillLevelTolerance();
		int setVolumeState(
			RANGE);
		RANGE getVolumeState();
		std::string getVolumeStateAsString();
			
		// Temperature 
		int setInitialTemp(
			double);
		int getInitialTemp();
		int setCurrentTemp(
			double);
		double getCurrentTemp();
		int addTemp(
			double);
		int setTempTarget(
			double);
		double getTempTarget();
		int setTempTolerance(
			double);
		double getTempTolerance();
		int setTempRate(
			double);
		double getTempRate();
		int setTempMin(
			double);
		double getTempMin();
		int setTempMax(
			double);
		double getTempMax();
		int setTempRange();
		int setTemperatureState(
			RANGE);
		RANGE getTemperatureState();
		std::string getTemperatureStateAsString();
		
		// Pressure
		int setInitialPressure(
			double);
		int getInitialPressure();
		int setCurrentPressure(
			double);	
		double getCurrentPressure();
		int addPressure(
			double);
		int setPressureRate(
			double);
		double getPressureRate();
		int setMaxPressure(
			double);
		double getMaxPressure();
		int setPressureMin(
			double);
		double getPressureMin();
		int setPressureMax(
			double);
		double getPressureMax();
		int setPressureRange();
		int setPressureState(
			RANGE);
		RANGE getPressureState();
		std::string getPressureStateAsString();
		
		// Ph
		int setInitialPh(
			double);
		int getInitialPh();
		int setCurrentPh(
			double);
		double getCurrentPh();
		int addPh(
			double);
		int setPhMin(
			double);
		double getPhMin();
		int setPhMax(
			double);
		double getPhMax();
		int setPhRange();

		// Valves		
		void openInputValve();
		void closeInputValve();
		void openOutputValve();
		void closeOutputValve();
		bool isInputValveOpen();
		bool isOutputValveOpen();
		
		int setTotalTime(
			double);
		double getTotalTime();
		
		int importConfig();		
		int exportConfig();
		
		std::string getReport();
		std::string getStatus();
		
		int emptyRunningTemp();
		int emptyRunningPressure();
		int emptyRunningPh();
		
		// TODO ===========================================
		int run();

	private:
		
		void init();
		void reset();
		
		// Parameters
		unsigned ID = ERROR_UNT;
		std::string Label = "";
		double ContainerVolume = 0.0;
		double FillLevel = 0.0;
		double FillTarget = 0.0;			// Container fill target in percentage 
		double FillPercentage = 0.0; 		// as percentage
		double FillRate = 0.0; 				// Container fill rate unit/sec
		double FillLevelTolerance = 1.0;	// Fill tolerance +/- percent of fill /container size
		double InitialTemp = 0.0;
		double CurrentTemp = 0.0;			// Temperature in Celsius
		double TempTarget = 0.0;			// Temperature target in Celsius
		double TempTolerance = 0.0;		// Temperature tolerance +/- C
		double TempRate = 0.0;				// Temperature change rate C/sec
		double TempMin = 0.0;				// Recorded Minimum temp
		double TempMax = 0.0;				// Recorded Maximum temp
		double InitialPressure = 101.0;
		double CurrentPressure = 0.0;		// Pressure in kPa
		double PressureRate = 0.0;			// in kPa /sec
		double PressureMin = 0.0;			// Recorded Minimum pressure
		double PressureMax = 0.0;			// Recorded Maximum pressure
		double MaxPressure = 1.0; 			// Ceiling value kPa
		double InitialPh = 7.0;
		double CurrentPh = 0.0;				// Ph
		double PhMin = 0.0;					// Recorded Ph pressure
		double PhMax = 0.0;					// Recorded Ph pressure
		double TotalTime = 0.0;				// Time to completion
		
		bool InputValveOpen = false;
		bool OutputValveOpen = false;
		STATES Status = IDLE;
		RANGE VolumeState = BELOW;
		RANGE TemperatureState = BELOW;
		RANGE PressureState = OK;
		
		std::vector<double>RunningTemp;
		std::vector<double>RunningPressure;
		std::vector<double>RunningPh;
		
		unsigned DebugMode = 0;		// Debug mode
		unsigned BaseIndent = 0;	
		Timer timer;
		Timer ticks;
		double TIME_OUT = 30;				// 30 Second max execution per step
};
}

#endif 
