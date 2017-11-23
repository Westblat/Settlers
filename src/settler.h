#ifndef SETTLER_H
#define SETLLER_H

#include <string>
#include <vector>

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
	bool setHP(int hp);


private:
	int hp;
	std::string name;
	std::string task;
	std::pair<std::vector<int>, int> inventory;
};

#endif