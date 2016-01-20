#include "SoundAsset.hpp"

SoundAsset::SoundAsset(string _name, SoundBuffer buffer) {
    name = _name;
    sound.setBuffer(buffer);
}

Sound SoundAsset::getSound() {
    // Check if Sound exists
    if (sound.getBuffer()) {
        return sound;
    } else {
        // Throw EngineException
        throw EngineException("Error: Getting Sound");
    }
}

void SoundAsset::play() {
    // Check if Sound exists
    if (sound.getBuffer()) {
        sound.play();
    } else {
        // Throw EngineException
        throw EngineException("Error: Playing Sound");
    }
}

void SoundAsset::stop() {
    // Check if Sound exists
    if (sound.getBuffer()) {
        sound.stop();
    } else {
        // Throw EngineException
        throw EngineException("Error: Stopping Sound");
    }
}

void SoundAsset::pause() {
    // Check if Sound exists
    if (sound.getBuffer()) {
        sound.pause();
    } else {
        // Throw EngineException
        throw EngineException("Error: Pausing Sound");
    }
}
