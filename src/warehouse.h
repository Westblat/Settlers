#ifndef WAREHOUSE_H
#define WAREHOUSE_H
#include "building.h"
#include "terrain.h"
#include "coordinates.h"

class Warehouse: public Building {
public:
    Warehouse(Terrain *terrain, bool initialize);
    Coordinates* getLocation();
private:
    Terrain *terrain;
};


#endif
