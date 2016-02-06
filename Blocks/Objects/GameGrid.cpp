#include "GameGrid.hpp"

GameGrid::GameGrid(float x, float y, float width, float height,
    float completeX, float completeY, float tileGap, int _winWidth,
    int _infoTextY, ResourceManager *res) {
    // Initialize a new Grid
    grid = new Grid(x, y, width, height, completeX, completeY, tileGap);
    // Initialize the MinuteClock
    clock = MinuteClock();
    // Obtain all the textures
    textures["TX_BH21"] = res->getTexture("TX_BH21");
    textures["TX_BH22"] = res->getTexture("TX_BH22");
    textures["TX_BH23"] = res->getTexture("TX_BH23");
    textures["TX_BH24"] = res->getTexture("TX_BH24");
    textures["TX_BH25"] = res->getTexture("TX_BH25");
    textures["TX_BH26"] = res->getTexture("TX_BH26");
    textures["TX_BH31"] = res->getTexture("TX_BH31");
    textures["TX_BH32"] = res->getTexture("TX_BH32");
    textures["TX_BV21"] = res->getTexture("TX_BV21");
    textures["TX_BV22"] = res->getTexture("TX_BV22");
    textures["TX_BV23"] = res->getTexture("TX_BV23");
    textures["TX_BV24"] = res->getTexture("TX_BV24");
    textures["TX_BV25"] = res->getTexture("TX_BV25");
    textures["TX_BV26"] = res->getTexture("TX_BV26");
    textures["TX_BV31"] = res->getTexture("TX_BV31");
    textures["TX_BV32"] = res->getTexture("TX_BV32");
    // Obtain the game's resources for this object
    Font font = res->getFont("FN_COPPER");
    // Configure the infoText
    textFont = font;
    infoText.setFont(textFont);
    infoText.setString("Time: 00:00:00    Moves: 0");
    winWidth = _winWidth;
    infoTextY = _infoTextY;
    centerInfoText();
    // Set the remaining instance variables
    numMoves = 0;
    isGridComplete = false;
}

GameGrid::~GameGrid() {
    // Delete the Grid pointers
    delete grid;
    grid = NULL;
}

void GameGrid::reset() {
    // Reset the block, reset all the Blocks on the Grid and set numMoves to 0
    clock.reset();
    grid->reset();
    numMoves = 0;
}

void GameGrid::onMouseLeftClick(Vector2i mousePosition) {
    // Process select Block when left mouse button clicked
    grid->selectBlock((float)mousePosition.x, (float)mousePosition.y);
}

void GameGrid::onMouseMove(Vector2i mousePosition) {
    // Process move Block when mouse is moved
    grid->moveBlock((float)mousePosition.x, (float)mousePosition.y);
}

void GameGrid::onMouseLeftRelease(Vector2i mousePosition) {
    // Process release Clock when left mouse button clicked
    grid->releaseBlock(numMoves);
}

void GameGrid::update() {
    // Update the MinuteClock
    clock.tick();
    // Update the infoText's drawing position and text
    centerInfoText();
    infoText.setString("Time: " + clock.getTime() + "    Moves: " +
		to_string(numMoves));
    // Check if Grid is complete
    if (grid->getIsComplete()) {
        isGridComplete = true;
    }
}

void GameGrid::draw(RenderWindow *window) {
    // Draw the infoText
    window->draw(infoText);
    // Iterate over all Blocks on the grid
    for (unsigned int i = 0; i < grid->getBlocks().size(); i++) {
        // Obtain the current Block
        Block block = grid->getBlocks()[i];
        // Create a Sprite with the current Block and draw it
        Sprite blockSprite;
        blockSprite.setTexture(textures[block.getTextureName()]);
        blockSprite.setPosition(block.getX(), block.getY());
        window->draw(blockSprite);
    }
}

void GameGrid::addBlock(string textureName, float size, float x, float y,
    float width, float height, bool orientation, bool flag) {
    Block block = Block(textureName, size, x, y, width, height, orientation);
    if (flag) {
        block.flag();
    }
    grid->addBlock(block);
}

void GameGrid::centerInfoText() {
    FloatRect rect;
    // Center the text horizontally
    rect = infoText.getLocalBounds();
    infoText.setOrigin((rect.left + rect.width) / 2, 0);
    infoText.setPosition((float)winWidth / 2, (float)infoTextY);
}

unsigned int GameGrid::getNumMoves() {
    // Return the number of moves
    return numMoves;
}

string GameGrid::getClockTime() {
    // Return the time on MinuteClock
    return clock.getTime();
}

bool GameGrid::getIsGridComplete() {
    // Return if the grid is complete
    return isGridComplete;
}
