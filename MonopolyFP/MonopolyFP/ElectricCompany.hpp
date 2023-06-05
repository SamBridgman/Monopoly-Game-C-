//
//  ElectricCompany.hpp
//  MonopolyFP
//
//  Created by Sam Bridgman on 12/12/22.
//

#ifndef ElectricCompany_hpp
#define ElectricCompany_hpp
#include <string>
#include "Tile.hpp"
#include <stdio.h>
#include <vector>
//THIS IS FOR UTILS IN GENERAL NOT JUST ELECTRICAL COMPANY
class ElectricCompany: public Tile {
private:
    std::string name;
    int houseCount = 0;
    int cost = 1;
    int mortgage;
    int dice = 0;
    int rent;
    std::string ownedBy;
public:
    ElectricCompany(std::string,int, int,int);
    void setName(std::string);
    std::string getName();
    int getCost();
    int getHouseCount();
    void setHouseCount(int);
    void setMortage(int);
    int getMortgage();
    void setOwner(std::string);
    std::string getOwner();
    void setRent();
    int getRent();
    void setDice(int);
};

#endif /* ElectricCompany_hpp */
