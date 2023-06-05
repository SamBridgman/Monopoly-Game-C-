//
//  game.hpp
//  MonopolyFP
//
//  Created by Sam Bridgman on 12/8/22.
//

#ifndef game_hpp
#define game_hpp
#include <string>
#include <stdio.h>
#include "Player.hpp"
#include <vector>
#include "Tile.hpp"
#include "Property.hpp"
#include "ElectricCompany.hpp"


class game {
public:
    void play();
    void displayBoard(Player, Player);
    void showStats(Player);
    void propActionEvent(Player&,Player&);
    void utilityActionEvent(Player&,Player&,int dice); //utility property action
    //sets board
    void setBoard(std::vector<Property>&);
    void setutilBoard(std::vector<ElectricCompany>);
    void railroadTravel(Player& );
    void propertyManagment(Player&);
    void tradeProperty(Player&, Player&);
private:
    std::vector<Property> board; // property
    std::vector<ElectricCompany> utilityBoard;
};

#endif /* game_hpp */
