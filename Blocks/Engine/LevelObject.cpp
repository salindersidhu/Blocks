#include "LevelObject.hpp"

void LevelObject::draw(RenderWindow *window) {
    // Iterate through all the GameObject pointers in the LevelObject
    for (unsigned int i = 0; i < objects.size(); i++) {
        // Draw the GameObjects
        objects[i]->draw(window);
    }
}

void LevelObject::update() {
    // Iterate through all the GameObject pointers in the LevelObject
    for (unsigned int i = 0; i < objects.size(); i++) {
        objects[i]->update();
    }
}

void LevelObject::processEvents(Event *event, Vector2i mousePosition) {
    // Iterate through all the GameObject pointers in the LevelObject
    for (unsigned int i = 0; i < objects.size(); i++) {
        // Process mouse click events
        if (event->type == Event::MouseButtonPressed) {
            objects[i]->onMouseClick(mousePosition);
        }
        // Process mouse release events
        if (event->type == Event::MouseButtonReleased) {
            objects[i]->onMouseRelease(mousePosition);
        }
        // Process all mouse movement events
        if (event->type == Event::MouseMoved) {
            objects[i]->onMouseMove(mousePosition);
        }
    }
}

bool LevelObject::getComplete() {
    return isComplete;
}
