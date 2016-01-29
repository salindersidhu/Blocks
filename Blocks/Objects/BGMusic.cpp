#include "BGMusic.hpp"

BGMusic::BGMusic(SoundBuffer _bgMusicBuffer, float _loopStartTime) {
    // Configure the background music Sound
    bgMusicBuffer = _bgMusicBuffer;
    bgMusic.setBuffer(bgMusicBuffer);
    bgMusic.play();
    // Set remaining instance variables
    loopStartTime = _loopStartTime;
}

BGMusic::~BGMusic() {
    // Stop the background music Sound
    bgMusic.stop();
}

void BGMusic::update() {
    // Loop audio from the loop start point when stops playing
    if (bgMusic.getStatus() == SoundSource::Status::Stopped) {
        bgMusic.setPlayingOffset(seconds(loopStartTime));
        bgMusic.play();
    }
}
