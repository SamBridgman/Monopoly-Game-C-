//
//  Chance.hpp
//  MonopolyFP
//
//  Created by Sam Bridgman on 12/12/22.
//

#ifndef Chance_hpp
#define Chance_hpp

#include <stdio.h>
#include "Card.hpp"
#include <vector>
#include "Tile.hpp"
class Chance: public Tile {
private:
    std::vector<Card> chance;
public:
    Chance(std::vector<Card>, int);
    Card getCard();
};
#endif /* Chance_hpp */
