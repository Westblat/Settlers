#include "building.h"

Building::Building() { }

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