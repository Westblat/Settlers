#include "terrain.h"

Terrain::Terrain(Coordinates::Coordinates *coord, int type) : location(*coord), type(type) {}

Terrain::~Terrain() {
      delete *coordinates;
}

bool Terrain::isBlocked() {return blocked;}

void Terrain::toggleBlock() {
    if (Terrain::isBlocked) {
        Terrain::blocked = False;
    }
    else {
        Terrain::blocked = True;
    }
}

int Terrain::getType() {return type;}

void Terrain::setType(int newType) {type = newType;}

Coordinates::Coordinates Terrain::getLocation() {return location;}
