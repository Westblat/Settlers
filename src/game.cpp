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

void Game::setBuildings(){
    House *talo = new House(1,1,map->get_map()[10][10]);
    talo->setReady();
    buildings.push_back(talo);
}
