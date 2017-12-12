#include "terrainitem.h"

//TerrainItem::TerrainItem(int type, Terrain *terrainptr, QGraphicsItem *parent) : QGraphicsPixmapItem(parent) {
TerrainItem::TerrainItem(int type, int coord_x, int coord_y, QGraphicsItem *parent) : QGraphicsPixmapItem(parent) {
	//terrain = terrainptr;
	x = coord_x;
	y = coord_y;

	if (type == 0) {		// 0: GRASS/PLAINS
		setPixmap(QPixmap(":/graphics/grass.png"));
	}
	else if (type == 1) {	// 1: STONE
		setPixmap(QPixmap(":/graphics/stone.png"));
	}
	else if (type == 2) {	// 2: MOUNTAIN
		setPixmap(QPixmap(":/graphics/mountain.png"));
	}
	else if (type == 3) {	// 3: BEACH
		setPixmap(QPixmap(":/graphics/beach.png"));
	}
	else if (type == 4) {	// 4: WATER
		setPixmap(QPixmap(":/graphics/water.png"));
	}
}

void TerrainItem::mousePressEvent(QGraphicsSceneMouseEvent *event) {
	/*
	int x = terrain->getLocation()->getX();
    int y = terrain->getLocation()->getY();
    std::cout << "You clicked on x: " << x << " y: " << y << std::endl;
    */
    if (event->button() == Qt::RightButton) {
    	//std::cout << "You pressed the RIGHT mousebutton!" << std::endl;
    	//emit rightclicked(terrain);
    	emit rightclicked(x, y);
    }
    else {
    	//emit clicked(terrain);
    	emit clicked(x, y);
    	//std::cout << "You pressed the LEFT mousebutton!" << std::endl;
    }
    //emit clicked(0);
}