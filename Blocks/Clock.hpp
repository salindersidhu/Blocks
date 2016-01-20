#ifndef CLOCK_HPP
#define CLOCK_HPP

#include <string>
using namespace std;

class Clock {
    public:
        // Constructor and destructor
        Clock();
        virtual ~Clock() {};
        // Clock functions
        void reset();
        void tick();
        // Get attribute functions
        string getTime();
    private:
        string dDigit(int);
        void update(int&, int&);
        int msecs;
        int secs;
        int mins;
};

#endif // CLOCK_HPP
