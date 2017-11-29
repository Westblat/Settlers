#include "building.h"

Building::Building(int type, int hp): type(type), hp(hp) { }

// Adds a given item to the inventory vector, assuming the the inventory isn't full (vector.size != maxsize)
bool Building::addItem(int item)
{
	if (inventory.first.size() != inventory.second)
	{
		inventory.first.push_back(item);
		return true;
	}
	else
	{
		return false;
	}
}

// Function that deletes a given item (int) from inventory vector assuming the inventory isn't empty (vector.size != 0)
bool Building::removeItem(int item)
{
	if (inventory.first.size() != 0)
	{
		std::vector<int>::iterator it = std::find(inventory.first.begin(), inventory.first.end(), item);
		inventory.first.erase(it);
		return true;
	}
	else
	{
		return false;
	}
}

Building::~Building() { }

Building::getType() { return type;}

void Building::setReady() {
	Building::isReady = true;
}

Building::Building (Building& building) {
	this.type = building.type;
	this.hp = building.hp;
}