#include "Game.h"
#include "Util.h"
#include <iostream>
using namespace std;
void Game::addPlayer(const Player& player) {
    auto it = players.find(player);
    if(it!=players.end()){
        cout << player.Name() << " player already exists"<<endl;
        return;
    }
    if(players.size()>=Util::maxSupportedPlayers()) {
        cout << "max players reached"<<endl;
        return;
    }
    players.insert(player);
}

void Game::removePlayer(Player& player) {
    players.erase(player);
    player.reset();
}
std::vector<Player> Game::getPlayers() const {
    vector<Player> ret;
    for(auto p: players) ret.push_back(p);
    return ret;
}

void Game::dealCards(Player& player, int numberCards) {
    if(players.find(player)==players.end()) {
        if(Util::isVerbose())cout << "dealCards "<< player.Name() << " player not in the game"<<endl;
        return;
    }
    vector<Card> cards;
    if(!deck.dealCard(cards, numberCards)) return;
    players.erase(player);
    player.receiveCard(cards);
    players.insert(player);
}