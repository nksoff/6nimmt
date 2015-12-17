#ifndef CARD_H
#define CARD_H

class GameWindow;
#include "cardstate.h"
#include "cardstateactive.h"
#include "cardstatestatic.h"

#include <QWidget>
#include <QLabel>
#include <QDebug>

#include <string>

class Card : public QWidget
{
    Q_OBJECT

    const std::string IMG_PATH = ":/cards/";
    const std::string IMG_EXT = ".png";
    const int DEFAULT_HEIGHT = 110;

    unsigned short number;

    QLabel *label;

    GameWindow *gameWindow;
    CardState *state;

    void enterEvent(QEvent *);
    void leaveEvent(QEvent *);
    void mouseReleaseEvent(QMouseEvent *);

public:
    static const short MAX_NUMBER = 104;

    explicit Card(unsigned short, GameWindow *, QWidget *parent = 0);

    ~Card();

    void setActive();
    void setStatic();

    unsigned short getNumber() const;
    short getPoints() const;

    GameWindow *getGameWindow();
};

#endif // CARD_H
