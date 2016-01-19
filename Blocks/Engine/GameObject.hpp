#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP

#include <string>
#include <exception>
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;

class GameObjectException : public exception {
    public:
        GameObjectException(string _message) {message = _message;};
        virtual ~GameObjectException() throw() {};
        const char *what() const throw() {return message.c_str();};
    private:
        string message;
};

class GameObject {
    public:
        // Abstract functions
        virtual void onMouseClick(Event*) = 0;
        virtual void onMouseRelease(Event*) = 0;
        virtual void onKeyPress(Event*) = 0;
        virtual void onKeyRelease(Event*) = 0;
        virtual void update() = 0;
        virtual void draw(RenderWindow*) = 0;
};

#endif // GAMEOBJECT_HPP
