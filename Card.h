
#ifndef CARD_H
#define CARD_H


#include "Type.h"
#include <string>

using namespace std;
class Card {
private:
    Suit suit;
    FaceValue faceValue;
public:
    static const int MaxCardsNumber = (int)Suit::Max*(int)FaceValue::Max;
    static const int MaxSuitNumber = (int)Suit::Max;
    static const int MaxFaceValueNumber = (int)FaceValue::Max;

    Card(Suit suit, FaceValue faceValue):suit(suit), faceValue(faceValue) {}
    Card(int rank=0);

    Suit getSuit() const { return suit; }
    FaceValue getFaceValue() const { return faceValue; }
    string toString() const;
    bool operator<(const Card& other) const{
        return suit>other.suit || (suit==other.suit && faceValue>other.faceValue);
    }
};
#endif