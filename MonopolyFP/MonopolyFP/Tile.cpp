//
//  Tile.cpp
//  MonopolyFP
//
//  Created by Sam Bridgman on 12/8/22.
//

#include "Tile.hpp"
#include <iostream>
using namespace std;

Tile::Tile(int pos)
: pos(pos){}

//returns tile position
int Tile::getPos() {
    return this->pos;
}
