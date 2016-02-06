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
        BGMusic(SoundBuffer, float, bool);
        virtual ~BGMusic() {};
        // BGMusic functions
        void stop();
        void start();
        void update();
        void reset() {};
        void draw(RenderWindow*) {};
        void onMouseMove(Vector2i) {};
        void onMouseLeftClick(Vector2i) {};
        void onMouseRightClick(Vector2i) {};
        void onMouseLeftRelease(Vector2i) {};
        void onMouseRightRelease(Vector2i) {};
    private:
        // BGMusic private variables
        bool isLoop;
        bool isStarted;
        float loopStartTime;
        Sound bgMusic;
        SoundBuffer bgMusicBuffer;
};

#endif // BGMUSIC_HPP
