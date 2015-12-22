/*
FILENAME:		DrawManager.cpp
AUTHOR:			Salinder Sidhu
DESCRIPTION:	Implementation for DrawManager.h.
UPDATE DATE:	12/22/2015
*/

#include "DrawManager.h"

/* PhyfsStreamException class*/

PhyfsStreamException::PhyfsStreamException(string action) {

	message = "PhyfsStreamException: Could not perform required action: '" + action + "'";
}

/* ResourceNotLoadedException class */

ResourceNotLoadedException::ResourceNotLoadedException(string resourceType, string resourceFilePath) {

	message = "ResourceNotLoadedException: Can't load resource of type '" + resourceType + "' from '" + resourceFilePath + "'";
}

/* ResourceNotFoundException class */

ResourceNotFoundException::ResourceNotFoundException(string resourceType, int resourceID) {

	message = "ResourceNotFoundException: Can't locate resource of type '" + resourceType + "' with ID '" + to_string(resourceID) + "'";
}

/* DrawManager class */

DrawManager::DrawManager(sf::RenderWindow *window, string *resourceArchive) {

	canvasWindow = window;
	// Initalize the PHYSFS system
	PHYSFS_init(NULL);
	// Open the resource archive with PHYSFS
	PHYSFS_addToSearchPath(resourceArchive->c_str(), 1);
}

DrawManager::~DrawManager() {

	// De initalize the PHYSFS system
	PHYSFS_deinit();
}

void DrawManager::loadSpriteTexture(SPRITE spriteId, string filePath) {

	// Load the texture from the resource file using the custom input stream
	if (!archiveStream.open(&filePath)) {
		// Throw PhyfsStreamException
		throw PhyfsStreamException("Loading from archive: " + filePath);
	}
	// Obtain the texture from the stream
	sf::Texture texture;
	if (texture.loadFromStream(archiveStream)) {
		texturesMap[spriteId] = texture;
		// Close the stream
		archiveStream.close();
	} else {
		// Throw a ResourceNotLoadedException
		throw ResourceNotLoadedException("Texture", filePath);
	}
}

void DrawManager::loadTextFont(TEXTS fontId, string filePath) {

	// Load the texture from the resource file using the custom input stream
	if (!archiveStream.open(&filePath)) {
		// Throw PhyfsStreamException
		throw PhyfsStreamException("Loading from archive: " + filePath);
	}
	sf::Font font;
	if (font.loadFromStream(archiveStream)) {
		fontsMap[fontId] = font;
		// Note: Stream is not closed because SFML can't preload all the data.
	} else {
		// Throw a ResourceNotLoadedException
		throw ResourceNotLoadedException("Font", filePath);
	}
}

void DrawManager::configSpritePosition(SPRITE spriteId, float positionX, float positionY) {

	if (texturesMap.find(spriteId) != texturesMap.end()) {
		sf::Sprite sprite;
		sprite.setTexture(texturesMap[spriteId]);
		sprite.setPosition(positionX, positionY);
		spritesMap[spriteId] = sprite;
	} else {
		// Throw a ResourceNotFoundException
		throw ResourceNotFoundException("Sprite", spriteId);
	}
}

void DrawManager::configText(TEXTS fontId, unsigned int fontSize, sf::Color fontColor, string textString, float positionX, float positionY) {

	if (fontsMap.find(fontId) != fontsMap.end()) {
		sf::Text text;
		text.setFont(fontsMap[fontId]);
		text.setCharacterSize(fontSize);
		text.setColor(fontColor);
		text.setString(textString);
		text.setPosition(positionX, positionY);
		textsMap[fontId] = text;
	} else {
		// Throw a ResourceNotFoundException
		throw ResourceNotFoundException("Text", fontId);
	}
}

void DrawManager::configTextCenterHorizontal(TEXTS fontId, unsigned int fontSize, sf::Color fontColor, string textString, float positionY) {

	if (fontsMap.find(fontId) != fontsMap.end()) {
		sf::Text text;
		sf::FloatRect textRect;
		// Configure text's attributes
		text.setFont(fontsMap[fontId]);
		text.setCharacterSize(fontSize);
		text.setColor(fontColor);
		text.setString(textString);
		// Center the text horizontally
		textRect = text.getLocalBounds();
		text.setOrigin((textRect.left + textRect.width) / 2, 0);
		text.setPosition(WINDOW_WIDTH / 2, positionY);
		// Add the text to the map
		textsMap[fontId] = text;
	} else {
		// Throw a ResourceNotFoundException
		throw ResourceNotFoundException("Text", fontId);
	}
}

void DrawManager::configTextCenterRectangle(TEXTS fontId, unsigned int fontSize, sf::Color fontColor, string textString, float startPositionX, float startPositionY, float endPositionX, float endPositionY) {

	if (fontsMap.find(fontId) != fontsMap.end()) {
		sf::Text text;
		sf::FloatRect textRect;
		// Configure text's attributes
		text.setFont(fontsMap[fontId]);
		text.setCharacterSize(fontSize);
		text.setColor(fontColor);
		text.setString(textString);
		// Center the text in a rectangular area
		textRect = text.getLocalBounds();
		text.setOrigin((textRect.left + textRect.width) / 2, (textRect.top + textRect.height) / 2);
		text.setPosition(startPositionX + ((endPositionX - startPositionX) / 2), (startPositionY - 5) + ((endPositionY - startPositionY) / 2));
		// Add the text to the map
		textsMap[fontId] = text;
	} else {
		// Throw a ResourceNotFoundException
		throw ResourceNotFoundException("Text", fontId);
	}
}

void DrawManager::drawSprite(SPRITE spriteId) {

	if (spritesMap.find(spriteId) != spritesMap.end()) {
		canvasWindow->draw(spritesMap[spriteId]);
	} else {
		// Throw a ResourceNotFoundException
		throw ResourceNotFoundException("Sprite", spriteId);
	}
}

void DrawManager::drawText(TEXTS fontId) {

	if (textsMap.find(fontId) != textsMap.end()) {
		canvasWindow->draw(textsMap[fontId]);
	} else {
		// Throw a ResourceNotFoundException
		throw ResourceNotFoundException("Text", fontId);
	}
}