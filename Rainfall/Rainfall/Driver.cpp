#include "LinkedList.h"
#include "RainDataHandler.h"
#include "PrecondViolatedExcep.h"
#include "UserVerification.h"
#include <chrono>
#include <iostream>
#include <regex>
using namespace std;

void initializeRainHandler();
void enterRainData();

	//RainData structure holds a chrono date and rainfall in cm 
struct RainData {
	chrono::year_month_day date;
	double rainInCm;
};

int main() {
	initializeRainHandler();
	return 0;
}

	//create rainhandler class using user input
void initializeRainHandler() {
	printf("Welcome to the Rainfall tracker.\n");
	printf("How many initial months would you like to track?\n>>");
	int userMonths = numberVerification(0, 100, "Please choose an amount of months between 0-100\n>>");
	string userString;
	regex validFormat("^\\d{4}/\\d{2}/\\d{2}$"); //format for our date
	double rainInCm;
	RainData* rainData = new RainData[userMonths];

		//for each day do while uses regex to check for proper format then checkDate checks for proper bounds
	for (int count = 0; count < userMonths; count++) {
		do {
			printf("Enter Day %d in format yyyy/mm/dd\n>>", count + 1);
			getline(cin, userString);
			if (!regex_match(userString, validFormat)) { printf("Date was not in proper format"); }
		} while (!regex_match(userString, validFormat) || !checkDate(userString, 1800, "Improper date entered\n>>"));
			//rainfall is collected
		printf("\nEnter rain fall in cm\n>>");
		rainInCm = numberVerification(0.1, 2646.68, "\nEnter a value: 0.1-2646.68/n>>");

		//RainData newRainData{ userString, rainInCm };
	}
}