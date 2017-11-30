#include "game.h"

Game::Game() {
    map = new Map(21,21);
    map->setMap();
    //std::cout << *map<<std::endl;
}

Game::~Game() {
    delete map;
}
Map& Game::getMap() {return *map;}

void Game::setBuildings(){
    Game::addBuilding(1, &(map->get_map()[10][10])->getLocation());
    Game::addBuilding(2, &(map->get_map()[13][13])->getLocation());
    /*House *talo = new House(map->get_map()[10][10]);
    talo->setReady();
    buildings.push_back(talo);*/
}

void Game::addBuilding(int type, Coordinates *location){
    if(type == 1) {
        House *talo = new House(map->get_map()[location->getX()][location->getY()]);
        buildings.push_back(talo);
        addSettler(talo);
        addSettler(talo);
    } else if (type == 2){
        Warehouse *varasto = new Warehouse(map->get_map()[location->getX()][location->getY()]);
        buildings.push_back(varasto);
    }
}

void Game::addSettler(House *house) {
    Settler *settler = new Settler("John Cena");
    house->addSettler(settler);
    settlers.push_back(settler);
}

std::vector<Settler*> Game::getSettlers() {return settlers;}

std::vector<Building*> Game::getBuildings() {return buildings;}