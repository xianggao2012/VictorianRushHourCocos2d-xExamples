#include "Terrain.h"

Terrain::~Terrain () {

}

Terrain::Terrain():
_startTerrain(false)
,_blockPoolIndex(0)
,_currentPatternCnt(1)
,_currentPatternIndex(0)
,_currentTypeIndex(0)
,_currentWidthIndex(0)
,_currentHeightIndex(0)
,_showGap(false)
{
	_visibleSize = Director::getInstance()->getVisibleSize();
	_origin = Director::getInstance()->getVisibleOrigin();

}
Terrain * Terrain::create() {
    Terrain * terrain = new Terrain();
	if (terrain && terrain->initWithFile("blank.png")) {
        terrain->setAnchorPoint(Vec2(0,0));
        terrain->initTerrain();
		terrain->autorelease();
		return terrain;
	}

	return NULL;
}

void Terrain::initTerrain () {

}


void Terrain::checkCollision (Player * player) {


}

void Terrain::move (float xMove) {

}

void Terrain::reset() {

}

void Terrain::addBlocks(int currentWidth) {

}

void Terrain::distributeBlocks() {

}

void Terrain::initBlock(Block * block) {


}
