#include <string>
#include "settler.h"
#include <algorithm>

Settler::Settler(std::string name, std::string task) : name(name), task(task) {
	inventory.second = 5;
}

Settler::addItem(std::string name, int size) {
	if (inventory.second - size > 0)
	{
		inventory.first.push_back(name);
		inventory.second = inventory.second - size;
	}
}

Settler::removeItem(std::string name, int size) {
	std::vector<Item>::iterator it = find(inventory.first.begin(), inventory.first.end(), name);
	inventory.first.erase(it);
	inventory.second = inventory.second + size;
}

~Settler::Settler() { }
