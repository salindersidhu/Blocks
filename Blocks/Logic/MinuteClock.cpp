#include "MinuteClock.hpp"

MinuteClock::MinuteClock() {
    reset();
}

void MinuteClock::reset() {
    ms = 0;
    sec = 0;
    min = 0;
}

void MinuteClock::tick() {
    ms++;
    update(ms, sec);
    update(sec, min);
}

void MinuteClock::update(int &unit1, int &unit2) {
    if (unit1 >= 60) {
        unit2++;
        unit1 = 0;
    }
}

string MinuteClock::getMs() {
    return to_string(ms);
}

string MinuteClock::getSec() {
    return to_string(sec);
}

string MinuteClock::getMin() {
    return to_string(min);
}

string MinuteClock::getTime() {
    return dDigit(min) + ":" + dDigit(sec) + ":" + dDigit(ms);
}

string MinuteClock::dDigit(int unit) {
    string num = to_string(unit);
    if (num.length() == 1) {
        num = "0" + num;
    }
    return num;
}
