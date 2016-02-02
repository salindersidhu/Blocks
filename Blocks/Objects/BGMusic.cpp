#include "BGMusic.hpp"

BGMusic::BGMusic(SoundBuffer _bgMusicBuffer, float _loopStartTime) {
    // Configure the background music Sound
    bgMusicBuffer = _bgMusicBuffer;
    bgMusic.setBuffer(bgMusicBuffer);
    // Set remaining instance variables
    loopStartTime = _loopStartTime;
    isStarted = false;
}

void BGMusic::start() {
    bgMusic.play();
    isStarted = true;
}

void BGMusic::stop() {
    bgMusic.stop();
    isStarted = false;
}

void BGMusic::update() {
    // Loop audio from the loop start point when stops playing
    if (isStarted && bgMusic.getStatus() == SoundSource::Status::Stopped) {
        bgMusic.setPlayingOffset(seconds(loopStartTime));
        bgMusic.play();
    }
}
