#ifndef GAME_H
#define GAME_H
#include "map.h"
#include "building.h"
#include "house.h"
#include "warehouse.h"
#include "stonecutter.h"
#include "ironcutter.h"
#include "tree.h"
#include "keep.h"
#include "road.h"
#include "blacksmith.h"


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
    void pathToNearbyBuilding(Settler *settler, int building);
    bool atWarehouse(Settler *settler);
    int checkTask(int task, Settler *settler);
    void removeBuilding(Building *building);
    void cutTree(Settler *settler);
    void cutStone(Settler *settler);
    void cutIron(Settler *settler);
    void cutSwords(Settler *settler);
    void buildBuilding(Settler *settler);
    void enemy(Settler *settler);
    void combat(Settler *settler);
private:
    Map *map;
    std::vector<Building*> buildings;
    std::vector<Settler*> settlers;
    std::vector<Building*> notReady;
    std::vector<House*> houses;
    /* Types for task:
    0 = idle
    1 = build
    2 = cut tree
    3 = cut stone
    4 = cut iron
    5 = cut swords
    6 = empty inventory
    7 = get item
    8 = combat
    */
};

#endif // GAME_H
