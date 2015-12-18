#include "cardstateactive.h"

CardStateActive::CardStateActive(Card *card) : CardState(card)
{
    QString style = CardStateActive::BORDER
                    + ":"
                    + CardStateActive::BORDER_VAL + ";"
                    + CardStateActive::BACKGROUND_COLOR
                    + ":"
                    + CardStateActive::BACKGROUND_COLOR_VAL + ";";
    getParent()->setStyleSheet(style);
}

void CardStateActive::enterEvent(QEvent *)
{
    QString style = CardStateActive::BORDER
                    + ":"
                    + CardStateActive::BORDER_VAL_HOVER + ";";
    getParent()->setStyleSheet(style);
    QApplication::setOverrideCursor(CardStateActive::CURSOR_VAL_HOVER);
}

void CardStateActive::leaveEvent(QEvent *)
{
    QString style = CardStateActive::BORDER
                    + ":"
                    + CardStateActive::BORDER_VAL + ";";
    getParent()->setStyleSheet(style);
    QApplication::setOverrideCursor(CardStateActive::CURSOR_VAL);
}

void CardStateActive::mouseReleaseEvent(QMouseEvent *)
{
    getParent()->getGameWindow()->selectCard(getParent());
}

CardStateActive::~CardStateActive()
{
    getParent()->setStyleSheet(CardStateActive::RESET);
}

bool CardStateActive::isActive() const
{
    return true;
}

