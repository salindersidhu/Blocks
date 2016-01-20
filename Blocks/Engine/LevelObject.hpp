#ifndef LEVELOBJECT_HPP
#define LEVELOBJECT_HPP

#include <string>
#include <SFML/Graphics.hpp>
#include "EngineException.hpp"
using namespace sf;
using namespace std;

class LevelObject {
    public:
        // Abstract functions
        virtual void draw(RenderWindow*) = 0;
        virtual void update() = 0;
        virtual void processEvents(Event*) = 0;
        virtual bool isComplete() = 0;
};

#endif // LEVELOBJECT_HPP
