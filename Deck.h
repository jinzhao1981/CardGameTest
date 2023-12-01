#ifndef DECK_H
#define DECK_H
#include <map>
#include <vector>
#include "Card.h"
using namespace std;
class Deck {
    std::map<Card, int> cards;
    std::map<Suit, int> cardsPerSuit;
    int deckCount;
public:
    Deck(int _deckCount=0);
    void reset() {
        deckCount=0;
        cards.clear();
        cardsPerSuit.clear();
    }
    void addDeck(int count); 
    bool dealCard(vector<Card> &cardsVec, int numberCards);
    void shuffle();
    void receiveCard(Card card) ;
    string toString() const;
    vector<pair<Card, int> > getCards() const;
    vector<pair<Suit, int> > getCardsPerSuit() const ;
};
#endif