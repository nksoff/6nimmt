#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

class Card;
class PlayerCardsContainer;
class RowContainer;
#include "card.h"
#include "serverloader.h"
#include "playercardscontainer.h"
#include "playerpoints.h"
#include "temporarycardscontainer.h"
#include "rowcontainer.h"

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
    const QString GAME_END_LOST = "You lost!";

    GameData gameData;

    RowContainer *rowContainer;
    PlayerCardsContainer *playerCardsContainer;
    TemporaryCardsContainer *temporaryCardsContainer;
    PlayerPoints *playerPoints;
    PlayerPoints *serverPoints;

public:
    explicit GameWindow(QWidget *parent = 0);
    ~GameWindow();

    void addPlayerPoints(short);
    void addServerPoints(short);
    void selectCard(Card *);
};

#endif // GAMEWINDOW_H
