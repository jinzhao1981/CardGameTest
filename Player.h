#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <vector>
#include <map>
#include "Card.h"
#include "Deck.h"
using namespace std;

class Player {

private:
    string name;
    Deck playerDeck;
    int totalCardValue;
public:
    Player(string _name):name(_name), totalCardValue(0){}
    string Name() const { return name;  }
    int TotalCardValue() const { return totalCardValue; }
    void receiveCard(const vector<Card>& cards);
    vector<pair<Card, int> > getCards() const { return playerDeck.getCards(); }
    void reset() {
        playerDeck.reset();
        totalCardValue = 0;
    }
    bool operator<(const Player& other) const {
        // players is sorted by totalCardValue first
        return totalCardValue>other.totalCardValue || (totalCardValue==other.totalCardValue && name>other.name);
    }
};
#endif
