#ifndef BUILDING_H
#define BUILDING_H

#include <string>
#include <vector>

class Building
{
public:
	Building();
	~Building();
	virtual void build() = 0;

	bool addItem(int item);
	bool removeItem(int item);


protected:
	bool isReady;
	std::pair<std::vector<int>, int> inventory;
	int type;
	int hp;
};


#endif // !BUILDING_H