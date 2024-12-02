// russian_roulette_final.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <cmath>
#include <ostream>
#include <fstream>
#include <vector>
#include <iostream>
#include <string>
#include "russian_roulette_header.h" 
#include <random>

// want to have random amount of blank shots, and random amount of real shots. at least 1 real shot should be avalible every round
// each player starts with 3 lives. 
// trick list: 1--> double damage: player does double damage on next shot (if its a real shot) 2--> peek: peek what the next round is, blank or real 3--> reload: reloads the magazine to a new set of random blanks or real rounds
// trick list continued: 4--> Vodka Shot: adds a life to player 5--> Steal: steal an item from enemy player  6--> Scare: cause the opposing player to misfire. 


using namespace std;



void display_rules() {
    cout << "Rules:" << endl;
    cout << "You have 3 lives, computer has 4" << endl;
    cout << "You can use the gun on yourself if you think its a blank, and if it is ~BONUS 150 CASH~" << endl;
    cout << "You can point the gun at the other player if you think its hot, and deal them 1 point of damage." << endl;
    cout << "The winning player can choose the following:" << endl;
    cout << "1. Quit and save their score." << endl;
    cout << "2. Continue to play and earn more money." << endl;
    cout << "Those are the rules. try not to die by the way. We dont like cleaning up around here. " << endl;
    cout << "-------------------------------------------------------------------------------------------------------------------" << endl; 
}
void display_menu(Player& player1) {
    int playerchoice;
    while (true){
        cout << "-----------------------------------------------" << endl;
        cout << "PLAYER MENU" << endl; 
        cout << "------------" << endl;
        cout << "Type 1:  for player info." << endl;
        cout << "Type 2:  for rules." << endl;
        cout << "Type 3: for leaderboard info" << endl; 
        cout << "Any other number to continue." << endl;
        cout << "----------------------------------------------" << endl;
        cin >> playerchoice;
        switch (playerchoice) {
        case 1:
            player1.displayInfo();
            break;
        case 2:
            display_rules();
            break;
        case 3:
            Player:: display_leaderboard();
            break;

        default:
            return;
        } 
    }
}
void roulette(Player& player1, Computer& computer1) {
    cout << "Player always goes first." << endl; 

    while (player1.getHealth() > 0 && computer1.getHealth() > 0) {
        cout << "  Your Health: " << player1.getHealth() << "  COMPUTER Health: " << computer1.getHealth() << endl;
        cout << "----------------------------------------------------" << endl;
        //---- player goes first. then computer. -- //
        int choice;
        int shot = 0;
        cout << "Do you want to shoot opponent (type 1) or shoot yourself? (type 2)" << endl;
        cin >> choice;
        if (choice == 1) {
            if (shot % 2 != 0) {
                cout << "BLANK! No damage to the opponent." << endl;
            }
            else {
                cout << "HOT! You dealt 1 damage to the computer." << endl;
                computer1.setHealth(computer1.getHealth() - 1); // Deal 1 damage to the computer
            }
        }
        else if (choice == 2) {
            if (shot % 2 != 0) {
                cout << "BLANK! No damage to yourself." << endl;
                cout << "You are rewarded for bravery.." << endl;
                player1.add_cash(150);
                cout << "Cash: " << player1.checkCash() << endl; 

            }
            else {
                cout << "HOT! You dealt 1 damage to yourself." << endl;
                player1.setHealth(player1.getHealth() - 1); // Deal 1 damage to the player
                cout << "Remaining health: " << player1.getHealth() << endl;
            }
        }
        else {
            cout << "Remeber, only type 1 or 2. This means you missed your turn!" << endl;
        }
        if (computer1.getHealth() <= 0) {
            cout << "The computer has been eliminated!" << endl;
            player1.add_cash(100);
            cout << "New Cash Total: " << player1.checkCash() << endl;
            break;
        }
        // COMPUTER TURN----//
        cout << "Computer's Turn! Remember, it will always take a shot at you." << endl;
        shot = rand() % 6 + 1; 

        if (shot % 2 != 0) {
            cout << "BLANK! No damage." << endl;
        }
        else {
            cout << "HOT! The computer dealt 1 damage to you!" << endl;
            player1.setHealth(player1.getHealth() - 1); 
            cout << "Remaining Health: " << player1.getHealth() << endl;
        }
        if (player1.getHealth() <= 0) {
            cout << "You have been defeated! The computer wins!" << endl;
            cout << display_skull() << endl;
            cout << "-------------------------------------------------------------------------------" << endl;
            cout << "Final Results: " << endl;
            cout << "Total Cash: " << player1.checkCash() << endl;
            break;
        }



    }


}

///------------------------------------------------------creating more space to organize my code--------------------------------------------------------------------------///
void show_leaderboard() {
    Player::display_leaderboard();
}
void play_game(Player& player1) {
    bool playgame = true;
    int round = 1;
    while (playgame) {
        
        string computername;
        Computer computer1("THE COMPUTER", 4, false);
        cout << "Round: " << round << endl;
        cout << "Your opponent is " << computer1.getName() << endl;
        cout << "With " << computer1.getHealth() << " lives remaining." << endl;
        roulette(player1, computer1);

        if (computer1.getHealth() <= 0) {
            cout << "You defeated the computer! Well done!" << endl;
        }

        string choice;
        cout << "Do you want to play again? (yes/no): ";
        cin >> choice;
        // this will increment the round -- allowing thee player to see how many rounds they came //
        if (choice == "yes" || choice == "Yes") {
            round++;  
            player1.resetHealth();  

            cout << "Starting next round..." << endl;
        }
        else {
            cout << "Thank you for playing. TOTAL RESULTS:" << endl;
            cout << "Cash: " << player1.checkCash() << endl;
            cout << "Round:" << round << endl;
            cout << "-------------------------------------" << endl; 
            Player::save_leaderboard(player1);
            show_leaderboard(); 

            playgame = false;  
        }

    }
}
int main()
{ 
    srand(time(0));
    //seed//
    //initializing player class for player 1. 

   string playername;  
   Player player1(playername, 3, 0, false);
   
    
    cout << display_start()  << endl;
    cout << "WELCOME TO RUSSIAN ROULETTE! First things first: please type in your name : " << endl;
    cin >> playername;
    player1.setName(playername);     
    display_menu(player1);
    play_game(player1);

    
   
 return 0;
    

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
