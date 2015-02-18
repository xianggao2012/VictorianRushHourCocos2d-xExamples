#ifndef __TERRAIN_H__
#define __TERRAIN_H__

#include "cocos2d.h"
#include "Block.h"
#include "Player.h"
USING_NS_CC;

#define TILE_H_SIZE 6
#define TILE_W_SIZE 8

class Terrain : public Sprite{
	Vector<Block *> _blockPool;
	int _blockPoolIndex;

    Vector<Block *> _blocks;
	int _lastBlockHeight;
    int _lastBlockWidth;
	int _minTerrainWidth;

    bool _showGap;

    int _currentPatternIndex;
    int _currentPatternCnt;
    int _currentWidthIndex;
    int _currentHeightIndex;
    int _currentTypeIndex;

    int _increaseGapInterval;
    float _increaseGapTimer;
    int _gapSize;


    Size _visibleSize;
    Vec2 _origin;

    void initTerrain ();
    void addBlocks(int currentWidth);

    void distributeBlocks();
    void initBlock(Block * block);

    inline float getWidth () {

        int count = _blocks.size();
        int width = 0;
        Block * block;
        for (int i = 0; i < count; i++) {
            block = (Block *) _blocks.at(i);
            width += block->getWidth();
        }
        return width;
    }
public:
	Terrain();
	~Terrain();

	static Terrain * create();

	CC_SYNTHESIZE(bool, _startTerrain, StartTerrain);

    void checkCollision (Player * player);

	void move (float xMove);
    void reset (void);
};

#endif // __TERRAIN_H__
