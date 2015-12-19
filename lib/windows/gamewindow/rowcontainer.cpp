#include "rowcontainer.h"
#include <QPainter>

RowContainer::RowContainer(QWidget *parent) : QWidget(parent)
{
    resize(RowContainer::DEFAULT_WIDTH, RowContainer::DEFAULT_HEIGHT);

    for(size_t i = 0; i < RowContainer::ROWS; i++)
    {
        Row *row = new Row(this);
        checkNullPointer(row, [=]()
        {
            for(size_t i = 0; i < rows.size(); i++)
            {
                delete rows.at(i);
            }
        });
        row->move(RowContainer::DEFAULT_X_SPACE,
                  i * (row->geometry().height() + RowContainer::DEFAULT_Y_SPACE));
        row->show();
        rows.push_back(row);
    }
}

RowContainer::~RowContainer() {
    for(size_t i = 0; i < RowContainer::ROWS; i++) {
        if(rows.at(i) != NULL) delete rows.at(i);
    }
}

short RowContainer::addCard(Card *card) {
    for(size_t i = 0; i < RowContainer::ROWS; i++)
    {
        if(rows[i]->count() == 0)
        {
            return rows[i]->addCard(card);
        }
    }

    short delta[RowContainer::ROWS];
    for(size_t i = 0; i < RowContainer::ROWS; i++)
    {
        delta[i] = card->getNumber() - rows[i]->getLastCard()->getNumber();
        if(delta[i] < 0)
        {
            delta[i] = 0;
        }
    }

    short min = Card::MAX_NUMBER;
    size_t minKey = 0;
    for(size_t i = 1; i < RowContainer::ROWS; i++)
    {
        if(delta[i] == 0)
        {
            continue;
        }
        if(delta[i] < min)
        {
            min = delta[i];
            minKey = i;
        }
    }

    return rows[minKey]->addCard(card);
}

void RowContainer::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(RowContainer::BACKGROUND_COLOR);
    QRect rect;
    rect.setSize(QSize(RowContainer::DEFAULT_WIDTH, RowContainer::DEFAULT_HEIGHT));
    painter.fillRect(rect, QBrush(RowContainer::BACKGROUND_COLOR));
}
