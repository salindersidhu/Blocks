#ifndef BLOCK_HPP
#define BLOCK_HPP

#include <string>
using namespace std;

class Block{
    public:
        // Constructor and destructor
        Block(string, float, float, float, float, float, bool);
        virtual ~Block() {};
        // Block functions
        float getX();
        float getY();
        float getWidth();
        float getHeight();
        float getSize();
        void setX(float);
        void setY(float);
        void setDefaultX(float);
        void setDefaultY(float);
        void select();
        void unselect();
        void flag();
        void resetPosition();
        bool getIsSelected();
        bool getIsFlagged();
        bool getIsVertical();
        string getTextureName();
    private:
        // Block variables
        float x;
        float y;
        float size;
        float defaultX;
        float defaultY;
        float width;
        float height;
        bool isFlagged;
        bool isSelected;
        bool isVertical;
        string textureName;
};

#endif // BLOCK_HPP
