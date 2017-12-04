#include "warehouse.h"

Warehouse::Warehouse(Terrain *terrain, bool initialize): Building(2, 10, initialize), terrain(terrain){
    Warehouse::inventorySize = -1;
 }

void Warehouse::build() {return;}