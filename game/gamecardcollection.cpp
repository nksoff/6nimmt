#include "gamecardcollection.h"

GameCardCollection::GameCardCollection()
{

}

const std::vector<GameCard> &GameCardCollection::getCards() const {
    return _cards;
}

void GameCardCollection::addCard(GameCard *card) {
    _cards.push_back(*card);
}

void GameCardCollection::removeCard(GameCard *) {
    // TODO:
}

size_t GameCardCollection::getSize() const {
    return _cards.size();
}

