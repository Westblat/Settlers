#include "settler.h"

// Constructor take the name of the settler and sets the values for max inventory size, max hp, (current) hp and playerControlled to true
Settler::Settler(std::string name) : name(name) {
	inventory.second = 5;
	hp = 10;
	maxHp = 10;
	playerControlled = true;
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
	if ((int)inventory.first.size() != inventory.second)
	{
		inventory.first.push_back(item);
		return true;
	}
	else
	{
		return false;
	}
}

// Function that deletes a given item (int) from inventory vector assuming the inventory isn't empty (vector.size != 0) and that given item is in the inventory
bool Settler::removeItem(int item) {
	if ((inventory.first.size() != 0) && (std::find(inventory.first.begin(), inventory.first.end(), item) != inventory.first.end()))
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

// Function that adds a given value to the settlers hp and returns the health the settler has after the addition, if the health were to go over the maximum amount current hp is set to maxHp
int Settler::addHP(int newHp)
{
	if (hp + newHp < maxHp)
	{
		hp = hp + newHp;
		return hp;
	}
	else
	{
		hp = maxHp;
		return hp;
	}
}

// Function that removes a given value from the settlers hp and returns the health the settler has after the addition, if the health were to go below 0 it is set to 0
int Settler::removeHP(int newHp)
{
	if (hp - newHp > 0)
	{
		hp = hp - newHp;
		return hp;
	}
	else
	{
		hp = 0;
		return hp;
	}
}

// Adds given coordinates to path
void Settler::pushPath(int x, int y)
{
	std::pair<int, int> newPath = std::make_pair(x, y);
	path.push(newPath);
}

// Returns path
std::queue <std::pair<int, int> > Settler::getPath() { return path; }

// Sets action delay to the given value
void Settler::setDelay(int delay) { actionDelay = delay; }

// Reduces the delay by 1, until the delay is 0 and returns true once it is
bool Settler::reduceDelay()
{
	if (actionDelay - 1 <= 0)
	{
		actionDelay = 0;
		return true;
	}
	else
	{
		actionDelay--;
		return false;
	}
}

// Returns the delay
int Settler::getDelay() { return actionDelay; }

Settler::~Settler() { }