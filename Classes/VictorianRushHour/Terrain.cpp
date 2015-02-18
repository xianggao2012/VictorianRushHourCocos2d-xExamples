#include "Terrain.h"

Terrain::Terrain(){

}

Terrain::~Terrain(){

}
Terrain * Terrain::create() {
    Terrain * terrain = new Terrain();
	if (terrain && terrain->initWithFile("blank.png")) {

        terrain->setAnchorPoint(Vec2(0,0));

        terrain->initTerrain();

        terrain->autorelease();

        return terrain;
	}

	CC_SAFE_DELETE(terrain);

	return NULL;
}

void Terrain::initTerrain(){

}
