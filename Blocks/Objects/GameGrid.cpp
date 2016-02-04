#include "GameGrid.hpp"

GameGrid::GameGrid(float x, float y, float width, float height,
    float completeX, float completeY, float tileGap, ResourceManager *res) {
    // Initialize a new Grid
    grid = new Grid(x, y, width, height, completeX, completeY, tileGap);
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
}

GameGrid::~GameGrid() {
    // Delete the Grid pointers
    delete grid;
    grid = NULL;
}

void GameGrid::reset() {
    grid->reset();
}

void GameGrid::onMouseClick(Vector2i mousePosition) {
    grid->selectBlock((float)mousePosition.x, (float)mousePosition.y);
}

void GameGrid::onMouseMove(Vector2i mousePosition) {
    grid->moveBlock((float)mousePosition.x, (float)mousePosition.y);
}

void GameGrid::onMouseRelease(Vector2i mousePosition) {
    grid->releaseBlock(*numMoves);
}

void GameGrid::draw(RenderWindow *window) {
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

void GameGrid::addBlock(string textureName, float x, float y, float width,
    float height, bool orientation, bool flag) {
    Block block = Block(textureName, x, y, width, height, orientation);
    if (flag) {
        block.flag();
    }
    grid->addBlock(block);
}

void GameGrid::setNumMoves(unsigned int *_numMoves) {
    numMoves = _numMoves;
}
