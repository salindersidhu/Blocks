#include "BGMusic.hpp"

BGMusic::BGMusic(SoundBuffer _bgMusicBuffer, float _loopStartTime,
    bool _isLoop) {
    // Configure the background music Sound
    bgMusicBuffer = _bgMusicBuffer;
    bgMusic.setBuffer(bgMusicBuffer);
    // Set remaining instance variables
    loopStartTime = _loopStartTime;
    isLoopVar = _isLoop;
    isStartedVar = false;
}

void BGMusic::start() {
    // Start playing the background music
    bgMusic.play();
    isStartedVar = true;
}

void BGMusic::stop() {
    // Stop playing the background music
    bgMusic.stop();
    isStartedVar = false;
}

void BGMusic::update() {
    // Loop audio from the loop start point when stops playing
    if (isLoopVar && isStartedVar && bgMusic.getStatus() ==
        SoundSource::Status::Stopped) {
        bgMusic.setPlayingOffset(seconds(loopStartTime));
        bgMusic.play();
    }
}
