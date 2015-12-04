#ifndef GAMESESSION_H
#define GAMESESSION_H

class Game;

class GameSession
{
private:
    Game *_game;
public:
    GameSession(Game *);
};

#endif // GAMESESSION_H
