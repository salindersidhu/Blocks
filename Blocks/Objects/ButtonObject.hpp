#ifndef BUTTONOBJECT_HPP
#define BUTTONOBJECT_HPP

#include <string>
#include <SFML/Graphics.hpp>
#include "../Engine/TextAsset.hpp"
#include "../Engine/GameObject.hpp"
#include "../Engine/SpriteAsset.hpp"
using namespace sf;
using namespace std;

class ButtonObject : public GameObject {
    public:
        // Constructor and destructor
        ButtonObject(string, unsigned int, float, float, Color, Color, TextAsset*, SpriteAsset*, SpriteAsset*);
        virtual ~ButtonObject() {};
        // ButtonObject functions
        void onMouseRelease(Vector2i);
        void onMouseMove(Vector2i);
        void draw(RenderWindow*);
        // Get Button attribute functions
    private:
        // ButtonObject functions
        bool isHovering(int, int);
        // ButtonObject variables
        bool isMouseOver;
        SpriteAsset *spriteNormal;
        SpriteAsset *spriteHover;
        TextAsset *buttonText;
        Color colNormal;
        Color colHover;
};

#endif // BUTTONOBJECT_HPP
