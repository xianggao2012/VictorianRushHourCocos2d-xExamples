#include "Player.h"

Player::Player() {

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

void Player::initPlayer(){

}
