#ifndef SETTLER_H
#define SETTLER_H

#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>
#include "coordinates.h"


class Settler
{
public:
    Settler(std::string name, Coordinates *location);
	~Settler();

    std::string getName();

    int getTask();
    bool setTask(int newTask);

	std::vector<int> getItems();
	bool addItem(int item);
	bool removeItem(int item);
    void emptyInventory();
    bool inventoryFull();
    bool inventoryEmpty();
    bool controlled() {return playerControlled;};
    void setEnemy();

	int getHP();
	int removeHP(int hpChange);
	int addHP(int hpChange);

    Coordinates* getLocation();

    void setPath(std::stack<std::pair<int, int> > newPath);
    bool move();
	
	void setDelay(int time);
	bool reduceDelay();
	int getDelay();
    void teleport(int x, int y);

private:
	std::string name; // Settlers name
    int task; // Current task
    int hp; // Current hp of the settler
    int maxHp; // Maximum hp of the settler
    //Building *home;
	std::pair<std::vector<int>, int> inventory; // Inventory, where the first element of the pair is the item identification number and the latter is the maximum size
    bool playerControlled; // Determines whether settlers is able to accept commands from player or not
    Coordinates *location;
    std::stack<std::pair<int, int> > path; // Movement path, contains directions in the form of x and y coordinates
    int actionDelay; // How much time action takes
};

std::ostream& operator <<(std::ostream& os, Settler& settler);

bool operator==(Settler &a, Settler &b);


#endif
