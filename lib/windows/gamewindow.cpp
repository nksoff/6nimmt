#include "gamewindow.h"

GameWindow::GameWindow(QWidget *parent) : QWidget(parent)
{
    QSize size(GameWindow::DEFAULT_WIDTH, GameWindow::DEFAULT_HEIGHT);
    QPixmap bkgnd(GameWindow::BACKGROUND_FILE);
    bkgnd = bkgnd.scaled(size,
                         Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    setPalette(palette);
    setFixedSize(size);

    ServerLoader loader;
    gameData = loader.createGame();

    if(gameData.isError()) {
        throwError("Couldn't load server data. Sorry :(", false);
        close();
        return;
    }

    rowContainer = new RowContainer(this);
    checkNullPointer(rowContainer);
    rowContainer->move(GameWindow::ROWCONTAINER_X,
                       GameWindow::ROWCONTAINER_Y);
    rowContainer->show();
    for(size_t i = 0; i < gameData.getFieldCards().size(); i++)
    {
        Card *card = new Card(gameData.getFieldCards().at(i), this);
        checkNullPointer(card, [=]() {
            delete rowContainer;
        });
        rowContainer->addCard(card);
    }

    playerCardsContainer = new PlayerCardsContainer(this);
    checkNullPointer(playerCardsContainer, [=]() {
        delete rowContainer;
    });
    playerCardsContainer->move(rowContainer->geometry().bottomLeft().rx(),
                               rowContainer->geometry().bottomLeft().ry() + GameWindow::DEFAULT_Y_SPACE);
    playerCardsContainer->show();

    std::vector<Card *> _playerCards;
    for(size_t i = 0; i < gameData.getPlayerCards().size(); i++)
    {
        Card *card = new Card(gameData.getPlayerCards().at(i), this);
        checkNullPointer(playerCardsContainer, [=]() {
            delete rowContainer;
            for(size_t i = 0; i < _playerCards.size(); i++) {
                delete _playerCards.at(i);
            }
        });
        card->setActive();
        _playerCards.push_back(card);
    }
    playerCardsContainer->setCards(_playerCards);

    serverPoints = new PlayerPoints(this);
    checkNullPointer(serverPoints, [=]() {
        delete rowContainer;
        delete playerCardsContainer;
    });
    serverPoints->move(rowContainer->geometry().topRight().rx() + GameWindow::DEFAULT_X_SPACE,
                       rowContainer->geometry().top());
    serverPoints->show();

    temporaryCardsContainer = new TemporaryCardsContainer(this);
    checkNullPointer(temporaryCardsContainer, [=]() {
        delete rowContainer;
        delete playerCardsContainer;
        delete serverPoints;
    });
    temporaryCardsContainer->move(rowContainer->geometry().topRight().rx()  + GameWindow::DEFAULT_X_SPACE,
                                  serverPoints->geometry().bottom()         + GameWindow::DEFAULT_Y_SPACE);
    temporaryCardsContainer->show();

    playerPoints = new PlayerPoints(this);
    checkNullPointer(playerPoints, [=]() {
        delete rowContainer;
        delete playerCardsContainer;
        delete serverPoints;
        delete temporaryCardsContainer;
    });
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
    checkNullPointer(serverCard);
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

void GameWindow::closeEvent(QCloseEvent *event) {
    if(playerCardsContainer->countLeft() != 0) {
        QMessageBox::StandardButton res = QMessageBox::question(this,
                                                                QApplication::applicationDisplayName(),
                                                                tr("The game is not finished yet. Are you sure you want to close the window?"),
                                                                QMessageBox::Cancel | QMessageBox::Yes,
                                                                QMessageBox::Cancel);
        if(res == QMessageBox::Yes) {
            event->accept();
        }
        else
        {
            event->ignore();
        }
    }
}
