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
        // Abstract functions
        virtual void onMouseClick(Vector2i) = 0;
        virtual void onMouseRelease(Vector2i) = 0;
        virtual void onMouseMove(Vector2i) = 0;
        virtual void update() = 0;
        virtual void draw(RenderWindow*) = 0;
};

#endif // GAMEOBJECT_HPP
