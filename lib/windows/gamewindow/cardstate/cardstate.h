#ifndef CARDSTATE_H
#define CARDSTATE_H

#include "lib/main.h"

class Card;

#include <QEvent>
#include <QMouseEvent>

class CardState
{
private:
    Card *parent;

protected:
    Card *getParent();

public:
    CardState(Card *);
    virtual ~CardState();

    virtual void enterEvent(QEvent *);
    virtual void leaveEvent(QEvent *);
    virtual void mouseReleaseEvent(QMouseEvent *);

    virtual bool isActive() const = 0;
};

#endif // CARDSTATE_H
