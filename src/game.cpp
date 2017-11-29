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
    House *talo = new House(map->get_map()[10][10]);
    talo->setReady();
    buildings.push_back(talo);
}

void Game::addBuilding(int type, Coordinates *location){
    if(type == 1) {
        House *talo = new House(map->get_map()[location->getX()][location->getY()]);
        buildings.push_back(talo);
    }
}