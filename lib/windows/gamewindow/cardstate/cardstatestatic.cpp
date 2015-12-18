#include "cardstatestatic.h"

CardStateStatic::CardStateStatic(Card *card) : CardState(card)
{
}

bool CardStateStatic::isActive() const
{
    return false;
}
