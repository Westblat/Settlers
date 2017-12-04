#include "tree.h"

Tree::Tree(Terrain *terrain, bool initialize) : Building(0, 20, initialize), terrain(terrain) { this->setReady(); }

void Tree::build() {return;}

Tree::~Tree() { }