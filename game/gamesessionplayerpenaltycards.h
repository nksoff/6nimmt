#ifndef GAMESESSIONPLAYERPENALTYCARDS_H
#define GAMESESSIONPLAYERPENALTYCARDS_H

#include "game/gamecardcollection.h"

class GameSessionPlayerPenaltyCards
{
private:
    GameCardCollection collection;
public:
    GameSessionPlayerPenaltyCards();

    void addCard(GameCard *card);
    void removeCard(GameCard *card);
};

#endif // GAMESESSIONPLAYERPENALTYCARDS_H
