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
        // Throw AssetException
        throw AssetException("Cannot get Sound");
    }
}

void SoundAsset::play() {
    // Check if Sound exists
    if (sound.getBuffer()) {
        sound.play();
    } else {
        // Throw AssetException
        throw AssetException("Cannot play Sound");
    }
}

void SoundAsset::stop() {
    // Check if Sound exists
    if (sound.getBuffer()) {
        sound.stop();
    } else {
        // Throw AssetException
        throw AssetException("Cannot stop Sound");
    }
}

void SoundAsset::pause() {
    // Check if Sound exists
    if (sound.getBuffer()) {
        sound.pause();
    } else {
        // Throw AssetException
        throw AssetException("Cannot pause Sound");
    }
}
