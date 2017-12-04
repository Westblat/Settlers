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
    std::ifstream myfile;
    std::string line;
    myfile.open("default.txt");
    std::vector<std::vector<int> > temp1;
    while(std::getline(myfile, line)){
        std::vector<int> temp2;
        std::string buf;
        std::stringstream ss(line);
        
        while (ss >> buf){
            temp2.push_back(std::stoi(buf));
            }
        
        temp1.push_back(temp2); 
    }
        int type;
    for(std::vector<std::vector<int> >::iterator it = temp1.begin(); it != temp1.end(); it++){
        type = (*it)[0];
        int xcoord = (*it)[1];
        int ycoord = (*it)[2];        
        Game::addBuilding(type, (map->get_map()[xcoord][ycoord])->getLocation());
    }
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
    } else if(type == 0){
        Tree *tree = new Tree(map->get_map()[location->getX()][location->getY()]);
        buildings.push_back(tree);
    }
}

void Game::addSettler(House *house) {
    Settler *settler = new Settler("John Cena");
    house->addSettler(settler);
    settlers.push_back(settler);
}

std::vector<Settler*> Game::getSettlers() {return settlers;}

std::vector<Building*> Game::getBuildings() {return buildings;}