#include "LinkedList.h"
#include "DataHandler.h"
#include "PrecondViolatedExcep.h"
#include "UserVerification.h"
#include <chrono>
#include <iostream>
#include <regex>
#include "Utilities.h"
#include<vector>
using namespace std;

void addData(DataHandler& dataHandler);
void editData(DataHandler& datahandler);
void print(DataHandler& dataHandler);
void test(DataHandler& dataHandler);

	//RainData structure holds a chrono date and rainfall in cm 
struct RainData {
	chrono::year_month_day date;
	double rainInCm;
};

int main() {
	char userChar;
	char allowedChar[] = { 'A','a','E','e', 'P', 'p', 'T', 't', 'Q', 'q' };
	DataHandler dataHandler;

	do {
		printf("A: Add a Day of data\nE: Edit a day of data\nP: Print report\nT: quick data entry for test\nQ: Quit\n>>");
		userChar = charVerification(allowedChar, 8, "A: Add a Day of data\nE: Edit a day of data\nP: Print report\nT: quick data entry for test\nQ: Quit\n>>");
		userChar = toupper(userChar);
		switch (userChar) {
		case 'A':	addData(dataHandler);
			break;
		case 'E':	editData(dataHandler);
			break;
		case 'P':	print(dataHandler);
			break;
		case 'T':	test(dataHandler);
			break;
		}
	} while (userChar != 'Q');
	return 0;
}

void addData(DataHandler& dataHandler) {
	string userDate;
	bool success;
	double rainInCm;
	printf("Enter a day in format yyyy/mm/dd\n>>");
	cin.ignore();
	getline(cin, userDate);
	printf("\nEnter the amount of rainfall in Centimeters that occured this date:\n>>");
	rainInCm = numberVerification(0.0, 182.5, "Enter a value: 0-182.5");
	try {
		success = dataHandler.enterData(userDate, rainInCm);
		if (!success) { printf("Invalid date, add aborted.\n"); }
	}
	catch (PrecondViolatedExcep& pve) {
		cout << pve.what() << "\nAdd aborted.\n";
	}
}

void editData(DataHandler& dataHandler){
	string userDate;
	bool success;
	double rainInCm;
	printf("Enter a date to edit in format yyyy/mm/dd\n>>");
	cin.ignore();
	getline(cin, userDate);
	printf("Enter a new amount of rain for this date\n>>");
	rainInCm = numberVerification(0.0, 182.5, "Enter a value: 0-182.5");
	try {
		success = dataHandler.editData(userDate, rainInCm);
		if (!success) { printf("Date does not exist in the data set.\n"); }
	}
	catch (PrecondViolatedExcep(&pve)) {
		cout << pve.what() << "\nEdit Aborted.\n";
	};
}

void print(DataHandler& dataHandler) {
	dataHandler.printData();
}

void test(DataHandler& dataHandler) {
	int year = 1999;
	int month = 1;
	int day = 0;
	string sDay;
	string sMonth;
	string input;
	for (int count = 1; count < 100; count++) {
		if (day < 31) { day++; }
		else if (month < 12) {
			day = 1;
			month++;
		}
		else {
			year++;
			month = 1;
			day = 1;
		}
		if (day < 10) { sDay = "0" + to_string(day);}
		else { sDay = to_string(day); }
		if (month < 10) { sMonth = "0" + to_string(month); }
		else { sMonth = to_string(month); }
		input = to_string(year) + "/" + sMonth + "/" + sDay;
		dataHandler.enterData(input, 1.1*count);
	}
}
