#include "keep.h"

Keep::Keep(Terrain *terrain, bool initialize) : Building(6, 100, initialize), terrain(terrain){
    terrain->placeBuilding(this);
    if(!initialize){
        
        for(int i = 0; i < 20; i++){
            inventory.first.push_back(0);
        }
        for(int i = 0; i < 10; i++){
            inventory.first.push_back(1);
        }
        for(int i = 0; i < 10; i++){
            inventory.first.push_back(2);
        }
        for(int i = 0; i < 3; i++){
            inventory.first.push_back(3);
        }
    }
}

Keep::~Keep() {
    this->terrain->setBuildingType(-1);
}

Coordinates* Keep::getLocation() {
	return terrain->getLocation();
}