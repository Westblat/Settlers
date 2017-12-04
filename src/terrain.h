#ifndef TERRAIN_H
#define TERRAIN_H
#include "coordinates.h"
#include "building.h"
#include <ostream>

class Terrain {
public:
    Terrain(Coordinates *coord, int type);
    ~Terrain();
    
    bool isBlocked();
    void toggleBlock();
    
    int getType();
    void setType(int newType);
    
    Coordinates& getLocation();

    void placeBuilding(Building *building);

private:
    Coordinates *location;
    int type;
    bool blocked;
    int buildingType;

};
std::ostream& operator<<(std::ostream& os, Terrain& terrain);


#endif
