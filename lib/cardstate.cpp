#include "cardstate.h"

CardState::CardState(Card *card) : parent(card)
{
}

Card *CardState::getParent()
{
    return parent;
}

CardState::~CardState()
{
}

void CardState::enterEvent(QEvent *)
{
}

void CardState::leaveEvent(QEvent *)
{
}

void CardState::mouseReleaseEvent(QMouseEvent *)
{
}

