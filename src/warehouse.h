#ifndef WAREHOUSE_H
#define WAREHOUSE_H
#include "building.h"
#include "terrain.h"

class Warehouse: public Building {
public:
    Warehouse(Terrain *terrain);
    void build();
private:
    Terrain *terrain;
};


#endif