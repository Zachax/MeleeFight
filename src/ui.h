/*
Console based UI class for Melee Warrior game. 

Created by: Sakari Eskelinen

Changelog:
9.1.2023 Class created
10.1.2023 Implemented possibility to attack and to defeat enemies
14.5.2023 Enemies with < 1 hit points are not shown as active. The game ends when all enemies are down.
21.8.2023 Added HP to default view of a character. Refactoring. Added enemies turn, they now attack back. Added RNG engine.

(All little changes are not necessarily booked up.)
*/

#include <iostream>
#include <random>
#include "battlefield.h"

// Action ID names
const string ATTACK = "Attack";
const string DEFEND = "Defend";
const string QUIT = "Quit game";
const string actions[] = { ATTACK, DEFEND, QUIT };

class Ui {
private:
    random_device rd; // Init random seed
    int gameRunning;
    void showActions();
    int inputAction();
    void performAction(int action, Battlefield*);
    void playerAttack(Battlefield*);
    void doEnemyActions(Battlefield *);
    void attack(Character*, Character*);
    void showWarriors(Battlefield);
    bool enemiesRemaining(Battlefield);
    bool isPlayerAlive(Battlefield*);
public:
    Ui();
    void runBattlefield(Battlefield*);
    void setGameRunning(int);
    int getGameRunning();
    void endGame();
};