#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "cocos2d.h"
#include "GameSprite.h"

USING_NS_CC;

#define PLAYER_INITIAL_SPEED 8
#define PLAYER_JUMP 42
#define GRAVITY 1.5
#define FLOATNG_GRAVITY 0.4
#define TERMINAL_VELOCITY 70
#define FLOATING_FRICTION 0.98f
#define AIR_FRICTION 0.99f

typedef enum
{
    kPlayerMoving,
    kPlayerFalling,
    kPlayerDying

} PlayerState;

class Player: public GameSprite {
	float _speed;

	int _floatingTimerMax;
	float _floatingTimer;
	int _floatingInterval;
	bool _hasFloated;

	void initPlayer();

public:
	CC_SYNTHESIZE(PlayerState, _state, State);
	CC_SYNTHESIZE(bool, _inAir, InAir);
	CC_SYNTHESIZE(bool, _floating, Floating);
	CC_SYNTHESIZE(bool, _jumping, Jumping);
	CC_SYNTHESIZE(float, _maxSpeed, MaxSpeed);

	Player();
	~Player();

	static Player * create();

	virtual void update(float dt);

	void reset(void);

	inline virtual void place() {
		this->setPositionY(_nextPosition.y);
		if (_vector.x > 0
				&& this->getPositionX()
						< _visibleSize.width * 0.2f + _origin.x) {
			this->setPositionX(this->getPositionX() + _vector.x);
			if (this->getPositionX() > _visibleSize.width * 0.2f + _origin.x) {
				this->setPositionX(_visibleSize.width * 0.2f + _origin.x);
			}
		}
	}
	;

	inline int left() {
		return this->getPositionX() - _width * 0.5f;
	}

	inline int right() {
		return this->getPositionX() + _width * 0.5f;
	}

	inline int top() {
		return this->getPositionY();
	}

	inline int bottom() {
		return this->getPositionY() - _height;
	}

	inline int next_left() {
		return _nextPosition.x - _width * 0.5f;
	}

	inline int next_right() {
		return _nextPosition.x + _width * 0.5f;
	}

	inline int next_top() {
		return _nextPosition.y;
	}

	inline int next_bottom() {
		return _nextPosition.y - _height;
	}
};

#endif // __PLAYER_H__
