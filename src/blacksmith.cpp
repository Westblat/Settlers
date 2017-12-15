#include "blacksmith.h"

Blacksmith::Blacksmith(Terrain *terrain, bool initialize) : Building(5, 10, initialize), terrain(terrain) {
    terrain->placeBuilding(this);
    if(!initialize){
        for(int i = 0; i < 10; i++){
            inventory.first.push_back(0);
        }
        for(int i = 0; i < 5; i++){
            inventory.first.push_back(1);
        }
        for(int i = 0; i < 5; i++){
            inventory.first.push_back(2);
        }
    }
    
    inventory.second = -1;
}


Coordinates* Blacksmith::getLocation() {
    return terrain->getLocation();
}
