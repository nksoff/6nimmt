#include "gamecard.h"

GameCard::GameCard(unsigned short number) : _number(number)
{
}

unsigned short GameCard::getNumber() const
{
    return _number;
}

short GameCard::getPenaltyPoints() const
{
    // TODO
    return 0;
}

