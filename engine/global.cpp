#include "global.hpp"

CRandomMother RandGen((unsigned)time(0));

double money = 0;


int getrand(int options)
{
	// The random number generator produces a number between 0 and 1, so the 'interval' is a fraction between those numbers.
	// Each fraction has an equal chance of being rolled.
	double interval = 1.0/options;
	double sum = interval;
	double randNum = RandGen.Random();
	int i;
	for(i = 0; i < options; i++) {
		if(randNum < sum) 
			return i;
		sum += interval;
	}
	return i-1; // just in case
}

