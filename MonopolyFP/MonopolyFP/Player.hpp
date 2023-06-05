//
//  Player.hpp
//  MonopolyFP
//
//  Created by Sam Bridgman on 12/8/22.
//

#ifndef Player_hpp
#define Player_hpp

#include <stdio.h>
#include <string>
#include "Property.hpp"
#include <vector>
#include "ElectricCompany.hpp"

//player needs name, vector for propertys, money, position
class Player {
private:
    std::string name = "Player 1";
    int money = 1500;
    int position = 0;
    std::vector<Property> ownedProperties;
    bool bankrupt = false;
    int playerFlag;
    std::string symbol;
    int jailFlag = 0;
    std::vector<ElectricCompany> ownedUtilities;
public:
    
    Player(std::string, int,int,std::vector<Property>, int);
    
    std::string getName();
    void setName(std::string name);
    
    void subtractMoney(int);
    void addMoney(int);
    
    void movePosition(int);
    int getPosition();
    void setPosition(int);
    Property buy(Property&, int);
    ElectricCompany buy(ElectricCompany&, int);
    
    int getMoney();
    void setMoney(int);
    
    void addProperty(Property);
    void addProperty(ElectricCompany);
    void remove(Property&);
    void remove(ElectricCompany&);
    void getProperties();
    void getUtilities();
    
    void setProperty(std::vector<Property>);
    void setUtilities(std::vector<ElectricCompany>);
    
    std::vector<ElectricCompany> getUtilityVec();
    std::vector<Property> getPropertiesVec();
    void playerIsBankrupt();
    bool checkBankrupt();
    void setSymbol(std::string);
    std::string getSymbol();
    void setJailFlag(int);
    void subtractJailFlag();
    int getJailFlag();
};
#endif /* Player_hpp */
