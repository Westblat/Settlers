#include "game.h"

Game::Game() {
    map = new Map(21,21);
    map->setMap();
    //std::cout << *map<<std::endl;
    settlers.push_back(new Settler("Bob", new Coordinates(20,20)));
    settlers[0]->setEnemy();
    settlers[0]->setDelay(10000000000000000);
    Game::addBuilding(5, (map->get_map()[1][1])->getLocation(), true);
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
        Blacksmith *blacksmith = new Blacksmith(map->getTerrain(location), initialize);
        buildings.push_back(blacksmith);
    } else if(type == 6){
        Keep *keep = new Keep(map->getTerrain(location), initialize);
        buildings.push_back(keep);
    } else if(type == 7){
        Road *road = new Road(map->getTerrain(location), initialize, type);
        buildings.push_back(road);
    } else if(type == 8){
        Road *road = new Road(map->getTerrain(location), initialize, type);
        buildings.push_back(road);
    } else if(type == 9){
        Road *road = new Road(map->getTerrain(location), initialize, type);
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
    for(std::vector<Settler*>::reverse_iterator it = settlers.rbegin(); it !=settlers.rend(); it++){
       //std::cout<< (*it)->getDelay() << std::endl;
       if((**it).getDelay() > 0 ){
        (**it).reduceDelay();
       }else{
           if((**it).move()){
               if((*it)->controlled()){
                   (**it).setDelay(0);
               }else{(**it).setDelay(1);}
           }else {
               checkTask((**it).getTask(), *it);
           }
       }    
        //std::cout << **it << std::endl;        
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
    } else if (task == 8){
        combat(settler);
    } else if (task == 5){
        cutSwords(settler);
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

void Game::cutSwords(Settler *settler){
    Coordinates *s_loc = settler->getLocation();
    Coordinates *bm_loc = map->findNearby(s_loc, 5);
    Building *bm = map->getTerrain(bm_loc)->getBuilding();

    if(s_loc == bm_loc){
        std::cout << "making swords" << std::endl;
        if(settler->removeItem(2)){
            settler->addItem(3);
        }else{
            std::cout << "going to warehouse" << std::endl;
            pathToNearbyBuilding(settler, 2);
        }
        
        
       /* if(bm->removeItem(2)){
            if(bm->addItem(3)){
                std::cout<<"Sword made"<<std::endl;
                settler->setDelay(5);
            }
            else{
                std::cout<<"Unexpected result making swords, no sword created"<<std::endl;
            }
        }*/
        /*else if(!settler->inventoryEmpty()){
            for(int i = 0; i != (int)(settler->getItems().size()); i++) {
                bm->addItem(items[i]);
            }
            settler->emptyInventory();
        }*/
        /*else{
            while(bm->getInventory().first.size() > 0 && !(settler->inventoryFull())) {
                if(settler->addItem(bm->getInventory().first[0])){
                    bm->removeItem(bm->getInventory().first[0]);
                }else{break;}
            }
            pathToNearbyBuilding(settler, 2);
        }*/
    }
    else if (!settler->inventoryFull() && map->getTerrain(s_loc)->getBuildingType() == 2){
                    std::cout << "going to warehouse" << std::endl;
        Building *warehouse = map->getTerrain(settler->getLocation())->getBuilding();
        for(int it = 0; it != (int)warehouse->getInventory().first.size(); it++){
            if(warehouse->getInventory().first[it] == 2){
                settler->addItem(2);
                warehouse->removeItem(it);
                it--;
                return;
            }
        }
    }
    else if (settler->inventoryFull() && settler->getItems()[4] == 2){
                    std::cout << "going to smith" << std::endl;

        pathToNearbyBuilding(settler, 5);
    }
    else if (!settler->inventoryEmpty() && settler->getItems()[4] != 2 && map->getTerrain(s_loc)->getBuildingType() == 2){
        std::cout << "mpty items" << std::endl;
        for(int i = 0; i != (int)(settler->getItems().size()); i++) {
            map->getTerrain(s_loc)->getBuilding()->addItem(settler->getItems()  [i]);
        }
        settler->emptyInventory();
    }
    std::cout << "fuck this shit" << std::endl;

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
        //std::cout << "entering warehouse" << std::endl;
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
        //std::cout<< "route to building" << std::endl;
        settler->setPath(map->solvePath(settler->getLocation(),buildThis->getLocation()));
    }else if(settler->inventoryEmpty()){
           //std::cout << "route to warehouse" << std::endl;
           pathToNearbyBuilding(settler, 2);
    }else if((*settler->getLocation()) == (*buildThis->getLocation()) ){
        //std::cout << "build the building" << std::endl;
        if(settler->getItems()[0] == requirements[0]){
            settler->removeItem(requirements[0]);
            if(buildThis->build(requirements[0])){
                buildThis->setReady();
                notReady.erase(notReady.begin());
            }
        }
    } else if(!(settler->inventoryFull())){
        //std::cout << "route to warehouse" << std::endl;
        pathToNearbyBuilding(settler, 2);
    } else {
        //std::cout <<(*(*settler).getLocation()) <<std::endl;
        //std::cout <<(*(*buildThis).getLocation()) <<std::endl;
    }
}

//Bob is your enemy, he is on an island, but he will find a way and wreck your houses
void Game::enemy(Settler *settler){
    if(*(settler->getLocation())==*(map->getTerrain(20,20)->getLocation())){
        //std::cout<<"tp";
        settler->teleport(20,13);
        return;
    }

    if ( map->getTerrain(settler->getLocation())->getBuildingType() != -1){
        
        if(map->getTerrain(settler->getLocation())->getBuilding()->takeDamage()){

            House *destroyed;

            //Find house located where attacker is
            for(std::vector<House*>::iterator it = houses.begin(); it != houses.end(); it++){
                if((**it) == *(map->getTerrain(settler->getLocation())->getBuilding())){
                    destroyed = *it;
                    break;
                }
            }

            //Settlers living in house are killed even though they are not there
            std::vector<Settler*> tobeDeleted = destroyed->getHabitants();

            //Removes settlers from settler vector, so they can be deleted safely
            for(std::vector<Settler*>::iterator ite = tobeDeleted.begin(); ite != tobeDeleted.end(); ite++){
                for(std::vector<Settler*>::iterator iter = settlers.begin(); iter != settlers.end(); iter++){
                    if((**iter) == (**ite)){
                    settlers.erase(iter);
                    break;
                    }
                }
            }
            removeBuilding(destroyed);
            settler->setDelay(5);
        }

    } else {
        pathToNearbyBuilding(settler, 1);
    }
}

void Game::combat(Settler *settler){
    Coordinates *def_loc = settler->getLocation();
    Coordinates *bob_loc = settlers[0]->getLocation();

    if(settler->inventoryEmpty() || settler->getItems()[0] != 3){
        if(!settler->inventoryEmpty()){
            if(map->getTerrain(def_loc)->getType() == 2){
                Building *building = map->getTerrain(def_loc)->getBuilding();
                std::vector<int> items = settler->getItems();
                for (int i = 0; i != (int)items.size(); i++){
                    building->addItem(items[i]);
                }
                settler->emptyInventory();;
            }
            else{
                pathToNearbyBuilding(settler, 2);
            }
        }
        else{
            for(auto i : buildings) {
                if(i->getReadiness()){
                    for(auto it : i->getInventory().first){
                        if(it == 3){
                            if(def_loc == i->getLocation()){
                                i->removeItem(3);
                                settler->addItem(3);
                                std::cout<<"Got a sword"<<std::endl;
                                break;
                            }
                            else{
                                settler->setPath(map->solvePath(def_loc,i->getLocation()));
                                return;
                            }
                        }
                    }
                }
            }
        }
    }

    //If sword is not found or settler has a sword he starts to wonder if Bob is nearby
    if(*(bob_loc) == *(map->getTerrain(20,20)->getLocation())){
        pathToNearbyBuilding(settler, 6);
    }
    else{
        if(*def_loc == *bob_loc){
            if(settler->inventoryEmpty() || settler->getItems()[0] != 3){
                if(settlers[0]->removeHP(2) == 0){
                    settlers[0]->teleport(20,20);
                    settlers[0]->addHP(12);
                    settlers[0]->setDelay(100);
                }
            }
            else{
                if(settlers[0]->removeHP(4) == 0){
                    settlers[0]->teleport(20,20);
                    settlers[0]->addHP(14);
                    settlers[0]->setDelay(1000);
                }
            }
        }
        else {
            std::stack<std::pair<int, int> > path = map->solvePath(def_loc,bob_loc);
            std::stack<std::pair<int, int> > step;
            step.push(path.top());
            settler->setPath(step);
        }
    }
}

