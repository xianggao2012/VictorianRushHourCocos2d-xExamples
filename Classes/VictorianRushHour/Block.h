#ifndef __BLOCK_H__
#define __BLOCK_H__

#include "cocos2d.h"
#include "GameSprite.h"

USING_NS_CC;

enum {
	kBlockGap, kBlock1, kBlock2, kBlock3, kBlock4
};

class Block: public GameSprite {

private:

	int _tileWidth;
	int _tileHeight;

	void initBlock();

public:

	CC_SYNTHESIZE(int, _type, Type);

	Block();
	~Block();

	static Block * create();

	void setupBlock(int width, int height, int type);

	inline virtual int left() {
		return this->getPositionX();
	}

	inline virtual int right() {
		return this->getPositionX() + this->getWidth();
	}

	inline virtual int top() {
		return this->getHeight();
	}

	inline virtual int bottom() {
		return 0;
	}

};
#endif // __BLOCK_H__
