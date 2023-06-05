//
//  Player.cpp
//  MonopolyFP
//
//  Created by Sam Bridgman on 12/8/22.
//

#include "Player.hpp"
using namespace std;
#include <vector>
#include <string>
#include <iostream>
#include "Property.hpp"
#include "ElectricCompany.hpp"


Player::Player(string name, int money, int position, vector<Property> ownedProperties, int flag)
:name(name),money(money),position(0),playerFlag(flag),ownedProperties(ownedProperties){}

//displays owned properties
void Player::getProperties(){
    cout << name << "'s Owned Properties: \n";
    for(auto& i : this->ownedProperties) {
        cout << i.getName() << ": " << i.getHouseCount() << " property(s) owned: Rent = " <<i.getRentPerProp() << endl;
    }
}
//displays owned utilities
void Player::getUtilities(){
    for(auto& i : this->ownedUtilities) {
        cout << i.getName() << ": " << i.getHouseCount() << " utilities owned:" << endl;
    }
}

void Player::addProperty(Property prop) {
    this->ownedProperties.push_back(prop);
}
void Player::addProperty(ElectricCompany prop) {
    this->ownedUtilities.push_back(prop);
}
//buying prop
Property Player::buy(Property& prop, int numOfTimes) {
    //sets owner
    prop.setOwner(this->symbol);
    //subtracts cost to player
    this->money -= (prop.getCost() * numOfTimes);
    //sets house count
    prop.setHouseCount(numOfTimes);
    //add to player
    this->addProperty(prop);
    //returns it
    return prop;
}
//buying utilities
ElectricCompany Player::buy(ElectricCompany& prop, int numOfTimes) {
    //sets owner
    prop.setOwner(this->symbol);
    //subtracts cost of util
    this->money -= (prop.getCost() * numOfTimes);
    //sets prop house count
    prop.setHouseCount(numOfTimes);
    //add to player util inv
    this->addProperty(prop);
    //returns prop
    return prop;
}
vector<ElectricCompany> Player::getUtilityVec() {
    return this->ownedUtilities;
}
vector<Property> Player::getPropertiesVec() {
    return this->ownedProperties;
}
void Player::setProperty(vector<Property> prop) {
    this->ownedProperties = prop;
}
void Player::setUtilities(vector<ElectricCompany> prop) {
    this->ownedUtilities = prop;
}

//for removing an owned property
void Player::remove(Property& prop) {
    //creates temp vec
    vector<Property> tempVec;
    for(Property i : ownedProperties) {
        //adds every owned prop except parameter prop
        if(i.getName() == prop.getName()) {
            //
        }
        else {
            //adds to temp vec
            tempVec.push_back(i);
        }
    }
    this->ownedProperties = tempVec;
}
//for removing an owned utility
void Player::remove(ElectricCompany& prop) {
    //creates temp vec
    vector<ElectricCompany> tempVec;
    for(ElectricCompany i : ownedUtilities) {
        //adds every owned utility except parameter prop
        if(i.getName() == prop.getName()) {
            //
        }
        else {
            //adds to temp vec
            tempVec.push_back(i);
        }
    }
    //reasign the owned utilities
    this->ownedUtilities = tempVec;
}

std::string Player::getName() {
    return this->name;
}
void Player::setName(string name){
    this->name = name;
}
int Player::getPosition() {
    return this-> position;
}
void Player::movePosition(int position) {
    this->position += position;
}
void Player::setPosition(int num) {
    this->position = num;
}
void Player::setMoney(int money) {
    this->money = money;
}
int Player::getMoney() {
    return this->money;
}
void Player::subtractMoney(int num) {
    this->money -= num;
}
void Player::addMoney(int num) {
    this->money += num;
}
void Player::playerIsBankrupt() {
    this->bankrupt = true;
}
bool Player::checkBankrupt() {
    if(this->money < 0) {
        return true;
    }
    else {
        return false;
    }
}
void Player::setSymbol(string symbol) { // players symbol
    this-> symbol = symbol;
};
string Player::getSymbol() {
    return this->symbol;
}
void Player::setJailFlag(int num) {
    this->jailFlag = num;
}
void Player::subtractJailFlag() {
    this->jailFlag -= 1;
}
int Player::getJailFlag() {
    return this->jailFlag;
}
