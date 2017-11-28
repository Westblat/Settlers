#include "game.h"

Game::Game() {
    map = new Map(11,11);
}

Game::~Game() {
    delete map;
}
