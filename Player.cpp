#include "Player.h"
#include "Util.h"
#include <iostream>
using namespace std;
void Player::receiveCard(const vector<Card>& cards) {
    for (auto card: cards) {
        playerDeck.receiveCard(card);
        totalCardValue+=(int)card.getFaceValue()+1;
        if(Util::isVerbose())cout << "Player "<<name<<" received a card "<< card.toString()<<", put it to deck. increase totalCardValue to "<<totalCardValue<<" accordingly. "<<endl;
    }
}
