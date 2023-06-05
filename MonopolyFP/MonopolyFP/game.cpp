//
//  game.cpp
//  MonopolyFP
//
//  Created by Sam Bridgman on 12/8/22.
//

#include "game.hpp"
#include "Player.hpp"
#include <vector>
#include <iostream>
#include "Property.hpp"
#include "Dice.hpp"
#include "Card.hpp"
#include "CommunityChest.hpp"
#include "Chance.hpp"
#include <string>
#include "ElectricCompany.hpp"
using namespace std;
//prototypes
Card displayCommChest(CommunityChest);
void commAction(Player&, Card);
Card displayChanceChest(Chance);
void chanceAction(Player&, Card);
int determineTurn();
int cheatMenu(Player&);
void displayMenu();
bool checkIfProp(Player);
void movePlayer(Player,int);
string checkOwner(vector<Property>, int);
string checkPos(Player, Player, int);

//enums
enum names{START = 0,INCOME_TAX = 4,FREE_PARKING = 20,JAIL_TWO = 30,JAIL = 10, LUXARY_TAX = 38,ELECTRIC_COMPANY = 12, WATER_WORKS = 28, CHANCE_ONE = 7, CHANCE_TWO = 22, CHANCE_THREE = 36, CHEST_ONE = 2, CHEST_TWO = 17, CHEST_THREE = 33};
enum Railroads{SHORT_LINE = 35, READING_RAILROAD = 5, PENN_RAILROAD = 15, BANO = 25};
void game::play() {
    
    
    
    //tiles that are not properties
    Tile start{0};
    Tile incomeTax{4};
    Tile FreeParking{20};
    Tile jail2{30};
    Tile jail{10};
    Tile luxaryTax{38};
    
    //the list of properties ----------------------
    //rentperd\prop is the rent per hiuse
    vector <int> rentPerProp{10,30,90,160};
    Property MediterraneanAvenue("Mediterranean Avenue",0,60,rentPerProp,1);
    
    vector <int> rentPerProp1{20,60,180,320};
    Property BalticAvenue("Baltic Avenue",0,60,rentPerProp1,3);
    
    vector <int> rentPerProp2{30,90,270,400};
    Property OrientalAvenue("Oriental Avenue",0,100,rentPerProp2,6);
    
    vector <int> rentPerProp3{30,90,270,400};
    Property VermontAvenue("Vermont Avenue",0,100,rentPerProp3,8);
    
    vector <int> rentPerProp4{40,100,300,450};
    Property ConnecticutAvenue("Connecticut Avenue",0,120,rentPerProp4,9);
    
    vector <int> rentPerProp5{50,150,450,625};
    Property StCharlesPlace("St. Charles Place",0,140,rentPerProp5,11);
    
    vector <int> rentPerProp6{50,150,450,625};
    Property StatesAvenue("States Avenue",0,140,rentPerProp6,13);
    
    vector <int> rentPerProp7{60,180,500,700};
    Property VirginiaAvenue("Virginia Avenue",0,140,rentPerProp7,14);
    
    vector <int> rentPerProp8{70,200,550,750};
    Property StJamesPlace("St. James Place",0,180,rentPerProp8,16);
    
    vector <int> rentPerProp9{70,200,550,750};
    Property TennesseeAvenue("Tennessee Avenue",0,180,rentPerProp9,18);
    
    vector <int> rentPerProp10{80,220,600,800};
    Property NewYorkAvenue("New York Avenue",0,200,rentPerProp10,19);
    
    vector <int> rentPerProp11{90,250,700,875};
    Property KentuckyAvenue("Kentucky Avenue",0,220,rentPerProp11,21);
    
    vector <int> rentPerProp12{90,250,700,875};
    Property IndianaAvenue("Indiana Avenue",0,220,rentPerProp12,23);
    
    vector <int> rentPerProp13{100,300,750,925};
    Property IllinoisAvenue("IllinoisAvenue",0,240,rentPerProp13,24);
    
    vector <int> rentPerProp14{110,330,800,975};
    Property AtlanticAvenue("Atlantic Avenue",0,260,rentPerProp14,26);
    
    vector <int> rentPerProp15{110,330,800,975};
    Property VentnorAvenue("VentnorAvenue",0,260,rentPerProp15,27);
    
    vector <int> rentPerProp16{120,360,850,1025};
    Property MarvinGardens("Marvin Gardens",0,280,rentPerProp16,29);
    
    vector <int> rentPerProp17{130,390,900,1100};
    Property PacificAvenue("Pacific Avenue",0,300,rentPerProp17,31);
    
    vector <int> rentPerProp18{130,390,900,1100};
    Property NorthCarolinaAvenue("North Carolina Avenue",0,300,rentPerProp18,32);
    
    vector <int> rentPerProp19{150,450,1000,1200};
    Property PennsylvaniaAvenue("Pennsylvania Avenue",0,320,rentPerProp19,34);
    
    vector <int> rentPerProp20{175,500,1100,1300};
    Property ParkPlace("Park Place",0,350,rentPerProp20,37);
    
    vector <int> rentPerProp21{200,600,1400,1700};
    Property BoardWalk("Board Walk",0,400,rentPerProp21,39);
    // --------------------------------------------
    
    
    //setting up community chest
    vector<Card> communityChest;
    
    //community chest cards
    Card c1{"c1", "Go to Jail"};
    Card c2{"c2", "Speeding fine: pay $15"};
    Card c3{"c3", "Blank card:)"};
    Card c4{"c4", "Income tax refund, collect 60"};
    Card c5{"c5", "Inheritance, collect 150"};
    Card c6{"c6", "Doctors fee, pay 50"};
    Card c7{"c7", "Bank Error, collect 200"};
    Card c8{"c8", "Advance to go, collect 200"};
    Card c9{"c9", "It is your birthday, collect 10 from each player"};
    Card c10{"c10", "Pay school fees of 50"};
    
    //adding to chest
    communityChest.push_back(c1);
    communityChest.push_back(c2);
    communityChest.push_back(c3);
    communityChest.push_back(c4);
    communityChest.push_back(c5);
    communityChest.push_back(c6);
    communityChest.push_back(c7);
    communityChest.push_back(c8);
    communityChest.push_back(c9);
    communityChest.push_back(c10);
    //add to community chest obj with position
    CommunityChest chest1{communityChest,2};
    
    //----------------------------------
    //chance cards
    Card ch1{"ch1", "Go to Jail"};
    Card ch2{"ch2", "Collect 100"};
    Card ch3{"ch3", "Go back 3 spaces"};
    Card ch4{"ch4", "Uh Oh, you got a dui, pay 150"};
    Card ch5{"ch5", "Pay 150"};
    Card ch6{"ch6", "Collect 40"};
    
    vector<Card> chanceChest;
    chanceChest.push_back(ch1);
    chanceChest.push_back(ch2);
    chanceChest.push_back(ch3);
    chanceChest.push_back(ch4);
    chanceChest.push_back(ch5);
    chanceChest.push_back(ch6);
    
    Chance chance1{chanceChest,7};
    //adds to chance obj with position
    
    
    //utilities
    ElectricCompany electricCompany{"Electric Company",0,200,12};
    //for some reason I was not able to rename eletric company to just utility, but this is the water works
    ElectricCompany waterWorks{"Water Works",0,150,28};
    vector<ElectricCompany> utilityBoard;
    utilityBoard.push_back(electricCompany);
    utilityBoard.push_back(waterWorks);
    setutilBoard(utilityBoard);
    //----------------------------------
    
    //railroads
    vector <int> rentPerPropR1{25,50,100,200};
    Property ShortLine("Short Line",0,200,rentPerPropR1,35);
    
    vector <int> rentPerPropR2{25,50,100,200};
    Property ReadingRailroad("Reading Railroad",0,200,rentPerPropR2,5);
    
    vector <int> rentPerPropR3{25,50,100,200};
    Property PennsylvaniaRailroad("Pennsylvania Railroad",0,200,rentPerPropR3,15);
    
    vector <int> rentPerPropR4{25,50,100,200};
    Property BAndO("B.&.O.",0,200,rentPerPropR4,25);
    
    
    // dice
    Dice dice;
    
    //the board w/ properties
    vector<Property> board = {MediterraneanAvenue,BalticAvenue,ReadingRailroad,OrientalAvenue,VermontAvenue,ConnecticutAvenue,StCharlesPlace,StatesAvenue,VirginiaAvenue,PennsylvaniaRailroad,StJamesPlace,TennesseeAvenue,NewYorkAvenue,KentuckyAvenue,IndianaAvenue,IllinoisAvenue,BAndO,AtlanticAvenue,VentnorAvenue,MarvinGardens,PacificAvenue,NorthCarolinaAvenue,PennsylvaniaAvenue,ShortLine,ParkPlace,BoardWalk};
    
    setBoard(board); //sets board
    
    //setting up players
    vector<Property> p1Properties;
    Player p1("Player 1",1500,0,p1Properties,1);
    p1.setSymbol("~");
    
    vector<Property> p2Properties;
    Player p2("Player 2",1500,0,p2Properties,2);
    p2.setSymbol("*");
    
    //----------------
    //----------------------------
    //THIS IS THE MAIN GAME LOOP
    //----------------------------
    int turn = determineTurn();
    int outerDone = false;
    while(outerDone != true) {
        //while neither player is bankrupt
        while(p1.checkBankrupt() != true || p2.checkBankrupt() != true) {
            // player 1
            if(turn == 1) {
                //displays ui
                displayBoard(p1, p2);
                cout << "\nPLAYER 1's TURN\n" << endl;
                showStats(p1);
                showStats(p2);
                displayMenu();
                //-----------
                //ask user for meny selection
                int menuSelection;
                cin >> menuSelection;
                if(menuSelection == 1) {
                    // -----------------------------------------------
                    //this checks if player is in jail or not
                    if(p1.getJailFlag() == 0) { // not in jail
                        //if player is on a railroad and owns it
                        if((p1.getPosition() == READING_RAILROAD && this->board[2].getOwner() == p1.getSymbol()) || (p1.getPosition() == BANO && this->board[16].getOwner() == p1.getSymbol()) || (p1.getPosition() == PENN_RAILROAD && this->board[9].getOwner() == p1.getSymbol()) || (p1.getPosition() == SHORT_LINE && this->board[23].getOwner() == p1.getSymbol())) {
                            cout << "Would you like to travel to a railroad instead of rolling? y/n" << endl;
                            string answer;
                            cin >> answer;
                            //player travels
                            if(answer == "y" || answer == "Y") {
                                railroadTravel(p1);
                                turn = 2; //player 2 turns
                                break;
                            }
                        }
                        dice.rollDice(); //rolls dice
                        p1.movePosition(dice.getDiceValue()); //moves position with dice value
                        displayBoard(p1, p2);
                        cout << "\nPLAYER 1's TURN\n" << endl;
                        showStats(p1);
                        showStats(p2);
                        displayMenu();
                        //positioning adjustment, cant be greater than 39
                        if(p1.getPosition() > 39) {
                            int temp = p1.getPosition() - 39;
                            p1.setPosition(0 + temp - 1); //sets position
                            
                        }
                        //--------------------------
                        if(checkIfProp(p1) == true && p1.checkBankrupt() == false) { // if player is on property and not bankrupt
                            propActionEvent(p1,p2); // trigger action event for properties
                        }
                        //--------------------------
                        
                        //-------UTILITIES-------------------
                        //same thing but utilties
                        if(p1.getPosition() == 28 || p1.getPosition() == 12) { // waterworks and electrical company
                            utilityActionEvent(p1, p2,dice.getDiceValue());
                        }
                        //-----------------------------------
                        
                        //if player is on income tax tile
                        if(p1.getPosition() == INCOME_TAX) {
                            cout << "\n-----------NOTIFICATION---------------" << endl;
                            cout << p1.getName() << "Landed on Income Tax, pay 200" << endl;
                            cout << "--------------------------------------" << endl;
                            p1.subtractMoney(200);
                        }
                        //if player lands on go tile
                        if(p1.getPosition() == START) {
                            cout << "\n-----------NOTIFICATION---------------" << endl;
                            cout << p1.getName() << "Landed on Go, collect 200" << endl;
                            cout << "--------------------------------------" << endl;
                            p1.addMoney(200);
                        }
                        //if player lands on luxary tax
                        if(p1.getPosition() == LUXARY_TAX) {
                            cout << "\n-----------NOTIFICATION---------------" << endl;
                            cout << p1.getName() << "Landed on Luxary Tax, pay 100" << endl;
                            cout << "--------------------------------------" << endl;
                            p1.subtractMoney(100);
                        }
                        //if player lands on go to jail tile
                        if(p1.getPosition() == JAIL_TWO) {
                            cout << "\n\n-----------NOTIFICATION---------------" << endl;
                            cout << p1.getName() << "'s In Jail, pay 50 dollars" << endl;
                            p1.setPosition(JAIL); //set position to jail
                            p1.setJailFlag(3); // jail flag to 3 turns
                            cout << "---------------------------------------" << endl;
                        }
                        //if player on chance tiles
                        if(p1.getPosition() == CHANCE_ONE || p1.getPosition() == CHANCE_TWO || p1.getPosition() == CHANCE_THREE) {
                            Card chanceCard = displayChanceChest(chance1); //displays card and assigns to chanceCard
                            chanceAction(p1, chanceCard);
                        }
                        //if player on chest tiles
                        if(p1.getPosition() == CHEST_ONE || p1.getPosition() == CHEST_TWO || p1.getPosition() == CHEST_THREE) {
                            Card chestCard = displayCommChest(chest1); //displays card and assigns to chanceCard
                            commAction(p1, chestCard);
                        }
                        //ends loop if player is bankrupt
                        if(p1.checkBankrupt() == true) {
                            break;
                        }
                        
                        turn = 2;
                    }
                    else { // if player is in jail
                        int jailSelection;
                        cout << "--------------------------------------------" << endl;
                        cout << "1) Pay 50 2) try and roll 3 doubles" << endl;
                        cout << "--------------------------------------------" << endl;
                        cin >> jailSelection;
                        if(jailSelection == 1) { //pays 50 bucks
                            cout << "You paid 50 dollars to leave jail" << endl;
                            p1.subtractMoney(50);
                            p1.setJailFlag(0); // jail flag to 0 turns aka off
                        }
                        else {
                            //this is for rolling three times in a row and also subtracts flag to make sure player does not roll more than three turns
                            dice.rollDice();
                            p1.subtractJailFlag();
                            if (dice.getDiceOne() == dice.getDiceTwo()) {
                                dice.rollDice();
                                if (dice.getDiceOne() == dice.getDiceTwo()) {
                                    dice.rollDice();
                                    if (dice.getDiceOne() == dice.getDiceTwo()) {
                                        p1.setJailFlag(0);
                                    }
                                }
                            }//leaves jail
                            if(p1.getJailFlag() == 0) {
                                cout << p1.getName() << " left jail" << endl;
                            }
                            turn = 2; // player 2 turn
                        }
                    }
                }
                else if (menuSelection == 4) {
                    int sel = cheatMenu(p1); // cheat menu returns what person used
                    if (sel == 2) { // sets position which uses the same thing from layout above
                        if(p1.getPosition() > 39) {
                            int temp = p1.getPosition() - 39;
                            p1.setPosition(0 + temp - 1);
                            
                        }
                        //--------------------------
                        if(checkIfProp(p1) == true && p1.checkBankrupt() == false) {
                            propActionEvent(p1,p2);
                        }
                        //--------------------------
                        
                        //-------UTILITIES-------------------
                        if(p1.getPosition() == 28 || p1.getPosition() == 12) { // waterworks
                            utilityActionEvent(p1, p2,dice.getDiceValue());
                        }
                        //-----------------------------------
                        
                        if(p1.getPosition() == INCOME_TAX) {
                            cout << "\n-----------NOTIFICATION---------------" << endl;
                            cout << p1.getName() << "Landed on Income Tax, pay 200" << endl;
                            cout << "--------------------------------------" << endl;
                            p1.subtractMoney(200);
                        }
                        if(p1.getPosition() == START) {
                            cout << "\n-----------NOTIFICATION---------------" << endl;
                            cout << p1.getName() << "Landed on Go, collect 200" << endl;
                            cout << "--------------------------------------" << endl;
                            p1.addMoney(200);
                        }
                        if(p1.getPosition() == LUXARY_TAX) {
                            cout << "\n-----------NOTIFICATION---------------" << endl;
                            cout << p1.getName() << "Landed on Luxary Tax, pay 100" << endl;
                            cout << "--------------------------------------" << endl;
                            p1.subtractMoney(100);
                        }
                        if(p1.getPosition() == JAIL_TWO) {
                            cout << "\n\n-----------NOTIFICATION---------------" << endl;
                            cout << p1.getName() << "'s In Jail, pay 50 dollars" << endl;
                            p1.setPosition(JAIL);
                            p1.setJailFlag(3);
                            cout << "---------------------------------------" << endl;
                        }
                        if(p1.getPosition() == CHANCE_ONE || p1.getPosition() == CHANCE_TWO || p1.getPosition() == CHANCE_THREE) {
                            Card chanceCard = displayChanceChest(chance1); //displays card and assigns to chanceCard
                            chanceAction(p1, chanceCard);
                        }
                        if(p1.getPosition() == CHEST_ONE || p1.getPosition() == CHEST_TWO || p1.getPosition() == CHEST_THREE) {
                            Card chestCard = displayCommChest(chest1); //displays card and assigns to chanceCard
                            commAction(p1, chestCard);
                        }
                        if(p1.checkBankrupt() == true) {
                            break;
                        }
                    }
                }//if user picks property managment
                else if (menuSelection == 3) {
                    propertyManagment(p1);
                }
                else if (menuSelection == 2) { // if player uses trade property
                    tradeProperty(p1, p2);
                }
            }
            //-----------------------------------------
            //       PLAYER 2
            //-----------------------------------------
            else if (turn == 2) {
                //ui
                displayBoard(p1, p2);
                cout << "\nPLAYER 2's TURN\n" << endl;
                showStats(p1);
                showStats(p2);
                displayMenu();
                int menuSelection;
                cin >> menuSelection;
                //--------
                if(menuSelection == 1)
                {
                    dice.rollDice();
                    if(p2.getJailFlag() == 0) { //checks if player in jail
                        //if player is on railroad and owns it
                        if((p2.getPosition() == READING_RAILROAD && this->board[2].getOwner() == p2.getSymbol()) || (p2.getPosition() == BANO && this->board[16].getOwner() == p2.getSymbol()) || (p2.getPosition() == PENN_RAILROAD && this->board[9].getOwner() == p2.getSymbol()) || (p2.getPosition() == SHORT_LINE && this->board[23].getOwner() == p2.getSymbol())) {
                            //if player wants to travel using railroad
                            cout << "Would you like to travel to a railroad instead of rolling? y/n" << endl;
                            string answer;
                            cin >> answer;
                            if(answer == "y" || answer == "Y") {
                                railroadTravel(p2);
                                turn = 1; //sets to player 1
                                break;
                            }
                        }
                        //moves player based on dice value
                        p2.movePosition(dice.getDiceValue());
                        displayBoard(p1, p2);
                        cout << "\nPLAYER 2's TURN\n" << endl;
                        showStats(p1);
                        showStats(p2);
                        displayMenu();
                        //position aligment
                        if(p2.getPosition() > 39) {
                            int temp = p2.getPosition() - 39;
                            p2.setPosition(0 + temp - 1);
                        }
                        //property
                        //-----------------------------
                        if(checkIfProp(p2) == true && p2.checkBankrupt() == false) {
                            propActionEvent(p2,p1);
                        }
                        
                        //-------------------------------
                        
                        //-------UTILITIES-------------------
                        if(p1.getPosition() == 28 || p2.getPosition() == 12) { // waterworks
                            utilityActionEvent(p2, p1,dice.getDiceValue());
                        }
                        //-----------------------------------
                        
                        //if on income tax
                        if(p2.getPosition() == INCOME_TAX) {
                            cout << "\n-----------NOTIFICATION---------------" << endl;
                            cout << p2.getName() << " Landed on Income Tax, pay 200" << endl;
                            cout << "--------------------------------------" << endl;
                            p2.subtractMoney(200);
                        }
                        //if on start
                        if(p2.getPosition() == START) {
                            cout << "\n-----------NOTIFICATION---------------" << endl;
                            cout << p2.getName() << " Landed on Go , collect 200" << endl;
                            cout << "--------------------------------------" << endl;
                            p2.addMoney(200);
                        }
                        //if on luxart tax
                        if(p2.getPosition() == LUXARY_TAX) {
                            cout << "\n-----------NOTIFICATION---------------" << endl;
                            cout << p2.getName() << " Landed on Luxary Tax, pay 100" << endl;
                            cout << " --------------------------------------" << endl;
                            p2.subtractMoney(100);
                        }
                        //if on go to jail tile
                        if(p2.getPosition() == JAIL_TWO) {
                            cout << "\n\n-----------NOTIFICATION---------------" << endl;
                            cout << p2.getName() << "'s In Jail" << endl;
                            p2.setPosition(JAIL);
                            p2.setJailFlag(3);
                            cout << "---------------------------------------" << endl;
                        }
                        //if one chance
                        if(p2.getPosition() == CHANCE_ONE || p2.getPosition() == CHANCE_TWO || p2.getPosition() == CHANCE_THREE) {
                            Card chanceCard = displayChanceChest(chance1); //displays card and assigns to chanceCard
                            chanceAction(p2, chanceCard);
                        }
                        //if one chest
                        if(p2.getPosition() == CHEST_ONE || p2.getPosition() == CHEST_TWO || p2.getPosition() == CHEST_THREE) {
                            Card chestCard = displayCommChest(chest1); //displays card and assigns to chanceCard
                            commAction(p2, chestCard);
                        }
                        if(p2.checkBankrupt() == true) {
                            break;
                        }
                        turn = 1;
                    }
                    else
                    {
                        
                        int jailSelection;
                        cout << "--------------------------------------------" << endl;
                        cout << "1) Pay 50 2) try and roll 3 doubles" << endl;
                        cout << "--------------------------------------------" << endl;
                        cin >> jailSelection;
                        if(jailSelection == 1) {
                            cout << "You paid 50 dollars to leave jail" << endl;
                            p2.subtractMoney(50);
                            p2.setJailFlag(0); // leaves jail
                        }
                        else {
                            dice.rollDice();
                            p2.subtractJailFlag();
                            if (dice.getDiceOne() == dice.getDiceTwo()) {
                                dice.rollDice();
                                if (dice.getDiceOne() == dice.getDiceTwo()) {
                                    dice.rollDice();
                                    if (dice.getDiceOne() == dice.getDiceTwo()) {
                                        p2.setJailFlag(0);
                                    }
                                }
                            }
                            if(p2.getJailFlag() == 0) { // leaves jail
                                cout << p2.getName() << " left jail" << endl;
                            }
                            turn = 1; // player 1 turn
                        }
                    }
                }
                else if (menuSelection == 4)
                {
                    int sel = cheatMenu(p2); // cheats menu, same layout for player 1
                    if (sel == 2) {
                        if(p2.getPosition() > 39) {
                            int temp = p2.getPosition() - 39;
                            p2.setPosition(0 + temp - 1);
                            
                        }
                        //--------------------------
                        if(checkIfProp(p2) == true && p2.checkBankrupt() == false) {
                            propActionEvent(p2,p1);
                        }
                        //--------------------------
                        
                        //-------UTILITIES-------------------
                        if(p1.getPosition() == 28 || p2.getPosition() == 12) { // waterworks
                            utilityActionEvent(p2, p1,dice.getDiceValue());
                        }
                        //-----------------------------------
                        
                        if(p2.getPosition() == INCOME_TAX) {
                            cout << "\n-----------NOTIFICATION---------------" << endl;
                            cout << p2.getName() << "Landed on Income Tax, pay 200" << endl;
                            cout << "--------------------------------------" << endl;
                            p2.subtractMoney(200);
                        }
                        if(p2.getPosition() == START) {
                            cout << "\n-----------NOTIFICATION---------------" << endl;
                            cout << p2.getName() << "Landed on Go, collect 200" << endl;
                            cout << "--------------------------------------" << endl;
                            p2.addMoney(200);
                        }
                        if(p2.getPosition() == LUXARY_TAX) {
                            cout << "\n-----------NOTIFICATION---------------" << endl;
                            cout << p2.getName() << "Landed on Luxary Tax, pay 100" << endl;
                            cout << "--------------------------------------" << endl;
                            p2.subtractMoney(100);
                        }
                        if(p2.getPosition() == JAIL_TWO) {
                            cout << "\n\n-----------NOTIFICATION---------------" << endl;
                            cout << p2.getName() << "'s In Jail, pay 50 dollars" << endl;
                            p2.setPosition(JAIL);
                            p2.setJailFlag(3);
                            cout << "---------------------------------------" << endl;
                        }
                        if(p2.getPosition() == CHANCE_ONE || p2.getPosition() == CHANCE_TWO || p2.getPosition() == CHANCE_THREE) {
                            Card chanceCard = displayChanceChest(chance1); //displays card and assigns to chanceCard
                            chanceAction(p2, chanceCard);
                        }
                        if(p2.getPosition() == CHEST_ONE || p2.getPosition() == CHEST_TWO || p2.getPosition() == CHEST_THREE) {
                            Card chestCard = displayCommChest(chest1); //displays card and assigns to chanceCard
                            commAction(p2, chestCard);
                        }
                        if(p2.checkBankrupt() == true) {
                            break;
                        }
                    }
                }
                else if (menuSelection == 3) { // property managment
                    propertyManagment(p2);
                }
                else if (menuSelection == 2) { // property managment
                    tradeProperty(p2, p1);
                }
            }
        //FOR WHEN PLAYER 1 IS BANKRUPT ---------------------------------------------------------
        }
        if(p1.checkBankrupt() == true)
        {
            
            cout<< "\n|----------------------------------|" << endl;
            cout<< "|            BANKRUPTCY            |" << endl;
            cout<< "|----------------------------------|" << endl;
            
            
            cout << "Uh oh, " <<p1.getName() <<   " you are bankrupt" << endl;
            
            while(p1.getMoney() < 0) { //while money is less than 0
                int selection;
                int propCount = 0;
                int utilCount = 0;
                //checks how many props and utils the player has
                for(Property i : p1.getPropertiesVec()) {
                    propCount++;
                }
                for(ElectricCompany i : p1.getUtilityVec()) {
                    utilCount++;
                }
                //when there is no more props and util to sell and money is under 0
                if(propCount < 1 && utilCount < 1 && p1.getMoney() < 0) {
                    cout << p1.getName() << "\nYou have no properties to mortgage" << endl;
                    cout << "\n\n-----------------------------------------" << endl;
                    cout << p2.getName() << " HAS WON!" << endl;
                    cout << "-----------------------------------------" << endl;
                    outerDone = true; // ends outer loop
                    break; // ends currents loop
                }
                if(p1.getMoney() > 0) { // while money is greater than 0
                    //ends bankruptcy area
                }
                //ui
                cout << "------------------------------------------" << endl;
                cout << "\n\nBank Account: " << p1.getMoney() << endl;
                cout << "Which property would you like to mortgage?" << endl;
                cout << "1) Properties 2) Utilities" << endl;
                cout << "------------------------------------------" << endl;
                cin >> selection;
                
                propCount = 0;
                utilCount = 0;
                if(selection == 1) {// for mortgaging properties
                    int mortgageSelection;
                    cout << "Which Property would you like to mortgage? " << endl;
                    for(Property i : p1.getPropertiesVec()) { //displays properties
                        cout << (propCount + 1) << ": "  << i.getName() << ": Mortgage Value: " << i.getMortgage() << endl;
                        propCount++;
                    }
                    cin >> mortgageSelection;
                    mortgageSelection -= 1;// for indexing
                    //create temp vector with current player properties
                    vector<Property>tempVec = p1.getPropertiesVec();
                    //add money to player based on user property selection mortgage
                    p1.addMoney(tempVec[mortgageSelection].getMortgage());
                    cout << tempVec[mortgageSelection].getName() << " has been mortgaged" << endl;
                    //remove property from player
                    p1.remove(tempVec[mortgageSelection]);
                }
                else if (selection == 2) {
                    //moves through player utilities and displays them
                    for(ElectricCompany i : p1.getUtilityVec()) {
                        cout << (propCount + 1) << ": "  << i.getName() << ": Mortgage Value: " << i.getMortgage() << endl;
                        utilCount++;
                    }
                    if(utilCount < 1) {
                        cout << "You have no utilities" << endl;
                        
                    }
                    else {
                        int mortgageSelection;
                        mortgageSelection -= 1;
                        cout << "Which Utility would you like to mortgage? " << endl;
                        cin >> mortgageSelection;
                        //creates temp vec with current utilities
                        vector<ElectricCompany>tempVec = p1.getUtilityVec();
                        //adds money from utilities mortgage money
                        p1.addMoney(tempVec[mortgageSelection].getMortgage());
                        cout << tempVec[mortgageSelection].getName() << " has been mortgaged" << endl;
                        //remove utility from player
                        p1.remove(tempVec[mortgageSelection]);
                        
                    }
                }
            }
            
        }
        //same thing as player 1 but for player 2
        if(p2.checkBankrupt() == true)
        {
            
            cout<< "\n|----------------------------------|" << endl;
            cout<< "|            BANKRUPTCY            |" << endl;
            cout<< "|----------------------------------|" << endl;
            
            
            cout << "Uh oh, " <<p2.getName() <<   " you are bankrupt" << endl;
            
            while(p2.getMoney() < 0) {
                int selection;
                int propCount = 0;
                int utilCount = 0;
                
                for(Property i : p2.getPropertiesVec()) {
                    propCount++;
                }
                for(ElectricCompany i : p2.getUtilityVec()) {
                    utilCount++;
                }
                
                if(propCount < 1 && utilCount < 1 && p2.getMoney() < 0) {
                    cout << p2.getName() << "\n You have no properties to mortgage" << endl;
                    cout << "\n\n-----------------------------------------" << endl;
                    cout << p1.getName() << " HAS WON!" << endl;
                    cout << "-----------------------------------------" << endl;
                    outerDone = true;
                    break;
                }
                
                cout << "------------------------------------------" << endl;
                cout << "\n\nBank Account: " << p2.getMoney() << endl;
                cout << "Which property would you like to mortgage?" << endl;
                cout << "1) Properties 2) Utilities" << endl;
                cout << "------------------------------------------" << endl;
                cin >> selection;
                
                propCount = 0;
                utilCount = 0;
                if(selection == 1) {
                    int mortgageSelection;
                    
                    cout << "Which Property would you like to mortgage? " << endl;
                    for(Property i : p2.getPropertiesVec()) {
                        cout << (propCount + 1) << ": "  << i.getName() << ": Mortgage Value: " << i.getMortgage() << endl;
                        propCount++;
                    }
                    cin >> mortgageSelection;
                    mortgageSelection -= 1;
                    vector<Property>tempVec = p2.getPropertiesVec();
                    p2.addMoney(tempVec[mortgageSelection].getMortgage());
                    p2.remove(tempVec[mortgageSelection]);
                    cout << tempVec[mortgageSelection].getName() << " has been mortgaged" << endl;
                }
                else if (selection == 2) {
                    for(ElectricCompany i : p2.getUtilityVec()) {
                        cout << (propCount + 1) << ": "  << i.getName() << ": Mortgage Value: " << i.getMortgage() << endl;
                        utilCount++;
                    }
                    if(utilCount < 1) {
                        cout << "You have no utilities" << endl;
                        
                    }
                    else {
                        int mortgageSelection;
                        cout << "Which Utility would you like to mortgage? " << endl;
                        cin >> mortgageSelection;
                        mortgageSelection -= 1;
                        vector<ElectricCompany>tempVec = p2.getUtilityVec();
                        p2.addMoney(tempVec[mortgageSelection].getMortgage());
                        p2.remove(tempVec[mortgageSelection]);
                        cout << tempVec[mortgageSelection].getName() << " has been mortgaged" << endl;
                        
                    }
                }
            }
            
        }
    }
}

//this is the board that constantly checks whether a player is on the tiles position
void game::displayBoard(Player p1, Player p2) {
    cout  << "\t  \t\t\t" << checkPos(p1,p2, 21) << "\t\t\t" << checkPos(p1,p2, 22) << "\t\t\t " << checkPos(p1,p2, 23) << "\t\t\t " << checkPos(p1,p2, 24) << "\t\t\t  " << checkPos(p1,p2, 25) << "\t\t " << checkPos(p1,p2, 26) << "\t\t\t " << checkPos(p1,p2, 27) << "\t\t\t  " << checkPos(p1,p2, 28) << "\t\t  " << checkPos(p1,p2, 29) << "\t\t" << checkPos(p1,p2, 30) << endl;
    cout << "  -------------------------------------------------------------------------------------------------------------------------------------      KEY:" << endl;
    cout << "  |           | Kentucky  |           |  Indiana  |  Illinois |   B.& O.  |  Atlantic |  Ventnor  |   Water   |  Marvin   |   Go to   |      Player 1 = ~" << endl;
    cout << checkPos(p1,p2, 20) <<  "|   free    |  Avenue   |  Chance   |  Avenue   |   Avenue  |  Railroad |   Avenue  |   Avenue  |   Works   |  Gardins  |   Jail    |      Player 2 = *" <<endl;
    cout << "  |  parking  |  ($220)   |           |  ($220)   |   ($240)  |   ($200)  |   ($260)  |   ($260)  |   ($150)  |  ($280)   |           |" << endl;
    cout << "  |___________|___________|___________|___________|___________|___________|___________|___________|___________|___________|___________|"<<  endl;
    cout << "  |    NY     |                                                                                                           |  Pacific  |" << endl;
    cout << checkPos(p1,p2, 19) <<  "|    Ave    |                                                                                                           |    Ave    |" <<checkPos(p1,p2,31)<< endl;
    cout << "  |   ($200)  |                                                                                                           |   ($300)  |" << endl;
    cout << "  |___________|                                                                                                           |___________|" << endl;
    cout << "  |   Tenn.   |                                                                                                           |    N.C    |" << endl;
    cout << checkPos(p1,p2, 18) <<  "|    Ave    |                                                                                                           |    Ave    |" <<checkPos(p1,p2,32)<< endl;
    cout << "  |   ($180)  |                                                                                                           |   ($300)  |" << endl;
    cout << "  |___________|                                                                                                           |___________|" << endl;
    cout << "  |           |                                                                                                           |           |" << endl;
    cout << checkPos(p1,p2, 17) <<  "| Community |                                                                                                           | Community |" << checkPos(p1,p2,33)<<endl;
    cout << "  |   Chest   |                                                                                                           |   Chest   |" << endl;
    cout << "  |___________|                                                                                                           |___________|" << endl;
    cout << "  |  St James |                                                                                                           |    Penn   |" << endl;
    cout << checkPos(p1,p2, 16) <<  "|   ($180)  |                                                                                                           |    Ave    |" << checkPos(p1,p2,34)<<endl;
    cout << "  |           |                                                                                                           |  ($320)   |" << endl;
    cout << "  |___________|                                                                                                           |___________|" << endl;
    cout << "  |   Penn    |                                                                                                           |   Short   |" << endl;
    cout << checkPos(p1,p2, 15) <<  "|  Railroad |                                                                                                           |   Line    |" <<checkPos(p1,p2,35)<< endl;
    cout << "  |   ($200)  |                                                                                                           |   ($200)  |" << endl;
    cout << "  |___________|                                                                                                           |___________|" << endl;
    cout << "  |  Virginia |                                                                                                           |           |" << endl;
    cout << checkPos(p1,p2, 14) <<  "|    Ave    |                                                                                                           |  Chance   |" <<checkPos(p1,p2,36)<< endl;
    cout << "  |   ($140)  |                                                                                                           |           |" << endl;
    cout << "  |___________|                                                                                                           |___________|" << endl;
    cout << "  |  States   |                                                                                                           |   Park    |" << endl;
    cout << checkPos(p1,p2, 13) <<  "|    Ave    |                                                                                                           |   Place   |" <<checkPos(p1,p2,37)<< endl;
    cout << "  |  ($140)   |                                                                                                           |   ($350)  |" << endl;
    cout << "  |___________|                                                                                                           |___________|" << endl;
    cout << "  | Electric  |                                                                                                           |   Luxary  |" << endl;
    cout << checkPos(p1,p2, 12) <<  "|  Company  |                                                                                                           |    Tax    |" <<checkPos(p1,p2,38)<< endl;
    cout << "  |  ($150)   |                                                                                                           |   (-$100) |" << endl;
    cout << "  |___________|                                                                                                           |___________|" << endl;
    cout << "  | St Charles|                                                                                                           | Boardwalk |" << endl;
    cout << checkPos(p1,p2, 11) <<  "|   Place   |                                                                                                           |  ($400)   |" <<checkPos(p1,p2,39)<< endl;
    cout << "  |   ($140)  |                                                                                                           |           |" << endl;
    cout << "  |-----------|-----------------------------------------------------------------------------------------------------------|-----------|" << endl;
    cout << "  |           |    CT     |  Vermont  |           |  Oriental |  Reading  |   Income  |  Baltic   | Community |   Med.    |    Go     |" << endl;
    cout << "  |  Jail/Vis |    Ave    |  Avenue   |  Chance   |    Ave    |  Railroad |    Tax    |   Ave     |   Chest   |   Ave.    |  (+$200)  |" << endl;
    cout << "  |           |   ($120)  |  ($100)   |           |   ($100)  |  ($200)   |  (-$200)  |  ($60)    |           |   ($60)   |           |" << endl;
    cout << "  |___________|___________|___________|___________|___________|___________|___________|___________|___________|___________|___________|" << endl;
    cout << "\t" << checkPos(p1,p2, 10) << "\t\t\t" << checkPos(p1,p2, 9) << "\t\t\t" << checkPos(p1,p2, 8) << "\t\t\t " << checkPos(p1,p2, 7) << "\t\t\t " << checkPos(p1,p2, 6) << "\t\t\t  " << checkPos(p1,p2, 5) << "\t\t " << checkPos(p1,p2, 4) << "\t\t\t " << checkPos(p1,p2, 3) << "\t\t\t  " << checkPos(p1,p2, 2) << "\t\t  " << checkPos(p1,p2, 1) << "\t\t" << checkPos(p1,p2, 0) << endl;
    cout  << "Note: check above board for notifcations" << endl;
};
//shows player properties and money
void game::showStats(Player p) {
    cout << "\n---------------------" << endl;
    p.getProperties();
    p.getUtilities();
    cout << "---------------------" << endl;
    cout << "Money: " << p.getMoney() << endl;
    cout << "---------------------\n" << endl;
}


//this is for property actions
void game::propActionEvent(Player& p,Player& p2) {
    int count = 0;
    int selection;
    //this is for getting the property
    for(Property i : board) {
        if(i.getPos() == p.getPosition()) {
            selection = count;
        }
        count++;
    }
    //if the property is not owned
    if(board[selection].getOwner() == "")
    { //not owned
        //cout << board[selection].getOwner();
        bool done = false;
        while(done != true){
            //ask user if they want to buy
            cout << p.getName() <<", would you like to buy " << board[selection].getName() << " for " << board[selection].getCost()<<"? y/n" << endl;
            string choice;
            cin >> choice;
            if(choice == "y" || choice == "Y") {
                cout << "How many? 1-4" << endl;
                int countChoice;
                cin >> countChoice;
                //checks if buy amount would exceed the 4 max house count
                if (countChoice > 0 && countChoice < 5 && board[selection].getHouseCount() + countChoice < 5) {
                    //checks if player can afford it
                    if (p.getMoney() >= (board[selection].getCost() * countChoice)) {
                        //player buys the board which reassigns the game attributes board to reflect change;
                        board[selection] = p.buy(board[selection], countChoice);
                        done = true;
                    }
                    else {
                        cout << "Not enough money" << endl;;
                    }
                }
                else {
                    cout << "Cannot have more than 4 properties" << endl;
                }
            }
            else {// if player did not want to buy and it turns to auction, theres only two player so it asks the other player
                cout << "--PROPERTY BEING AUCTIONED--" << endl;
                bool innerDone = false;
                while(innerDone != true){
                    //asks if player wants to buy
                    cout << p2.getName() <<", would you like to buy " << board[selection].getName() << " for " << board[selection].getCost()<<"? y/n" << endl;
                    string choice;
                    cin >> choice;
                    if(choice == "y" || choice == "Y") {
                        cout << "How many? 1-4" << endl;
                        int countChoice;
                        cin >> countChoice;
                        //if house count doesnt exceed 4
                        if (countChoice > 0 && countChoice < 5 && board[selection].getHouseCount() + countChoice < 5) {
                            //if player can afford it
                            if (p2.getMoney() >= (board[selection].getCost() * countChoice)) {
                                board[selection] = p2.buy(board[selection], countChoice); //update game attribute board value
                                done = true;
                                innerDone = true;
                            }
                            else {
                                cout << "Not enough money";
                            }
                        }
                        else {
                            cout << "Cannot have more than 4 properties" << endl;
                        }
                    }
                    else {
                        //no one buys the property
                        done = true;
                        innerDone = true;
                    }
                }
                //no one bought this
                if( board[selection].getOwner() =="") {
                    cout << "No one bought this property at auction." << endl;
                    
                }
                done = true;
            }
        }
    }
    //if player lands on an owned property
    else if(board[selection].getOwner() == p2.getSymbol()) {
        cout << "\n----------------------------------------------------------" << endl;
        cout << p.getName() <<" landed on a owned property, must pay " << board[selection].getRentPerProp() << " in rent" << endl;
        cout << "----------------------------------------------------------" << endl;
        //subtracts money from player who lands and gives it to owner
        p.subtractMoney(board[selection].getRentPerProp());
        p2.addMoney(board[selection].getRentPerProp());
        
    }
}

//for utilities
//this is the same as the property action function but is for utilities since they are different classes except for rent setting
void game::utilityActionEvent(Player& p,Player& p2, int dice) {
    
    int count = 0;
    int selection;
    for(ElectricCompany i : utilityBoard) {
        if(i.getPos() == p.getPosition()) {
            selection = count;
        }
        count++;
    }
    cout << "\n" << endl;
    if(utilityBoard[selection].getOwner() == "")
    { //not owned
        cout << utilityBoard[selection].getOwner();
        bool done = false;
        while(done != true){
            cout << p.getName() <<", would you like to buy " << utilityBoard[selection].getName() << " for " << utilityBoard[selection].getCost()<<"? y/n" << endl;
            string choice;
            cin >> choice;
            if(choice == "y" || choice == "Y") {
                cout << "How many? 1 or 2" << endl;
                int countChoice;
                cin >> countChoice;
                if (countChoice > 0 && countChoice < 3 && utilityBoard[selection].getHouseCount() + countChoice < 3) {
                    if (p.getMoney() >= (utilityBoard[selection].getCost() * countChoice)) {
                        utilityBoard[selection] = p.buy(utilityBoard[selection], countChoice);
                        utilityBoard[selection].setDice(dice);
                        utilityBoard[selection].setRent();
                        cout << "ELECTRIC COMPAMY RENT: " << utilityBoard[selection].getRent();
                        done = true;
                    }
                    else {
                        cout << "Not enough money";
                    }
                }
                else {
                    cout << "Cannot have more than 2 properties" << endl;
                }
            }
            else {
                cout << "--PROPERTY BEING AUCTIONED--" << endl;
                bool innerDone = false;
                while(innerDone != true){
                    cout << p2.getName() <<", would you like to buy " << utilityBoard[selection].getName() << " for " << utilityBoard[selection].getCost()<<"? y/n" << endl;
                    string choice;
                    cin >> choice;
                    if(choice == "y" || choice == "Y") {
                        cout << "How many? 1 or 2" << endl;
                        int countChoice;
                        cin >> countChoice;
                        if (countChoice > 0 && countChoice < 3 && utilityBoard[selection].getHouseCount() + countChoice < 3) {
                            if (p2.getMoney() >= (utilityBoard[selection].getCost() * countChoice)) {
                                //this sets the rent since rent is based on dice rolled value
                                utilityBoard[selection] = p2.buy(utilityBoard[selection], countChoice);
                                utilityBoard[selection].setDice(dice);
                                utilityBoard[selection].setRent();
                                done = true;
                                innerDone = true;
                            }
                            else {
                                cout << "Not enough money";
                            }
                        }
                        else {
                            cout << "Cannot have more than 2 properties" << endl;
                        }
                    }
                    else {
                        done = true;
                        innerDone = true;
                    }
                }
                if( utilityBoard[selection].getOwner() =="") {
                    cout << "No one bought this property at auction." << endl;
                    
                }
                done = true;
            }
        }
    }
    else if(utilityBoard[selection].getOwner() == p2.getSymbol()) {
        utilityBoard[selection].setDice(dice);
        utilityBoard[selection].setRent();
        cout << "\n----------------------------------------------------------" << endl;
        cout << p.getName() <<" landed on a owned property, must pay " << utilityBoard[selection].getRent() << " in rent" << endl;
        cout << "----------------------------------------------------------" << endl;
        p.subtractMoney(utilityBoard[selection].getRent());
        p2.addMoney(utilityBoard[selection].getRent());
        
    }
}


//FOR COMMUNITY CHEST -----------------------------
//gets a random community card and returns the card
Card displayCommChest(CommunityChest chest) {
    cout << "\n-----------------------------------------" << endl;
    cout << "Community Card: " << endl;
    Card curCard = chest.getCard();
    cout << curCard.getDescription() << endl;
    cout << "-----------------------------------------" << endl;
    return curCard;
}
//goes through each card name and determines what it does
void commAction(Player& p, Card commCard) {
    if(commCard.getName() == "c1") {
        p.setPosition(JAIL);
        p.setJailFlag(3);
    }
    else if(commCard.getName() == "c2") {
        p.subtractMoney(15);
    }
    else if(commCard.getName() == "c3") {
    }
    else if(commCard.getName() == "c4") {
        p.addMoney(60);
    }
    else if(commCard.getName() == "c5") {
        p.addMoney(150);
    }
    else if(commCard.getName() == "c6") {
        p.subtractMoney(50);
    }
    else if(commCard.getName() == "c7") {
        p.addMoney(200);
    }
    else if(commCard.getName() == "c8") {
        p.setPosition(0);
        p.addMoney(200);
    }
    else if(commCard.getName() == "c9") {
        p.addMoney(10);
    }
    else if(commCard.getName() == "c10") {
        p.subtractMoney(50);
    }
}
//---------------------------------------------------


//FOR THE CHANCE CARDs---------------------------------
//picks a random chance card and returns it
Card displayChanceChest(Chance chance) {
    cout << "\n-----------------------------------------" << endl;
    cout << "Chance Card: " << endl;
    Card curCard = chance.getCard();
    cout << curCard.getDescription() << endl;
    cout << "-----------------------------------------" << endl;
    return curCard;

}

//determines what each card does and how it affects the player
void chanceAction(Player& p, Card chanceCard) {
    if (chanceCard.getName() == "ch1") {
        p.setPosition(JAIL);
        p.setJailFlag(3);
    }
    else if (chanceCard.getName() == "ch2") {
        p.addMoney(100);
    }
    else if (chanceCard.getName() == "ch3") {
        p.setPosition(p.getPosition() - 3);
    }
    else if (chanceCard.getName() == "ch4") {
        p.subtractMoney(150);
    }
    else if (chanceCard.getName() == "ch5") {
        p.subtractMoney(150);
    }
    else if (chanceCard.getName() == "ch6") {
        p.addMoney(40);
    }



}
//------------------------------------------------------
//checks whether the player is on a property
bool checkIfProp(Player p) {
    if(p.getPosition() == ELECTRIC_COMPANY || p.getPosition() == WATER_WORKS || p.getPosition() == CHANCE_ONE || p.getPosition() == CHANCE_TWO || p.getPosition() == CHANCE_THREE || p.getPosition() == CHEST_ONE || p.getPosition() == CHEST_TWO || p.getPosition() == CHEST_THREE || p.getPosition() == START || p.getPosition() == LUXARY_TAX || p.getPosition() == INCOME_TAX || p.getPosition() == JAIL || p.getPosition() == JAIL_TWO || p.getPosition() == FREE_PARKING) {
        cout << "returns false," << p.getPosition();
        return false;
    }
    else {
        return true;
    }
}
//determines who foes first
int determineTurn(){
    srand(time(0));
    
    int pTurn = rand()%2+1;
    return pTurn;
}
//moves player
void movePlayer(Player p, int num) {
    p.movePosition(num);
}
//displays menu choice
void displayMenu() {
    cout << "|--------|---------|---------------------|----------|" << endl;
    cout << "|1) move |2) trade |3) property managment|4) cheats |"  << endl;
    cout << "|--------|---------|---------------------|----------|" << endl;
}
//checks the players position for the board and outputs the correct formatting
string checkPos(Player p1, Player p2, int pos) {
    string rt = "";
    if(p1.getPosition() == pos && p2.getPosition() != pos) { // if p1 is on and p1 is not
        rt = " ";
        rt += p1.getSymbol();
    }
    if(p2.getPosition() == pos && p1.getPosition() != pos) {//if p2 is on and p1 is not
        rt = " ";
        rt += p2.getSymbol();
    }
    if(p2.getPosition() != pos && p1.getPosition() != pos) { // if neither are on
        rt = "  ";
    }
    if(p2.getPosition() == pos && p1.getPosition() == pos) { // if both are on
        rt += p1.getSymbol();
        rt += p2.getSymbol();
    }
    return rt;
}
//sets the game board for properties
void game::setBoard(vector<Property>& board) {
    this->board = board;
}
//sets the utility board for game
void game::setutilBoard(vector<ElectricCompany> uboard) {
    this->utilityBoard = uboard;
}
//railroad travel
void game::railroadTravel(Player& p) {
    bool done = false;
    while(done != true) {
        int selection;
        //ask user for railroad choice to travel to
        cout << "WHICH RAILROAD WOULD YOU LIKE TO TRAVEL TO?" << endl;
        cout << "1) ShortLine 2) Penn 3) Reading railroad 4) B&O 5) exit" << endl;
        cin >> selection;
        if(selection == 1) {
            selection = SHORT_LINE;
        }
        else if(selection == 2) {
            selection = PENN_RAILROAD;
        }
        else if(selection == 3) {
            selection = READING_RAILROAD;
        }
        else if(selection == 4) {
            selection = BANO;
        }
        else if(selection == 5) {
            done = true;
        }
        //if player owns the railroad they want to travel to, and checks if it is not the current railroad they are on
        if(p.getPosition() != selection) {
            for(Property i : board) {
                if(i.getPos() == selection) {
                    if(i.getOwner() == p.getSymbol()) {
                        p.setPosition(selection); // sets position
                        done = true;
                    }
                    else {
                        cout << "You do not own this property" << endl;
                    }
                }
            }
        }
        else {
            cout << "You are already on this property" << endl;
        }
    }
}
//cheat menu
int cheatMenu(Player& p) {
    cout << "|------------|--------------|" << endl;
    cout << "|1) set money|2)set position|" << endl;
    cout << "|------------|--------------|" << endl;
    int selection;
    cin >> selection;
    if(selection == 1) { // sets user money
        int amount;
        cout << "Set amount: " << endl;
        cin >> amount;
        p.setMoney(amount);
        return 1;
    }
    else if (selection == 2) { //sets user position
        int pos;
        cout << "Set position, 1-40" << endl; // dont need to verify because it will automatically in play
        cin >> pos;
        p.setPosition(pos);
        return 2;
    }
    else {
        return 0;
    }
}
//for managaging your properties
void game::propertyManagment(Player& p) {
    cout << "|---------------------|----------------|" << endl;
    cout << "|1) mortgage property |2) buy property |" << endl;
    cout << "|---------------------|----------------|" << endl;
    int selection;
    cin >> selection;
    if(selection == 1) {//mortgage
        cout << "1) Property 2) Utilities" << endl; //ask for property or utility
        int innerSelection;
        cin >> innerSelection;
        int mortgageSelection;
        int propCount = 0;
        if (innerSelection == 1) { // if user answer property
            for(Property i : p.getPropertiesVec()) { // moves through property and displays name and mortagage amount
                cout << (propCount + 1) << ": "  << i.getName() << ": Mortgage Value: " << i.getMortgage() << endl;
                propCount++;
            }
            if(propCount > 0) { // if they have actual property
                cin >> mortgageSelection;
                mortgageSelection -= 1; //indexing
                //create temp vector with players current properties
                vector<Property>tempVec = p.getPropertiesVec();
                //add mortgage amount to player
                p.addMoney(tempVec[mortgageSelection].getMortgage());
                cout << tempVec[mortgageSelection].getName() << " has been mortgaged" << endl;
                //remove it from players inventory
                p.remove(tempVec[mortgageSelection]);
            }
            else {
                cout << "No properties owned" << endl;
            }
        }
        //does the same thing as properties but with utilities
        else if (innerSelection == 2) {
            int propCount = 0;
            for(ElectricCompany i : p.getUtilityVec()) {
                cout << (propCount + 1) << ": "  << i.getName() << ": Mortgage Value: " << i.getMortgage() << endl;
                propCount++;
            }
            if(propCount > 0) {
                cin >> mortgageSelection;
                mortgageSelection -= 1;
                vector<ElectricCompany>tempVec = p.getUtilityVec();
                p.addMoney(tempVec[mortgageSelection].getMortgage());
                cout << tempVec[mortgageSelection].getName() << " has been mortgaged" << endl;
                p.remove(tempVec[mortgageSelection]);
            }
            else {
                cout << "No utilities owned" << endl;
            }
        }
    }
    //for buying more owned properties
    else if(selection == 2) {
        //if they want to buy more props or utils
        cout << "1) Property 2) Utilities" << endl;
        int innerSelection;
        cin >> innerSelection;
        int buySelection;
        int propCount = 0;
        //if props
        if (innerSelection == 1) {
            //moves through players owned props and displays their info
            for(Property i : p.getPropertiesVec()) {
                cout << (propCount + 1) << ": "  << i.getName() << ": House Count: " << i.getHouseCount() << endl;
                propCount++;
            }
            if(propCount > 0) { // if they have property
                //ask user for which prop
                cin >> buySelection;
                buySelection -= 1;//indexing
                //creates tempvector for current owned props
                vector<Property>tempVec = p.getPropertiesVec();
                //if current property choice is less than max
                if(tempVec[buySelection].getHouseCount() < 4) {
                    //ask user for how much
                    cout << "How many would you like to buy? (" << tempVec[buySelection].getCost() << " per house)" << endl;
                    int buyCount;
                    cin >> buyCount;
                    /*
                    cout << tempVec[buySelection].getName() << endl;
                    cout << propCount << endl;
                    for(Property i : tempVec) {
                        cout << i.getName() << endl;
                    }
                     */
                    if ((tempVec[buySelection].getHouseCount() + buyCount) > 4) { // if user wants to buy more than is acceptable
                        cout << "Total house count cannot be greater than 4" << endl;
                    }
                    else {
                        if((tempVec[buySelection].getCost() * buyCount) > p.getMoney()) { // not enough money to buy
                            cout << "You do not have enough money" << endl;
                        }
                        else {
                            //sets the props house count
                            tempVec[buySelection].setHouseCount(buyCount);
                            //reassigns current property vector
                            p.setProperty(tempVec);
                            //subtract money from the user account
                            p.subtractMoney((tempVec[buySelection].getCost()) * buyCount);
                            cout << "\nBought more " << tempVec[buySelection].getName() << endl;
                        }
                    }
                }
            }
            else {
                cout << "No properties owned" << endl;
            }
        }
        //same thing as properties but with utilities
        else if (innerSelection == 2) {
            int propCount = 0;
            for(ElectricCompany i : p.getUtilityVec()) {
                cout << (propCount + 1) << ": "  << i.getName() << ": House Count: " << i.getHouseCount() << endl;
                propCount++;
            }
            if(propCount > 0) {
                cin >> buySelection;
                buySelection -= 1;
                vector<ElectricCompany>tempVec = p.getUtilityVec();
                if(tempVec[buySelection].getHouseCount() < 4) {
                    cout << "How many would you like to buy? (" << tempVec[buySelection].getCost() << " per house)" << endl;
                    int buyCount;
                    cin >> buyCount;
                    /*
                    cout << tempVec[buySelection].getName() << endl;
                    cout << propCount << endl;
                    for(ElectricCompany i : tempVec) {
                        cout << i.getName() << endl;
                    }
                     */
                    
                    if ((tempVec[buySelection].getHouseCount() + buyCount) > 4) {
                        cout << "Total house count cannot be greater than 4" << endl;
                    }
                    else {
                        if((tempVec[buySelection].getCost() * buyCount) > p.getMoney()) {
                            cout << "You do not have enough money" << endl;
                        }
                        else {
                            tempVec[buySelection].setHouseCount(buyCount);
                            p.setUtilities(tempVec);
                            p.subtractMoney((tempVec[buySelection].getCost()) * buyCount);
                            cout << "\nBought more " << tempVec[buySelection].getName() << endl;
                        }
                    }
                }
            }
            else {
                cout << "No utilities owned" << endl;
            }
        }
    }
    else {
        cout << "Not a valid option" << endl;
    }
}
//if players want to trade property
void game::tradeProperty(Player& p1,Player& p2) {
    //ask if player two wants to trade with player 1
    cout << p2.getName() << " would you like to trade with " << p1.getName() << "? y/n" << endl;
    string answer;
    cin >> answer;
    //these are meant to hold the trade packages
    //player 1
    vector<Property> p1Prop;
    vector<ElectricCompany> p1Utilities;
    
    //player 2
    vector<Property> p2Prop;
    vector<ElectricCompany> p2Utilities;
    //---------------------------------
    bool p1Done = false;
    bool p2Done = false;
    bool tradeDone = false;
    
    if(answer == "y" || answer == "Y")
    {
        while(tradeDone != true){
            while(p1Done != true){
                //displays current user packages-------------------------------
                //player 1
                cout << p1.getName() << "'s Current Package:" << endl;
                cout << "|--------------------------------------|" << endl;
                for(Property i : p1Prop) {
                    cout << i.getName() << endl;
                }
                for(ElectricCompany i : p1Utilities) {
                    cout << i.getName() << endl;
                }
                cout << "|--------------------------------------|\n" << endl;
                //plAYER 2
                cout << p2.getName() << "'s Current Package:" << endl;
                cout << "|--------------------------------------|" << endl;
                for(Property i : p2Prop) {
                    cout << i.getName() << endl;
                }
                for(ElectricCompany i : p2Utilities) {
                    cout << i.getName() << endl;
                }
                cout << "|--------------------------------------|" << endl;
                //---------------------------------------------------------

                cout << p1.getName() << ", 1) property 2) utilities 3) remove an offer 4) end offer" << endl;
                int selection;
                cin >> selection;
                if(selection == 1) { // adds property to trade package
                    cout << p1.getName() << ", add to your trade package" << endl;
                    int count = 0;
                    //create temp vector of current owned properties
                    vector<Property> tempVec = p1.getPropertiesVec();
                    for(Property i : tempVec) {
                        //displays the info
                        cout << (count + 1) << ": "  << i.getName() << ": House Count: " << i.getHouseCount() << endl;
                        count++;
                    }
                    if(count == 0) { // if player has not properties
                        cout << "No properties" << endl;
                    }
                    else {
                        int propSelection;
                        cin >>propSelection;
                        propSelection -= 1;//indexing
                        
                        bool alreadyIn = false;
                        //checks if player is trying to add a property that is already in the trade package
                        for(Property i : p1Prop) {
                            if(i.getName() == tempVec[propSelection].getName()) {
                                alreadyIn = true;
                            }
                        }
                        //if it is
                        if(alreadyIn == true) {
                            cout << "Already in your trade package" << endl;
                        }
                        else {
                            //adds property to player 1 property trade package
                            p1Prop.push_back(tempVec[propSelection]);
                            cout << "Added " << tempVec[propSelection].getName() << " to trade package" << endl;
                        }
                    }
                }
                //does the same thing as property but for utilities
                else if(selection == 2) {
                    cout << p1.getName() << ", add to your trade package" << endl;
                    int count = 0;
                    vector<ElectricCompany> tempVec = p1.getUtilityVec();
                    for(ElectricCompany i : tempVec) {
                        cout << (count + 1) << ": "  << i.getName() << ": House Count: " << i.getHouseCount() << endl;
                        count++;
                    }
                    if(count == 0) {
                        cout << "No properties" << endl;
                    }
                    else {
                        int propSelection;
                        cin >>propSelection;
                        propSelection -= 1;
                        bool alreadyIn = false;
                        for(ElectricCompany i : p1Utilities) {
                            if(i.getName() == tempVec[propSelection].getName()) {
                                alreadyIn = true;
                            }
                        }
                        if(alreadyIn == true) {
                            cout << "Already in your trade package" << endl;
                        }
                        else {
                            p1Utilities.push_back(tempVec[propSelection]);
                            cout << "Added " << tempVec[propSelection].getName() << " to trade package" << endl;
                        }
                    }
                }
                //for if player wants to remove a property or utility from the trade package
                else if (selection == 3) {
                    //displays------------------------
                    cout << p1.getName() << "'s Current Package:" << endl;
                    cout << "|--------------------------------------|" << endl;
                    for(Property i : p1Prop) {
                        cout << i.getName() << endl;
                    }
                    for(ElectricCompany i : p1Utilities) {
                        cout << i.getName() << endl;
                    }
                    cout << "|--------------------------------------|" << endl;
                    //------------------------------------------------
                    cout << "Enter name of property you want to remove, type exactly as shown" << endl;
                    string removeSelection;
                    cin.ignore();
                    getline(cin,removeSelection);
                    //gets line from player and ignores the \n in the thread
                    
                    int count = 0;
                    for(Property i : p1Prop) {
                        //goes through player 1 property list and if the names match
                        if(i.getName() == removeSelection) {
                            //remove from player 1 property trade package
                            p1Prop.erase((p1Prop.begin()) + count);
                            cout << "Property Erased" << endl;
                        }
                        count++;
                    }
                    int utilCount = 0;
                    //checks if the desired prop to be removed is in the utility trade package
                    for(ElectricCompany i : p1Utilities) {
                        if(i.getName() == removeSelection) {
                            //removes from utility player 1 trade package
                            p1Utilities.erase((p1Utilities.begin()) + utilCount);
                            cout << "Property Erased" << endl;
                        }
                        utilCount++;
                    }
                }
                //ends current offer and switches to other player for their offer
                else if(selection == 4)
                {
                    p1Done = true; // ends player 1
                    while(p2Done != true){
                        //displays current package-------------
                        cout << p1.getName() << "'s Current Package:" << endl;
                        cout << "|--------------------------------------|" << endl;
                        for(Property i : p1Prop) {
                            cout << i.getName() << endl;
                        }
                        for(ElectricCompany i : p1Utilities) {
                            cout << i.getName() << endl;
                        }
                        cout << "|--------------------------------------|\n" << endl;
                        
                        cout << p2.getName() << "'s Current Package:" << endl;
                        cout << "|--------------------------------------|" << endl;
                        for(Property i : p2Prop) {
                            cout << i.getName() << endl;
                        }
                        for(ElectricCompany i : p2Utilities) {
                            cout << i.getName() << endl;
                        }
                        cout << "|--------------------------------------|" << endl;
                        //--------------------------------------------------------
                        
                        cout << p2.getName() << ", 1) property 2) utilities 3) remove an offer 4) end offer" << endl;
                        int selection;
                        cin >> selection;
                        if(selection == 1) {
                            cout << p2.getName() << ", add to your trade package" << endl;
                            int count = 0;
                            vector<Property> tempVec = p2.getPropertiesVec();
                            //creates temp vector of player 2 properties and moves through them and displays them
                            for(Property i : tempVec) {
                                cout << (count + 1) << ": "  << i.getName() << ": House Count: " << i.getHouseCount() << endl;
                                count++;
                            }
                            if(count == 0) { // player 2 has no props
                                cout << "No properties" << endl;
                            }
                            else {
                                
                                int propSelection;
                                cin >>propSelection;
                                propSelection -= 1;
                                bool alreadyIn = false;
                                //checks if property is already in the trade package
                                for(Property i : p2Prop) {
                                    if(i.getName() == tempVec[propSelection].getName()) {
                                        alreadyIn = true;
                                    }
                                }
                                if(alreadyIn == true) {
                                    cout << "Already in your trade package" << endl;
                                }
                                else {//if its not in the trade package already
                                    //add to player 2 property trade package
                                    p2Prop.push_back(tempVec[propSelection]);
                                    cout << "Added " << tempVec[propSelection].getName() << " to trade package" << endl;
                                }
                            }
                        }
                        //same thing as property trade package above but for utilities
                        else if(selection == 2) {
                            cout << p2.getName() << ", add to your trade package" << endl;
                            int count = 0;
                            vector<ElectricCompany> tempVec = p2.getUtilityVec();
                            for(ElectricCompany i : tempVec) {
                                cout << (count + 1) << ": "  << i.getName() << ": House Count: " << i.getHouseCount() << endl;
                                count++;
                            }
                            if(count == 0) {
                                cout << "No properties" << endl;
                            }
                            else {
                                int propSelection;
                                cin >>propSelection;
                                propSelection -= 1;
                                bool alreadyIn = false;
                                for(ElectricCompany i : p2Utilities) {
                                    if(i.getName() == tempVec[propSelection].getName()) {
                                        alreadyIn = true;
                                    }
                                }
                                if(alreadyIn == true) {
                                    cout << "Already in your trade package" << endl;
                                }
                                else {
                                    p2Utilities.push_back(tempVec[propSelection]);
                                    cout << "Added " << tempVec[propSelection].getName() << " to trade package" << endl;
                                }
                            }
                        }
                        //for removing a package from player 2's current package
                        else if (selection == 3) {
                            //displays------------------------------------------------
                            cout << p2.getName() << "'s Current Package:" << endl;
                            cout << "|--------------------------------------|" << endl;
                            for(Property i : p2Prop) {
                                cout << i.getName() << endl;
                            }
                            for(ElectricCompany i : p1Utilities) {
                                cout << i.getName() << endl;
                            }
                            cout << "|--------------------------------------|" << endl;
                            //displays---------------------------------------------
                            cout << "Enter name of property you want to remove, type exactly as shown" << endl;
                            
                            //ask user for which property they want to remove
                            string removeSelection;
                            //grab line and ignores the \n
                            cin.ignore();
                            getline(cin,removeSelection);
                            
                            int count = 0;
                            //if the name matches in the player 2 current property, remove it
                            for(Property i : p2Prop) {
                                if(i.getName() == removeSelection) {
                                    p2Prop.erase((p2Prop.begin()) + count);
                                    cout << "Property Erased" << endl;
                                }
                                count++;
                            }
                            int utilCount = 0;
                            //checks if the prop is in the utility vec and removes it
                            for(ElectricCompany i : p2Utilities) {
                                if(i.getName() == removeSelection) {
                                    p2Utilities.erase((p2Utilities.begin()) + utilCount);
                                    cout << "Property Erased" << endl;
                                }
                                utilCount++;
                            }
                        }
                        else if(selection == 4) { // ends offer
                            p2Done = true;
                        }
                    }
                }
            }
            cout << p1.getName() << ", are you ok with this deal? y/n" << endl;
            string p1Confirmation;
            cin >> p1Confirmation;
            //if player 1 says no
            if(p1Confirmation == "n" || p1Confirmation == "N") {
                //redo whole trade function
                p1Done = false;
                p2Done = false;
            }
            //asks player 2
            cout << p2.getName() << ", are you ok with this deal? y/n" << endl;
            string p2Confirmation;
            cin >> p2Confirmation;
            //if not ok, redos the whole trade func
            if(p2Confirmation == "n" || p2Confirmation == "N") {
                p2Done = false;
                p1Done = false;
            }
            //if both say yes
            if((p1Confirmation == "y" || p1Confirmation == "Y") && (p2Confirmation == "Y" || p2Confirmation == "y") ) {
                tradeDone = true;
                
                //adds player props and utilites to each other props and utils properties
                for(Property i : p1Prop) {
                    p2.addProperty(i);
                    p1.remove(i);
                }
                for(ElectricCompany i : p1Utilities) {
                    p2.addProperty(i);
                    p1.remove(i);
                }
                for(Property i : p2Prop) {
                    p1.addProperty(i);
                    p2.remove(i);
                }
                for(ElectricCompany i : p2Utilities) {
                    p1.addProperty(i);
                    p2.remove(i);
                }
                
                cout << "Trade successful" << endl;
            }
        }
    }
    else {// if player declines offer
        cout << p2.getName() << " declined the offer" << endl;
    }
}
