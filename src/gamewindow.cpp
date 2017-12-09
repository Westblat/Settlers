#include "gamewindow.h"
#include "map.h"
#include "terrainitem.h"

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
	int type;
	for (int j = 0; j < width; j++) {
		x = 0;
		for (int i = 0; i < height; i++) { //draw a TerrainItem (which is a rectangle)
			type = terrain_map[j][i]->getType();
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
		std::cout << "Type: " << i->getType() << std::endl;
		//std::cout << " Location: " << i->getLocation()->getX() << " " << i->getLocation()->getY() << std::endl;
		
		//Apparently buildings don't have locations, how do I know where to place buildings?
    }
/*
    int x = 0;
	int y = 0;
	int type;
	for (int j = 0; j < width; j++) {
		x = 0;
		for (int i = 0; i < height; i++) {
			type = terrain_map[j][i]->getType();
			BuildingItem *bitem = new BuildingItem(type);
			bitem->setPos(x,y);
			scene->addItem(bitem);
			x += tilesize;

		}
		y += tilesize;
	}*/

}

void GameWindow::draw_settlers(QGraphicsScene *scene) {
	//draws settlers on the map

}