#include "warehouse.h"

Warehouse::Warehouse(Terrain *terrain, bool initialize): Building(2, 10, initialize), terrain(terrain){
    inventory.second = -1;
    if(!initialize){
        inventory.first.push_back(0);//TEMP? House is built with 4 "0" resources (wood)
        inventory.first.push_back(0);//UUUUUUUUUUUUUUUUUUUUUHHHHHH
        inventory.first.push_back(0);
        inventory.first.push_back(0);
        inventory.first.push_back(0);
        inventory.first.push_back(0);
    }
 }

void Warehouse::build() {return;}