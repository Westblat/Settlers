#ifndef BUILDING_H
#define BUILDING_H
#include <string>
#include <vector>
#include <algorithm>
#include <ostream>
#include "coordinates.h"

class Building
{
public:
    Building(int type, int hp, bool initialize);
    virtual ~Building();
    bool build(int item); //Returns if building isReady
    bool addItem(int item);
	bool removeItem(int item);
	virtual void setReady();
    bool getReadiness() {return isReady;}
	int getType();
    int getHp() {return hp;}
	virtual Coordinates* getLocation() = 0;
	bool takeDamage();
	std::pair<std::vector<int>, int> getInventory();

protected:
	int type;
	int hp;
    bool isReady;
    std::pair<std::vector<int>, int> inventory; //First == vector of items, Second == inventory max size
    //-1 for unlimited size, 0 for 0 items, positive number for limited size
};
/*Building types are
   -1: No building
	0: tree
	1: House
	2: Warehouse
	3: Stonecutter
	4: Iron cutter
	5: Blacksmith
	6: Keep
    7: Road
*/

/*Item types are
    0: Wood
    1: Stone
    2: Iron
    3: Sword
*/

std::ostream& operator <<(std::ostream& os, Building& building);
bool operator==(Building &a, Building &b);
#endif // !BUILDING_H
