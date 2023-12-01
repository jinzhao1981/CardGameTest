#include "Util.h"
#include <string>
#include <vector>
using namespace std;

string Util::toString(Suit suit){
    if(suit < Suit::Min && suit >= Suit::Max)
        return "Unknown";
    const vector<string> v = { "Diamonds", "Clubs", "Spades", "Hearts"};
    return v[(int)suit];
}
string Util::toString(FaceValue faceValue){
    if(faceValue < FaceValue::Min && faceValue >= FaceValue::Max)
        return "Unknown";
    const vector<string> v = {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
    return v[(int)faceValue];
}
bool Util::isVerbose() {
    return true;
}
int Util::maxSupportedPlayers(){return 1000000;}
int Util::maxSupportedDecks(){return 1000000;}