#ifndef GAME_H
#define GAME_H

#include <vector>
#include "game/gamesession.h"
#include "game/gamestatus.h"
#include "game/gameplayer.h"

class Game
{
private:
    unsigned int _id;
    std::vector<GameSession> _sessions;
    GameStatus _status;
    std::vector<GamePlayer> _players;
    GamePlayer *_curPlayer;
public:
    Game(unsigned int id, GameStatus status = GameStatus::NOT_STARTED);
    ~Game();

    void setStatus(GameStatus status);
    void start();
    void finish();

    void addPlayer(GamePlayer *);
    void setCurrentPlayer(GamePlayer *);
    const std::vector<GamePlayer> &getPlayers() const;
    GamePlayer *getCurrentPlayer() const;

    const std::vector<GameSession> &getSessions() const;
    const GameSession *getCurrentSession() const;
    void addSession(GameSession *game);

    unsigned int getId() const;

    friend QDebug operator <<(QDebug, const Game &);
};

#endif // GAME_H
