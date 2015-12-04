#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QDebug>

#include "game/gameplayer.h"
#include "game/game.h"
#include "game/gamedataprovider.h"

int main()
{
    GamePlayer *player = new GamePlayer(100, "Nikita");
    qDebug() << (*player);

    GameDataProvider *dataProvider = new GameDataProvider();

    std::vector<unsigned int> gameIds = dataProvider->findGames();
    qDebug() << "Searching for games...";
    for(size_t i = 0; i < gameIds.size(); i++) {
        qDebug() << " - id: " << gameIds[i];
    }

    qDebug() << "Will use game ##" << gameIds[gameIds.size() - 1];

    Game *game = new Game(gameIds[gameIds.size() - 1]);

    dataProvider->setGame(game);

    // further code is executed by DataProvider

    qDebug() << *game;

    game->addPlayer(player);
    game->setCurrentPlayer(player);

    GamePlayer *player1 = new GamePlayer(101, "Player 101");
    GamePlayer *player2 = new GamePlayer(102 , "Player 102");

    game->addPlayer(player1);
    game->addPlayer(player2);

    qDebug() << *game;

    game->start();

    game->finish();

    delete player1;
    delete player2;

    // end code

    delete game;
    delete dataProvider;
    delete player;

    return 0;
}
