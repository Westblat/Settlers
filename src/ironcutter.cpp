#include "ironcutter.h"

Ironcutter::Ironcutter(Terrain *terrain, bool initialize) : Building(4, 10, initialize), terrain(terrain){
    terrain->placeBuilding(this);
    if(!initialize){
        for(int i = 0; i < 10; i++){
            inventory.first.push_back(0);
        }
        for(int i = 0; i < 5; i++){
            inventory.first.push_back(1);
        }
    }
}

Ironcutter::~Ironcutter() {
    this->terrain->setBuildingType(-1);
}

Coordinates* Ironcutter::getLocation() {
	return terrain->getLocation();
}

void Ironcutter::setReady() {
    for(int i = 0; i < 20; i++){
        inventory.first.push_back(2);
    }
}
