#include "FadeTrans.hpp"

FadeTrans::FadeTrans(int _speed, int width, int height) {
    // Set instance variables based on constructor arguments
    speed = _speed;
    // Configure the transition effect rectangle
    alpha = 255;
    cover = new RectangleShape(Vector2f((float)width, (float)height));
    // Set remaining instance variables
    fadeSwitch = 0;
}

FadeTrans::~FadeTrans() {
    delete cover;
    cover = NULL;
}

void FadeTrans::update() {
    if (fadeSwitch == 0) {
        // Update the fade in colour
        if (alpha > 0) {
            alpha -= speed;
            if (alpha > 0) {
                cover->setFillColor(Color(0, 0, 0, alpha));
            }
        } else {
            isComplete = true;
        }
    } else {
        // Update the fade out colour
        if (alpha < 255) {
            alpha += speed;
            if (alpha < 255) {
                cover->setFillColor(Color(0, 0, 0, alpha));
            }
        } else {
            isComplete = true;
        }
    }
}

void FadeTrans::draw(RenderWindow *window) {
    // Draw the fade in effect
    window->draw(*cover);
}

void FadeTrans::setFadeIn() {
    alpha = 255;
    fadeSwitch = 0;
    isComplete = false;
}

void FadeTrans::setFadeOut() {
    alpha = 0;
    fadeSwitch = 1;
    isComplete = false;
}
