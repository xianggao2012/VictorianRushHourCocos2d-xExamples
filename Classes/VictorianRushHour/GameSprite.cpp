#include "GameSprite.h"

GameSprite::GameSprite(): _vector(Vec2(0,0))
{
	_visibleSize = Director::getInstance()->getVisibleSize();
	_origin = Director::getInstance()->getVisibleOrigin();
}

GameSprite::~GameSprite(){

}
