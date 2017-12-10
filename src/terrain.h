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

   	std::vector<int> availableBuildings(); 
    //returns vector of building types, if it returns -1, there is no available buildings

    int getBuildingType();
    void setBuildingType(int newtype);


private:
    Coordinates *location;
    int type;
    bool blocked;
    int buildingType;
    /*Terrain types
        0 = plains
        1 = stone
        2 = mountain
        3 = beach
        4 = water
    */

};
std::ostream& operator<<(std::ostream& os, Terrain& terrain);
bool operator==(Terrain &a, Terrain &b);

#endif
