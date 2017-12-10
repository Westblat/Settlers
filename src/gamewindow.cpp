#include "gamewindow.h"

GameWindow::GameWindow(QWidget *parent) : QWidget(parent, Qt::Window) {

	setWindowTitle("The Settlers");
    //setMinimumSize(800, 600);
    setFixedSize(1000, 800);

    QGridLayout *grid = new QGridLayout;
    setLayout(grid);

    menu_button = new QPushButton("Main Menu");  //button that shows the main menu
    grid->addWidget(menu_button, 0, 0);
    connect(menu_button, SIGNAL (clicked()), this , SLOT (ShowMainMenu()));

    QGraphicsScene *scene = new QGraphicsScene(this); //scene for viewing game map
    QGraphicsView *view = new QGraphicsView(scene);
    view->show();
    grid->addWidget(view, 1, 0, 10, 10);

    game.setBuildings(); // the buildings the player starts with

    buildings = game.getBuildings();
    settlers = game.getSettlers();

    // DEBUG, say hello to Bob, he's a free settler not tied to a building
    Coordinates *loc = new Coordinates(0,0);
    settlers.push_back(new Settler("Bob", loc));

    draw_terrain(scene); //draws the terrain on the map
    draw_buildings(scene);
    draw_settlers(scene);

    //TODO
    //add a timer
    //refresh the scene in regards to settlers and buildings
    QTimer *timer = new QTimer();
    //x = 0;
    connect(timer, SIGNAL (timeout()), this, SLOT (moveSettlers()));
    //connect(timer, SIGNAL (timeout()), this, SLOT (refreshBuildings()));

    //connect(timer, SIGNAL (timeout()), this, SLOT (randomLocation()));

    timer->start(refresh_time);

}

void GameWindow::randomLocation() {
	// used for DEBUG, moves Bob to a random location
	settlers[2]->move();
}

void GameWindow::ShowMainMenu() {
    this->hide();
}

void GameWindow::draw_terrain(QGraphicsScene *scene) {
	//draws the terrain on the map

	// DEBUG
	//std::cout << "width: " << width << " ";
	//std::cout << "height: " << height << std::endl;
	
	int x = 0;
	int y = 0;
	for (int j = 0; j < width; j++) {
		x = 0;
		for (int i = 0; i < height; i++) { //draw a TerrainItem (which is a rectangle)
			int type = terrain_map[j][i]->getType();
			TerrainItem *titem = new TerrainItem(type);
			titem->setPos(x,y);
			scene->addItem(titem);
			x += tilesize;

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

    int x = 0;
    for (auto building : buildings) {
    	//int type = building->getType();
    	BuildingItem *buildingitem = new BuildingItem(building->getType(), building->getReadiness());
    	buildingitem->setPos(tilesize*building->getLocation()->getX(), tilesize*building->getLocation()->getY());
    	buildingitems.push_back(buildingitem);
    	scene->addItem(buildingitem);
    	x += tilesize;
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
	//DEBUG
	/*
	std::cout << "Settlers moved!" << std::endl;
	for (unsigned int i = 0; i < settlers.size(); i++) {
		settleritems[i]->setPos(tilesize*x, 0);
	}
	x++;*/
	for (unsigned int i = 0; i < settlers.size(); i++) {
		int x = tilesize*settlers[i]->getLocation()->getX();
		int y = tilesize*settlers[i]->getLocation()->getY();
		settleritems[i]->setPos(x, y);
	}
	std::cout << "Refresh" << std::endl;
}

void GameWindow::refreshBuildings() {
	//DEBUG
	/*
	std::cout << "Buildings refreshed!" << std::endl;
	for (unsigned int i = 0; i < buildings.size(); i++) {
		buildingitems[i]->setPos(0, tilesize*x);
	}*/
	// UMMH updating the location of settlers seems to update location of houses too... note: only affects Houses.
	for (unsigned int i = 0; i < buildings.size(); i++) {
		int x = tilesize*buildings[i]->getLocation()->getX();
		int y = tilesize*buildings[i]->getLocation()->getY();
		buildingitems[i]->setPos(x, y);
	}
}