//
//  ElectricCompany.cpp
//  MonopolyFP
//
//  Created by Sam Bridgman on 12/12/22.
//

#include "ElectricCompany.hpp"
#include <string>
using namespace std;
//constructor
ElectricCompany::ElectricCompany(string name,int houseCount,int cost, int position)
        :name(name),houseCount(0),cost(cost), Tile(position){}

string ElectricCompany::getName() {
    return this->name;
}
void ElectricCompany::setName(string name) {
    this->name = name;
}
int ElectricCompany::getHouseCount() {
    return this->houseCount;
}
void ElectricCompany::setHouseCount(int num) {
    this-> houseCount += num;
}
void ElectricCompany::setMortage(int mortgage) {
    this-> mortgage = mortgage;
}
//mortgage is half of cost
int ElectricCompany::getMortgage() {
    mortgage = (cost / 2) * houseCount;
    return this-> mortgage;
}
int ElectricCompany::getCost() {
    return this->cost;
}
void ElectricCompany::setOwner(string owner) {
    this->ownedBy = owner;
}
string ElectricCompany::getOwner() {
    return this->ownedBy;
}
//sets the rent for the utils
void ElectricCompany::setRent() {
    if(houseCount == 1) { // if one prop is owned
        rent = 4 * dice;
    }
    else if (houseCount == 2) { // if two
        rent = 10 * dice;
    }
    else {
        rent = 0;
    }
}
void ElectricCompany::setDice(int num) {
    this->dice = num;
}
int ElectricCompany::getRent() {
    return this->rent;
}
