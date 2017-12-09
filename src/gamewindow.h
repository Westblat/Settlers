#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QtWidgets>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>

#include "game.h"
#include "map.h"

class Map;

//window showing the actual game
//opens when new game is started from main menu
class GameWindow : public QWidget {
	Q_OBJECT

public:
	explicit GameWindow(QWidget *parent = 0);
	void draw_terrain(QGraphicsScene* scene);
	void draw_buildings(QGraphicsScene* scene);
	void draw_settlers(QGraphicsScene* scene);


private:
	Game game; // creates the game
	Map map = game.getMap();
	int tilesize = 64; // images used are 64x64 pixels

	QPushButton *menu_button;

public slots:
	void ShowMainMenu();
};

#endif