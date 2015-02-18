#include "GameLayer.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;
using namespace CocosDenshion;

Scene* GameLayer::createScene() {
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = GameLayer::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool GameLayer::init() {
	//////////////////////////////
	// 1. super init first
	if (!Layer::init()) {
		return false;
	}

	_visibleSize = Director::getInstance()->getVisibleSize();
	_origin = Director::getInstance()->getVisibleOrigin();

	createGameScreen();

	resetGame();

	// touch events
	auto listener = EventListenerTouchAllAtOnce::create();

	listener->onTouchesBegan = CC_CALLBACK_2(GameLayer::onTouchBegan, this );
	listener->onTouchesEnded = CC_CALLBACK_2(GameLayer::onTouchEnded, this );

	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener,
			this);

	// schedule update
	this->scheduleUpdate();

	return true;
}

void GameLayer::createGameScreen() {

	Sprite *quickSprite = Sprite::create("blank.png");
	quickSprite->setTextureRect(Rect(0, 0, 100, 100));
	quickSprite->setColor(Color3B(255, 255, 255));

	quickSprite->setPosition(Vec2(
			_visibleSize.width * 0.5 + _origin.x,
			_visibleSize.height * 0.5 + _origin.y
	));

	this->addChild(quickSprite);
}

void GameLayer::resetGame() {

}

void GameLayer::onTouchBegan(const std::vector<Touch*>& touches,
		cocos2d::Event *event) {

}

void GameLayer::onTouchEnded(const std::vector<Touch*>& touches,
		cocos2d::Event *event) {

}

void GameLayer::update(float dt){

}
