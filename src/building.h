#ifndef BUILDING_H
#define BUILDING_H
#include <string>
#include <vector>
#include <algorithm>
#include <ostream>

class Building
{
public:
	Building(int type, int hp, bool initialize);
	~Building();
	virtual void build() = 0;

    bool addItem(int item);
	bool removeItem(int item);
	void setReady();
	int getType();

protected:
	int type;
	int hp;
    bool isReady;
    std::pair<std::vector<int>, int> inventory; //First == vector of items, Second == inventory max size
    //-1 for unlimited size, 0 for 0 items, positive number for limited size
};
/*Building types are
	0: tree
	1: House
	2: Warehouse
	3: Stonecutter
	4: Mine
	5: Blacksmith
	6: Keep
*/

std::ostream& operator <<(std::ostream& os, Building& building);

#endif // !BUILDING_H
