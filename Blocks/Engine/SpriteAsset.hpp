#ifndef SPRITEASSET_HPP
#define SPRITEASSET_HPP

#include <string>
#include <SFML/Graphics.hpp>
#include "RenderAsset.hpp"
using namespace sf;
using namespace std;

class SpriteAsset : public RenderAsset {
    public:
        // Constructor and destructor
        SpriteAsset(string, Texture);
		virtual ~SpriteAsset() {};
        // Get asset attribute functions
        Sprite getSprite();
        // Configure asset functions
        void setPosition(float, float);
        // Rendering asset function
        void draw(RenderWindow*);
    private:
        Sprite sprite;  // The Sprite object
};

#endif // SPRITEASSET_HPP
