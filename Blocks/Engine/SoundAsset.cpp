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
