#ifndef BUILDING_H
#define BUILDING_H
#include <string>
#include <vector>

class Building
{
public:
	Building(int type, int hp);
	~Building();
	virtual void build() = 0;

	bool addItem(int item);
	bool removeItem(int item);
	void setReady();
	int getType();

	Building (Building& b);


protected:
	int type;
	int hp;
	bool isReady;
	std::pair<std::vector<int>, int> inventory;
};




#endif // !BUILDING_H