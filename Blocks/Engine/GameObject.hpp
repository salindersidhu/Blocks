#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP

#include <string>
#include <SFML/Graphics.hpp>
#include "EngineException.hpp"
using namespace sf;
using namespace std;

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
