#ifndef GAMECARDCOLLECTION_H
#define GAMECARDCOLLECTION_H

#include <vector>
#include <string.h>
#include "game/gamecard.h"

class GameCardCollection
{
private:
    std::vector<GameCard> _cards;

public:
    GameCardCollection();

    const std::vector<GameCard> &getCards() const;
    void addCard(GameCard *card);
    void removeCard(GameCard *card);

    size_t getSize() const;
};

#endif // GAMECARDCOLLECTION_H
