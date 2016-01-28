#include "BGMusic.hpp"

BGMusic::BGMusic(SoundBuffer _bgMusicBuffer, float loopStartTime) {
    // Configure the Sounds
    bgMusicBuffer = _bgMusicBuffer;
    bgMusic.setBuffer(bgMusicBuffer);
    bgMusic.play();
    // Set remaining instance variables
    loopTime = loopStartTime;
}

BGMusic::~BGMusic() {
    // Stop the background music Sound
    bgMusic.stop();
}

void BGMusic::update() {
    // Loop audio from specific point when stops playing
    if (bgMusic.getStatus() == SoundSource::Status::Stopped) {
        bgMusic.setPlayingOffset(seconds(loopTime));
        bgMusic.play();
    }
}
