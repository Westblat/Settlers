#include "tree.h"

Tree::Tree(Terrain *terrain, bool initialize) : Building(0, 20, initialize), terrain(terrain) { 
    this->setReady();
    terrain->setBuildingType(0); 
    }

Tree::~Tree() { }

Coordinates* Tree::getLocation() {
	return terrain->getLocation();
}