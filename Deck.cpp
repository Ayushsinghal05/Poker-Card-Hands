#include "Deck.h"
#include <cstdlib>  
#include <ctime>    

Deck::Deck() {
    std::string suits[4] = {"spades", "diamonds", "clubs", "hearts"};
    int cardCount = 0;
    for (int suit = 0; suit < 4; ++suit) {
        for (int value = 1; value <= 13; ++value) {
            deck[cardCount] = PlayingCard(value, suits[suit]);
            ++cardCount;
        }
    }
    cardsLeft = 52;
}

void Deck::shuffle() {
    srand(static_cast<unsigned int>(time(0)));

    for (int i = 0; i < 52; ++i) {
        int randomIndex = rand() % 52;
        PlayingCard temp = deck[i];
        deck[i] = deck[randomIndex];
        deck[randomIndex] = temp;
    }
}

PlayingCard Deck::dealCard() {
    if (cardsLeft > 0) {
        --cardsLeft;
        return deck[cardsLeft];
    }
    return PlayingCard();  // Return an empty card if the deck is empty
}

void Deck::refill() {
    cardsLeft = 52;
}
