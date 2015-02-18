#ifndef __GAMESPRITE_H__
#define __GAMESPRITE_H__

#include "cocos2d.h"

USING_NS_CC;

enum {

    kBackground,
    kMiddleground,
    kForeground
};

class GameSprite : public Sprite{
protected:
	Size _visibleSize;
	Vec2 _origin;
public:

	CC_SYNTHESIZE(Point, _nextPosition, NextPosition);

	CC_SYNTHESIZE(float, _width, Width);

	CC_SYNTHESIZE(float, _height, Height);

	CC_SYNTHESIZE(Vec2, _vector, Vector);

	GameSprite();
	~GameSprite();

	inline virtual void place () { this->setPosition(_nextPosition); };

	inline void setSize(){
		_width = this->getBoundingBox().size.width;
		_height = this->getBoundingBox().size.height;
	}
};

#endif // __GAMESPRITE_H__
