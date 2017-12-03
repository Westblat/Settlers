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
	//draws the terrain of the map
	int tilesize = 50;
	
	int width = game.getMap().get_width();
	int height = game.getMap().get_height();
	int x = 0;
	int y = 0;
	for (int j = 0; j < width; j++) {
		x = 0;
		for (int i = 0; i < height; i++) {
			//draw a TerrainItem (which is a rectangle)
			TerrainItem *titem = new TerrainItem(tilesize);
			titem->setPos(x,y);
			//QBrush red = QBrush(QColor(255, 0, 0));
            //titem->setBrush(red);
			scene->addItem(titem);
			x += tilesize;

		}
		//next row
		y += tilesize;
	}
	/*
	int i = game.getMap().get_width();
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "Map width is: " << i << std::endl;
	*/
}