#ifndef LEVELOBJECT_HPP
#define LEVELOBJECT_HPP

#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include "GameObject.hpp"
#include "EngineException.hpp"
#include "ResourceManager.hpp"
using namespace sf;
using namespace std;

class LevelObject {
    public:
        // Constructor and destructor
        ~LevelObject();
        // LevelObject functions
        virtual void init() {};
        virtual void draw();
        virtual void update();
        virtual void processEvents(Event*, Vector2i);
        void setResourceManager(ResourceManager*);
		void setRenderWindow(RenderWindow*);
        bool getisFinished();
    protected:
        // LevelObject variables
        vector<GameObject*> objects;    // Collection of GameObjects pointers
        ResourceManager *resMan;        // ResourceManager pointer
        RenderWindow *window;           // RenderWindow pointer
        bool isFinished;                // Is the LevelObject finished
};

#endif // LEVELOBJECT_HPP
