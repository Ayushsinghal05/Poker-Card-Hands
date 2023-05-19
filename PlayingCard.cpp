#include "PlayingCard.h"
using namespace std;
PlayingCard::PlayingCard() {
    value = 0;
    suit = "";
}

PlayingCard::PlayingCard(int value, string suit) {
    this->value = value;
    this->suit = suit;
}

int PlayingCard::getValue() const {
    return value;
}

string PlayingCard::getSuit() const {
    return suit;
}

string PlayingCard::getCardInfo() const {
    string cardInfo;
    switch (value) {
        case 1:
            cardInfo += "Ace";
            break;
        case 11:
            cardInfo += "Jack";
            break;
        case 12:
            cardInfo += "Queen";
            break;
        case 13:
            cardInfo += "King";
            break;
        default:
            cardInfo += to_string(value);
            break;
    }
    cardInfo += " of " + suit;
    return cardInfo;
}
