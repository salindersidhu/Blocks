#ifndef LEVELOBJECT_HPP
#define LEVELOBJECT_HPP

#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include "GameObject.hpp"
#include "EngineException.hpp"
using namespace sf;
using namespace std;

class LevelObject {
    public:
        // Constructor and destructor
        LevelObject();
        ~LevelObject();
        // LevelObject functions
        virtual void draw(RenderWindow*);
        virtual void update();
        virtual void processEvents(Event*, Vector2i);
        bool getComplete();
    protected:
        // LevelObject variables
        vector<GameObject*> objects;    // Collection of GameObjects pointers
        bool isComplete;                // Is the LevelObject complete
        bool isTransition;              // Is the LevelObject in transition
};

#endif // LEVELOBJECT_HPP
