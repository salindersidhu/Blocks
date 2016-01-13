#ifndef SPRITEASSET_HPP
#define SPRITEASSET_HPP

#include <string>
#include <exception>
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;

class SpriteAsset {
    public:
        void SpriteAsset(string, Texture);
        virtual ~SpriteAsset();
        virtual void draw() = 0;
        string getName();
        Sprite getSprite();
    private:
        string name;        // The name of the Sprite Asset
        Texture texture;    // The Sprite's Texture object
        Sprite sprite       // The Sprite object
};

#endif // SPRITEASSET_HPP
