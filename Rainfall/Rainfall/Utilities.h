#ifndef UTILITIES_H
#define UTILITIES_H
#include <random>
#include <vector>
#include <chrono>
using namespace std;


vector<int> getRandoms(int size, int lowerBound, int upperBound);

chrono::year_month_day stringToChrono(string userString);

#endif