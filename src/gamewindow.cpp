#include "gamewindow.h"

GameWindow::GameWindow(QWidget *parent) : QWidget(parent, Qt::Window) {

	setWindowTitle("The Settlers");
    setMinimumSize(800, 600);

    QGridLayout *grid = new QGridLayout;
    setLayout(grid);

    // button that shows the main menu
    menu_button = new QPushButton("Main Menu");
    //grid->addWidget(menu_button, 0, 10);
    grid->addWidget(menu_button, 1, 0);
    connect(menu_button, SIGNAL (clicked()), this , SLOT (ShowMainMenu()));

    // GAMEMAP
    // creates the scene for viewing game map
    scene = new QGraphicsScene(this);
    view = new QGraphicsView(scene);
    view->show();
    //grid->addWidget(view, 1, 1, 10, 10);
    grid->addWidget(view, 2, 1, 10, 10);

    // BUILDMENU
    // scene for viewing build menu/buildingselection
    buildmode = false;
    buildscene = new QGraphicsScene(this);
    buildview = new QGraphicsView(buildscene);
    buildview->show();
    buildview->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //grid->addWidget(buildview, 1, 0, 8, 1);
    grid->addWidget(buildview, 3, 0, 9, 1);
    QLabel *buildlabel = new QLabel(this); // text above the buildingselection
    buildlabel->setText(QString("Buildings"));
    buildlabel->show();
    //grid->addWidget(buildlabel, 0, 0);
    grid->addWidget(buildlabel, 2, 0);
    for (int i = 1; i < 10; i++) {
    	//std::cout << "icon: " << i << std::endl;
    	BuildmenuIcon *icon = new BuildmenuIcon(i);
    	icon->setPos(0, tilesize*(i-1));
    	buildscene->addItem(icon);
    	connect(icon, SIGNAL(clicked(int)), this, SLOT(selectBuildingLocation(int)));
    }

    // RESOURCES
    // scene for viewing resourcecount
    resscene = new QGraphicsScene(this);
    resview = new QGraphicsView(resscene);
    resview->show();
    grid->addWidget(resview, 1, 1, 1, 1);
    QLabel *reslabel = new QLabel(this); // text above the buildingselection
    reslabel->setText(QString("Resources"));
    reslabel->show();
    grid->addWidget(reslabel, 0, 1);


    // COMMANDMENU
    // scene for viewing commands
    commandscene = new QGraphicsScene(this);
    commandview = new QGraphicsView(commandscene);
    commandview->show();
    grid->addWidget(commandview, 1, 2, 1, 1);
    QLabel *cmdlabel = new QLabel(this);
    cmdlabel->setText(QString("Commands"));
    cmdlabel->show();
    grid->addWidget(cmdlabel, 0, 2);
    for (int i = 0; i < 8; i++) {
    	cmdMenuIcon *icon = new cmdMenuIcon();
    	icon->setPos(tilesize*i, 0);
    	commandscene->addItem(icon);
    }

    // the buildings the player starts with
    game.setBuildings();

    buildings = game.getBuildings();
    settlers = game.getSettlers();

    
    // DEBUG, say hello to Bob, he's a free settler not tied to a building
    Coordinates *loc = new Coordinates(0,0);
    settlers.push_back(new Settler("Bob", loc));
    //game.addBuilding(1, (map.get_map()[15][15])->getLocation(), false);
    //game.addBuilding(2, (map.get_map()[5][5])->getLocation(), false);
	settlers[0]->setTask(1);
    settlers[1]->setTask(2);
	
    draw_terrain(scene); //draws the terrain on the map
    draw_buildings(scene);
    draw_settlers(scene);

    //add a timer
    //refresh the scene in regards to settlers and buildings
    QTimer *timer = new QTimer();
    //x = 0;
    connect(timer, SIGNAL (timeout()), this, SLOT (refresh()));
    connect(timer, SIGNAL (timeout()), this, SLOT (moveSettlers()));
    connect(timer, SIGNAL (timeout()), this, SLOT (refreshBuildings()));
    timer->start(refresh_time);

    //connect(timer, SIGNAL (timeout()), this, SLOT (randomLocation())); //DEBUG
    //DEBUG
    /*
    QTimer *damager = new QTimer();
    connect(damager, SIGNAL (timeout()), this, SLOT (removeHP()));
    damager->start(1000);
    */

}

void GameWindow::selectBuildingLocation(int type) {
	//std::cout << "Where ya wanna build?" << std::endl;
	//std::cout << "You've selected a " << type << std::endl;
	buildmode = true;
	newBuildingType = type;
}

void GameWindow::getSiteLocation(Terrain *terrain) {
	// Builds a new building in the given location
	//int x = terrain->getLocation()->getX();
    //int y = terrain->getLocation()->getY();
    //std::cout << "You clicked on x: " << x << " y: " << y << std::endl;
    if (buildmode == true) {

    	BuildingItem *buildingitem;

    	if (newBuildingType >= 7) {
    		game.addBuilding(7, terrain->getLocation(), true);
    	}
    	else {
    		//game.addBuilding(newBuildingType, terrain->getLocation(), true); //DEBUG
    		game.addBuilding(newBuildingType, terrain->getLocation(), false);
    	}

    	buildings = game.getBuildings();

    	if (newBuildingType >= 7) {
            buildingitem = new BuildingItem(newBuildingType, buildings.back()->getReadiness(), buildings.back()->getHp(), buildings.back()->getLocation()->getX(), buildings.back()->getLocation()->getY());
    	}
    	else {
            buildingitem = new BuildingItem(buildings.back()->getType(), buildings.back()->getReadiness(), buildings.back()->getHp(), buildings.back()->getLocation()->getX(), buildings.back()->getLocation()->getY());
    	}

    	buildingitem->setPos(tilesize*buildings.back()->getLocation()->getX(), tilesize*buildings.back()->getLocation()->getY());
    	buildingitem->setZValue(1);
    	buildingitems.push_back(buildingitem);
    	scene->addItem(buildingitem);

    	buildmode = false;
    	newBuildingType = -1;
    	//std::cout << "House built" << std::endl;
    }
}

void GameWindow::cancelBuild() {
	buildmode = false; // buildmode can be cancelled with rightclick
}

void GameWindow::giveCommand() {
	std::cout << "You clicked on a SETTLER!" << std::endl;
}

void GameWindow::randomLocation() {
	// used for DEBUG, moves Bob to a random location
	settlers[2]->move();
	//std::cout << buildings[1]->getLocation()->getX() << " " << buildings[1]->getLocation()->getY() << std::endl;
	//std::cout << settlers[1]->getLocation()->getX() << " " << settlers[1]->getLocation()->getY() << std::endl;
}

void GameWindow::removeHP() {
	//DEBUG
	/*
	bool destroyed = false;
	for (auto building : buildings) {
		std::cout << building->getHp() << std::endl;
		if (building->getHp() != 0) {
			destroyed = building->takeDamage();
		}
	}
	*/
}

void GameWindow::ShowMainMenu() {
    this->hide();
}

void GameWindow::draw_terrain(QGraphicsScene *scene) {
	//draws the terrain on the map
	//NOTE: x and y seem to be mirrored in terrain_map location-coordinates compared to their actual location...

	int x = 0;
	int y = 0;
	for (int j = 0; j < width; j++) {
		x = 0;
		for (int i = 0; i < height; i++) {
			//draw a TerrainItem
            int type = terrain_map[i][j]->getType();
			//TerrainItem *titem = new TerrainItem(type, terrain_map[j][i]);
			TerrainItem *titem = new TerrainItem(type, terrain_map[i][j]); // QUICK AND DIRTY FIX !!
			titem->setPos(x,y);
			scene->addItem(titem);
			x += tilesize;
			connect(titem, SIGNAL(clicked(Terrain*)), this, SLOT(getSiteLocation(Terrain*)));
			connect(titem, SIGNAL(rightclicked(Terrain*)), this, SLOT(cancelBuild()));
		}
		//next row
		y += tilesize;
	}
}

void GameWindow::draw_buildings(QGraphicsScene *scene) {
	//draws the buildings (and trees) on the map

    // DEBUG
    
    std::vector<Building*> buildings = game.getBuildings();
    for (auto i : buildings) {
		std::cout << "Type: " << i->getType();
		std::cout << " Location: " << i->getLocation()->getX() << " " << i->getLocation()->getY() << std::endl;
    }

    for (auto building : buildings) {
        BuildingItem *buildingitem = new BuildingItem(building->getType(), building->getReadiness(), building->getHp(), building->getLocation()->getX(), building->getLocation()->getY());
    	//BuildingItem *buildingitem = new BuildingItem(building->getType(), true, 10); //DEBUG
    	//BuildingItem *buildingitem = new BuildingItem(building->getType(), false, 0); //DEBUG
    	buildingitem->setPos(tilesize*building->getLocation()->getX(), tilesize*building->getLocation()->getY());
    	buildingitem->setZValue(1);
    	buildingitems.push_back(buildingitem);
    	scene->addItem(buildingitem);
    }

}

void GameWindow::draw_settlers(QGraphicsScene *scene) {
	//draws settlers on the map

	// DEBUG
	/*
	int i = 0;
	for (auto settler : settlers) {
		i++;
		std::cout << i << ": ";
		std::cout << "Name: " << settler->getName();
		std::cout << " Location: " << settler->getLocation()->getX() << " " << settler->getLocation()->getY() << std::endl;
	}*/

	for (auto settler : settlers) {
		SettlerItem *settleritem = new SettlerItem(settler);
		settleritem->setPos(tilesize*settler->getLocation()->getX(), tilesize*settler->getLocation()->getY());
		settleritems.push_back(settleritem);
		scene->addItem(settleritem);
		connect(settleritem, SIGNAL(clicked()), this, SLOT(giveCommand()));
	}
}

void GameWindow::moveSettlers() {
	// Refreshes the location of settlers
	std::cout << "Refresh" << std::endl;
	for (unsigned int i = 0; i < settlers.size(); i++) {
		int x = tilesize*settlers[i]->getLocation()->getX();
		int y = tilesize*settlers[i]->getLocation()->getY();
		settleritems[i]->setPos(x, y);
	}
}

void GameWindow::refreshBuildings() {
	// check readiness and health of buildings, update from constructionsite to complete building, tree to cut tree
	// or building to destroyed building

    //*___________Copies buildingitems to temp container______________
    auto tempBuildItems (buildingitems);
    //_______________________________________________________________*/

	for (unsigned int i = 0; i < buildings.size(); i++) {
		bool ready = buildings[i]->getReadiness();
        if (buildingitems[i]->getReadiness() != ready) {
			//remove old and replace with new
			scene->removeItem(buildingitems[i]);
            BuildingItem *buildingitem = new BuildingItem(buildings[i]->getType(), buildings[i]->getReadiness(), buildings[i]->getHp(), buildings[i]->getLocation()->getX(), buildings[i]->getLocation()->getY());
			buildingitem->setPos(tilesize*buildings[i]->getLocation()->getX(), tilesize*buildings[i]->getLocation()->getY());
			buildingitem->setZValue(1);
			buildingitems[i] = buildingitem;
			scene->addItem(buildingitem);
        }
        //*_______________________REMOVES EXISTING ITEMS FROM TEMP CONTAINER___________________________________
        for (auto iter = tempBuildItems.begin(); iter != tempBuildItems.end(); iter++){
            if((*iter)->getX() == buildingitems[i]->getX() && (*iter)->getY() == buildingitems[i]->getY()){
                tempBuildItems.erase(iter);
                break;
            }
        }
        //____________________________________________________________________________________________________*/
	}
    //*______________REMOVES ITEMS LEFT IN TEMP CONTAINER FROM QGRAPHICSSCENE__________________________________
    for(auto item : tempBuildItems){
        scene->removeItem(item);
        for(std::vector<BuildingItem*>::iterator it = buildingitems.begin(); it != buildingitems.end(); it++){
            if(item->getX()==(*it)->getX() && item->getY()==(*it)->getY()){
                buildingitems.erase(it);
                break;
            }
        }
    }
    tempBuildItems.clear();
    //________________________________________________________________________________________________________*/
}

void GameWindow::refresh() {

	//std::cout << "Refresh" << std::endl;
	game.simulate();
    buildings = game.getBuildings();
	settlers = game.getSettlers();
}
