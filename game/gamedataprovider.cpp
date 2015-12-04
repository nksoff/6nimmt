#include "gamedataprovider.h"

GameDataProvider::GameDataProvider()
    : _game(NULL)
{

}

std::vector<unsigned int> GameDataProvider::findGames() const {
    std::vector<unsigned int> result;
    result.push_back(10);
    result.push_back(20);
    result.push_back(4000);
    return result;
}

void GameDataProvider::setGame(Game *game) {
    _game = game;
}
