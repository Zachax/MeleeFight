/*
Console based UI class for Melee Warrior game. 

Created by: Sakari Eskelinen

Changelog:
9.1.2023 Class created
10.1.2023 Implemented possibility to attack and to defeat enemies
14.5.2023 Enemies with < 1 hit points are not shown as active. The game ends when all enemies are down.

(All little changes are not necessarily booked up.)
*/

#include <iostream>
#include "battlefield.h"

// Action ID names
const string ATTACK = "Attack";
const string DEFEND = "Defend";
const string QUIT = "Quit game";
const string actions[] = { ATTACK, DEFEND, QUIT };

class Ui {
private:
    int gameRunning;
    void showActions();
    int inputAction();
    void performAction(int action, Battlefield*);
    void attack(Battlefield*);
public:
    bool enemiesRemaining(Battlefield);
    void runBattlefield(Battlefield*);
    void showWarriors(Battlefield);
    void setGameRunning(int);
    int getGameRunning();
    void endGame();
};