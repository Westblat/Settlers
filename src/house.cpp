#include "house.h"

House::House(Terrain *terrain) : Building(1,10), terrain(terrain) {}

void House::build() {
    return;
}

void House::addSettler(Settler *settler) {
    habitants.push_back(settler);
}