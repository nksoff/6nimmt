#ifndef CARDSTATESTATIC_H
#define CARDSTATESTATIC_H

#include "cardstate.h"
#include "card.h"

class CardStateStatic : public CardState
{
public:
    CardStateStatic(Card *);

    virtual bool isActive() const;
};

#endif // CARDSTATESTATIC_H
