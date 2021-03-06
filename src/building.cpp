#include "building.h"

Building::Building(int type, int hp, bool initialize): type(type), hp(hp), isReady(initialize) { }

Building::~Building(){}

bool Building::build(int item) {
    if (!isReady) {
        for(std::vector<int>::iterator iter = this->inventory.first.begin(); iter != this->inventory.first.end(); ++iter){
            if (*iter == item){
                inventory.first.erase(iter);
                break;
            }
        }
        if (inventory.first.size()==0){isReady=true;}
    }
    return isReady;
}

// Adds a given item to the inventory vector, assuming the the inventory isn't full (vector.size != maxsize)
bool Building::addItem(int item) {
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

// Function that deletes a given item (int) from inventory vector assuming the inventory isn't empty (vector.size != 0)
bool Building::removeItem(int item)
{
	if (inventory.first.size() != 0 && std::find(inventory.first.begin(), inventory.first.end(), item) != inventory.first.end())
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

int Building::getType() { return type;}

void Building::setReady() {
	Building::isReady = true;
}

bool Building::takeDamage(){
	hp--;
	if(hp == 0){
		return true;
	}
	return false;
};

std::pair<std::vector<int>, int> Building::getInventory(){
	return inventory;
}

std::ostream& operator <<(std::ostream& os, Building& building){
	os << building.getType();
	os << building.getReadiness();
	return os;
}

bool operator==(Building &a, Building &b){
    return a.getLocation() == b.getLocation();
}
