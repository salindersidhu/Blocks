#include "DrawManager.hpp"

/* PhyfsStreamException class */
PhyfsStreamException::PhyfsStreamException(string action) {
    message = "Cannot perform action: " + action;
}

/* ResourceNotLoadedException class */
ResourceNotLoadedException::ResourceNotLoadedException(string type, string source) {
    message = "Cannot load resource " + type + " from " + source;
}

/* ResourceNotFoundException class */
ResourceNotFoundException::ResourceNotFoundException(string type, string name) {
    message = "Cannot find resource " + type + " called " + name;
}

/* DrawManager class */
DrawManager::DrawManager(sf::RenderWindow *window, string *resourceArchive) {
	canvas = window;
	// Initalize the PHYSFS system
	PHYSFS_init(NULL);
	// Open the resource archive with PHYSFS
	PHYSFS_addToSearchPath(resourceArchive->c_str(), 1);
}

DrawManager::~DrawManager() {
	// De initalize the PHYSFS system
	PHYSFS_deinit();
}

void DrawManager::createSprite(string source, string name) {
	sf::Texture texture;
	sf::Sprite sprite;
	// Load texture from the resource archive
	if (!archiveStream.open(&source)) {
		// Throw PhyfsStreamException
		throw PhyfsStreamException("Loading resource" + source);
	}
	// Obtain the texture from the stream
	if (texture.loadFromStream(archiveStream)) {
		// Add the texture to the sprite object and store it in sprites
		sprite.setTexture(texture);
		sprites[name] = sprite;
		archiveStream.close();
	} else {
		// Throw a ResourceNotLoadedException
		throw ResourceNotLoadedException("Texture", source);
	}
}

void DrawManager::createText(string source, string name) {
	sf::Font font;
	sf::Text newText;
	// Load font from the resource archive
	if (!archiveStream.open(&source)) {
		// Throw PhyfsStreamException
		throw PhyfsStreamException("Loading resource: " + source);
	}
	// Obtain the font from the stream
	if (font.loadFromStream(archiveStream)) {
		// Add the font to the text object and store it in text
		text[name] = newText;
		newText.setFont(font);
		archiveStream.close();
	} else {
		// Throw a ResourceNotLoadedException
		throw ResourceNotLoadedException("Font", source);
	}
}

void DrawManager::createImage(string source, string name) {
	sf::Image image;
	// Load image from the resource archive
	if (!archiveStream.open(&source)) {
		// Throw PhyfsStreamException
		throw PhyfsStreamException("Loading resource: " + source);
	}
	// Obtain the font from the stream
	if (image.loadFromStream(archiveStream)) {
		images[name] = image;
	} else {
		// Throw a ResourceNotLoadedException
		throw ResourceNotLoadedException("Image", source);
	}
}

void DrawManager::setSprite(string name, float x, float y) {
	// Check if the sprite exists and set its position
	if (sprites.find(name) != sprites.end()) {
		sprites[name].setPosition(x, y);
	} else {
		// Throw a ResourceNotFoundException
		throw ResourceNotFoundException("Sprite", name);
	}
}

void DrawManager::setText(string name, unsigned int size, sf::Color colour, string textString, float x, float y) {
	// Check if the text exists and set its parameters
	if (text.find(name) != text.end()) {
		text[name].setCharacterSize(size);
		text[name].setColor(colour);
		text[name].setString(textString);
		text[name].setPosition(x, y);
	} else {
		// Throw a ResourceNotFoundException
		throw ResourceNotFoundException("Text", name);
	}
}

void DrawManager::centerTextHorizontal(string name, float winWidth, float y) {
	sf::FloatRect rect;
	// Check if the text exists and set its parameters
	if (text.find(name) != text.end()) {
		// Center the text horizontally
		rect = text[name].getLocalBounds();
		text[name].setOrigin((rect.left + rect.width) / 2, 0);
		text[name].setPosition(winWidth / 2, y);
	} else {
		// Throw a ResourceNotFoundException
		throw ResourceNotFoundException("Text", name);
	}
}

void DrawManager::centerTextRectangle(string name, float startX, float startY, float endX, float endY) {
	sf::FloatRect rect;
	// Check if the text exists and set its paramters
	if (text.find(name) != text.end()) {
		// Center the text in the rectangular area
		rect = text[name].getLocalBounds();
		text[name].setOrigin((rect.left + rect.width) / 2, (rect.top + rect.height) / 2);
		text[name].setPosition(startX + ((endX - startX) / 2), startY + ((endY - startY) / 2));
	} else {
		// Throw a ResourceNotFoundException
		throw ResourceNotFoundException("Text", name);
	}
}

void DrawManager::drawSprite(string name) {
	// Check if the sprite exists and draw it
	if (sprites.find(name) != sprites.end()) {
		canvas->draw(sprites[name]);
	} else {
		// Throw a ResourceNotFoundException
		throw ResourceNotFoundException("Sprite", name);
	}
}

void DrawManager::drawText(string name) {
	// Check if the font exists and draw it
	if (text.find(name) != text.end()) {
		canvas->draw(text[name]);
	} else {
		// Throw a ResourceNotFoundException
		throw ResourceNotFoundException("Text", name);
	}
}

sf::Sprite DrawManager::getSprite(string name) {
	// Check if the sprite exists and return it
	if (sprites.find(name) != sprites.end()) {
		return sprites[name];
	} else {
		// Throw a ResourceNotFoundException
		throw ResourceNotFoundException("Sprite", name);
	}
}

sf::Text DrawManager::getText(string name) {
	// Check if the text exists and return it
	if (text.find(name) != text.end()) {
		return text[name];
	} else {
		// Throw a ResourceNotFoundException
		throw ResourceNotFoundException("Text", name);
	}
}

sf::Image DrawManager::getImage(string name) {
	// Check if the image exists and return it
	if (images.find(name) != images.end()) {
		return images[name];
	} else {
		// Throw a ResourceNotFoundException
		throw ResourceNotFoundException("Image", name);
	}
}
