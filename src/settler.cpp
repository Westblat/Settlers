#include "settler.h"
#include <algorithm>
#include <iostream>

Settler::Settler(std::string name) : name(name) {
	inventory.second = 5;
}

// These functions take no parameters and return the wanted variable
std::string Settler::getName() { return name; }

std::string Settler::getTask() { return task; }

std::vector<int> Settler::getItems() { return inventory.first; }

// TODO
bool Settler::setTask(std::string newTask)
{
	task = newTask;
	return true;
}

// Adds a given item to the inventory vector, assuming the the inventory isn't full (vector.size != maxsize)
bool Settler::addItem(int item) {
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
bool Settler::removeItem(int item) {
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

int Settler::getHP() { return hp; }

// Function that updates settlers hp to a given int value and return true or false based on whether the settler died or not (if hp is below 0, settler died)
bool Settler::setHP(int newHp)
{
	if (newHp > 0)
	{
		hp = newHp;
		return true;
	}
	else
	{
		return false;
	}
}

Settler::~Settler() { }