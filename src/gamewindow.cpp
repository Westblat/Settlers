#include "gamewindow.h"

GameWindow::GameWindow(QWidget *parent) : QWidget(parent, Qt::Window) {

	setWindowTitle("The Settlers");
    setFixedSize(1000, 800);

    QGridLayout *grid = new QGridLayout;
    setLayout(grid);

    // button that shows the main menu
    menu_button = new QPushButton("Main Menu");
    grid->addWidget(menu_button, 0, 10);
    connect(menu_button, SIGNAL (clicked()), this , SLOT (ShowMainMenu()));

    // GAMEMAP
    // creates the scene for viewing game map
    scene = new QGraphicsScene(this);
    view = new QGraphicsView(scene);
    view->show();
    grid->addWidget(view, 1, 1, 10, 10);

    // BUILDMENU
    buildmode = false;
    // scene for viewing build menu/buildingselection
    buildscene = new QGraphicsScene(this);
    buildview = new QGraphicsView(buildscene);
    buildview->show();
    grid->addWidget(buildview, 1, 0, 6, 1);
    QLabel *buildlabel = new QLabel(this); // text above the buildingselection
    buildlabel->setText(QString("Buildings"));
    buildlabel->show();
    grid->addWidget(buildlabel, 0, 0);
    for (int i = 1; i < 7; i++) {
    	BuildmenuIcon *icon = new BuildmenuIcon(i);
    	icon->setPos(0, tilesize*(i-1));
    	buildscene->addItem(icon);
    	connect(icon, SIGNAL(clicked(int)), this, SLOT(selectBuildingLocation(int)));
    }

    // the buildings the player starts with
    game.setBuildings();

    buildings = game.getBuildings();
    settlers = game.getSettlers();

    /*
    // DEBUG, say hello to Bob, he's a free settler not tied to a building
    Coordinates *loc = new Coordinates(0,0);
    settlers.push_back(new Settler("Bob", loc));
    */

    draw_terrain(scene); //draws the terrain on the map
    draw_buildings(scene);
    draw_settlers(scene);

    //add a timer
    //refresh the scene in regards to settlers and buildings
    QTimer *timer = new QTimer();
    //x = 0;
    //connect(timer, SIGNAL (timeout()), this, SLOT (refresh()));
    connect(timer, SIGNAL (timeout()), this, SLOT (moveSettlers()));
    connect(timer, SIGNAL (timeout()), this, SLOT (refreshBuildings()));

    //connect(timer, SIGNAL (timeout()), this, SLOT (randomLocation()));

    timer->start(refresh_time);

}

void GameWindow::selectBuildingLocation(int type) {
	std::cout << "Where ya wanna build?" << std::endl;
	std::cout << "You've selected a " << type << std::endl;
	buildmode = true;
	newBuildingType = type;
}

void GameWindow::getSiteLocation(Terrain *terrain) {
	int x = terrain->getLocation()->getX();
    int y = terrain->getLocation()->getY();
    std::cout << "You clicked on x: " << x << " y: " << y << std::endl;
    if (buildmode == true) {
    	game.addBuilding(newBuildingType, terrain->getLocation(), false);

    	buildings = game.getBuildings();
    	BuildingItem *buildingitem = new BuildingItem(buildings.back()->getType(), buildings.back()->getReadiness(), buildings.back()->getHp());
    	buildingitem->setPos(tilesize*buildings.back()->getLocation()->getX(), tilesize*buildings.back()->getLocation()->getY());
    	buildingitem->setZValue(1);
    	buildingitems.push_back(buildingitem);
    	scene->addItem(buildingitem);

    	buildmode = false;
    	newBuildingType = -1;
    	std::cout << "house built" << std::endl;
    }
}

void GameWindow::randomLocation() {
	// used for DEBUG, moves Bob to a random location
	settlers[1]->move();
	std::cout << buildings[1]->getLocation()->getX() << " " << buildings[1]->getLocation()->getY() << std::endl;
	std::cout << settlers[1]->getLocation()->getX() << " " << settlers[1]->getLocation()->getY() << std::endl;

	//game.simulate();
}

void GameWindow::ShowMainMenu() {
    this->hide();
}

void GameWindow::draw_terrain(QGraphicsScene *scene) {
	//draws the terrain on the map
	
	int x = 0;
	int y = 0;
	for (int j = 0; j < width; j++) {
		x = 0;
		for (int i = 0; i < height; i++) { //draw a TerrainItem (which is a rectangle)
			int type = terrain_map[i][j]->getType();
			TerrainItem *titem = new TerrainItem(type, terrain_map[i][j]);
			titem->setPos(x,y);
			//terrainitems.push_back(titem);
			scene->addItem(titem);
			x += tilesize;
			connect(titem, SIGNAL(clicked(Terrain*)), this, SLOT(getSiteLocation(Terrain*)));
		}
		//next row
		y += tilesize;
	}
}

void GameWindow::draw_buildings(QGraphicsScene *scene) {
	//draws the buildings (and trees) on the map

    // DEBUG
    /*
    std::vector<Building*> buildings = game.getBuildings();
    for (auto i : buildings) {
		std::cout << "Type: " << i->getType();
		std::cout << " Location: " << i->getLocation()->getX() << " " << i->getLocation()->getY() << std::endl;
    }*/

    for (auto building : buildings) {
    	BuildingItem *buildingitem = new BuildingItem(building->getType(), building->getReadiness(), building->getHp());
    	//BuildingItem *buildingitem = new BuildingItem(building->getType(), false, 0);
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
		SettlerItem *settleritem = new SettlerItem();
		settleritem->setPos(tilesize*settler->getLocation()->getX(), tilesize*settler->getLocation()->getY());
		settleritems.push_back(settleritem);
		scene->addItem(settleritem);
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
	for (unsigned int i = 0; i < buildings.size(); i++) {
		bool ready = buildings[i]->getReadiness();
		// check readiness of buildings, update from constructionsite to complete building
		if (buildingitems[i]->getReadiness() != ready) {
			//remove old and replace with new
			scene->removeItem(buildingitems[i]);
			BuildingItem *buildingitem = new BuildingItem(buildings[i]->getType(), buildings[i]->getReadiness(), buildings[i]->getHp());
			buildingitem->setPos(tilesize*buildings[i]->getLocation()->getX(), tilesize*buildings[i]->getLocation()->getY());
			buildingitem->setZValue(1);
			buildingitems[i] = buildingitem;
			scene->addItem(buildingitem);
		}
		// check health of building, update from whole tree to cut tree (yet to implement destroyed buildings)
		else if (buildingitems[i]->getHP() == 0) {
			scene->removeItem(buildingitems[i]);
			BuildingItem *buildingitem = new BuildingItem(buildings[i]->getType(), buildings[i]->getReadiness(), buildings[i]->getHp());
			buildingitem->setPos(tilesize*buildings[i]->getLocation()->getX(), tilesize*buildings[i]->getLocation()->getY());
			buildingitem->setZValue(1);
			buildingitems[i] = buildingitem;
			scene->addItem(buildingitem);
		}
	}
}

void GameWindow::refresh() {
	//std::cout << "Refresh" << std::endl;
	buildings = game.getBuildings();
	settlers = game.getSettlers();
}