#include <string>
#include <algorithm>
#include "settler.h"

Settler::Settler(std::string name, std::string task) : name(name), task(task) {
	inventory.second = 5;
}

void Settler::addItem(int name, int size) {
	if (inventory.second - size > 0)
	{
		inventory.first.push_back(name);
		inventory.second = inventory.second - size;
	}
}

void Settler::removeItem(int name, int size) {
	std::vector<int>::iterator it = std::find(inventory.first.begin(), inventory.first.end(), name);
	inventory.first.erase(it);
	inventory.second = inventory.second + size;
}

Settler::~Settler() { }