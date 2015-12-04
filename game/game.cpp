#include "game.h"
#include "game/gamesession.h"

Game::Game(unsigned int id, GameStatus status)
    : _id(id), _status(status)
{
}

Game::~Game() {
}

void Game::setStatus(GameStatus status) {
    _status = status;
}

void Game::start() {
    setStatus(GameStatus::STARTED);

    GameSession *session = new GameSession(this);
    addSession(session);
}

void Game::finish() {
    setStatus(GameStatus::STARTED);
}

unsigned int Game::getId() const {
    return _id;
}

void Game::addPlayer(GamePlayer *player) {
    _players.push_back(*player);
}

void Game::setCurrentPlayer(GamePlayer *player) {
    bool found = false;
    for(size_t i = 0; i < _players.size(); i++) {
        if(_players[i].getId() == player->getId()) {
            found = true;
            break;
        }
    }
    if(!found) {
        _players.push_back(*player);
    }

    _curPlayer = player;
}

const std::vector<GamePlayer> &Game::getPlayers() const {
    return _players;
}

const std::vector<GameSession> &Game::getSessions() const {
    return _sessions;
}

const GameSession *Game::getCurrentSession() const {
    if(_sessions.size() > 0) {
        return &_sessions[_sessions.size() - 1];
    }
    return NULL;
}

void Game::addSession(GameSession *game) {
    _sessions.push_back(*game);
}

QDebug operator <<(QDebug debug, const Game &game) {
    debug << "Game [" << game.getId() << "]" << endl;
    debug << "  Players [";

    for(size_t i = 0 ; i < game.getPlayers().size(); i++) {
        debug << game.getPlayers()[i];
        if(i != game.getPlayers().size() - 1) {
            debug << ", ";
        }
    }
    debug << "]" << endl;

    debug << "  Sessions (" << game.getSessions().size() << ")";

    return debug;
}
