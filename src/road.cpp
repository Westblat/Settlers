#include "road.h"

Road::Road(Terrain* terrain, bool initialize) : Building(7, 10, initialize), terrain(terrain){
    this->setReady();
    terrain->placeBuilding(this);
    this->inventory.second = 0;
}

Road::~Road(){
    this->terrain->setBuildingType(-1);
}

Coordinates* Road::getLocation(){
    return terrain->getLocation();
}
