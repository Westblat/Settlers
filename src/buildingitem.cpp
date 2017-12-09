#include "buildingitem.h"

BuildingItem::BuildingItem(int type, bool ready, QGraphicsItem *parent) : QGraphicsPixmapItem(parent) {
/*	Building types are
	0: tree
	1: House
	2: Warehouse
	3: Stonecutter
	4: Mine
	5: Blacksmith
	6: Keep
*/
	if (ready == false) {
		setPixmap(QPixmap(":/graphics/constructionsite.png"));
	}
	else {
		if (type == 0) {
			setPixmap(QPixmap(":/graphics/tree.png"));
		}
		else if (type == 1) {
			setPixmap(QPixmap(":/graphics/house.png"));
		}
		else if (type == 2) {
			setPixmap(QPixmap(":/graphics/warehouse.png"));
		}
		else if (type == 3) {
			setPixmap(QPixmap(":/graphics/stonecutter.png"));
		}
		else if (type == 4) {
			setPixmap(QPixmap(":/graphics/mine.png"));
		}
		else if (type == 5) {
			setPixmap(QPixmap(":/graphics/blacksmith.png"));
		}
	}
	/*
	// SPECIAL CASES
	else if (type == 6) {
		setPixmap(QPixmap(":/graphics/keep.png"));
	}*/
}