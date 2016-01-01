#include "Clock.hpp"

Clock::Clock() {
	minutes = 0;
	seconds = 0;
	milliSeconds = 0;
}

void Clock::tick() {
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

void Clock::reset() {
	seconds = 0;
	minutes = 0;
	milliSeconds = 0;
}

string Clock::doubleDigit(int integer) {
	string num = to_string(integer);
	if (num.length() == 1) {
		num = "0" + num;
	}
	return num;
}

string Clock::output() {
	return doubleDigit(minutes) + ":" + doubleDigit(seconds) + ":" + doubleDigit(milliSeconds);
}