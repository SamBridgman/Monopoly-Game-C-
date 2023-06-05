//
//  CommunityChest.hpp
//  MonopolyFP
//
//  Created by Sam Bridgman on 12/12/22.
//

#ifndef CommunityChest_hpp
#define CommunityChest_hpp
#include "Tile.hpp"
#include <stdio.h>
#include <vector>
#include "Card.hpp"
class CommunityChest: public Tile {
public:
    CommunityChest(std::vector<Card>, int);
    Card getCard();
private:
    //vector of cards
    std::vector<Card> chest;
};
#endif /* CommunityChest_hpp */
