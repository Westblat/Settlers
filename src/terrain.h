#ifndef TERRAIN_H
#define TERRAIN_H
#include "coordinates.h"
#include <ostream>

class Terrain {
public:
    Terrain(Coordinates *coord, int type);
    ~Terrain();
    
    bool isBlocked();
    void toggleBlock();
    
    int getType();
    void setType(int newType);
    
    Coordinates getLocation();

private:
    Coordinates *location;
    int type;
    bool blocked;

};
std::ostream& operator<<(std::ostream& os, Terrain terrain);


#endif