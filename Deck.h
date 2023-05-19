#ifndef DECK_H
#define DECK_H

#include "PlayingCard.h"

class Deck {
public:
    Deck();
    void shuffle();
    PlayingCard dealCard();
    void refill();

private:
    PlayingCard deck[52];
    int cardsLeft;
};

#endif
