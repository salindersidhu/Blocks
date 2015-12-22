/*
FILENAME:		MinuteClock.cpp
AUTHOR:			Salinder Sidhu
DESCRIPTION:	Implementation for MinuteClock.h.
UPDATE DATE:	10/27/2013
*/

#include "MinuteClock.h"

MinuteClock::MinuteClock() {

	minutes = 0;
	seconds = 0;
	milliSeconds = 0;
}

void MinuteClock::tick() {

	milliSeconds++;
	if (milliSeconds >= 60) {
		seconds++;
		milliSeconds = 0;
	}
	if (seconds >= 60) {
		minutes++;
		seconds = 0;
	}
}

void MinuteClock::reset() {

	seconds = 0;
	minutes = 0;
	milliSeconds = 0;
}

string MinuteClock::doubleDigit(int integer) {

	string num = to_string(integer);
	if (num.length() == 1) {
		num = "0" + num;
	}
	return num;
}

string MinuteClock::output() {

	return doubleDigit(minutes) + ":" + doubleDigit(seconds) + ":" + doubleDigit(milliSeconds);
}