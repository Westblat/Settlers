#include "warehouse.h"

Warehouse::Warehouse(Terrain *terrain): Building(2, 10), terrain(terrain){
    Warehouse::inventorySize = -1;
 }

void Warehouse::build() {return;}