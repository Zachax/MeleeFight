/*
Character class for Melee Warrior game. These Character objects are the combatants.

Created by: Sakari Eskelinen

Changelog:
7.1.2023 Class created
10.1.2023 Added isOperational method and some getters.
21.8.2023 Added maxHitPoints. Added skill.

(All little changes are not necessarily booked up.)
*/

#include <string>
#include "weapon.h"

using namespace std;

class Character {
private:
    string name = "Unnamed";
    int hitPoints, maxHitPoints, isPlayer;
    Weapon weapon;
    double skill;
public:
    int causeDamage(int);
    void setWeapon(Weapon);
    int attackDamage();
    string getName();
    Weapon getWeapon();
    int getIsPlayer();
    int getHitPoints();
    int getMaxHitPoints();
    int isOperational();
    float getSkill();
    Character(string name, int hp, int isPlayer, float skill);
};