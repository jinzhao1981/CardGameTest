#ifndef TYPE_H
#define TYPE_H

enum class Suit {
    Diamonds, Clubs, Spades, Hearts,
    Max, Min=0
};
enum class FaceValue {
    Ace, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King,
    Max, Min=0
};
#endif