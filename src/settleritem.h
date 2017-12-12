#ifndef SETTLERITEM_H
#define SETTLERITEM_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>
#include <QObject>

#include "settler.h"

class SettlerItem : public QObject, public QGraphicsPixmapItem {
	Q_OBJECT
public:
	//SettlerItem(Settler *settlerptr, QGraphicsItem *parent = 0);
	SettlerItem(QGraphicsItem *parent = 0);
	//Settler *getSettler() {return settler;};
	void mousePressEvent(QGraphicsSceneMouseEvent *event);

private:
	//Settler *settler;

signals:
	void clicked();
};

#endif