#include "house.h"

House::House(Terrain *terrain,bool initialize) : Building(1,10, initialize), terrain(terrain) {}

void House::build() {
    return;
}

void House::addSettler(Settler *settler) {
    habitants.push_back(settler);
}