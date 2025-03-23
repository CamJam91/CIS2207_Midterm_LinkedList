#ifndef USERVERIFICATION_H
#define USERVERIFICATION_H
#include <string>
#include <iostream>
#include <sstream>
#include <regex>
using namespace std;

int numberVerification(int, int, string);

double numberVerification(double lowerBound, double upperBound, string errorMessage);

char charVerification(char[], int, string);

string stringVerification(string*, int, string);

bool binaryChoice(string errorMessage);

bool containsString(string, string*, int);

bool containsString(string userString, regex pattern);

bool checkDate(string userDate, int lowerYear);


#endif