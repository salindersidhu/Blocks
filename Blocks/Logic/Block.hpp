#ifndef BLOCK_HPP
#define BLOCK_HPP

#include <string>
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;

class Block{
    public:
        // Constructor and destructor
        Block(Texture, float, float, bool);
        virtual ~Block() {};
        // Block functions
        float getX();
        float getY();
        float getWidth();
        float getHeight();
        void setX(float);
        void setY(float);
        void select();
        void unselect();
        void flag();
        bool getSelected();
        bool getFlagged();
        bool getVertical();
        Sprite getSprite();
    private:
        // Block variables
        bool isFlagged;
        bool isSelected;
        bool isVertical;
        Texture blockTexture;
        Sprite blockSprite;
};

#endif // BLOCK_HPP
