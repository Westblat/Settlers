#include "terrain.h"

Terrain::Terrain(Coordinates *coord, int type) : location(coord), type(type), blocked(false), buildingType(-1) {}

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
    this->building = building;
    this->buildingType = building->getType();
}

void Terrain::removeBuilding(){
    if(this->buildingType != -1){
        delete this->building;
        this->buildingType = -1;
    }
}

std::vector<int> Terrain::availableBuildings(){
    std::vector<int> available;
    if(buildingType == -1){
        if(type == 0) {
            available.push_back(1);
            available.push_back(2);
            available.push_back(5);
            available.push_back(6);
        }
        else if (type == 1){
            available.push_back(3);
        }
        else if (type == 2){
            available.push_back(4);
        } else {
            available.push_back(-1);
        }
    }
    return available;    
}

int Terrain::getBuildingType(){return this->buildingType;}
void Terrain::setBuildingType(int newtype) {
    buildingType = newtype;
}

Building* Terrain::getBuilding(){return building;}


std::ostream& operator<<(std::ostream& os, Terrain& terrain){
    os << terrain.getType();
    return os;
}

bool operator==(Terrain &a, Terrain &b){
    return a.getLocation() == b.getLocation();
}
