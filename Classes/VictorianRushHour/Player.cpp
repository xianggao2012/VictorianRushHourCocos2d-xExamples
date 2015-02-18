#include "Player.h"
#define ACCELERATION 0.5

Player::Player() {
	_visibleSize = Director::getInstance()->getVisibleSize();
	_origin = Director::getInstance()->getVisibleOrigin();

	_floatingTimerMax = 2;
	_floatingTimer = 0;
	_speed = PLAYER_INITIAL_SPEED;
	_maxSpeed = PLAYER_INITIAL_SPEED;
	_floating = false;

	_nextPosition.x = _origin.x;
	_nextPosition.y = _visibleSize.height * 0.6f + _origin.y;

	_state = kPlayerMoving;
	_jumping = false;
	_hasFloated = false;
}

Player::~Player() {

}
Player * Player::create() {

	Player * player = new Player();
	if (player && player->initWithFile("blank.png")) {

		player->autorelease();

		player->setSize();

		player->initPlayer();

		return player;
	}

	CC_SAFE_DELETE(player);

	return NULL;
}

void Player::initPlayer() {

}

void Player::reset() {
	_speed = PLAYER_INITIAL_SPEED;
	_maxSpeed = PLAYER_INITIAL_SPEED;
	_vector = Vec2(0, 0);
	this->setFloating(false);
	this->setRotation(0);
	_nextPosition.y = _visibleSize.height * 0.6f + _origin.y;
	this->setPosition(Vec2(_visibleSize.width * 0.2f + _origin.x, _nextPosition.y));
	_state = kPlayerMoving;
	_jumping = false;
	_hasFloated = false;
}
void Player::update(float dt){

}
