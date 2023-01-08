/*
Weapon class for Melee Warrior game. This is equipment for combatants. 

Created by: Sakari Eskelinen

Changelog:
7.1.2023 Class created
*/

#include <string>

using namespace std;

enum weaponType {eUnarmed,eOneHandedSword,eTwoHandedSword,eMace, eAxe};

class Weapon {
private:
    string name = "Generic Weapon";
    int damage;
    weaponType type;
public:
    int getDamage();
    weaponType getType();
    string getName();
    Weapon();
    Weapon(string name, int damage, weaponType type);
};