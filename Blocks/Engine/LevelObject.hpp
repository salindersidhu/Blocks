#ifndef LEVELOBJECT_HPP
#define LEVELOBJECT_HPP

#include <string>
#include <SFML/Graphics.hpp>
#include "GameObject.hpp"
#include "EngineException.hpp"
using namespace sf;
using namespace std;

class LevelObject {
    public:
        // LevelObject functions
        void draw(RenderWindow*);
        void update();
        void processEvents(Event*, Vector2i);
        bool getComplete();
    protected:
        // LevelObject variables
        vector<GameObject*> objects;    // Collection of GameObjects
        bool isComplete;                // Is the LevelObject complete
};

#endif // LEVELOBJECT_HPP
