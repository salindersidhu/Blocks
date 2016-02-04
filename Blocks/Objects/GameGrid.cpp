#include "GameGrid.hpp"

GameGrid::GameGrid(float x, float y, float width, float height,
    float completeX, float completeY, float tileGap) {
    // Initialize a new Grid
    grid = new Grid(x, y, width, height, completeX, completeY, tileGap);
}

GameGrid::~GameGrid() {
    // Delete the Grid pointers
    delete grid;
    grid = NULL;
}

void GameGrid::onMouseClick(Vector2i mousePosition) {

}

void GameGrid::onMouseMove(Vector2i mousePosition) {

}

void GameGrid::onMouseRelease(Vector2i mousePosition) {

}

void GameGrid::update() {

}

void GameGrid::draw(RenderWindow *window) {

}

void GameGrid::addBlock(Texture texture, float x, float y, bool orientation,
    bool flag) {
    Block block = Block(texture, x, y, orientation);
    if (flag) {
        block.flag();
    }
    grid->addBlock(block);
}
