#ifndef CARDSTATEACTIVE_H
#define CARDSTATEACTIVE_H

#include "lib/main.h"

#include "lib/windows/gamewindow/cardstate/cardstate.h"
#include "lib/windows/gamewindow/card.h"
#include "lib/windows/gamewindow.h"

#include <QApplication>
#include <QCursor>

class CardStateActive : public CardState
{
    const QString BORDER = "border";
    const QString BACKGROUND_COLOR = "background-color";

    const QString BORDER_VAL = "3px solid #fff";
    const QString BORDER_VAL_HOVER = "3px solid #ccc";
    const QString BACKGROUND_COLOR_VAL = "#fff";

    const QCursor CURSOR_VAL = QCursor(Qt::ArrowCursor);
    const QCursor CURSOR_VAL_HOVER = QCursor(Qt::PointingHandCursor);

    const QString RESET = "border: none; background: none;";

public:
    CardStateActive(Card *);
    virtual ~CardStateActive();

    virtual void enterEvent(QEvent *);
    virtual void leaveEvent(QEvent *);
    virtual void mouseReleaseEvent(QMouseEvent *);

    virtual bool isActive() const;
};

#endif // CARDSTATEACTIVE_H
