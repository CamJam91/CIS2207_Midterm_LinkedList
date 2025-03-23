/*Cameron Murphy
CIS 2207 N02
Rainfall Project*/
#include "Utilities.h"

vector<int> getRandoms(int size, int lowerBound, int upperBound) {
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

//Got the info for using year_month_day from microsoft c++ docs and a youtube video that I seem to have trouble remembering
chrono::year_month_day stringToChrono(string userString)
{
	//turn user string into ints so they can be turned into chronos
	int userYear = stoi(userString.substr(0, 4));
	int userMonth = stoi(userString.substr(5, 2));
	int userDay = stoi(userString.substr(8, 2));


	//turn ints to chronos
	chrono::year chronoYear(userYear);
	chrono::month chronoMonth(userMonth);
	chrono::day chronoDay(userDay);
	return chrono::year_month_day(chronoYear, chronoMonth, chronoDay);
}