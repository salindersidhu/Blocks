#include "Clock.hpp"

Clock::Clock() {
    reset();
}

void Clock::reset() {
    msecs = 0;
    secs = 0;
    mins = 0;
}

void Clock::tick() {
    update(msecs, secs);
    update(secs, mins);
}

string Clock::getTime() {
    return dDigit(mins) + ":" + dDigit(secs) + ":" + dDigit(msecs);
}

string Clock::dDigit(int timeUnit) {
    string num = to_string(timeUnit);
    if (num.length() == 1) {
        num = "0" + num;
    }
    return num;
}

void Clock::update(int &timeUnit1, int &timeUnit2) {
    timeUnit1++;
    if (timeUnit1 >= 60) {
		timeUnit2++;
		timeUnit1 = 0;
    }
}
