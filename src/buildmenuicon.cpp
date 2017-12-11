#include "buildmenuicon.h"

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

BuildmenuIcon::BuildmenuIcon(int type, QGraphicsItem *parent) : QGraphicsPixmapItem(parent) {
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