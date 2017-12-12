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
	//setPixmap(QPixmap(":/graphics/cmdicon.png"));
    if (type == 0) {
        setPixmap(QPixmap(":/graphics/cmdicon0.png"));
    }
    else if (type == 1) {
        setPixmap(QPixmap(":/graphics/cmdicon1.png"));
    }
    else if (type == 2) {
        setPixmap(QPixmap(":/graphics/cmdicon2.png"));
    }
    else if (type == 3) {
        setPixmap(QPixmap(":/graphics/cmdicon3.png"));
    }
    else if (type == 4) {
        setPixmap(QPixmap(":/graphics/cmdicon4.png"));
    }
    else if (type == 5) {
        setPixmap(QPixmap(":/graphics/cmdicon5.png"));
    }
    else if (type == 6) {
        setPixmap(QPixmap(":/graphics/cmdicon6.png"));
    }
    else if (type == 7) {
        setPixmap(QPixmap(":/graphics/cmdicon7.png"));
    }
    else if (type == 8) {
        setPixmap(QPixmap(":/graphics/cmdicon8.png"));
    }
}

void cmdMenuIcon::mousePressEvent(QGraphicsSceneMouseEvent *) {
    emit clicked(cmdtype);
}