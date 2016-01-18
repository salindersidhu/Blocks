#include "ResourceManager.hpp"

PhysfsStreamException::PhysfsStreamException(string _message) {
    message = "PHYSFS cannot perform action: " + _message;
}

ResourceException::ResourceException(string _message) {
    message = _message;
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

void ResourceManager::loadTexture(string source, string name) {
    Texture texture;
    // Load texture from the resource archive
    if (!archiveStream.open(&source)) {
        // Throw PhysfsStreamException
        throw PhysfsStreamException("Loading resource " + source);
    }
    // Obtain the texture from the stream
    if (texture.loadFromStream(archiveStream)) {
        // Store the texture
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
    if (!archiveStream.open(&source)) {
        // Throw PhysfsStreamException
        throw PhysfsStreamException("Loading resource " + source);
    }
    // Obtain the font from the stream
    if (font.loadFromStream(archiveStream)) {
        // Store the font
        fonts[name] = font;
        // Stream is not closed because SFML can't preload all the data.
    } else {
        // Throw a ResourceException
        throw ResourceException("Cannot load Font " + source);
    }
}

SpriteAsset ResourceManager::createSprite(string name, string textureName) {
    // Check if the texture exists
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
    // Check if the font exists
    if (fonts.find(fontName) != fonts.end()) {
        // Return a new TextAsset with the specified name and font
        TextAsset newText(name, fonts[fontName]);
        return newText;
    } else {
        // Throw a ResourceException
        throw ResourceException("Cannot find Font " + fontName);
    }
}
