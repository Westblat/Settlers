#ifndef SETTLER_H
#define SETLLER_H

#include <string>
#include <vector>

class Settler
{
public:
	Settler(std::string name, std::string task);
	~Settler();
	void addItem(int name, int size);
	void removeItem(int name, int size);

private:
	std::string name;
	std::string task;
	std::pair<std::vector<int>, int> inventory;
};

#endif