#pragma once
#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>
#include <algorithm>

using namespace std; 
// string print functions held in header. 
string display_start() {
    return
        ".______       __    __       _______.     _______. __       ___      .__   __.    .______        ______    __    __   __       _______ .___________.___________. _______ \n"
        "|   _  \\     |  |  |  |     *       |    *       ||  |     /   \\     |  \\ |  |    |   _  \\      *  __  \\  |  |  |  | |  |     |   ____||           |           ||   ____|\n"
        "|  |_)  |    |  |  |  |    |   (----`   |   (----`|  |    /  ^  \\    |   \\|  |    |  |_)  |    |  |  |  | |  |  |  | |  |     |  |__   `---|  |----`---|  |----`|  |__   \n"
        "|      /     |  |  |  |     \\   \\        \\   \\    |  |   /  /_\\  \\   |  . `  |    |      /     |  |  |  | |  |  |  | |  |     |   __|      |  |        |  |     |   __|  \n"
        "|  |\\  \\----.|  `--'  | .----)   |   .----)   |   |  |  /  _____  \\  |  |\\   |    |  |\\  \\----.|  `--'  | |  `--'  | |  `----.|  |____     |  |        |  |     |  |____ \n"
        "| _| `._____| \\______/  |_______/    |_______/    |__| /__/     \\__\\ |__| \\__|    | _| `._____| \\______/   \\______/  |_______||_______|    |__|        |__|     |_______|\n";

}
string display_skull() {
    return
        "                                               _,.-------.,_\n"
        "                                          ,;~'             '~;,\n"
        "                                        ,;                     ;,\n"
        "                                       ;                         ;\n"
        "                                      ,'                         ',\n"
        "                                     ,;                           ;,\n"
        "                                     ; ;      .           .      ; ;\n"
        "                                     | ;   ______       ______   ; |\n"
        "                                     |  `/~\"     ~\" . \"~     \"~\\'  |\n"
        "                                     |  ~  ,-~~~^~, | ,~^~~~-,  ~  |\n"
        "                                      |   |        }:{        |   |\n"
        "                                      |   l       / | \\       !   |\n"
        "                                      .~  (__,.--\" .^. \"--.,__)  ~.\n"
        "                                      |     ---;' / | \\ `;---     |\n"
        "                                       \\__.       \\/^\\/       .__/\n"
        "                                        V| \\                 / |V\n"
        "                     __                  | |T~\\___!___!___/~T| |                  _____\n"
        "                  .-~  ~\"-.              | |`IIII_I_I_I_IIII'| |               .-~     \"-.\n"
        "                 /         \\             |  \\,III I I I III,/  |              /           Y\n"
        "                Y          ;              \\   `~~~~~~~~~~'    /               i           |\n"
        "                `.   _     `._              \\   .       .   /               __)         .'\n"
        "                  )=~         `-.._           \\ .    ^    ./           _..-'~         ~\"<_\n"
        "               .-~                 ~`-.._       ^~~~^~~~^       _..-'~                   ~.\n"
        "              /                          ~`-.._           _..-'~                           Y\n"
        "              {        .~\"-._                  ~`-.._ .-'~                  _..-~;         ;\n"
        "               `._   _,'     ~`-.._                  ~`-.._           _..-'~     `._    _.-\n"
        "                  ~~\"              ~`-.._                  ~`-.._ .-'~              ~~\"~\n"
        "                .----.            _..-'  ~`-.._                  ~`-.._          .-~~~~-.\n"
        "               /      `.    _..-'~             ~`-.._                  ~`-.._   (        \".\n"
        "              Y        `=--~                  _..-'  ~`-.._                  ~`-'         |\n"
        "              |                         _..-'~             ~`-.._                         ;\n"
        "              `._                 _..-'~                         ~`-.._            -._ _.'\n"
        "                 \"-.=\"      _..-'~                                     ~`-.._        ~`.\n"
        "                  /        `.                                                ;          Y\n"
        "                 Y           Y                                              Y           |\n"
        "                 |           ;                                              `.          /\n"
        "                 `.       _.'                                                 \"-.____.-'\n"
        "                   ~-----\"\n";

}






class Player {
protected:

    string name;
    int health;
    int startinghealth = 3;
    int cash;
    int round = 0; 
    bool check_win;
    vector<string> inventory;
public:
    //creating public player constructor
    Player(const string& playername, int playerhealth, int playercash, bool playercheck_win) :
        name(playername), health(playerhealth), cash(playercash), check_win(playercheck_win) {}

    string getName() const {
        return name;
    }
    void take_damage(int damage) {
        health -= damage;
        if (health <= 0) {
            health = 0;
        }
        else {
            cout << name << " took " << damage << " Only " << health << " lives remain..." << endl;
        }
    }
    

    void death(const string& playername) {
        cout << playername << " HAS DIED" << endl;
        cout << display_skull() << endl;
        cout << "GAME OVER" << endl;

    }
    void setName(const string& playername) {
        name = playername;
    }
    void resetHealth() {
        health = startinghealth;
    }

    int checkCash() const {
        return cash;
    }

    void add_cash(int playercash) {
        cash += playercash;
    }

    int getHealth() const {
        return health;
    }

    void setHealth(int playerhealth) {
        health = playerhealth;
    }

    void setW(bool playercheck_win) {
        check_win = playercheck_win;

    }

    bool checkW() {
        return check_win;
    }
    void displayInfo() {
        cout << "Name: " << name << "\n";
        cout << "Health: " << health << "\n";
        cout << "Cash: " << cash << "\n";
        cout << "__________________" << endl;

    }
  //------------------------------------------------------this will save the player round and cash to leaderboard---------------------------------------// 

    static void save_leaderboard(const Player& player) {
        ofstream leaderboard("leaderboard.txt", ios::app); 
        if (leaderboard.is_open()) {
            leaderboard << player.getName() << " " << player.checkCash()  << endl; 
            leaderboard.close();
            cout << "Saved Score Successfully" << endl;
        }
        else {
            cout << "Unable to open leaderboard file for writing." << endl;
            cout << "Unable to save score" << endl;  
        }
    }

    static void display_leaderboard() {
        ifstream leaderboard("leaderboard.txt");
        string name;
        int cash;
        vector<pair<string, int>> leaderboardData;

        if (leaderboard.is_open()) {
            while (leaderboard >> name >> cash) {
                leaderboardData.push_back(make_pair(name, cash));
            }
            leaderboard.close();

            // Sort the leaderboard by cash in descending order
            sort(leaderboardData.begin(), leaderboardData.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
                return a.second > b.second;  // Sort by cash, highest first
                });

            cout << "Leaderboard:" << endl;
            for (const auto& entry : leaderboardData) {
                cout << entry.first << " - " << entry.second << " cash" << endl;
            }
        }
        else {
            cout << "Unable to open leaderboard file for reading." << endl;
        }
    }






}; 


class Computer {
protected:
    string name; 
    int health ;
    bool check_win;
public:
    //basic constructor 

    Computer(const string& computername, int computerhealth, bool computercheck_win) : 
    name(computername), health(computerhealth) , check_win(computercheck_win){}

    string getName() const {
        return name;
    }
    void setName(const string& computername) {
        name = computername;
    }

    void take_damage(int damage) {
        health -= damage;
        if (health <= 0) {
            health = 0;
        }
        else {
            cout << name << " took " << damage << " Only " << health << " lives remain..." << endl;
        }
    }

    int getHealth() {
        return health;
    }

    void setHealth(int computerhealth) {
        health = computerhealth; 
    }

    void checkwin() const {
        if (health <= 0){
            cout << name << " has died.Player wins." << endl; 
            
            
        }else{
            cout << name << " is stil alive with " << health << " lives left." << endl; 
        }

    }
    void display_stats(){
        cout << "Computer Stats: " << endl;
        cout <<"Name: " << getName() << endl;
        cout <<"Health: " << getHealth() << endl;
        cout << "-----------------------" << endl; 

    
    }


    void reset(const string& computername, int computerhealth, bool check_win) {
        cout << getName() << " Had Died. Resetting stats now." << endl;
        setHealth(4);
        check_win = true;
    }





};