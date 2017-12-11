#include "blacksmith.h"

Blacksmith::Blacksmith(Terrain *terrain, bool initialize) : Building(5, 10, initialize), terrain(terrain) {
	// TODO add items needed to build and set the inventory size to a correct value
	inventory.second = 10; //Sets max inventory size
						  //Adds required materials to inventory, if house is not initialized as ready building

    terrain->placeBuilding(this);
}

bool Blacksmith::makeWeapon() {
    //Removes one iron from inventory and adds one sword
    if(this->removeItem(2)){
        return addItem(3);
    }
    else{return false;}
}

Coordinates* Blacksmith::getLocation() {
    return terrain->getLocation();
}