#ifndef GAMESESSIONTURN_H
#define GAMESESSIONTURN_H

#include <map>
#include "game/gameplayer.h"
#include "game/gamecard.h"

class GameSessionTurn
{
private:
    std::map<GamePlayer, GameCard> _data;
public:
    GameSessionTurn();
};

#endif // GAMESESSIONTURN_H
