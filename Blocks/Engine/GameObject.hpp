#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP

#include <string>
#include <SFML/Graphics.hpp>
#include "EngineException.hpp"
using namespace sf;
using namespace std;

class GameObject {
    public:
        // Destructor
        virtual ~GameObject() {};
        // Abstract functions to be implemented in child class
        virtual void reset() = 0;
        virtual void update() = 0;
        virtual void draw(RenderWindow*) = 0;
        virtual void onMouseMove(Vector2i) = 0;
        virtual void onMouseLeftClick(Vector2i) = 0;
        virtual void onMouseRightClick(Vector2i) = 0;
        virtual void onMouseLeftRelease(Vector2i) = 0;
        virtual void onMouseRightRelease(Vector2i) = 0;
};

#endif // GAMEOBJECT_HPP
