#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "cocos2d.h"
#include "GameSprite.h"

USING_NS_CC;

class Player : public GameSprite{
public:
	Player();
	~Player();

    static Player * create();

    void initPlayer();
};

#endif // __PLAYER_H__
