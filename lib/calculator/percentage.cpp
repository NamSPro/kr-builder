// percentage.cpp
// This file implements functions declared in percentage.h

#include <cmath>
#include "percentage.h"

double actualStat(int statType, double value){
	if(statType > OPTION_MPDMG || CAP_GRID[statType][CAP_2ND_UPPER] == 0.0){ // dmg dealt shenanigans
		return value;
	}

	double actual = 0.0;

	if(value == 0.0) actual = 0.0;
	else if(value > CAP_GRID[statType][CAP_2ND_UPPER]){
		actual = attenuateInverse(value, CAP_ABSOLUTE_GRID[statType][CAP_MAX], CAP_A_GRID[statType][CAP_2ND_UPPER], CAP_B_GRID[statType][CAP_2ND_UPPER]);
	}
	else if(value > CAP_GRID[statType][CAP_1ST_UPPER]){
		actual = floor((value * CAP_A_GRID[statType][CAP_1ST_UPPER]) / 1000.0 + CAP_B_GRID[statType][CAP_1ST_UPPER]);
	}
	else if(value < CAP_GRID[statType][CAP_2ND_LOWER]){
		actual = attenuateInverse(value, CAP_ABSOLUTE_GRID[statType][CAP_MIN], CAP_A_GRID[statType][CAP_2ND_LOWER], CAP_B_GRID[statType][CAP_2ND_LOWER]);
	}
	else if(value < CAP_GRID[statType][CAP_1ST_LOWER]){
		actual = attenuate(value, CAP_ABSOLUTE_GRID[statType][CAP_MIN], CAP_A_GRID[statType][CAP_1ST_LOWER], CAP_B_GRID[statType][CAP_1ST_LOWER]);
	}
	else actual = value;

	actual = round(actual) / 10.0;
	return actual;
}

double attenuate(double x, double k, double a, double b){
	return floor((k * PERCENTAGE_DIVIDEND) / (a * x * x + b * x + PERCENTAGE_DIVIDEND));
}

double attenuateInverse(double x, double k, double a, double b){
	return k - floor((k * PERCENTAGE_DIVIDEND) / (a * x * x + b * x + PERCENTAGE_DIVIDEND));
}