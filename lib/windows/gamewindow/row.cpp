#include "row.h"

Row::Row(QWidget *parent) : QWidget(parent)
{
    resize(Row::DEFAULT_WIDTH, Row::DEFAULT_HEIGHT);
}

short Row::addCard(Card *card)
{
    short points = 0;
    if(cards.size() > 0)
    {
        if((cards.size() == Row::MAX_LENGTH - 1 && card->getNumber() > getLastCard()->getNumber()) ||
                (card->getNumber() < getLastCard()->getNumber()))
        {
            points = getPoints();
            for(size_t i = cards.size() - 1; i >= 0; i--)
            {
                delete cards.at(i);
                cards.pop_back();
            }
        }
    }

    card->setParent(this);
    card->move(cards.size() * (card->geometry().width() + Row::DEFAULT_SPACE_X), Row::DEFAULT_SPACE_Y);
    card->show();
    cards.push_back(card);
    return points;
}

size_t Row::count() const
{
    return cards.size();
}

short Row::getPoints() const
{
    short points = 0;
    for(size_t i = 0; i < cards.size(); i++)
    {
        points += cards.at(i)->getPoints();
    }
    return points;
}

const Card *Row::getLastCard()
{
    if(cards.size() == 0)
    {
        return NULL;
    }
    return cards.at(cards.size() - 1);
}

Row::~Row()
{
    for(size_t i = 0; i < cards.size(); i++)
    {
        if(cards.at(i) != NULL) delete cards.at(i);
    }
}
