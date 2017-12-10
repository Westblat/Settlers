#include "house.h"

House::House(Terrain *terrain, bool initialize) : Building(1,10,initialize), terrain(terrain) {
    inventory.second = 0; //Sets max inventory size
    //Adds required materials to inventory, if house is not initialized as ready building
    terrain->placeBuilding(this);
    if (!initialize){
    inventory.first.push_back(0);//TEMP? House is built with 4 "0" resources (wood)
    inventory.first.push_back(0);//UUUUUUUUUUUUUUUUUUUUUHHHHHH
    inventory.first.push_back(0);
    inventory.first.push_back(0);
    }
}

House::~House(){
    for(auto i : this->habitants){
        delete i;
    }
    this->terrain->setBuildingType(-1);
}

void House::addSettler(Settler *settler) {
    habitants.push_back(settler);
}

Coordinates* House::getLocation() {
    return terrain->getLocation();
}
