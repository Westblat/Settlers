#include "terrainitem.h"

TerrainItem::TerrainItem(int type, Terrain *terrainptr, QGraphicsItem *parent) : QGraphicsPixmapItem(parent) {
	terrain = terrainptr;

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

void TerrainItem::mousePressEvent(QGraphicsSceneMouseEvent *) {
	/*
	int x = terrain->getLocation()->getX();
    int y = terrain->getLocation()->getY();
    std::cout << "You clicked on x: " << x << " y: " << y << std::endl;
    */
    emit clicked(terrain);
    //emit clicked(0);
}