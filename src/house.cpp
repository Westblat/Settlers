#include "house.h"

House::House(int health, int space, Terrain *terrain) : Building(1,health),space(space), terrain(terrain) {}

void House::build() {
    return;
}