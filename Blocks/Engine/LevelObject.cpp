#include "LevelObject.hpp"

LevelObject::~LevelObject() {
    // Iterate through all the GameObject pointers in the LevelObject
    vector<GameObject*>::iterator iter;
    for(iter = objects.begin(); iter != objects.end(); iter++) {
        // Free memory used by all the GameObject pointers
        delete (*iter);
        (*iter) = NULL;
    }
}

void LevelObject::draw() {
    // Iterate through all the GameObject pointers in the LevelObject
    vector<GameObject*>::iterator iter;
    for(iter = objects.begin(); iter != objects.end(); iter++) {
        // Draw the GameObjects
        (*iter)->draw(window);
    }
}

void LevelObject::update() {
    // Iterate through all the GameObject pointers in the LevelObject
    vector<GameObject*>::iterator iter;
    for(iter = objects.begin(); iter != objects.end(); iter++) {
        (*iter)->update();
    }
}

void LevelObject::processEvents(Event *event, Vector2i mousePosition) {
    // Iterate through all the GameObject pointers in the LevelObject
    vector<GameObject*>::iterator iter;
    for(iter = objects.begin(); iter != objects.end(); iter++) {
        // Process mouse click events
        if (event->type == Event::MouseButtonPressed) {
            (*iter)->onMouseClick(mousePosition);
        }
        // Process mouse release events
        if (event->type == Event::MouseButtonReleased) {
			(*iter)->onMouseRelease(mousePosition);
        }
        // Process all mouse movement events
        if (event->type == Event::MouseMoved) {
            (*iter)->onMouseMove(mousePosition);
        }
    }
}

void LevelObject::setResourceManager(ResourceManager *_resMan) {
    // Set the ResourceManager and initialize level
    resMan = _resMan;
    init();
}

void LevelObject::setRenderWindow(RenderWindow *_window) {
    // Set the RenderWindow
    window = _window;
}

bool LevelObject::getComplete() {
    // Return if the level is finished or not
    return isComplete;
}
