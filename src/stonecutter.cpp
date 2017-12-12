#include "stonecutter.h"

Stonecutter::Stonecutter(Terrain *terrain, bool initialize) : Building(3, 10, initialize), terrain(terrain){
    terrain->placeBuilding(this);
    if(!initialize){
        for(int i = 0; i != 10; i++){
            inventory.first.push_back(0);
        }
    }
}

Stonecutter::~Stonecutter {
    this->terrain->setBuildingType(-1);
}

Coordinates* Tree::getLocation() {
	return terrain->getLocation();
}
