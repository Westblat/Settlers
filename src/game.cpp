#include "game.h"

Game::Game() {
    map = new Map(21,21);
    map->setMap();
    std::cout << *map<<std::endl;
}

Game::~Game() {
    delete map;
}
Map& Game::getMap() {return *map;}
