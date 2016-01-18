#ifndef DRAWRASSET_HPP
#define DRAWRASSET_HPP

#include "Asset.hpp"
#include <SFML/Graphics.hpp>
using namespace sf;

class DrawAsset : public Asset {
    public:
        virtual void draw(RenderWindow*) = 0;   // For drawing graphics
};

#endif // DRAWRASSET_HPP
