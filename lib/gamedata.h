#ifndef GAMEDATA_H
#define GAMEDATA_H

#include <vector>
#include <string>

class GameData
{
private:
    std::vector<unsigned short> fieldCards;
    std::vector<unsigned short> playerCards;
    std::vector<unsigned short> serverCards;

    bool _isError;
    std::string _error;
public:
    GameData();

    std::vector<unsigned short> &getFieldCards();
    std::vector<unsigned short> &getPlayerCards();
    std::vector<unsigned short> &getServerCards();

    void setError(const std::string &);
    bool isError() const;
    const std::string &getError() const;
};

#endif // GAMEDATA_H
