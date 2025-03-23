#include "DataHandler.h"
#include "UserVerification.h"
#include "Utilities.h"
DataHandler::DataHandler() {};


/*
checkDate ensures the date is in bounds and in proper format if so string to chrono turns this into a proper 
chrono date. If the date is out of bounds return false, if format isn't proper throw exception,
if date already exists throw exception*/
bool DataHandler::enterData(string date, double cmOfRain) throw (PrecondViolatedExcep){
	chrono::year_month_day chronoDate;
	try {
		if (!checkDate(date)) { return false; }
		chronoDate = stringToChrono(date);
	} catch (PrecondViolatedExcep& pve) { throw pve; };
	if (checkExists(chronoDate) != -1) {
		throw PrecondViolatedExcep("Date already exists in data set.\n");
	}
	RainData rainData{ chronoDate, cmOfRain };
	rainList.push(rainData);
	return true;
}

//returns false if date doesn't exist in list, throws exception if date is improper format
bool DataHandler::editData(string date, double cmOfRain) throw(PrecondViolatedExcep){
	chrono::year_month_day chronoDate;
	int position;
	try {
		if (!checkDate(date)) { return false; }
		chronoDate = stringToChrono(date);
		position = checkExists(chronoDate);
		if (position == -1) { return false; }
			//create new entry and replace
		RainData dataReplace{ chronoDate, cmOfRain };
		rainList.setEntry(position, dataReplace);
	}catch (PrecondViolatedExcep& pve) { throw pve; }
	return true;
}

void DataHandler::printData() {
	double totalRain = 0;
	chrono::year_month_day dateOfMostRain;
	double mostRain = 0;
	double leastRain = 1000;
	for (int count = 0; count < rainList.getLength(); count++) {
		cout << rainList.getEntry(count + 1).date << ": " << rainList.getEntry(count + 1).cmOfRain << "\n";
	}
	for (int count = 1; count <= rainList.getLength(); count++) {
		RainData rainData; //grab rain data so we don't need to traverse the list more than once
		rainData = rainList.getEntry(count);
		
		totalRain += rainData.cmOfRain;
		if (rainData.cmOfRain > mostRain) {
			mostRain = rainData.cmOfRain;
			dateOfMostRain = rainData.date;
		}

	}
	printf("Total Rainfall Recorded: %.2f\n", totalRain);
	cout << "Date of most rain fall: " << dateOfMostRain << "\n";
	printf("Average rain fall overall: %.2f", (totalRain / rainList.getLength()));
}

/*takes user date represented by string and checks if it is in bounds
* rethrows invalid_argument from stoi meaning date is not in ####/##/## format
returns true if format && bounds are good
*/
bool DataHandler::checkDate(string userDate){
	int yearCheck;
	int monthCheck;
	int dayCheck;

	regex validFormat("^\\d{4}/\\d{2}/\\d{2}$"); //format for our date
	if (!regex_match(userDate, validFormat)) { throw (PrecondViolatedExcep("Improper date format")); }
	yearCheck = stoi(userDate.substr(0, 4));
	monthCheck = stoi(userDate.substr(5, 2));
	dayCheck = stoi(userDate.substr(8, 2));
	if (yearCheck < 1800 || monthCheck < 1 || monthCheck > 12 || dayCheck < 1 || dayCheck > 31) {
		return false;
	}
	return true;
}


int DataHandler::checkExists(chrono::year_month_day date)
{
	for (int count = 1; count <= rainList.getLength(); count++) {
		if (date == rainList.getEntry(count).date) { return count; }
	}
	return -1;
}

