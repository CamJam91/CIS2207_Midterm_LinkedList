#include "RainDataHandler.h"
RainDataHandler::RainDataHandler()
{
}

//RainDataHandler::RainDataHandler()
//{
//}

bool RainDataHandler::enterData(chrono::year_month_day date, double cmOfRain)
{
	if (cmOfRain < 0 || cmOfRain > 182.327) { return false; }
	if (date < 1800y / 1 / 1) { return false; }

	RainData rainData{ date, cmOfRain };
	rainList.push(rainData);
	return true;
}
