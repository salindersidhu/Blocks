#ifndef CLOCK_HPP
#define CLOCK_HPP

#include <string>
using namespace std;

class Clock {
	public:
		Clock();
		virtual ~Clock() {};
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
