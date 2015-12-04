#include "gameplayer.h"

GamePlayer::GamePlayer(unsigned int id, QString name)
    : _id(id), _name(name)
{
}

unsigned int GamePlayer::getId() const {
    return _id;
}

QString GamePlayer::getName() const {
    return _name;
}

void GamePlayer::setName(QString name) {
    _name = name;
}

QDebug operator <<(QDebug debug, const GamePlayer &player) {
    QDebugStateSaver saver(debug);
    debug.nospace()
            << "GamePlayer [" << player.getId()
            << ", "
            << player.getName() <<"]";
    return debug;
}
