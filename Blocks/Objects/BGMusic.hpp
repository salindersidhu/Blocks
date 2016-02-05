#ifndef BGMUSIC_HPP
#define BGMUSIC_HPP

#include <string>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "../Engine/GameObject.hpp"
using namespace sf;
using namespace std;

class BGMusic : public GameObject {
    public:
        // Constructor and destructor
        BGMusic(SoundBuffer, float);
        virtual ~BGMusic() {};
        // BGMusic functions
        void onMouseMove(Vector2i) {};
        void onMouseLeftClick(Vector2i) {};
        void onMouseRightClick(Vector2i) {};
        void onMouseLeftRelease(Vector2i) {};
        void onMouseRightRelease(Vector2i) {};
        void update();
        void draw(RenderWindow*) {};
        void start();
        void stop();
    private:
        // BGMusic variables
        SoundBuffer bgMusicBuffer;
        Sound bgMusic;
        float loopStartTime;
        bool isStarted;
};

#endif // BGMUSIC_HPP
