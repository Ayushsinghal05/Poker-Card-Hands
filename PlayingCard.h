#ifndef PLAYINGCARD_H
#define PLAYINGCARD_H

#include <string>
using namespace std;
class PlayingCard {
public:
    PlayingCard();
    PlayingCard(int value, string suit);

    int getValue() const;
    string getSuit() const;
    string getCardInfo() const;

private:
    int value;
    string suit;
};

#endif
