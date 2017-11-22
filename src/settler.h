#ifndef SETTLER_H
#define SETLLER_H

#include <string>
#include <vector>

class Settler
{
public:
	Settler(std::string name, std::string task);
	~Settler();
	void addItem(std::string, int size);
	void removeItem(std::string, int size);

private:
	std::string name;
	std::string task;
	std::pair<std::vector<std::string>, int> inventory;
};

#endif