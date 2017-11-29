#include "tree.h"

Tree::Tree(Terrain *terrain): Building(20, 0), terrain(terrain) { this->setReady(); }

void Tree::build() {return;}

Tree::~Tree { }