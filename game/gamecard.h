#ifndef GAMECARD_H
#define GAMECARD_H

class GameCard
{
private:
    unsigned short _number;
public:
    GameCard(unsigned short number);

    unsigned short getNumber() const;
    short getPenaltyPoints() const;
};

#endif // GAMECARD_H
