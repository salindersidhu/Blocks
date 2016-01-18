#ifndef RENDERASSET_HPP
#define RENDERASSET_HPP

#include "Asset.hpp"
#include <SFML/Graphics.hpp>
using namespace sf;

class RenderAsset : public Asset {
    public:
        virtual void draw(RenderWindow*) = 0;   // For drawing graphics
};

#endif // RENDERASSET_HPP
