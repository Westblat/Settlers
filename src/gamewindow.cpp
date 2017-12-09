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

}

void GameWindow::ShowMainMenu() {
    this->hide();
}

void GameWindow::draw_terrain(QGraphicsScene *scene) {
	//draws the terrain on the map
	
	std::vector<std::vector<Terrain*>> terrain_map = map.get_map();
	int width = map.get_width();
	int height = map.get_height();
	
	int x = 0;
	int y = 0;
	int type = 0; //initialized as normal grass-terrain
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
	//draws buildings on the map

	// stuff taken from main.cpp when merging GUIdevelop branch with settlerdevelop.
    Terrain location = *(map.get_map())[19][19];
    
    game.setBuildings();

    std::vector<Building*> buildings = game.getBuildings();
    for (std::vector<Building*>:: iterator it = buildings.begin();it != buildings.end(); it++){
        std::cout << **it << std::endl;

    }
}

void GameWindow::draw_settlers(QGraphicsScene *scene) {
	//draws settlers on the map

}