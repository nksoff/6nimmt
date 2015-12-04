#include "gamesessionplayercards.h"

GameSessionPlayerCards::GameSessionPlayerCards()
{

}

void GameSessionPlayerCards::addCard(GameCard *card) {
    collection.addCard(card);
}

void GameSessionPlayerCards::removeCard(GameCard *card) {
    collection.removeCard(card);
}
