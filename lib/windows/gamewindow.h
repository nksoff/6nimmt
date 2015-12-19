#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include "lib/main.h"

class Card;
class PlayerCardsContainer;
class RowContainer;
#include "lib/windows/gamewindow/card.h"
#include "lib/server/serverloader.h"
#include "lib/windows/gamewindow/playercardscontainer.h"
#include "lib/windows/gamewindow/playerpoints.h"
#include "lib/windows/gamewindow/temporarycardscontainer.h"
#include "lib/windows/gamewindow/rowcontainer.h"

#include <QWidget>
#include <QImage>
#include <QMessageBox>

#include <algorithm>
#include <random>

class GameWindow : public QWidget
{
    Q_OBJECT

    const QString BACKGROUND_FILE = ":/background.jpg";
    const int DEFAULT_WIDTH = 1200;
    const int DEFAULT_HEIGHT = 650;

    const int ROWCONTAINER_X = 20;
    const int ROWCONTAINER_Y = 15;

    const int DEFAULT_X_SPACE = 10;
    const int DEFAULT_Y_SPACE = 20;

    const QString GAME_END_WON = "You won!!! Congratulations!";
    const QString GAME_END_LOST = "You lose!";

    GameData gameData;

    RowContainer *rowContainer;
    PlayerCardsContainer *playerCardsContainer;
    TemporaryCardsContainer *temporaryCardsContainer;
    PlayerPoints *playerPoints;
    PlayerPoints *serverPoints;

    virtual void closeEvent(QCloseEvent *);

public:
    explicit GameWindow(QWidget *parent = 0);
    ~GameWindow();

    void addPlayerPoints(short);
    void addServerPoints(short);
    void selectPlayerCard(Card *);
    void selectServerCard(Card *);
};

#endif // GAMEWINDOW_H
