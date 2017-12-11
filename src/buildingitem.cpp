#include "buildingitem.h"

BuildingItem::BuildingItem(int buildingtype, bool ready, int health, QGraphicsItem *parent) : QGraphicsPixmapItem(parent) {
/*	Building types are
	0: tree
	1: House
	2: Warehouse
	3: Stonecutter
	4: Mine
	5: Blacksmith
	6: Keep
	7: Road
*/
	readiness = ready;
	type = buildingtype;
	hp = health;
	if (readiness == false && type != 0) {
		setPixmap(QPixmap(":/graphics/constructionsite.png"));
	}
	else if (hp == 0 && type != 0) {
		setPixmap(QPixmap(":/graphics/destroyedbuilding.png"));
	}
	else {
		if (type == 0) {
			if (hp != 0) {
				setPixmap(QPixmap(":/graphics/tree.png"));
			}
			else {
				setPixmap(QPixmap(":/graphics/cut_tree.png"));
			}
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
		else if (type == 6) {
			setPixmap(QPixmap(":/graphics/keep.png"));
		}
		else if (type == 7) {
			setPixmap(QPixmap(":/graphics/road1.png"));
		}
		else if (type == 8) {
			setPixmap(QPixmap(":/graphics/road2.png"));	
		}
		else if (type == 9) {
			setPixmap(QPixmap(":/graphics/road3.png"));
		}
	}
}