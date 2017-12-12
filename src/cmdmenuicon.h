#ifndef CMDMENUICON_H
#define CMDMENUICON_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>
#include <QObject>

class cmdMenuIcon : public QObject, public QGraphicsPixmapItem {
	Q_OBJECT
public:
	cmdMenuIcon(QGraphicsItem *parent = 0);
private:

signals:
	
};

#endif