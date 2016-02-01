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

void LevelObject::draw(RenderWindow *window) {
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

bool LevelObject::getComplete() {
    return isComplete;
}
