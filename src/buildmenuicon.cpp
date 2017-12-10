#include "buildmenuicon.h"

#include <iostream>

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

BuildmenuIcon::BuildmenuIcon(int buildingtype, QGraphicsItem *parent) : QGraphicsPixmapItem(parent) {
	type = buildingtype;
	if (type == 1) {
		setPixmap(QPixmap(":/graphics/houseicon.png"));
	}
	else if (type == 2) {
		setPixmap(QPixmap(":/graphics/warehouseicon.png"));
	}
	else if (type == 3) {
		setPixmap(QPixmap(":/graphics/stonecuttericon.png"));
	}
	else if (type == 4) {
		setPixmap(QPixmap(":/graphics/mineicon.png"));
	}
	else if (type == 5) {
		setPixmap(QPixmap(":/graphics/blacksmithicon.png"));
	}
	else if (type == 6) {
		setPixmap(QPixmap(":/graphics/keepicon.png"));
	}
	/*else if (type == 7) {
		setPixmap(QPixmap(":/graphics/roadicon.png"));
	}*/
}

void BuildmenuIcon::mousePressEvent(QGraphicsSceneMouseEvent *) {
    if (type == 1) {
    	std::cout << "You clicked on a House!" << std::endl;
    }
    else if (type == 2) {
    	std::cout << "This is a WAREHOUSE!" << std::endl;
    }
    else {
    	std::cout << "Hey!" << std::endl;
    }
}