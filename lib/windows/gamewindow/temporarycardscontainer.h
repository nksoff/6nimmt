#ifndef TEMPORARYCARDSCONTAINER_H
#define TEMPORARYCARDSCONTAINER_H

#include "lib/main.h"

#include <QWidget>
#include <QPainter>

class TemporaryCardsContainer : public QWidget
{
    Q_OBJECT

    const int DEFAULT_WIDTH = 300;
    const int DEFAULT_HEIGHT = 200;

public:
    explicit TemporaryCardsContainer(QWidget *parent = 0);

};

#endif // TEMPORARYCARDSCONTAINER_H
