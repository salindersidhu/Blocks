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
        void onMouseClick(Vector2i) {};
        void onMouseMove(Vector2i) {};
        void onMouseRelease(Vector2i) {};
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
