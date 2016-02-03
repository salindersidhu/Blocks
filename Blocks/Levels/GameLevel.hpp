#ifndef GAMELEVEL_HPP
#define GAMELEVEL_HPP

#include <string>
#include <SFML/Graphics.hpp>
#include "CoreLevel.hpp"
#include "../Objects/Button.hpp"
#include "../Objects/GameInfo.hpp"
using namespace sf;
using namespace std;

class GameLevel : public CoreLevel {
    public:
        // Constructor and destructor
        GameLevel(String, Font, Texture, Texture, Texture, SoundBuffer, SoundBuffer, SoundBuffer, RenderWindow*);
        virtual ~GameLevel() {};
    private:
        // GameLevel functions
        void update();
        // GameLevel variables
        Button *resetButton;
        Button *quitButton;
        GameInfo *gameInfo;
};

#endif // GAMELEVEL_HPP
