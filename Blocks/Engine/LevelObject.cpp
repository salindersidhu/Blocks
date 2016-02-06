#include "LevelObject.hpp"

LevelObject::LevelObject(ResourceManager *_resMan, RenderWindow *_window,
    SaveObject *_saveObj) {
    // Set ResourceManager and RenderWindow pointers
    resMan = _resMan;
    window = _window;
    saveObj = _saveObj;
}

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
            if (event->mouseButton.button == Mouse::Left) {
                (*iter)->onMouseLeftClick(mousePosition);
            } else if (event->mouseButton.button == Mouse::Right) {
                (*iter)->onMouseRightClick(mousePosition);
            }
        }
        // Process mouse release events
        if (event->type == Event::MouseButtonReleased) {
            if (event->mouseButton.button == Mouse::Left) {
                (*iter)->onMouseLeftRelease(mousePosition);
            } else if (event->mouseButton.button == Mouse::Right) {
                (*iter)->onMouseRightRelease(mousePosition);
            }
        }
        // Process all mouse movement events
        if (event->type == Event::MouseMoved) {
            (*iter)->onMouseMove(mousePosition);
        }
    }
}

void LevelObject::reset() {
    // Iterate through all the GameObject pointers in the LevelObject
    vector<GameObject*>::iterator iter;
    for(iter = objects.begin(); iter != objects.end(); iter++) {
        // Reset each GameObject
        (*iter)->reset();
    }
}

bool LevelObject::getisFinished() {
    // Return if the level is finished or not
    return isFinished;
}
