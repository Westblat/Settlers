#include "mainwindow.h"
#include <QApplication>
#include "game.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("Asd");
    w.show();
    Game *game = new Game();
    Map gameMap = game->getMap();

    Terrain location = *(gameMap.get_map())[19][19];
    
    std::cout << location << std::endl;


    return a.exec();
}
