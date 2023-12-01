#include <iostream>
#include "GameMgr.h"
#include "Util.h"
using namespace std;
int main() {
    auto &mgr = GameMgr::getInstance();
    auto game = mgr.createGame("game1");
    if(!game) {
        cout << "failed to create game"<<endl;
        return 0;
    }

    Player p1("p1"), p2("p2");
    game->addPlayer(p1);
    game->addPlayer(p2);
    game->addDeck(1);

    game->shuffleDeck();
    game->dealCards(p1);
    game->dealCards(p1);
    game->dealCards(p2,3);
    auto players = game->getPlayers();
    cout << "=====players====="<<endl;
    for(auto p: players){
        cout<<p.Name()<<" "<<p.TotalCardValue()<<endl;
    }
    {
    cout << "=====p1 cards====="<<endl;
    auto cards = p1.getCards();
    for(auto c: cards){
        cout<<c.first.toString()<<" "<<c.second<<",";
    }
    cout<<endl;
    }
    {
    cout << "=====p2 cards====="<<endl;
    auto cards = p2.getCards(); 
    for(auto c: cards){
        cout<<c.first.toString()<<" "<<c.second<<",";
    }
    cout<<endl;
    }
    cout << "=====undelt cards====="<<endl;
    auto cards = game->getUndeltCardsCount();
    for(auto c: cards){
        cout<<c.first.toString()<<" "<<c.second<<",";
    }
    cout<<endl;
        cout << "=====undelt cards per suit====="<<endl;
    auto cardsPerSuit = game->getUndeltCardsCountPerSuit();
    for(auto c: cardsPerSuit){
        cout<<Util::toString(c.first)<<" "<<c.second<<",";
    }
    cout<<endl;

    return 0;
}
