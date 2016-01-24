#include "ResourceManager.hpp"

ResourceManager::ResourceManager(string resourceArchive) {
	// Initalize the PHYSFS system
	PHYSFS_init(NULL);
	// Open the resource archive with PHYSFS
	PHYSFS_addToSearchPath(resourceArchive.c_str(), 1);
}

ResourceManager::~ResourceManager() {
	// De initalize the PHYSFS system
	PHYSFS_deinit();
}

void ResourceManager::openVerifyStream(string source) {
    // Loading resource from resource archive
    if (!archiveStream.open(&source)) {
        // Throw EngineException
        throw EngineException("Error: Loading resource " + source);
    }
}

void ResourceManager::loadTexture(string source, string name) {
    Texture texture;
    // Load Texture from the resource archive
    openVerifyStream(source);
    // Obtain the Texture from the stream
    if (texture.loadFromStream(archiveStream)) {
        // Store the t=Texture
        textures[name] = texture;
        archiveStream.close();
    } else {
        // Throw a EngineException
        throw EngineException("Error: Loading Texture " + source);
    }
}

void ResourceManager::loadFont(string source, string name) {
    Font font;
    // Load font from the resource archive
    openVerifyStream(source);
    // Obtain the Font from the stream
    if (font.loadFromStream(archiveStream)) {
        // Store the Font
        fonts[name] = font;
        // Stream is not closed because SFML can't preload all the data.
    } else {
        // Throw a EngineException
        throw EngineException("Error: Loading Font " + source);
    }
}

void ResourceManager::loadImage(string source, string name) {
    Image image;
    // Load image from the resource archive
    openVerifyStream(source);
    // Obtain the Image from the stream
    if (image.loadFromStream(archiveStream)) {
        // Store the Image
        images[name] = image;
    } else {
        // Throw a EngineException
        throw EngineException("Error: Loading Image " + source);
    }
}

void ResourceManager::loadSound(string source, string name) {
    SoundBuffer buffer;
    // Load sound from the resource archive
    openVerifyStream(source);
    // Obtain the Sound from the stream
    if (buffer.loadFromStream(archiveStream)) {
        // Store the Sound
		soundBuffers[name] = buffer;
    } else {
        // Throw a EngineException
        throw EngineException("Error: Loading SoundBuffer " + source);
    }
}

Image ResourceManager::getImage(string imageName) {
    // Check if the Image exists
    if (images.find(imageName) != images.end()) {
        return images[imageName];
    } else {
        // Throw a EngineException
        throw EngineException("Error: Getting Image " + imageName);
    }
}

Texture ResourceManager::getTexture(string textureName) {
	// Check if the Image exists
	if (textures.find(textureName) != textures.end()) {
		return textures[textureName];
	} else {
		// Throw a EngineException
		throw EngineException("Error: Getting Texture " + textureName);
	}
}

Font ResourceManager::getFont(string fontName) {
	// Check if the Image exists
	if (fonts.find(fontName) != fonts.end()) {
		return fonts[fontName];
	} else {
		// Throw a EngineException
		throw EngineException("Error: Getting Font " + fontName);
	}
}

SoundBuffer ResourceManager::getSound(string soundName) {
	// Check if the Image exists
	if (soundBuffers.find(soundName) != soundBuffers.end()) {
		return soundBuffers[soundName];
	} else {
		// Throw a EngineException
		throw EngineException("Error: Getting Sound " + soundName);
	}
}
