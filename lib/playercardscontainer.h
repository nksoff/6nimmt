#ifndef PLAYERCARDSCONTAINER_H
#define PLAYERCARDSCONTAINER_H

#include "card.h"

#include <QWidget>
#include <QRect>
#include <QPainter>

#include <vector>

class PlayerCardsContainer : public QWidget
{
    Q_OBJECT

    const int DEFAULT_WIDTH = 1160;
    const int DEFAULT_HEIGHT = 160;
    const float ROUND_CORNER_RADIUS = 10.0;
    const QColor BACKGROUND_COLOR = QColor(255, 255, 255, 64);
    const int DEFAULT_SPACE_X = 20;
    const int DEFAULT_SPACE_Y = 20;

    std::vector<Card *> cards;

    void paintEvent(QPaintEvent *);

public:
    explicit PlayerCardsContainer(QWidget *parent = 0);
    ~PlayerCardsContainer();

    void setCards(std::vector<Card *>);
    void remove(Card *);
    size_t countLeft() const;

};

#endif // PLAYERCARDSCONTAINER_H
