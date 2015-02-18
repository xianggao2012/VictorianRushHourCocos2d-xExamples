#define TILE_H_SIZE 6
#define TILE_W_SIZE 8

#include "Block.h"

Block::~Block() {
}

Block::Block() {
	_visibleSize = Director::getInstance()->getVisibleSize();

    _tileWidth = _visibleSize.width / TILE_W_SIZE;
    _tileHeight = _visibleSize.height / TILE_H_SIZE;

    this->setVisible(false);
}

Block * Block::create () {

    Block * block = new Block();
	if (block && block->initWithFile("blank.png")) {
		block->initBlock();
        block->autorelease();
		return block;
	}
	CC_SAFE_DELETE(block);
	return NULL;
}


void Block::setupBlock (int width, int height, int type) {


}

void Block::initBlock() {


}
