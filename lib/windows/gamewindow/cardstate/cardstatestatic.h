#ifndef CARDSTATESTATIC_H
#define CARDSTATESTATIC_H

#include "lib/main.h"

#include "lib/windows/gamewindow/cardstate/cardstate.h"
#include "lib/windows/gamewindow/card.h"

class CardStateStatic : public CardState
{
public:
    CardStateStatic(Card *);

    virtual bool isActive() const;
};

#endif // CARDSTATESTATIC_H
