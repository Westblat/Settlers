#include "terrain.h"

Terrain::Terrain(Coordinates::Coordinates *coord, int type) : location(*coord), type(type) {}

void Terrain::toggleBlock = {
    if (Terrain::isBlocked) {
        Terrain::blocked = False;
    }
    else {
        Terrain::blocked = True;
    }
}

bool Terrain::isBlocked = {return blocked;}

Coordinates::Coordinates Terrain::getLocation = {return location;}

Terrain::~Terrain() {
      delete *coordinates;
}
int Terrain::getType = {return type;}

void Terrain::setType(int newType) = {type = newType;}