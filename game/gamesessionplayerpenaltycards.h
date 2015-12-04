#ifndef GAMESESSIONPLAYERPENALTYCARDS_H
#define GAMESESSIONPLAYERPENALTYCARDS_H

#include "game/gamecardcollection.h"

class GameSessionPlayerPenaltyCards
{
private:
    GameCardCollection collection;
public:
    GameSessionPlayerPenaltyCards();

    void add(GameCard *card);
    void remove(GameCard *card);
};

#endif // GAMESESSIONPLAYERPENALTYCARDS_H
