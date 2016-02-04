#ifndef BLOCK_HPP
#define BLOCK_HPP

#include <string>
using namespace std;

class Block{
    public:
        // Constructor and destructor
        Block(string, float, float, float, float, int);
        virtual ~Block() {};
        // Block functions
        void setX(float);
        void setY(float);
        void select();
        void unselect();
        void flag();
        float getX();
        float getY();
        float getWidth();
        float getHeight();
        bool getSelected();
        bool getFlagged();
        bool getVertical();
        string getSpriteName();
    private:
        // Block variables
        float x;
        float y;
        float width;
        float height;
        bool isFlagged;
        bool isSelected;
        int orientation;    // 0 = vertical and 1 = horizontal
        string spriteName;
};

#endif // BLOCK_HPP
