#ifndef SPRITEASSET_HPP
#define SPRITEASSET_HPP

#include <string>
#include <SFML/Graphics.hpp>
#include "Asset.hpp"
using namespace sf;
using namespace std;

class SpriteAsset : public Asset {
    public:
        // Constructor and destructor
        SpriteAsset(string, Texture);
		virtual ~SpriteAsset() {};
        // Get asset attribute functions
        Sprite getSprite();
        // Rendering asset function
        void draw(RenderWindow*);
    private:
        Sprite sprite;  // The Sprite object
};

#endif // SPRITEASSET_HPP
