/*
Character class for Melee Warrior game. These Character objects are the combatants.

Created by: Sakari Eskelinen

Changelog:
7.1.2023 Class created
*/

#include <string>
#include "weapon.h"

using namespace std;

class Character {
private:
    string name = "Unnamed";
    int hitPoints;
    Weapon weapon;
public:
    int causeDamage(int);
    void setWeapon(Weapon);
    int attackDamage();
    string getName();
    Weapon getWeapon();
    Character(string name, int hp);
};