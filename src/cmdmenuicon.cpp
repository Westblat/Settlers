#include "cmdmenuicon.h"

    /* Types for task:
    0 = idle
    1 = build
    2 = cut tree
    3 = cut stone
    4 = cut iron
    5 = cut swords
    6 = empty inventory
    7 = get item
    8 = combat
    */

cmdMenuIcon::cmdMenuIcon(int type, QGraphicsItem *parent) : QGraphicsPixmapItem(parent) {
    cmdtype = type;
	setPixmap(QPixmap(":/graphics/cmdicon.png"));
}

void cmdMenuIcon::mousePressEvent(QGraphicsSceneMouseEvent *) {
    emit clicked(cmdtype);
}