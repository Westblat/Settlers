#include "settler.h"

// Constructor take the name of the settler and sets the values for max inventory size, max hp, (current) hp and playerControlled to true
Settler::Settler(std::string name, Coordinates *location) : name(name), location(location), actionDelay(0) {
	inventory.second = 5;
	hp = 10;
	maxHp = 10;
	playerControlled = true;
    task = 0; //0 stands for idle task
}


Settler::~Settler() {
    delete location;
}


// These functions take no parameters and return the wanted variable
std::string Settler::getName() { return name; }

int Settler::getTask() { return task; }

// TODO

bool Settler::setTask(int newTask)
{
	task = newTask;
	return true;
}

std::vector<int> Settler::getItems() { return inventory.first; }

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

void Settler::emptyInventory(){
		inventory.first.clear();
}

bool Settler::inventoryFull(){
	if((int)inventory.first.size() != inventory.second){
		return false;
	}else{
		return true;
	}
}

bool Settler::inventoryEmpty(){
	if((int)inventory.first.size() == 0){
		return true;
	} else {
		return false;
	}
}

void Settler::setEnemy(){
	this->playerControlled = false;
}

int Settler::getHP() { return hp; }

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

Coordinates* Settler::getLocation(){return this->location;}

// Sets new path
void Settler::setPath(std::stack<std::pair<int, int> > newPath){
    this->path = newPath;
}

// Returns next step
bool Settler::move() {
	
    if (this->path.size() > 0) {
        std::pair<int,int> next (this->path.top());
        this->path.pop();
        return this->location->updateCoords(this->getLocation()->getX() + next.first,this->getLocation()->getY() + next.second);
    }
    else {return false;}
}

// Sets action delay to the given value
void Settler::setDelay(int delay) { actionDelay = delay; }

// Reduces the delay by 1, until the delay is 0 and returns true once it is
bool Settler::reduceDelay() {
    actionDelay -= 1;
    if (actionDelay <= 0) {
		actionDelay = 0;
		return true;
	}
    else {return false;}
}

// Returns the delay
int Settler::getDelay() { return actionDelay; }

std::ostream& operator <<(std::ostream& os, Settler& settler){
	os << "His name is "<< settler.getName();
	return os;
}

bool operator==(Settler &a, Settler &b){
    return a.getName() == b.getName();
}

