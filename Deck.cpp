#include "Deck.h"
#include "Util.h"
#include <iostream>
using namespace std;

Deck::Deck(int _deckCount){
        if(_deckCount<0) _deckCount = 0;
        if(_deckCount>Util::maxSupportedDecks()) _deckCount = Util::maxSupportedDecks();
        deckCount = _deckCount;
        addDeck(_deckCount);
}
void Deck::addDeck(int count) {
    if(count<=0) return;
    if(deckCount+count>Util::maxSupportedDecks()) {
        cout << "addDeck "<<count<<" exceeded "<<Util::maxSupportedDecks()<<endl;
        count = Util::maxSupportedDecks()-deckCount;
    }
    if(Util::isVerbose())cout << "Adding "<< count <<" deck(s) of cards. increase count for each card and per suits accordingly. "<<endl;
    deckCount+=count;
    for(int i=0; i<Card::MaxCardsNumber; i++)
        cards[i]+=count;
    for(auto i=Suit::Min; i<Suit::Max; i=(Suit)((int)i+1))
        cardsPerSuit[i]+=count*Card::MaxFaceValueNumber;
}
bool Deck::dealCard(vector<Card> &cardsVec, int numberCards){
    if(numberCards<=0) return false;
    if(cards.empty()) return false;
    for(int i=0; i<numberCards; i++){
        if(cards.empty()) break;
        int r = rand()%cards.size();
        auto it = cards.begin();
        advance(it, r);
        Card card = it->first;
        if(Util::isVerbose())cout << "dealCard: from deck randomly choose card: "<<card.toString()<<endl;

        cards[card]--;
        if(cards[card]<=0) cards.erase(card);
        cardsPerSuit[card.getSuit()]--;
        cardsVec.push_back(card);
    }
    return true;
}
void Deck::shuffle() {
    // vector<Card> cards;
    // for (int i =0; i<cards.size(); i++) {
    //     int r = rand()%cards.size();
    //     swap(cards[i], cards[r]);
    // }

    if(Util::isVerbose())cout << "do nothing. shuffle when dealing a card "<<endl;
}
void Deck::receiveCard(Card card) {
    if(Util::isVerbose())cout << "Adding card "<< card.toString()<<" to deck. increase count for the card and per suit accordingly. "<<endl;
    cards[card]++;
    cardsPerSuit[card.getSuit()]++;
}
string Deck::toString() const{
    string ret="";
    for(auto c: cards){
        ret+=c.first.toString()+" "+ to_string(c.second)+"\n";
    }
    return ret;
}
vector<pair<Card, int> > Deck::getCards() const {
    vector<pair<Card, int> > ret;
    for(auto c: cards) ret.push_back(c);
    return ret;
}
vector<pair<Suit, int> > Deck::getCardsPerSuit() const {
    vector<pair<Suit, int> > ret;
    for(auto c: cardsPerSuit) ret.push_back(c);
    return ret;
}