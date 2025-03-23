#pragma once
#include <chrono>
#include <iostream>
#include "LinkedList.h"
#include "DataHandler.h"
using namespace std;
class DataHandler
{
private:
	struct RainData{
		chrono::year_month_day date;
		double cmOfRain;
	};


	LinkedList<RainData> rainList;
	
public:
		//constructors
	DataHandler();

		//setters
	bool enterData(string date, double cmOfRain) throw (PrecondViolatedExcep);
	bool editData(string date, double cmOfRain) throw (PrecondViolatedExcep);
		//getters
	void printData();
	bool checkDate(string userDate);
	int checkExists(chrono::year_month_day date);
};

