/*Cameron Murphy
CIS2207 N02
1/15/2025
A file for verifying user input. Takes a lower bound, upper bound and error message*/
#include "UserVerification.h"

    //Fix: cin and cout should exist in main, have this function return a bool or int to represent success
int numberVerification(int lowerBound, int upperBound, string errorMessage) {
    int userNumber;
    string userString;
    getline(cin, userString);
    stringstream(userString) >> userNumber;
    while (userNumber < lowerBound || userNumber > upperBound) {
        cout << errorMessage; //number is not in range
        getline(cin, userString);
        stringstream(userString) >> userNumber;
    }

    return userNumber;
}

double numberVerification(double lowerBound, double upperBound, string errorMessage) {
    double userNumber;
    string userString;
    getline(cin, userString);
    stringstream(userString) >> userNumber;
    while (userNumber < lowerBound || userNumber > upperBound) {
        cout << errorMessage; //number is not in range
        getline(cin, userString);
        stringstream(userString) >> userNumber;
    }

    return userNumber;
}

    //Fix: cin and cout should exist in main, have this function return a bool or int to represent success
char charVerification(char allowedCharacters[], int size, string errorMessage) {
    char userChar;
    bool allowed = false;
    while (!allowed) {
    cin >> userChar;
        for (int count = 0; count < size; count++) {
            if (userChar = allowedCharacters[count]) { allowed = true; }
        }
    }
    return userChar;
}

string stringVerification(string* allowedStrings, int size, string) {
    string userString;
    bool allowed = false;
    while (!allowed) {
        cin >> userString;
        for (int count = 0; count < size; count++) {
            if (userString.compare(allowedStrings[count])) { allowed = true; }
        }
    }
    return userString;
}

bool binaryChoice(string errorMessage) {
    string allowableStrings[] = {"Y", "y", "Yes", "yes", "N", "n", "No", "no"};
    string positives[] = { "Y", "y", "Yes", "yes"};
    string* allowableptr = allowableStrings;
    string* positiveptr = positives;
    bool allowed = false;
    string userString;

    cin.clear();
    getline(cin, userString);
    if (containsString(userString, allowableptr, 8)) {
        allowed = true;
    }
    while (!allowed) {
        cin.clear();
        printf("%s",errorMessage);
        getline(cin, userString);
        if (containsString(userString, allowableptr, 8)) {
            allowed = true;
        }
    }
    return containsString(userString, positiveptr, 4);

}

    //takes a base string and looks for it in a list of strings, returns true is the string was found
bool containsString(string baseString, string* compareStrings, int size) {
    for (int count = 0; count < size; count++) {
        if (compareStrings[count].compare(baseString) == 0) {
            return true; //base string was found
        }
    }
    return false;
}

    //takes a regex and makes sure it matches
bool containsString(string userString, regex pattern) {
    return regex_match(userString, pattern);
}

bool checkDate(string userDate, int lowerYear, string errorMessage) {
    int yearCheck;
    int monthCheck;
    int dayCheck;
    yearCheck = stoi(userDate.substr(0,4));
    monthCheck = stoi(userDate.substr(5, 2));
    dayCheck = stoi(userDate.substr(8,2));
    if (yearCheck < lowerYear || monthCheck < 1 || monthCheck > 12 || dayCheck < 1 || dayCheck > 31) { 
        cout << errorMessage;
        return false; }
    return true;
}