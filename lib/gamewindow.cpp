#include "gamewindow.h"

GameWindow::GameWindow(QWidget *parent) : QWidget(parent)
{
    QPixmap bkgnd(GameWindow::BACKGROUND_FILE);
    bkgnd = bkgnd.scaled(QSize(GameWindow::DEFAULT_WIDTH,
                               GameWindow::DEFAULT_HEIGHT),
                         Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    setPalette(palette);
    resize(GameWindow::DEFAULT_WIDTH, GameWindow::DEFAULT_HEIGHT);

    ServerLoader loader;
    gameData = loader.createGame();

    rowContainer = new RowContainer(this);
    rowContainer->move(GameWindow::ROWCONTAINER_X,
                       GameWindow::ROWCONTAINER_Y);
    rowContainer->show();
    for(size_t i = 0; i < gameData.getFieldCards().size(); i++)
    {
        Card *card = new Card(gameData.getFieldCards().at(i), this);
        rowContainer->addCard(card);
    }

    playerCardsContainer = new PlayerCardsContainer(this);
    playerCardsContainer->move(rowContainer->geometry().bottomLeft().rx(),
                               rowContainer->geometry().bottomLeft().ry() + GameWindow::DEFAULT_Y_SPACE);
    playerCardsContainer->show();

    std::vector<Card *> _playerCards;
    for(size_t i = 0; i < gameData.getPlayerCards().size(); i++)
    {
        Card *card = new Card(gameData.getPlayerCards().at(i), this);
        card->setActive();
        _playerCards.push_back(card);
    }
    playerCardsContainer->setCards(_playerCards);

    serverPoints = new PlayerPoints(this);
    serverPoints->move(rowContainer->geometry().topRight().rx() + GameWindow::DEFAULT_X_SPACE,
                       rowContainer->geometry().top());
    serverPoints->show();

    temporaryCardsContainer = new TemporaryCardsContainer(this);
    temporaryCardsContainer->move(rowContainer->geometry().topRight().rx()  + GameWindow::DEFAULT_X_SPACE,
                                  serverPoints->geometry().bottom()         + GameWindow::DEFAULT_Y_SPACE);
    temporaryCardsContainer->show();

    playerPoints = new PlayerPoints(this);
    playerPoints->move(rowContainer->geometry().topRight().rx()     + GameWindow::DEFAULT_X_SPACE,
                       temporaryCardsContainer->geometry().bottom() + GameWindow::DEFAULT_Y_SPACE);
    playerPoints->setRed();
}

GameWindow::~GameWindow()
{
    delete rowContainer;
    delete playerCardsContainer;
    delete playerPoints;
    delete serverPoints;
    delete temporaryCardsContainer;
}

void GameWindow::addPlayerPoints(short n)
{
    playerPoints->add(n);
}

void GameWindow::addServerPoints(short n)
{
    serverPoints->add(n);
}

void GameWindow::selectCard(Card *card)
{
    card->hide();
    card->setStatic();
    addPlayerPoints(rowContainer->addCard(card));
    playerCardsContainer->remove(card);

    auto engine = std::default_random_engine{};
    std::shuffle(std::begin(gameData.getServerCards()), std::end(gameData.getServerCards()), engine);

    Card *serverCard = new Card(gameData.getServerCards().at(gameData.getServerCards().size() - 1), this);
    gameData.getServerCards().pop_back();
    addServerPoints(rowContainer->addCard(serverCard));

    if(playerCardsContainer->countLeft() == 0)
    {
        // end of the game
        bool won = playerPoints->getPoints() <= serverPoints->getPoints();
        QMessageBox::information(
                    this,
                    QApplication::applicationDisplayName(),
                    (won ? GameWindow::GAME_END_WON : GameWindow::GAME_END_LOST)
                    );
        close();
    }
}
