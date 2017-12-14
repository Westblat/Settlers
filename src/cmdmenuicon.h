#ifndef CMDMENUICON_H
#define CMDMENUICON_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>
#include <QObject>

class cmdMenuIcon : public QObject, public QGraphicsPixmapItem {
	Q_OBJECT
public:
	cmdMenuIcon(int type, QGraphicsItem *parent = 0);
	void mousePressEvent(QGraphicsSceneMouseEvent *event);
private:
	int cmdtype;

signals:
	void clicked(int cmdtype);
};

#endif