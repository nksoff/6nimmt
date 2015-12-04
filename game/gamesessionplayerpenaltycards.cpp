#include "gamesessionplayerpenaltycards.h"

GameSessionPlayerPenaltyCards::GameSessionPlayerPenaltyCards()
{

}


void GameSessionPlayerPenaltyCards::addCard(GameCard *card) {
    collection.addCard(card);
}

void GameSessionPlayerPenaltyCards::removeCard(GameCard *card) {
    collection.removeCard(card);
}
