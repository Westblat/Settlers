#include "mainwindow.h"
#include <QApplication>
#include <thread>
#include <chrono>

int main(/*int argc, char *argv[]*/)
{
    /*QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("Asd");
    w.show();*/

    Game *game = new Game();
    Map gameMap = game->getMap();
    game->setBuildings();
    Map *map = new Map(21,21);
    map->setMap();

    Coordinates *point1 = new Coordinates(0,0);
    Coordinates *point2 = new Coordinates(2,2);

    std::stack<std::pair<int,int> > path = map->solvePath(point1,point2);
    /*Terrain location = *(gameMap.get_map())[19][19];
    
    

    std::vector<Building*> buildings = game->getBuildings();
    for (std::vector<Building*>:: iterator it = buildings.begin();it != buildings.end(); it++){
        std::cout << **it << std::endl;

    }*/
    std::vector<Settler*> settlers = game->getSettlers();
    settlers[0]->setPath(path);
    while(1){
        game->simulate();
        std::this_thread::sleep_for (std::chrono::seconds(1));
    }


    return 1;//a.exec();
}
