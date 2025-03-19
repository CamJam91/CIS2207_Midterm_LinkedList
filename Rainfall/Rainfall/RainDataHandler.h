#pragma once
#include <chrono>
#include <iostream>
#include "LinkedList.h"
#include "RainDataHandler.h"
using namespace std;
class RainDataHandler
{
private:
	struct RainData{
		chrono::year_month_day date;
		double cmOfRain;
	};


	LinkedList<RainData> rainList;
	string filename = "rainfallData.txt";
	
public:
		//constructors
	RainDataHandler();
	//RainDataHandler(int months);

		//setters
	bool enterData(chrono::year_month_day date, double cmOfRain);
};

