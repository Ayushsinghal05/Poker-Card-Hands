#include <iostream>
#include "Deck.h"
using namespace std;
string determineHand(const PlayingCard hand[]) {
    // Check for Royal Flush
    bool hasSameSuit = true;
    int minVal = hand[0].getValue();
    for (int i = 1; i < 5; ++i) {
        if (hand[i].getSuit() != hand[0].getSuit()) {
            hasSameSuit = false;
            break;
        }
        if (hand[i].getValue() < minVal) {
            minVal = hand[i].getValue();
        }
    }
    if (hasSameSuit && minVal == 10) {
        return "Royal Flush";
    }

    // Check for Straight Flush
    bool isStraightFlush = true;
    int minValSF = hand[0].getValue();
    for (int i = 1; i < 5; ++i) {
        if (hand[i].getSuit() != hand[0].getSuit()) {
            isStraightFlush = false;
            break;
        }
        if (hand[i].getValue() != minValSF + i) {
            isStraightFlush = false;
            break;
        }
    }
    if (isStraightFlush) {
        return "Straight Flush";
    }

    // Check for Four of a Kind
    bool isFourOfAKind = false;
    int valueCounts[13] = {0};
    for (int i = 0; i < 5; ++i) {
        int value = hand[i].getValue();
        valueCounts[value - 1]++;
        if (valueCounts[value - 1] == 4) {
            isFourOfAKind = true;
            break;
        }
    }
    if (isFourOfAKind) {
        return "Four of a Kind";
    }

    // Check for Full House
    bool isFullHouse = false;
    bool hasThreeOfAKind = false;
    bool hasPair = false;
    for (int i = 0; i < 13; ++i) {
        if (valueCounts[i] == 3) {
            hasThreeOfAKind = true;
        } else if (valueCounts[i] == 2) {
            hasPair = true;
        }
    }
    if (hasThreeOfAKind && hasPair) {
        return "Full House";
    }

    // Check for Flush
    if (hasSameSuit) {
        return "Flush";
    }

    // Check for Straight
    bool isStraight = true;
    int minValS = hand[0].getValue();
    for (int i = 1; i < 5; ++i) {
        if (hand[i].getValue() != minValS + i) {
            isStraight = false;
            break;
        }
    }
    if (isStraight) {
        return "Straight";
    }

    // Check for Three of a Kind
    if (hasThreeOfAKind) {
        return "Three of a Kind";
    }

    // Check for Two Pair
    int pairCount = 0;
    for (int i = 0; i < 13; ++i) {
        if (valueCounts[i] == 2) {
            pairCount++;
        }
    }
    if (pairCount == 2) {
        return "Two Pair";
    }

    // Check for One Pair
    if (hasPair) {
        return "One Pair";
    }

    // If none of the above apply, return the highest value card
    int a = 0;
    int maxVal = hand[0].getValue();
    for (int i = 1; i < 5; ++i) {
        if (hand[i].getValue() > maxVal) {
            maxVal = hand[i].getValue();
            a = i;
        }
    }
    return "High Card: " + hand[a].getCardInfo();
}


int main() {
    Deck deck;
    deck.shuffle();

    PlayingCard hand[5];

    for (int i = 0; i < 5; ++i) {
        hand[i] = deck.dealCard();
        cout << hand[i].getCardInfo() << endl;
    }

    string bestHand = determineHand(hand);
    cout << "Best Hand: " << bestHand << endl;

    return 0;
}

