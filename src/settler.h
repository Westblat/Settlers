#ifndef SETTLER_H
#define SETLLER_H

#include <string>
#include <vector>
#include <queue>

class Settler
{
public:
	Settler(std::string name);
	~Settler();

	std::vector<int> getItems();
	bool addItem(int item);
	bool removeItem(int item);

	std::string getName();

	std::string getTask();
	bool setTask(std::string newTask);

	int getHP();
	int removeHP(int hpChange);
	int addHP(int hpChange);

	void pushPath(int x, int y);
	std::queue <std::pair<int, int> > getPath();
	
	void setDelay(int time);
	bool reduceDelay();
	int getDelay();

private:
	int hp; // Current hp of the settler
	int maxHp; // Maximum hp of the settler
	std::string name; // Settlers name
	std::string task; // Current task
	std::pair<std::vector<int>, int> inventory; // Inventory, where the first element of the pair is the item identification number and the latter is the maximum size
	std::queue<std::pair<int, int> > path; // Movement path, contains directions in the form of x and y coordinates
	int actionDelay; // How much time action takes
	bool playerControlled; // Determines whether settlers is able to accept commands from player or not
};

#endif