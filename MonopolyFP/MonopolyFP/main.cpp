//
//  main.cpp
//  MonopolyFP
//
//  Created by Sam Bridgman on 12/8/22.
//

#include <iostream>
#include "game.hpp"
using namespace std;

//This game includes the following additional features
//1) Implement both Chance and Community Chest cards.  They can be the ‘real’ cards from the game or have effects of your choosing.
//2) Level 1 – Allow the player to build houses on each property they own.  Cost of houses and increases to rent are specified by the game.  At this level, any amount of houses (up to four) can be built on any owned property.
//3) Level 1 – Allow players to trade properties.  Make sure multiple-for-one trades are possible.
//4) Level 1 – Implement the ‘property auction’ rules when a player lands on a space but does not wish to purchase it.
//5) Level 1 – Allow players that land on railroads to travel to any other owned Railroad instead of rolling.  If you pass Go, do not collect $200.
//6) Level 1 – Add in a cheats menu to speed up game-play and enable testing of various functions



int main() {
    //raw string
    cout << R"( .----------------.  .----------------.  .-----------------. .----------------.  .----------------.  .----------------.  .----------------.  .----------------.
 | .--------------. || .--------------. || .--------------. || .--------------. || .--------------. || .--------------. || .--------------. || .--------------. |
 | | ____    ____ | || |     ____     | || | ____  _____  | || |     ____     | || |   ______     | || |     ____     | || |   _____      | || |  ____  ____  | |
 | ||_   \  /   _|| || |   .'    `.   | || ||_   \|_   _| | || |   .'    `.   | || |  |_   __ \   | || |   .'    `.   | || |  |_   _|     | || | |_  _||_  _| | |
 | |  |   \/   |  | || |  /  .--.  \  | || |  |   \ | |   | || |  /  .--.  \  | || |    | |__) |  | || |  /  .--.  \  | || |    | |       | || |   \ \  / /   | |
 | |  | |\  /| |  | || |  | |    | |  | || |  | |\ \| |   | || |  | |    | |  | || |    |  ___/   | || |  | |    | |  | || |    | |   _   | || |    \ \/ /    | |
 | | _| |_\/_| |_ | || |  \  `--'  /  | || | _| |_\   |_  | || |  \  `--'  /  | || |   _| |_      | || |  \  `--'  /  | || |   _| |__/ |  | || |    _|  |_    | |
 | ||_____||_____|| || |   `.____.'   | || ||_____|\____| | || |   `.____.'   | || |  |_____|     | || |   `.____.'   | || |  |________|  | || |   |______|   | |
 | |              | || |              | || |              | || |              | || |              | || |              | || |              | || |              | |
 | '--------------' || '--------------' || '--------------' || '--------------' || '--------------' || '--------------' || '--------------' || '--------------' |
  '----------------'  '----------------'  '----------------'  '----------------'  '----------------'  '----------------'  '----------------'  '----------------' )" << endl;
    
    cout << "\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  By Sam Bridgman" << endl;
    cout << "\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tEnter 1 to continue" << endl;
    int conGame;
    cin >> conGame;
    if(conGame == 1) {
        //starts the game
        game game;
        game.play();
    }
    else{
        cout << "bye!"<< endl;
    }

    
    return 0;
}

