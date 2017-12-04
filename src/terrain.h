#ifndef TERRAIN_H
#define TERRAIN_H
#include "coordinates.h"
#include <iostream>
#include "building.h"

class Terrain {
public:
    Terrain(Coordinates *coord, int type);
    ~Terrain();
    
    bool isBlocked();
    void toggleBlock();
    
    int getType();
    void setType(int newType);
    
    Coordinates* getLocation();

    void placeBuilding(Building *building);

private:
    Coordinates *location;
    int type;
    bool blocked;
    int buildingType;

};
std::ostream& operator<<(std::ostream& os, Terrain& terrain);
bool operator==(Terrain &a, Terrain &b);

#endif
