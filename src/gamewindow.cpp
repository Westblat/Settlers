#include "gamewindow.h"
#include "map.h"
#include "terrainitem.h"
#include "buildingitem.h"
#include "settleritem.h"

//#include <iostream>

GameWindow::GameWindow(QWidget *parent) : QWidget(parent, Qt::Window) {

	setWindowTitle("The Settlers");
    setMinimumSize(800, 600);

    QGridLayout *grid = new QGridLayout;
    setLayout(grid);

    menu_button = new QPushButton("Main Menu");  //button that shows the main menu
    grid->addWidget(menu_button, 0, 0);
    connect(menu_button, SIGNAL (clicked()), this , SLOT (ShowMainMenu()));

    QGraphicsScene *scene = new QGraphicsScene(this); //scene for viewing game map
    QGraphicsView *view = new QGraphicsView(scene);
    view->show();
    grid->addWidget(view, 1, 0, 10, 10);

    draw_terrain(scene); //draws the terrain on the map
    draw_buildings(scene);
    draw_settlers(scene);

    //TODO
    //add a timer
    //refresh the scene in regards to settlers and buildings

}

void GameWindow::ShowMainMenu() {
    this->hide();
}

void GameWindow::draw_terrain(QGraphicsScene *scene) {
	//draws the terrain on the map

	// debug
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
    
    game.setBuildings(); // the buildings the player starts with

    // debug, prints the types of the buildings currently on the map. 2 = warehouse, 1 = house, 0 = trees
    std::vector<Building*> buildings = game.getBuildings();
    for (auto i : buildings) {
		std::cout << "Type: " << i->getType();
		std::cout << " Location: " << i->getLocation()->getX() << " " << i->getLocation()->getY() << std::endl;
    }

    int x = 0;
    for (auto building : buildings) {
    	int type = building->getType();
    	BuildingItem *buildingitem = new BuildingItem(type);
    	buildingitem->setPos(tilesize*building->getLocation()->getX(), tilesize*building->getLocation()->getY());
    	//buildingitem->setPos(x,0);
    	scene->addItem(buildingitem);
    	x += tilesize;
    }

}

void GameWindow::draw_settlers(QGraphicsScene *scene) {
	//draws settlers on the map

	std::vector<Building*> buildings = game.getBuildings();
	std::vector<Settler*> settlers = game.getSettlers();

	// debug
	int i = 0;
	for (auto settler : settlers) {
		i++;
		std::cout << i << ": ";
		std::cout << "Name: " << settler->getName();
		std::cout << " Location: " << settler->getLocation()->getX() << " " << settler->getLocation()->getY() << std::endl;
	}

	for (auto settler : settlers) {
		SettlerItem *settleritem = new SettlerItem();
		settleritem->setPos(tilesize*settler->getLocation()->getX(), tilesize*settler->getLocation()->getY());
		scene->addItem(settleritem);
	}
}