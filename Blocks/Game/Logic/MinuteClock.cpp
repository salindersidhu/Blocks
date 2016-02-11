#include "MinuteClock.hpp"

MinuteClock::MinuteClock() {
    // Reset clock's variables
    reset();
}

void MinuteClock::reset() {
    // Set the miliseconds, seconds and minutes to 0
    ms = 0;
    sec = 0;
    min = 0;
}

void MinuteClock::tick() {
    // Tick one miliseconds per call and update the seconds and minutes
    ms++;
    update(ms, sec);
    update(sec, min);
}

void MinuteClock::update(int &unit1, int &unit2) {
    // Increment unit2 by 1 if unit1 is >= 60 and set unit1 to 0
    if (unit1 >= 60) {
        unit2++;
        unit1 = 0;
    }
}

string MinuteClock::getMs() {
    // Return the miliseconds as a string
    return to_string(ms);
}

string MinuteClock::getSec() {
    // Return the seconds as a string
    return to_string(sec);
}

string MinuteClock::getMin() {
    // Return the minutes as a string
    return to_string(min);
}

string MinuteClock::getTime() {
    // Return the Clock's time as double digits of mins::secs::ms
    return dDigit(min) + ":" + dDigit(sec) + ":" + dDigit(ms);
}

string MinuteClock::dDigit(int unit) {
    // Return a double digit string of unit
    string num = to_string(unit);
    if (num.length() == 1) {
        // If unit is a single digit, then append '0' to the front
        num = "0" + num;
    }
    return num;
}
