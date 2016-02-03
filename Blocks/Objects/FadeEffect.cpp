#include "FadeEffect.hpp"

FadeEffect::FadeEffect(int _speed, int width, int height, Color _fadeColour) {
    // Set instance variables based on constructor arguments
    speed = _speed;
    fadeColour = _fadeColour;
    // Configure the fade out rectangle, make it transparent
    cover = new RectangleShape(Vector2f((float)width, (float)height));
    resetFade();
    // Set remaining instance variables
    isComplete = true;
}

FadeEffect::~FadeEffect() {
    delete cover;
    cover = NULL;
}

void FadeEffect::update() {
    if (!isComplete) {
        // Update the fade out colour
        if (alpha < 255) {
            alpha += speed;
            fade(alpha < 255, alpha);
        } else {
            isComplete = true;
        }
    }
}

void FadeEffect::fade(bool condition, int alphaVal) {
    // Check if the condition holds before updating
    if (condition) {
        fadeColour.a = alphaVal;
        cover->setFillColor(fadeColour);
    }
}

void FadeEffect::resetFade() {
    fadeColour.a = 0;
    cover->setFillColor(fadeColour);
}

void FadeEffect::draw(RenderWindow *window) {
    // Draw the fade effect
    if (!isComplete) {
        window->draw(*cover);
    }
}

void FadeEffect::start() {
    resetFade();
    alpha = 0;
    isComplete = false;
}

bool FadeEffect::isDone() {
    return isComplete;
}
