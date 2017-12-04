#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("Asd");
    w.show();

    Game *game = new Game();
    Map gameMap = game->getMap();

    Terrain location = *(gameMap.get_map())[19][19];
    
    game->setBuildings();

    std::vector<Building*> buildings = game->getBuildings();
    for (std::vector<Building*>:: iterator it = buildings.begin();it != buildings.end(); it++){
        std::cout << **it << std::endl;

    }


    return a.exec();
}
