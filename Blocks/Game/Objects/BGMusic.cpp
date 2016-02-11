#include "BGMusic.hpp"

BGMusic::BGMusic(SoundBuffer _bgMusicBuffer, float _loopStartTime,
    bool _isLoop) {
    // Configure the background music Sound
    bgMusicBuffer = _bgMusicBuffer;
    bgMusic.setBuffer(bgMusicBuffer);
    // Set remaining instance variables
    loopStartTime = _loopStartTime;
    isLoop = _isLoop;
    isStarted = false;
}

void BGMusic::start() {
    // Start playing the background music
    bgMusic.play();
    isStarted = true;
}

void BGMusic::stop() {
    // Stop playing the background music
    bgMusic.stop();
    isStarted = false;
}

void BGMusic::update() {
    // Loop audio from the loop start point when stops playing
    if (isLoop && isStarted && bgMusic.getStatus() ==
        SoundSource::Status::Stopped) {
        bgMusic.setPlayingOffset(seconds(loopStartTime));
        bgMusic.play();
    }
}
