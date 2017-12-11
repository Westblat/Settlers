#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QtWidgets>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <QLabel>
#include <QString>
#include <QGraphicsPixmapItem>
#include <QMouseEvent>

#include "game.h"
#include "map.h"
#include "terrainitem.h"
#include "buildingitem.h"
#include "settleritem.h"
#include "buildmenuicon.h"
#include "cmdmenuicon.h"

/*
Imagefiles taken from kenney.nl!
*/

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

	QGraphicsScene *scene;
	QGraphicsView *view;
	QGraphicsScene *buildscene;
	QGraphicsView *buildview;
	QGraphicsScene *commandscene;
	QGraphicsView *commandview;
	QGraphicsScene *resscene;
	QGraphicsView *resview;

	bool buildmode;
	int newBuildingType = -1;

private:
	Game game; // creates the game
	Map map = game.getMap();
	int width = map.get_width();
	int height = map.get_height();

	std::vector<std::vector<Terrain*>> terrain_map = map.get_map();

	std::vector<Building*> buildings;
	std::vector<BuildingItem*> buildingitems;
    std::vector<Settler*> settlers;
    std::vector<SettlerItem*> settleritems;

	int tilesize = 64; // images used are 64x64 pixels
	int refresh_time = 1000; // milliseconds, after how much time locations update on screen, 40 ms = roughly 25 fps

	//int x; //used for debugging timer

	QPushButton *menu_button;

public slots:
	void ShowMainMenu();
	void refresh();
	void moveSettlers();
	void refreshBuildings();

	void selectBuildingLocation(int type);
	void getSiteLocation(Terrain *terrain);
	void cancelBuild();
	void giveCommand();

	void randomLocation(); //debug function, gives settlers and buildings random new locations
	void removeHP(); //debug, destroys buildings
};

#endif