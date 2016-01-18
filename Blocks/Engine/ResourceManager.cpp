#include "ResourceManager.hpp"

PhysfsStreamException::PhysfsStreamException(string _message) {
    message = "PHYSFS cannot perform action: " + _message;
}

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
        // Throw PhysfsStreamException
        throw PhysfsStreamException("Loading resource " + source);
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
        // Throw a ResourceException
        throw ResourceException("Cannot load Texture " + source);
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
        // Throw a ResourceException
        throw ResourceException("Cannot load Font " + source);
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
        // Throw a ResourceException
        throw ResourceException("Cannot load Image " + source);
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
        // Throw a ResourceException
        throw ResourceException("Cannot load SoundBuffer " + source);
    }
}

Image ResourceManager::getImage(string imageName) {
    // Check if the Image exists
    if (images.find(imageName) != images.end()) {
        return images[imageName];
    } else {
        // Throw a ResourceException
        throw ResourceException("Cannot get Image " + imageName);
    }
}

SpriteAsset ResourceManager::createSprite(string name, string textureName) {
    // Check if the Texture exists
    if (textures.find(textureName) != textures.end()) {
        // Return a new SpriteAsset with the specified name and texture
        SpriteAsset newSprite(name, textures[textureName]);
        return newSprite;
    } else {
        // Throw a ResourceException
        throw ResourceException("Cannot find Texture " + textureName);
    }
}

TextAsset ResourceManager::createText(string name, string fontName) {
    // Check if the Font exists
    if (fonts.find(fontName) != fonts.end()) {
        // Return a new TextAsset with the specified name and font
        TextAsset newText(name, fonts[fontName]);
        return newText;
    } else {
        // Throw a ResourceException
        throw ResourceException("Cannot find Font " + fontName);
    }
}

SoundAsset ResourceManager::createSound(string name, string bufferName) {
    // Check if the SoundBuffer exists
    if (soundBuffers.find(bufferName) != soundBuffers.end()) {
        // Return a new SoundAsset with the specified name and buffer
        SoundAsset newSound(name, soundBuffers[bufferName]);
        return newSound;
    } else {
        // Throw a ResourceException
		throw ResourceException("Cannot find SoundBuffer" + bufferName);
    }
}
