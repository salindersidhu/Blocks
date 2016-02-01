#ifndef GAMELEVEL_HPP
#define GAMELEVEL_HPP

#include <string>
#include <SFML/Graphics.hpp>
#include "CoreLevel.hpp"
#include "../Objects/Button.hpp"
#include "../Objects/FadeTrans.hpp"
using namespace sf;
using namespace std;

class GameLevel : public CoreLevel {
    public:
        // Constructor and destructor
        GameLevel(String, Font, Texture, SoundBuffer, RenderWindow*);
        virtual ~GameLevel() {};
    private:
        // GameLevel functions
        // GameLevel variables
};

#endif // GAMELEVEL_HPP
