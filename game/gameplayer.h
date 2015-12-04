#ifndef GAMEPLAYER_H
#define GAMEPLAYER_H

#include <QDebug>

class GamePlayer
{
private:
    unsigned int _id;
    QString _name;
public:
    GamePlayer(unsigned int id, QString name = "");

    unsigned int getId() const;

    QString getName() const;
    void setName(QString name);

    bool operator <(const GamePlayer &) const;

    friend QDebug operator <<(QDebug, const GamePlayer &);
};

#endif // GAMEPLAYER_H
