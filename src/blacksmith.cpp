#include "blacksmith.h"

Blacksmith::Blacksmith(Terrain *terrain, bool initialize) : Building(5, 10, initialize), terrain(terrain) {
	// TODO add items needed to build and set the inventory size to a correct value
	inventory.second = 10; //Sets max inventory size
						  //Adds required materials to inventory, if house is not initialized as ready building

    terrain->placeBuilding(this);
}



// Possible improvements: add a sepate inventory for weapons
// Create a timer of sorts to wait a few turns before adding the sword to the inventory
void Blacksmith::makeWeapon() {
	// TODO change the item values to correct ones

	//remove iron ore from inventory
	removeItem(0);

	//add a weapon to inventory
	inventory.first.push_back(3);

}
