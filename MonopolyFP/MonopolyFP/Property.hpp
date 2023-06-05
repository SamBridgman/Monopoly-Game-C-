//
//  Property.hpp
//  MonopolyFP
//
//  Created by Sam Bridgman on 12/8/22.
//

#ifndef Property_hpp
#define Property_hpp
#include <string>
#include <stdio.h>
#include <vector>
#include "Tile.hpp"
class Property: public Tile {
private:
    std::string name;
    int houseCount = 0;
    int cost = 1;
    int mortgage;
    std::string ownedBy;
    std::vector<int> rentPerProp; //rent
public:
    Property(std::string,int,int,std::vector<int>, int);
    void setName(std::string);
    std::string getName();
    int getCost();
    int getHouseCount();
    void setHouseCount(int);
    int getRentPerProp();
    void setMortage(int);
    int getMortgage();
    void setOwner(std::string);
    std::string getOwner();
};

#endif /* Property_hpp */
