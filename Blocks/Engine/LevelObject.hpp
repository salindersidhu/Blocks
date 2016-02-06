#ifndef LEVELOBJECT_HPP
#define LEVELOBJECT_HPP

#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include "SaveObject.hpp"
#include "GameObject.hpp"
#include "EngineException.hpp"
#include "ResourceManager.hpp"
using namespace sf;
using namespace std;

class LevelObject {
    public:
        // Constructor and destructor
        LevelObject(ResourceManager*, RenderWindow*);
        ~LevelObject();
        // LevelObject functions
        bool getisFinished();
        void setSaveObject(SaveObject*);
        void processEvents(Event*, Vector2i);
        virtual void draw();
        virtual void reset();
        virtual void update();
    protected:
        // LevelObject private variables
        vector<GameObject*> objects;    // Collection of GameObjects pointers
        ResourceManager *resMan;        // ResourceManager pointer
        RenderWindow *window;           // RenderWindow pointer
        SaveObject *saveObj;            // Save object pointer
        bool isFinished;                // Is the LevelObject finished
};

#endif // LEVELOBJECT_HPP
