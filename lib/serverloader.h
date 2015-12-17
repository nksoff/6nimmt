#ifndef SERVERLOADER_H
#define SERVERLOADER_H

#include "gamedata.h"

#include <QDebug>

#include <boost/asio.hpp>

#include <vector>
#include <string>

class ServerLoader
{

    const std::string HOST = "localhost";
    const std::string PORT = "9000";
    const size_t CARDS_PER_USER = 10;
    const size_t CARDS_FIELD = 4;
    const size_t USERS = 2;

public:
    ServerLoader();

    GameData createGame() const;
};

#endif // SERVERLOADER_H
