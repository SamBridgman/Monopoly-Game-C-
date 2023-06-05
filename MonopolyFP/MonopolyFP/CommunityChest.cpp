//
//  CommunityChest.cpp
//  MonopolyFP
//
//  Created by Sam Bridgman on 12/12/22.
//

#include "CommunityChest.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;
CommunityChest::CommunityChest(vector<Card> chest, int position)
: chest(chest), Tile(position){}

Card CommunityChest::getCard() {
    
    srand(time(0));
    //gets random card and returns it
    int cardNum = rand()%chest.size()+1;
    return chest[cardNum - 1];
}
