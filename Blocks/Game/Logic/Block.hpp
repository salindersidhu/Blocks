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
        bool isSelected();
        bool isFlagged();
        bool isVertical();
        string getTextureName();
    private:
        // Block private variables
        float x;                // The Block's x positon
        float y;                // The Block's y position
        float size;             // The Block's orientation based size
        float defaultX;         // The Block's default starting x position
        float defaultY;         // The Block's default starting y position
        float width;            // The Block's width
        float height;           // The Block's height
        bool isFlaggedVar;      // If the Block is flagged
        bool isSelectedVar;     // If the Block is selected
        bool isVerticalVar;     // If the Block is vertical
        string textureName;     // Block's associated texture name
};

#endif // BLOCK_HPP
