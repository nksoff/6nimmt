#ifndef GAMESESSIONROW_H
#define GAMESESSIONROW_H


class GameSessionRow
{
private:
    GameCardCollection collection;
public:
    GameSessionRow();

    void add(GameCard *card);
    void remove(GameCard *card);
};

#endif // GAMESESSIONROW_H
