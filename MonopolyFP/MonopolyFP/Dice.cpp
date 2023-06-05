//
//  Dice.cpp
//  MonopolyFP
//
//  Created by Sam Bridgman on 12/8/22.
//

#include "Dice.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

//regular roll 1-6
void Dice::rollDice() {
    srand(time(0));
    
    this->diceOneValue = rand()%6+1;
    this->diceTwoValue = rand()%6+1;
    
    std::cout << "Roll: " << diceOneValue << " and " << diceTwoValue << std::endl;
    
}
int Dice::getDiceValue() {
    return diceTwoValue + diceOneValue;
}
int Dice::getDiceOne() {
    return this->diceOneValue;
}
int Dice::getDiceTwo() {
    return this->diceTwoValue;
}
//for setting prerolled values
void Dice::cheatRollDice(int one, int two) {
    
    this->diceOneValue = one;
    this->diceTwoValue = two;
    
    std::cout << "Roll: " << diceOneValue << " and " << diceTwoValue << std::endl;
    
}
