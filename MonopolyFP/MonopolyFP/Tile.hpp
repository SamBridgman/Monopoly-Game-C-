//
//  Tile.hpp
//  MonopolyFP
//
//  Created by Sam Bridgman on 12/8/22.
//

#ifndef Tile_hpp
#define Tile_hpp

#include <stdio.h>
#include <string>
class Tile {
protected://either action or property
    int ownedBy = 0;
    int pos;//position
public:
    Tile(int);
    //int getOwner();
    //void setOwner(int);
    int getPos();//gets position
};

#endif /* Tile_hpp */
