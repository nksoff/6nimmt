#ifndef GAMEDATAPROVIDER_H
#define GAMEDATAPROVIDER_H

#include <vector>
#include "game/game.h"

class GameDataProvider
{
private:
    Game *_game;

public:
    GameDataProvider();

    std::vector<unsigned int> findGames() const;
    void setGame(Game *game);
};

#endif // GAMEDATAPROVIDER_H
