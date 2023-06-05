//
//  Card.hpp
//  MonopolyFP
//
//  Created by Sam Bridgman on 12/12/22.
//

#ifndef Card_hpp
#define Card_hpp
#include <string>
#include <stdio.h>
class Card {
private:
    std::string name;
    std::string description;
public:
    Card(std::string, std::string);
    std::string getName();
    std::string getDescription();
};
#endif /* Card_hpp */
