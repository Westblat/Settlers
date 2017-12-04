#include "tree.h"

Tree::Tree(Terrain *terrain): Building(0, 20), terrain(terrain) { this->setReady(); }

void Tree::build() {return;}

Tree::~Tree() { }