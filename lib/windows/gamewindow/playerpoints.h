#ifndef PLAYERPOINTS_H
#define PLAYERPOINTS_H

#include "lib/main.h"

#include <QLabel>
#include <QPainter>

class PlayerPoints : public QWidget
{
    Q_OBJECT

    const int DEFAULT_WIDTH = 300;
    const int DEFAULT_HEIGHT = 100;
    const QColor BACKGROUND_COLOR = QColor(255, 255, 255, 64);
    const QString DEFAULT_STYLE = "font-size: 30px; color: #fff;";
    const QString RED_STYLE = "font-size: 30px; color: #c30;";
    const int DEFAULT_X_SPACE = 0;
    const int DEFAULT_Y_SPACE = 0;

    QLabel *label;
    short count;

    void paintEvent(QPaintEvent *);
public:
    explicit PlayerPoints(QWidget *parent = 0);
    ~PlayerPoints();

    short getPoints() const;
    void add(short);
    void setRed();

};

#endif // PLAYERPOINTS_H
