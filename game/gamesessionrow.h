#ifndef GAMESESSIONROW_H
#define GAMESESSIONROW_H

#include "game/gamecard.h"
#include "game/gamecardcollection.h"

class GameSessionRow
{
private:
    GameCardCollection collection;
public:
    GameSessionRow();

    void addCard(GameCard *card);
    void removeCard(GameCard *card);
};

#endif // GAMESESSIONROW_H
