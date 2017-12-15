#include "warehouse.h"

Warehouse::Warehouse(Terrain *terrain, bool initialize): Building(2, 10, initialize), terrain(terrain){
    inventory.second = -1;
    terrain->placeBuilding(this);
    inventory.first.push_back(2);
    inventory.first.push_back(2);
    inventory.first.push_back(2);
    inventory.first.push_back(2);
    inventory.first.push_back(2);
    inventory.first.push_back(2);
    inventory.first.push_back(2);
    inventory.first.push_back(2);
    inventory.first.push_back(2);
    inventory.first.push_back(2);
    inventory.first.push_back(2);
    inventory.first.push_back(2);
    inventory.first.push_back(2);
    inventory.first.push_back(2);
    inventory.first.push_back(2);
    inventory.first.push_back(2);
    inventory.first.push_back(2);
    inventory.first.push_back(2);
    inventory.first.push_back(2);
    inventory.first.push_back(2);
    inventory.first.push_back(2);
    inventory.first.push_back(2);
    inventory.first.push_back(2);
    inventory.first.push_back(2);
    inventory.first.push_back(2);
    
    
    if(!initialize){
        inventory.first.push_back(0);//TEMP? House is built with 4 "0" resources (wood)
        inventory.first.push_back(0);//UUUUUUUUUUUUUUUUUUUUUHHHHHH
        inventory.first.push_back(0);
        inventory.first.push_back(0);
        inventory.first.push_back(0);
        inventory.first.push_back(0);
    }
}

Warehouse::~Warehouse(){
    this->terrain->setBuildingType(-1);
}

Coordinates* Warehouse::getLocation() {
    return terrain->getLocation();
}
