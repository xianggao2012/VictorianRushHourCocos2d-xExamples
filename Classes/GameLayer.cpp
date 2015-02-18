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

	_gameBatchNode = SpriteBatchNode::create("blank.png", 200);
	this->addChild(_gameBatchNode, kMiddleground);

	_terrain = Terrain::create();
	_gameBatchNode->addChild(_terrain, kMiddleground);

	_player = Player::create();
	_gameBatchNode->addChild(_player, kBackground);
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
