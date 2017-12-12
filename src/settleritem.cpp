#include "settleritem.h"

//SettlerItem::SettlerItem(Settler *settlerptr, QGraphicsItem *parent) : QGraphicsPixmapItem(parent) {
SettlerItem::SettlerItem(int n, QGraphicsItem *parent) : QGraphicsPixmapItem(parent) {
	//settler = settlerptr;
	number = n;
	setPixmap(QPixmap(":/graphics/settler.png"));
}

void SettlerItem::mousePressEvent(QGraphicsSceneMouseEvent *) {
	emit clicked(number);
}