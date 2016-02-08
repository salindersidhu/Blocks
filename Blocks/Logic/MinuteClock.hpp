#ifndef MINUTECLOCK_HPP
#define MINUTECLOCK_HPP

#include <string>
using namespace std;

class MinuteClock {
    public:
        // Constructor and destructor
        MinuteClock();
        virtual ~MinuteClock() {};
        // MinuteClock functions
        void reset();
        void tick();
        string getTime();
        string getMs();
        string getSec();
        string getMin();
    private:
        // MinuteClock private functions
        void update(int&, int&);
        // MinuteClock private variables
        string dDigit(int);
        int ms;     // Clock's miliseconds
        int sec;    // Clock's seconds
        int min;    // Clokc's minutes
};

#endif // MINUTECLOCK_HPP
