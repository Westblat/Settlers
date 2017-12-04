#include "terrain.h"

Terrain::Terrain(Coordinates *coord, int type) : location(coord), type(type), blocked(false) {}

Terrain::~Terrain() {
      delete location;
}

bool Terrain::isBlocked() {return blocked;}

void Terrain::toggleBlock() {
    if (Terrain::blocked) {
        Terrain::blocked = false;
    }
    else {
        Terrain::blocked = true;
    }
}

int Terrain::getType() {return type;}

void Terrain::setType(int newType) {type = newType;}

Coordinates* Terrain::getLocation() {return location;}

void Terrain::placeBuilding(Building *building) {
    Terrain::buildingType = building->getType();
}

std::ostream& operator<<(std::ostream& os, Terrain& terrain){
    os << terrain.getType();
    return os;
}

bool operator==(Terrain &a, Terrain &b){
    return a.getLocation() == b.getLocation();
}
