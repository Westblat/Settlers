#include "game.h"

Game::Game() {
    map = new Map(21,21);
    map->setMap();
    //std::cout << *map<<std::endl;
}

Game::~Game() {
    
    for(std::vector<Building*>::iterator iter = buildings.begin(); iter!= buildings.end();iter++){
        delete *iter;
    }
    delete map;
}
Map& Game::getMap() {return *map;}

void Game::setBuildings(){    
    std::ifstream myfile;
    std::string line;
    try{
        myfile.open("default.txt");
          if (!myfile.is_open()){
              throw 0;
          }
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
            Game::addBuilding(type, (map->get_map()[xcoord][ycoord])->getLocation(), true);
        }   
    } catch (...){
        std::cout << "Error reading default.txt file" << std::endl;
    }
        
    
    
}

void Game::addBuilding(int type, Coordinates *location, bool initialize){
/*  Building types are
    0: tree
    1: House
    2: Warehouse
    3: Stonecutter
    4: Mine
    5: Blacksmith
    6: Keep
    7: Road, vertical
    8: Road, horizontal
    9: Road, crossroads
*/  
    if(type == 0) {
        Tree *building = new Tree(map->getTerrain(location), initialize);
        buildings.push_back(building);
        if(!initialize){
        notReady.push_back(building);
    }
    } else if (type == 1){
        House *building = new House(map->getTerrain(location), initialize);
        buildings.push_back(building);
        addSettler(building,location);
        addSettler(building,location);
        houses.push_back(building);
        if(!initialize){
        notReady.push_back(building);
    }
    } else if(type == 2){
        Warehouse *building = new Warehouse(map->getTerrain(location), initialize);
        buildings.push_back(building);
        if(!initialize){
        notReady.push_back(building);
    }
    } else if(type == 3){
        Stonecutter *building = new Stonecutter(map->getTerrain(location), initialize);
        buildings.push_back(building);
        if(!initialize){
        notReady.push_back(building);
    }
    } else if(type == 4){
        Ironcutter *building = new Ironcutter(map->getTerrain(location), initialize);
        buildings.push_back(building);
        if(!initialize){
        notReady.push_back(building);
    }
    } else if(type == 5){
        Blacksmith *blacksmith = new Blacksmith(map->get_map()[location->getX()][location->getY()], initialize);
        buildings.push_back(blacksmith);
    } else if(type == 6){
        //Keep
        
    } else if(type == 7){
        Road *road = new Road(map->get_map()[location->getX()][location->getY()], initialize, type);
        buildings.push_back(road);
    } else if(type == 8){
        Road *road = new Road(map->get_map()[location->getX()][location->getY()], initialize, type);
        buildings.push_back(road);
    } else if(type == 9){
        Road *road = new Road(map->get_map()[location->getX()][location->getY()], initialize, type);
        buildings.push_back(road);
    }
}

void Game::addSettler(House *house, Coordinates *location) {
    Settler *settler = new Settler("John Cena" + std::to_string(settlers.size()), new Coordinates(*location));
    house->addSettler(settler);
    settlers.push_back(settler);
}

std::vector<Settler*> Game::getSettlers() {return settlers;}

std::vector<Building*> Game::getBuildings() {return buildings;}

bool Game::simulate(){
    for(std::vector<Settler*>::iterator it = settlers.begin(); it !=settlers.end(); it++){
       std::cout<<"Moi"<<std::endl;
       if((**it).getDelay() > 0 ){
        std::cout<<"Moi1"<<std::endl;
        (**it).reduceDelay();
       }else{
           if((**it).move()){
               std::cout<<"Moi2"<<std::endl;
               (**it).setDelay(0);
           }else {
               std::cout<<"Moi3"<<std::endl;
               checkTask((**it).getTask(), *it);
           }
       }
        std::cout << **it << std::endl;        
    }
    return true;
}
    /* Types for task:
    0 = idle
    1 = build
    2 = cut tree
    3 = cut stone
    4 = cut iron
    5 = cut swords
    6 = empty inventory
    7 = get item
    8 = combat
    9 = enemy
    */

void Game::pathToNearbyBuilding(Settler *settler, int building){
    settler->setPath(map->solvePath(settler->getLocation(),map->findNearby(settler->getLocation(),building)));
}

bool Game::atWarehouse(Settler *settler){
    if( (map->getTerrain(settler->getLocation())->getBuildingType() ) != -1 ){
        if(map->getTerrain(settler->getLocation())->getBuilding()->getType() == 2){
            return true;
        }
            return false;
    } else {
        return false;
    }
    return false;
}

int Game::checkTask(int task, Settler *settler) {
    if(!(settler->controlled())){
        enemy(settler);
    }
    
    if(task == 1){
        buildBuilding(settler);
    }else if(task == 2){
        cutTree(settler);
    } else if(task == 3){
        cutStone(settler);
    } else if (task == 4){
        cutIron(settler);
    } 
    return 0;
}

void Game::removeBuilding(Building *building){
    std::vector<Building*>::iterator it = std::find(buildings.begin(), buildings.end(), building);
    buildings.erase(it);
    delete building;
}

void Game::cutTree(Settler *settler){
    if(map->getTerrain(settler->getLocation())->getBuildingType() == 0 && !(settler->inventoryFull())){
        Building *tree = map->getTerrain(settler->getLocation())->getBuilding();
        if(tree->takeDamage()){
            removeBuilding(tree);
			map->getTerrain(settler->getLocation())->setType(0);
        }
        settler->addItem(0);
        settler->setDelay(0);
    } else if (settler->inventoryFull() && atWarehouse(settler)){
        Building *building = map->getTerrain(settler->getLocation())->getBuilding();
        std::vector<int> items = settler->getItems();
        for (int i = 0; i != (int)items.size(); i++){
            building->addItem(items[i]);
        }
        settler->emptyInventory();
    } else if (settler->inventoryFull()) 
        pathToNearbyBuilding(settler, 2);
    
    else {
        pathToNearbyBuilding(settler, 0);
    }
}

void Game::cutStone(Settler *settler) {
	if (map->getTerrain(settler->getLocation())->getBuildingType() == 3 && !(settler->inventoryFull())) {
		Building *stonecutter = map->getTerrain(settler->getLocation())->getBuilding();
		bool notEmpty = stonecutter->removeItem(1);
		if (!notEmpty) {
			removeBuilding(stonecutter);
			map->getTerrain(settler->getLocation())->setType(0);
		}
		else {
			settler->addItem(1);
			settler->setDelay(0);
		}
	}
	else if (settler->inventoryFull() && atWarehouse(settler)) {
		Building *building = map->getTerrain(settler->getLocation())->getBuilding();
		std::vector<int> items = settler->getItems();
		for (int i = 0; i != (int)items.size(); i++) {
			building->addItem(items[i]);
		}
		settler->emptyInventory();
	}
	else if (settler->inventoryFull()) {
        pathToNearbyBuilding(settler, 2);
    }
	else {
		pathToNearbyBuilding(settler, 3);
	}
}

void Game::cutIron(Settler *settler) {
	if (map->getTerrain(settler->getLocation())->getBuildingType() == 4 && !(settler->inventoryFull())) {
		Building *mine = map->getTerrain(settler->getLocation())->getBuilding();
		bool notEmpty = mine->removeItem(2);
		if (!notEmpty) {
			removeBuilding(mine);
			map->getTerrain(settler->getLocation())->setType(0);
		}
		else {
			settler->addItem(2);
			settler->setDelay(0);
		}
	}
	else if (settler->inventoryFull() && atWarehouse(settler)) {
		Building *building = map->getTerrain(settler->getLocation())->getBuilding();
		std::vector<int> items = settler->getItems();
		for (int i = 0; i != (int)items.size(); i++) {
			building->addItem(items[i]);
		}
		settler->emptyInventory();
	}
	else if (settler->inventoryFull()) {
		pathToNearbyBuilding(settler, 2);
    }

	else {
		pathToNearbyBuilding(settler, 4);
	}
}

void Game::buildBuilding(Settler *settler){
    
    if((int)notReady.size() == 0){
        pathToNearbyBuilding(settler, 1);
        return;
    }
    Building *buildThis = notReady[0];
    std::vector<int> requirements = buildThis->getInventory().first;    
    
    if(map->getTerrain(settler->getLocation())->getBuildingType() == 2 && !(settler->inventoryFull()) && map->getTerrain(settler->getLocation())->getBuilding()->getReadiness()){
        //gets items from 
        std::cout << "entering warehouse" << std::endl;
        Building *warehouse = map->getTerrain(settler->getLocation())->getBuilding();
        for(int it = 0; it != (int)warehouse->getInventory().first.size(); it++){
            if(warehouse->getInventory().first[it] == requirements[0]){
                settler->addItem(requirements[0]);
                warehouse->removeItem(it);
                it--;
                return;
            }
        }
    }else if(settler->inventoryFull() && (*settler->getLocation()) != (*buildThis->getLocation())){
        std::cout<< "route to building" << std::endl;
        settler->setPath(map->solvePath(settler->getLocation(),buildThis->getLocation()));
    }else if(settler->inventoryEmpty()){
           std::cout << "route to warehouse" << std::endl;
           pathToNearbyBuilding(settler, 2);
    }else if((*settler->getLocation()) == (*buildThis->getLocation()) ){
        std::cout << "build the building" << std::endl;
        if(settler->getItems()[0] == requirements[0]){
            settler->removeItem(requirements[0]);
            if(buildThis->build(requirements[0])){
                buildThis->setReady();
                notReady.erase(notReady.begin());
            }
        }
    } else if(!(settler->inventoryFull())){
        std::cout << "route to warehouse" << std::endl;
        pathToNearbyBuilding(settler, 2);
    } else {
        std::cout <<(*(*settler).getLocation()) <<std::endl;
        std::cout <<(*(*buildThis).getLocation()) <<std::endl;
    }
}

void Game::enemy(Settler *settler){
    std::cout<<"hyi"<<std::endl;
    if ( map->getTerrain(settler->getLocation())->getBuildingType() != -1){
        if(map->getTerrain(settler->getLocation())->getBuilding()->takeDamage()){

            for(std::vector<House*>::iterator it = houses.begin(); it != houses.end(); it++){
                
                if((**it) == *(map->getTerrain(settler->getLocation())->getBuilding())){
                    
                    std::vector<Settler*> tobeDeleted = (*it)->getHabitants();
                    
                    for(std::vector<Settler*>::iterator ite = settlers.begin(); ite != settlers.end(); ite++){
                        
                        for(std::vector<Settler*>::iterator iter = tobeDeleted.begin(); iter != tobeDeleted.end(); iter++){
                            if((**iter) == (**ite)){
                                std::cout<<"plz ei"<<std::endl;
                                settlers.erase(ite);
                                delete *iter;
                                
                            }
                            
                        }
                        
                    }
                    
                    

                }
            }
            
            removeBuilding( map->getTerrain(settler->getLocation())->getBuilding());
        }

    } else {
        pathToNearbyBuilding(settler, 1);
    }
}

void Game::test(){
    addBuilding(1, (map->get_map()[3][3])->getLocation(), true);
    Settler *settler = new Settler("John Cena", new Coordinates(1,1));
    settlers.push_back(settler);
    settlers[2]->setEnemy();

}