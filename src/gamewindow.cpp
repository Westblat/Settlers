#include "gamewindow.h"
//#include "terrain.h"
#include "map.h"
#include "game.h"
#include "terrainitem.h"

//#include <iostream>


GameWindow::GameWindow(QWidget *parent) : QWidget(parent) {

	setWindowTitle("The Settlers");
    setMinimumSize(650, 650);

    QGridLayout *grid = new QGridLayout;

    menu_button = new QPushButton("Main Menu");  //button that shows the main menu
    grid->addWidget(menu_button, 0, 0);
    connect(menu_button, SIGNAL (clicked()), this , SLOT (ShowMainMenu()));

    QGraphicsScene *scene = new QGraphicsScene(); //scene for viewing game map
    QGraphicsView *view = new QGraphicsView(scene);
    view->show();
    grid->addWidget(view, 1, 0, 10, 10);

    draw_terrain(scene); //draws the terrain on the map

    setLayout(grid);
}

void GameWindow::ShowMainMenu() {
    //somehow show main menu
    this->hide(); //bad solution, works though
}

void GameWindow::draw_terrain(QGraphicsScene *scene) {
	//draws the terrain on the map
	int tilesize = 50;
	
	Map map = game.getMap(); //apparently not the same as the vector<vector<Terrain*>> map
	std::vector<std::vector<Terrain*>> terrain_map = map.get_map();
	int width = map.get_width();
	int height = map.get_height();
	
	int x = 0;
	int y = 0;
	int type = 0; //initialized as normal terrain
	for (int j = 0; j < width; j++) {
		x = 0;
		for (int i = 0; i < height; i++) { //draw a TerrainItem (which is a rectangle)
			type = terrain_map[j][i]->getType();
			TerrainItem *titem = new TerrainItem(tilesize, type);
			titem->setPos(x,y);
			scene->addItem(titem);
			x += tilesize;

		}
		//next row
		y += tilesize;
	}
}