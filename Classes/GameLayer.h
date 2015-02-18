#ifndef __GAMELAYER_H__
#define __GAMELAYER_H__

#include "cocos2d.h"

USING_NS_CC;

typedef enum {
    kGameIntro,
    kGamePlay,
    kGameOver
} GameState;

class GameLayer : public cocos2d::Layer
{
private:
	Size _visibleSize;
	Vec2 _origin;
	SpriteBatchNode* _gameBatchNode;

	bool _running = false;
	int _speedIncreaseInterval;
	float _speedIncreaseTimer;

public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    virtual void onTouchBegan(const std::vector<Touch*>& touches, cocos2d::Event *event);
    virtual void onTouchEnded(const std::vector<Touch*>& touches, cocos2d::Event *event);

    void update(float dt);
    void createGameScreen();
    void resetGame();

    // implement the "static create()" method manually
    CREATE_FUNC(GameLayer);
};

#endif // __GAMELAYER_H__
