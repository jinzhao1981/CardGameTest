#ifndef GAME_H
#define GAME_H
#include <string>
#include <set>
#include <vector>
#include "Player.h"
#include "Deck.h"

class Game {

private:
    set<Player> players;
    Deck deck;
    string name;

public:
    Game(string _name):name(_name){}
    string Name() const { return name;  }
    void addPlayer(const Player& player) ;

    void removePlayer(Player& player) ;
    std::vector<Player> getPlayers() const ;

    void addDeck(int count=1) { deck.addDeck(count); }
    void shuffleDeck() { deck.shuffle(); }

    void dealCards(Player& player, int numberCards=1) ;
    vector<pair<Card, int> > getUndeltCardsCount() const { return deck.getCards(); }
    vector<pair<Suit, int> > getUndeltCardsCountPerSuit() const { return deck.getCardsPerSuit(); }
};
#endif