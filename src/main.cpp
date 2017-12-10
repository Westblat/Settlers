#include "mainwindow.h"
#include <QApplication>
#include "gamewindow.h"

Window * w;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    
    //Main Menu when opening program
    w = new Window();
    w->show();
    
/* // THIS HAS MOVED TO GAMEWINDOW.CPP AND .H

    //Game *game = new Game();
    Map gameMap = game->getMap();

    Terrain location = *(gameMap.get_map())[19][19];
    
    game->setBuildings();

    std::vector<Building*> buildings = game->getBuildings();
    for (std::vector<Building*>:: iterator it = buildings.begin();it != buildings.end(); it++){
        std::cout << **it << std::endl;

    }
*/

    return a.exec();
}
