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

void DrawManager::loadTexture(string source, string name) {
	sf::Texture texture;
	// Load texture from the resource archive
	if (!archiveStream.open(&source)) {
		// Throw PhyfsStreamException
		throw PhyfsStreamException("Loading resource " + source);
	}
	// Obtain the texture from the stream
	if (texture.loadFromStream(archiveStream)) {
		// Store the texture
		textures[name] = texture;
		// Close the stream
		archiveStream.close();
	} else {
		// Throw a ResourceNotLoadedException
		throw ResourceNotLoadedException("Texture", source);
	}
}

void DrawManager::loadFont(string source, string name) {
	sf::Font font;
	// Load font from the resource archive
	if (!archiveStream.open(&source)) {
		// Throw PhyfsStreamException
		throw PhyfsStreamException("Loading resource: " + source);
	}
	// Obtain the font from the stream
	if (font.loadFromStream(archiveStream)) {
		// Store the font
		fonts[name] = font;
		// NOTE: Stream is not closed because SFML can't preload all the data.
	} else {
		// Throw a ResourceNotLoadedException
		throw ResourceNotLoadedException("Font", source);
	}
}

void DrawManager::loadImage(string source, string name) {
	sf::Image image;
	// Load image from the resource archive
	if (!archiveStream.open(&source)) {
		// Throw PhyfsStreamException
		throw PhyfsStreamException("Loading resource: " + source);
	}
	// Obtain the font from the stream
	if (image.loadFromStream(archiveStream)) {
		images[name] = image;
		// Close the stream
		archiveStream.close();
	} else {
		// Throw a ResourceNotLoadedException
		throw ResourceNotLoadedException("Image", source);
	}
}

void DrawManager::createSprite(string name, string texture, float x, float y) {
	sf::Sprite sprite;
	// Check if the texture exists, bind it to the sprite and set the sprite's position
	if (textures.find(texture) != textures.end()) {
		sprite.setTexture(textures[texture]);
		sprite.setPosition(x, y);
		// Store the sprite
		sprites[name] = sprite;
	} else {
		// Throw a ResourceNotFoundException
		throw ResourceNotFoundException("Texture", texture);
	}
}

void DrawManager::createText(string name, string font, unsigned int size, sf::Color colour, string textString, float x, float y) {
	sf::Text newText;
	// Check if the font exists, bind it to the text and set the text's attributes
	if (fonts.find(font) != fonts.end()) {
		newText.setFont(fonts[font]);
		newText.setCharacterSize(size);
		newText.setColor(colour);
		newText.setString(textString);
		newText.setPosition(x, y);
		// Store the text
		text[name] = newText;
	} else {
		// Throw a ResourceNotFoundException
		throw ResourceNotFoundException("Font", font);
	}
}

void DrawManager::setTextCentered(string name, float winWidth, float y) {
	sf::FloatRect rect;
	// Check if the text exists and set its parameters
	if (text.find(name) != text.end()) {
		// Center the text horizontally
		rect = text.find(name)->second.getLocalBounds();
		text.find(name)->second.setOrigin((rect.left + rect.width) / 2, 0);
		text.find(name)->second.setPosition(winWidth / 2, y);
	} else {
		// Throw a ResourceNotFoundException
		throw ResourceNotFoundException("Text", name);
	}
}

void DrawManager::setTextCentered(string name, float startX, float startY, float endX, float endY) {
	sf::FloatRect rect;
	// Check if the text exists and set its paramters
	if (text.find(name) != text.end()) {
		// Center the text in the rectangular area
		rect = text[name].getLocalBounds();
		text[name].setOrigin((rect.left + rect.width) / 2, (rect.top + rect.height) / 2);
		text[name].setPosition(startX + ((endX - startX) / 2), (startY - 5) + ((endY - startY) / 2));
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
