#ifndef GAMESESSIONPLAYERCARDS_H
#define GAMESESSIONPLAYERCARDS_H

#include "game/gamecardcollection.h"

class GameSessionPlayerCards
{
private:
    GameCardCollection collection;
public:
    GameSessionPlayerCards();

    void addCard(GameCard *card);
    void removeCard(GameCard *card);
};

#endif // GAMESESSIONPLAYERCARDS_H
