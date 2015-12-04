#include "gamesessionrow.h"

GameSessionRow::GameSessionRow()
{

}

void GameSessionRow::addCard(GameCard *card) {
    collection.addCard(card);
}

void GameSessionRow::removeCard(GameCard *card) {
    collection.removeCard(card);
}
