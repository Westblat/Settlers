#ifndef GAME_H
#define GAME_H
#include "map.h"
#include "building.h"
#include "house.h"
#include "warehouse.h"
#include "tree.h"


class Game
{
public:
    Game();
    ~Game();
    Map& getMap();
    void setBuildings();
    void addBuilding(int type, Coordinates *location, bool initialize);
    void addSettler(House *house, Coordinates *location);
    std::vector<Settler*> getSettlers();
    std::vector<Building*> getBuildings();
    bool simulate();
private:
    Map *map;
    std::vector<Building*> buildings;
    std::vector<Settler*> settlers;
};

#endif // GAME_H
