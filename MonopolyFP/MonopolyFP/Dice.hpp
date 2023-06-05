//
//  Dice.hpp
//  MonopolyFP
//
//  Created by Sam Bridgman on 12/8/22.
//

#ifndef Dice_hpp
#define Dice_hpp

#include <stdio.h>

class Dice {
private:
    int diceOneValue;
    int diceTwoValue;
public:
    void rollDice();
    int getDiceValue();
    int getDiceOne();
    int getDiceTwo();
    void cheatRollDice(int,int); // for presetting rolls
};

#endif /* Dice_hpp */
