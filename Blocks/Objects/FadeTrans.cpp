#include "FadeTrans.hpp"

FadeTrans::FadeTrans(int _speed, int width, int height, Color _fadeColour) {
    // Set instance variables based on constructor arguments
    speed = _speed;
    fadeColour = _fadeColour;
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

void FadeTrans::fade(bool condition, int alphaVal) {
    // Check if the condition holds before updating
    if (condition) {
        fadeColour.a = alphaVal;
        cover->setFillColor(fadeColour);
    }
}

void FadeTrans::update() {
    if (fadeSwitch == 0) {
        // Update the fade in colour
        if (alpha > 0) {
            alpha -= speed;
            fade(alpha > 0, alpha);
        } else {
            isComplete = true;
        }
    } else {
        // Update the fade out colour
        if (alpha < 255) {
            alpha += speed;
            fade(alpha < 255, alpha);
        } else {
            isComplete = true;
        }
    }
}

void FadeTrans::draw(RenderWindow *window) {
    // Draw the fade in effect
    window->draw(*cover);
}

void FadeTrans::setFade(int alphaVal, int fSwitch) {
    alpha = alphaVal;
    fadeSwitch = fSwitch;
    isComplete = false;
}

void FadeTrans::setFadeIn() {
    setFade(255, 0);
}

void FadeTrans::setFadeOut() {
    setFade(0, 1);
}
