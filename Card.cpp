
#include "Card.h"
#include "Util.h"
#include <stdexcept>
using namespace std;

Card::Card(int rank) {
    if(rank<0 || rank>=MaxCardsNumber) throw invalid_argument("invalid card value");
    suit = (Suit)(rank/MaxFaceValueNumber);
    faceValue = (FaceValue)(rank- (int)suit*MaxFaceValueNumber);
}

string Card::toString() const{
    return Util::toString(getSuit())+" "+Util::toString(getFaceValue());
}
