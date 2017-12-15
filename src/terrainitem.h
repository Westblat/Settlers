#ifndef TERRAINITEM_H
#define TERRAINITEM_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>
#include <QObject>

class TerrainItem : public QObject, public QGraphicsPixmapItem {
	Q_OBJECT
public:
	TerrainItem(int type, int coord_x, int coord_y, QGraphicsItem *parent = 0);
	void mousePressEvent(QGraphicsSceneMouseEvent *event);

private:
	int x;
	int y;

signals:
	void clicked(int x, int y);
	void rightclicked(int x, int y);
};

#endif