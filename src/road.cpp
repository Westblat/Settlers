#include "road.h"

Road::Road(Terrain* terrain, bool initialize) : Building(7, 10, initialize), terrain(terrain){
    this->setReady();
    terrain->placeBuilding(this);
}

Road::~Road(){
    this->terrain->setBuildingType(-1);
}
