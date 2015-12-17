#ifndef ROWCONTAINER_H
#define ROWCONTAINER_H

class Row;
#include "row.h"

#include <QWidget>
#include <QRect>

class RowContainer : public QWidget
{
    Q_OBJECT

    const int DEFAULT_WIDTH = 620;
    const int DEFAULT_HEIGHT = 460;
    const QColor BACKGROUND_COLOR = QColor(255, 255, 255, 64);
    const size_t ROWS = 4;
    const int DEFAULT_X_SPACE = 10;
    const int DEFAULT_Y_SPACE = -4;

    std::vector<Row *> rows;

    void paintEvent(QPaintEvent *);

public:
    explicit RowContainer(QWidget *parent = 0);
    ~RowContainer();

    short addCard(Card *);

};

#endif // ROWCONTAINER_H
