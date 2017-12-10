#include "tree.h"

Tree::Tree(Terrain *terrain, bool initialize) : Building(0, 20, initialize), terrain(terrain) { 
    this->setReady();
    terrain->placeBuilding(this);
    this->inventory.second = 0;
    }

Tree::~Tree() {
    this->terrain->setBuildingType(-1);
}

Coordinates* Tree::getLocation() {
	return terrain->getLocation();
}
