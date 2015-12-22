/*
FILENAME:		MinuteClock.h
AUTHOR:			Salinder Sidhu
DESCRIPTION:	A digital clock for displaying elapsed time in minutes, seconds and milliseconds.
UPDATE DATE:	10/27/2013
*/

#ifndef MINUTECLOCK_H
#define MINUTECLOCK_H

#include <string>
using namespace std;

class MinuteClock {
public:
	MinuteClock();
	virtual ~MinuteClock() {};
	void tick();
	void reset();
	string output();
private:
	string doubleDigit(int);
	int milliSeconds;
	int seconds;
	int minutes;
};

#endif