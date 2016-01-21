#ifndef BLOCK_HPP
#define BLOCK_HPP

#include <tuple>
#include <string>
using namespace std;

class Block{
    public:
        // Constructor and destructor
        Block(string, tuple<float, float>, int, int);
        virtual ~Block() {};
        // Configure Block functions
        void setPosition(int, int);
        void setSelected(bool);
        void flag();
        // Get Block attribute functions
        bool getIsSelected();
        bool getIsFlagged();
        bool getIsVertical();
        string getSpriteName();
        float getSize();
        tuple<float, float> getPosition();
        tuple<float, float> getDimensions();
    private:
        // Block variables
        tuple<float, float> position;
        tuple<float, float> dimensions;
        int orientation;    // 0 = vertical and 1 = horizontal
        float size;
        bool isFlagged;
        bool isSelected;
        string spriteName;
};

#endif // BLOCK_HPP
