//
//  Property.cpp
//  MonopolyFP
//
//  Created by Sam Bridgman on 12/8/22.
//

#include "Property.hpp"
#include <string>
#include "Player.hpp"

using namespace std;

Property::Property(string name,int houseCount,int cost, vector<int> rentPerProp, int position)
        :name(name),houseCount(0),cost(cost),rentPerProp(rentPerProp), Tile(position){}

string Property::getName() {
    return this->name;
}
void Property::setName(string name) {
    this->name = name;
}
int Property::getHouseCount() {
    return this->houseCount;
}
void Property::setHouseCount(int num) { //adds to house count
    this-> houseCount += num;
}
int Property::getRentPerProp() {
    return this->rentPerProp[this->houseCount - 1];//grabs rent from the rent vector
}
void Property::setMortage(int mortgage) {
    this-> mortgage = mortgage;
}
int Property::getMortgage() {
    mortgage = (cost / 2) * houseCount;
    return this-> mortgage;
}
int Property::getCost() {
    return this->cost;
}
void Property::setOwner(std::string owner) {
    this->ownedBy = owner;
}
std::string Property::getOwner() {
    return this->ownedBy;
}
