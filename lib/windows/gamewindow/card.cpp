#include "card.h"

Card::Card(unsigned short num, GameWindow *window, QWidget *parent)
    : QWidget(parent),
      number(num), gameWindow(window)
{
    state = new CardStateStatic(this);
    checkNullPointer(state);

    std::string path = std::string(Card::IMG_PATH) + std::to_string(number) + std::string(Card::IMG_EXT);

    QPixmap logo(path.c_str());
    logo = logo.scaledToHeight(Card::DEFAULT_HEIGHT);

    int height = logo.height(),
        width = logo.width();
    resize(width, height);

    label = new QLabel(this);
    checkNullPointer(label, [=]() {
        delete state;
    });
    label->setGeometry(0, 0, width, height);
    label->setPixmap(logo);
    label->show();
}

Card::~Card()
{
    delete state;
    delete label;
}

void Card::setActive()
{
    if(!state->isActive())
    {
        delete state;
        CardState *nState = new CardStateActive(this);
        checkNullPointer(nState);
        state = nState;
    }
}

void Card::setStatic()
{
    if(state->isActive())
    {
        delete state;
        CardState *nState = new CardStateStatic(this);
        checkNullPointer(nState);
        state = nState;
    }
}

unsigned short Card::getNumber() const
{
    return number;
}

short Card::getPoints() const
{
    short res = 1;

    if(number % 11 == 0)
    {
        res = 5;
    }
    else if(number % 10 == 0)
    {
        res = 3;
    }
    else if(number % 55 == 0)
    {
        res = 7;
    }
    else if(number % 5 == 0)
    {
        res = 2;
    }

    return res;
}

void Card::enterEvent(QEvent *event)
{
    state->enterEvent(event);
}

void Card::leaveEvent(QEvent *event)
{
    state->leaveEvent(event);
}

void Card::mouseReleaseEvent(QMouseEvent *event)
{
    state->mouseReleaseEvent(event);
}

GameWindow *Card::getGameWindow()
{
    return gameWindow;
}
