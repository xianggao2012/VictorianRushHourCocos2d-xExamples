#ifndef __TERRAIN_H__
#define __TERRAIN_H__

#include "cocos2d.h"

USING_NS_CC;

class Terrain : public Sprite{
public:
	Terrain();
	~Terrain();

	static Terrain * create();

	void initTerrain();
};

#endif // __TERRAIN_H__
