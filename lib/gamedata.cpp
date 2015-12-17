#include "gamedata.h"

GameData::GameData() : _isError(false)
{
}

std::vector<unsigned short> &GameData::getFieldCards()
{
    return fieldCards;
}
std::vector<unsigned short> &GameData::getPlayerCards()
{
    return playerCards;
}
std::vector<unsigned short> &GameData::getServerCards()
{
    return serverCards;
}

void GameData::setError(const std::string &str)
{
    _error = str;
    _isError = true;
}

bool GameData::isError() const
{
    return _isError;
}

const std::string &GameData::getError() const
{
    return _error;
}
