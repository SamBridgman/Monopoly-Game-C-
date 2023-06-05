//
//  Chance.cpp
//  MonopolyFP
//
//  Created by Sam Bridgman on 12/12/22.
//

#include "Chance.hpp"
using namespace std;
#include <vector>
using namespace std;
Chance::Chance(vector<Card> chance, int position)
: chance(chance),Tile(position){}

//gets a random card form the chance vector
Card Chance::getCard() {
    
    srand(time(0));
    
    int cardNum = rand()%chance.size()+1;
    return chance[cardNum - 1];
}
