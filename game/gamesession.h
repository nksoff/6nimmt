#ifndef GAMESESSION_H
#define GAMESESSION_H

#include <vector>
#include "game/gamesessionstatus.h"
#include "game/gamesessionplayercards.h"
#include "game/gamesessionplayerpenaltycards.h"
#include "game/gamesessionturn.h"
#include "game/gamesessionrow.h"
#include "game/gamesessionresult.h"
#include "game/gamesessionrender.h"

class Game;

class GameSession
{
private:
    Game *_game;
    GameSessionStatus status;
    GameSessionPlayerCards cards;
    GameSessionPlayerPenaltyCards penaltyCards;
    std::vector<GameSessionTurn> turns;
    std::vector<GameSessionRow> rows;

public:
    GameSession(Game *);

    void setStatus(GameSessionStatus);
    void start();
    void finish();

    void addTurn(GameSessionTurn *);
    const std::vector<GameSessionTurn> &getTurns() const;

    const GameSessionPlayerCards &getPlayerCards() const;
    void setPlayerCards(GameSessionPlayerCards *);
    const GameSessionPlayerPenaltyCards &getPlayerPenaltyCards() const;

    const std::vector<GameSessionRow> &getRows() const;

    const GameSessionResult getResult() const;

    GameSessionRender &getRender() const;
};

#endif // GAMESESSION_H
