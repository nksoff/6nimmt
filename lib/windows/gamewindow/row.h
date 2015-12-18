#ifndef ROW_H
#define ROW_H

#include "lib/main.h"

#include "lib/windows/gamewindow/card.h"

#include <QWidget>

class Row : public QWidget
{
    Q_OBJECT

    const int DEFAULT_WIDTH = 600;
    const int DEFAULT_HEIGHT = 120;
    const size_t MAX_LENGTH = 6;
    const int DEFAULT_SPACE_X = 10;
    const int DEFAULT_SPACE_Y = 0;

    std::vector<Card *> cards;

public:
    explicit Row(QWidget *parent = 0);
    ~Row();

    short addCard(Card *);
    size_t count() const;
    const Card *getLastCard();
    short getPoints() const;

};

#endif // ROW_H
