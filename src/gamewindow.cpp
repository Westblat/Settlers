#include "gamewindow.h"
 
GameWindow::GameWindow(QWidget *parent) : QWidget(parent, Qt::Window) {

	setWindowTitle("The Settlers");
    setFixedSize(1000, 800);
    this->move(50,50);
 
    QGridLayout *grid = new QGridLayout;
    setLayout(grid);
 
    // button that shows the main menu
    menu_button = new QPushButton("Main Menu");
    grid->addWidget(menu_button, 0, 0);
    connect(menu_button, SIGNAL (clicked()), this , SLOT (ShowMainMenu()));
 
    // GAMEMAP
    // creates the scene for viewing game map
    scene = new QGraphicsScene(this);
    view = new QGraphicsView(scene);
    view->show();
    grid->addWidget(view, 2, 1, 10, 10);
 
    // BUILDMENU
    // scene for viewing build menu/buildingselection
    buildmode = false;
    buildscene = new QGraphicsScene(this);
    buildview = new QGraphicsView(buildscene);
    buildview->show();
    buildview->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    grid->addWidget(buildview, 3, 0, 9, 1);
    QLabel *buildlabel = new QLabel(this); // text above the buildingselection
    buildlabel->setText(QString("Buildings"));
    buildlabel->show();
    grid->addWidget(buildlabel, 2, 0);
    for (int i = 1; i < 10; i++) {
      BuildmenuIcon *icon = new BuildmenuIcon(i);
      icon->setPos(0, tilesize*(i-1));
      buildscene->addItem(icon);
      connect(icon, SIGNAL(clicked(int)), this, SLOT(selectBuildingType(int)));
    }
 
    // COMMANDMENU
    // scene for viewing commands
    commandmode = false;
    commandscene = new QGraphicsScene(this);
    commandview = new QGraphicsView(commandscene);
    commandview->show();
    grid->addWidget(commandview, 1, 4, 1, 9);
    QLabel *cmdlabel = new QLabel(this);
    cmdlabel->setText(QString("Commands"));
    cmdlabel->show();
    grid->addWidget(cmdlabel, 1, 3);
    for (int i = 0; i < 9; i++) {
      cmdMenuIcon *icon = new cmdMenuIcon(i);
      icon->setPos(tilesize*i, 0);
      commandscene->addItem(icon);
      connect(icon, SIGNAL(clicked(int)), this, SLOT(selectCommand(int)));
    }
 
    // the buildings the player starts with
    //game.setBuildings();
    game.test();
    buildings = game.getBuildings();
    settlers = game.getSettlers();

    draw_terrain(scene); //draws the terrain on the map
    draw_buildings(scene);
    draw_settlers(scene);
 
    //add a timer
    //refresh the game one step forward
    //refresh the scene in regards to settlers and buildings
    QTimer *timer = new QTimer();
    connect(timer, SIGNAL (timeout()), this, SLOT (refresh()));
    connect(timer, SIGNAL (timeout()), this, SLOT (moveSettlers()));
    connect(timer, SIGNAL (timeout()), this, SLOT (refreshBuildings()));
    timer->start(refresh_time);

}

void GameWindow::selectBuildingType(int type) {
  buildmode = true;
  newBuildingType = type;
}
 
void GameWindow::getSiteLocation(int x, int y) {
    // Builds a new building in the given location, if terrain allows

    buildmode = false;
    std::vector<int> av_buildings = terrain_map[x][y]->availableBuildings();

    for(std::vector<int>::iterator type = av_buildings.begin(); type != av_buildings.end(); type++){
        if(*type == newBuildingType){
            std::cout<<*type;
            buildmode = true;
        }
    }

    if (buildmode == true) {

		BuildingItem *buildingitem;

		game.addBuilding(newBuildingType, terrain_map[x][y]->getLocation(), false);

        buildings = game.getBuildings();

		buildingitem = new BuildingItem(buildings.back()->getType(), buildings.back()->getReadiness(), buildings.back()->getHp());

		buildingitem->setPos(tilesize*buildings.back()->getLocation()->getX(), tilesize*buildings.back()->getLocation()->getY());
		if (newBuildingType >= 7) {
			buildingitem->setZValue(0);
		}

		buildingitems.push_back(buildingitem);
		scene->addItem(buildingitem);

		buildmode = false;
		newBuildingType = -1;
	}
}

void GameWindow::cancel() {
  buildmode = false; // buildmode can be cancelled with rightclick
  commandmode = false; // commandmode can also be cancelled
}
 
void GameWindow::giveCommand(int n) {
  commandmode = true;
  selectedSettler = n;
}
 
void GameWindow::selectCommand(int cmdtype) {
	if (commandmode == true) {
		settlers[selectedSettler]->setTask(cmdtype);

		commandmode = false;
		selectedSettler = -1;
	}
}

void GameWindow::ShowMainMenu() {
    this->hide();
}
 
void GameWindow::draw_terrain(QGraphicsScene *scene) {
  //draws the terrain on the map
 
  int x = 0;
  int y = 0;
  for (int j = 0; j < width; j++) {
    x = 0;
    for (int i = 0; i < height; i++) {
		//draw a TerrainItem
		int type = terrain_map[i][j]->getType();
		TerrainItem *titem = new TerrainItem(type, i, j);
		titem->setPos(x,y);
		scene->addItem(titem);
		x += tilesize;
		connect(titem, SIGNAL(clicked(int, int)), this, SLOT(getSiteLocation(int, int)));
		connect(titem, SIGNAL(rightclicked(int, int)), this, SLOT(cancel()));
    }
    //next row
    y += tilesize;
  }
}
 
void GameWindow::draw_buildings(QGraphicsScene *scene) {
  //draws the buildings (and trees) on the map
 
    for (auto building : buildings) {
      BuildingItem *buildingitem = new BuildingItem(building->getType(), building->getReadiness(), building->getHp());
      buildingitem->setPos(tilesize*building->getLocation()->getX(), tilesize*building->getLocation()->getY());
      buildingitems.push_back(buildingitem);
      scene->addItem(buildingitem);
    }
 
}

void GameWindow::draw_settlers(QGraphicsScene *scene) {
  //draws settlers on the map

  int i = 0;
  for (auto settler : settlers) {
    //SettlerItem *settleritem = new SettlerItem(settler);
    SettlerItem *settleritem = new SettlerItem(i);
    settleritem->setPos(tilesize*settler->getLocation()->getX(), tilesize*settler->getLocation()->getY());
    settleritems.push_back(settleritem);
    settleritem->setZValue(1);
    scene->addItem(settleritem);
    connect(settleritem, SIGNAL(clicked(int)), this, SLOT(giveCommand(int)));
    i++;
  }
}
 
void GameWindow::moveSettlers() {
  // Refreshes the location of settlers

  for (unsigned int i = 0; i < settlers.size(); i++) {
    int x = tilesize*settlers[i]->getLocation()->getX();
    int y = tilesize*settlers[i]->getLocation()->getY();
    settleritems[i]->setPos(x, y);
  }
}
 
void GameWindow::refreshBuildings() {
  // check readiness and health of buildings, update from constructionsite to complete building

  for (unsigned int i = 0; i < buildings.size(); i++) {
    bool ready = buildings[i]->getReadiness();
    if (buildingitems[i]->getReadiness() != ready) {
      //remove old image and replace with new
      scene->removeItem(buildingitems[i]);
      BuildingItem *buildingitem = new BuildingItem(buildings[i]->getType(), buildings[i]->getReadiness(), buildings[i]->getHp());
      buildingitem->setPos(tilesize*buildings[i]->getLocation()->getX(), tilesize*buildings[i]->getLocation()->getY());
      //buildingitem->setZValue(1);
      buildingitems[i] = buildingitem;
      scene->addItem(buildingitem);
    }
  }
}

void GameWindow::refresh() {
	//std::cout << "Refresh" << std::endl;

	game.simulate(); // drives game one step forward

	// REFRESH BUILDINGS
	// if amount of buildings changes, redraw the buildings
	std::vector<Building*> newbuildings = game.getBuildings();
	if (buildings.size() != newbuildings.size()) {
		buildings.clear();
		buildings = newbuildings;
		for (auto i : buildingitems) {
			scene->removeItem(i);
		}
		buildingitems.clear();
		draw_buildings(scene);
	}

	// REFRESH SETTLERS
	// if amount of settlers changes, redraw settlers
	std::vector<Settler*> newsettlers = game.getSettlers();
	if (settlers.size() != newsettlers.size()) {
		settlers.clear();
		settlers = newsettlers;
		for (auto i : settleritems) {
			scene->removeItem(i);
		}
		settleritems.clear();
		draw_settlers(scene);
	}
}
