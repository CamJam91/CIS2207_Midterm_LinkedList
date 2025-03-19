#include "Utilities.h"

vector<int> getRandoms(int size, int lowerBound, int upperBound){
	vector<int> randoms;
	int random;
	random_device randomDevice;
	mt19937 gen(randomDevice());
	uniform_int_distribution<> dis(lowerBound, upperBound);

	for (int count = 0; count < size; count++) {
		random = dis(gen);
		randoms.push_back(random);
	}
	return randoms;
}

chrono::year_month_day stringToChrono(string userString)
{
	int userYear = stoi(userString.substr(0, 4));
	int month = stoi(userString.substr(5, 2));
	int day = stoi(userString.substr(8, 2));

	chrono::year year = year{ userYear };

	chrono::year_month_day date = year{ Year } / month / day;
}
