#include "playercardscontainer.h"

PlayerCardsContainer::PlayerCardsContainer(QWidget *parent) : QWidget(parent)
{
    resize(PlayerCardsContainer::DEFAULT_WIDTH,
           PlayerCardsContainer::DEFAULT_HEIGHT);
}

void PlayerCardsContainer::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(PlayerCardsContainer::BACKGROUND_COLOR);
    QRect rect;
    rect.setSize(QSize(PlayerCardsContainer::DEFAULT_WIDTH,
                       PlayerCardsContainer::DEFAULT_HEIGHT));
    painter.setBrush(QBrush(PlayerCardsContainer::BACKGROUND_COLOR));
    painter.drawRoundedRect(rect,
                            PlayerCardsContainer::ROUND_CORNER_RADIUS,
                            PlayerCardsContainer::ROUND_CORNER_RADIUS);
}

void PlayerCardsContainer::setCards(std::vector<Card *> newCards)
{
    for(size_t i = 0; i < newCards.size(); i++) {
        newCards[i]->setParent(this);
        newCards[i]->show();

        newCards[i]->move(PlayerCardsContainer::DEFAULT_SPACE_X * (i + 1)
                          + i * newCards[i]->geometry().width(),
                          PlayerCardsContainer::DEFAULT_SPACE_Y);
        cards.push_back(newCards[i]);
    }
}

PlayerCardsContainer::~PlayerCardsContainer()
{
    for(size_t i = 0; i < cards.size(); i++) {
        if(cards.at(i) != NULL) delete cards.at(i);
    }
}

void PlayerCardsContainer::remove(Card *card)
{
    for(size_t i = 0; i < cards.size(); i++) {
        if(cards[i] == card) {
            cards[i] = NULL;
            break;
        }
    }
}

size_t PlayerCardsContainer::countLeft() const
{
    size_t count = 0;
    for(size_t i = 0; i < cards.size(); i++) {
        if(cards[i] != NULL) {
            count++;
        }
    }
    return count;
}
