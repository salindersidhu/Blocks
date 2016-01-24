#ifndef SOUNDASSET_HPP
#define SOUNDASSET_HPP

#include <string>
#include <SFML/Audio.hpp>
#include "Asset.hpp"
using namespace sf;
using namespace std;

class SoundAsset : public Asset {
    public:
        // Constructor and destructor
		SoundAsset(string, SoundBuffer);
        virtual ~SoundAsset() {};
        // Get asset attribute functions
        Sound getSound();
    private:
        Sound sound;    // The Sound object
};

#endif // SOUNDASSET_HPP
