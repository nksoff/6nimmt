#ifndef CARD_H
#define CARD_H

#include "lib/main.h"

class GameWindow;
#include "lib/windows/gamewindow/cardstate/cardstate.h"
#include "lib/windows/gamewindow/cardstate/cardstateactive.h"
#include "lib/windows/gamewindow/cardstate/cardstatestatic.h"

#include <QLabel>

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
