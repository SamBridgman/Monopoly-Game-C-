//
//  Card.cpp
//  MonopolyFP
//
//  Created by Sam Bridgman on 12/12/22.
//

#include "Card.hpp"
using namespace std;
//constrcutor
Card::Card(string name, string description)
: name(name), description(description){}

string Card::getName() {
    return this->name;
}
string Card::getDescription() {
    return this->description;
}
