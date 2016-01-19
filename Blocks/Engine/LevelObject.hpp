#ifndef LEVELOBJECT_HPP
#define LEVELOBJECT_HPP

#include <string>
#include <exception>
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;

class LevelObjectException : public exception {
    public:
        LevelObjectException(string _message) {message = _message;};
        virtual ~LevelObjectException() throw() {};
        const char *what() const throw() {return message.c_str();};
    private:
        string message;
};

class LevelObject {
    public:
        // Abstract functions
        virtual void draw(RenderWindow*) = 0;
        virtual void update() = 0;
        virtual void processEvents(Event*) = 0;
        virtual bool isComplete() = 0;
};

#endif // LEVELOBJECT_HPP
