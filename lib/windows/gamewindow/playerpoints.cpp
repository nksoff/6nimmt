#include "playerpoints.h"

PlayerPoints::PlayerPoints(QWidget *parent) : QWidget(parent), count(0)
{
    resize(PlayerPoints::DEFAULT_WIDTH, PlayerPoints::DEFAULT_HEIGHT);
    label = new QLabel("0", this);
    checkNullPointer(label);
    label->setStyleSheet(PlayerPoints::DEFAULT_STYLE);
    label->move(PlayerPoints::DEFAULT_X_SPACE, PlayerPoints::DEFAULT_Y_SPACE);
    label->resize(PlayerPoints::DEFAULT_WIDTH, PlayerPoints::DEFAULT_HEIGHT);
    label->setAlignment(Qt::AlignCenter);
    label->show();
}

PlayerPoints::~PlayerPoints()
{
    delete label;
}

void PlayerPoints::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(PlayerPoints::BACKGROUND_COLOR);
    QRect rect;
    rect.setSize(QSize(PlayerPoints::DEFAULT_WIDTH, PlayerPoints::DEFAULT_HEIGHT));
    painter.fillRect(rect, QBrush(PlayerPoints::BACKGROUND_COLOR));
    label->show();
}

void PlayerPoints::add(short num)
{
    count += num;
    label->setText(QString(std::to_string(count).c_str()));
}

short PlayerPoints::getPoints() const
{
    return count;
}

void PlayerPoints::setRed()
{
    label->setStyleSheet(PlayerPoints::RED_STYLE);
}
