#include <iostream>
#include "character.h"

Character::Character(string name, int hp, int isPlayer) {
    this->hitPoints = hp;
    this->name = name;
    this->isPlayer = isPlayer;
}

// Returns remaining hitpoints, so the return value can be directly printed out.
int Character::causeDamage(int damage) { 
    hitPoints -= damage;
    cout << this->hitPoints << " <- debug value" << endl;
    return hitPoints;
}

void Character::setWeapon(Weapon newWeapon) { 
    weapon = newWeapon;
}

// Returns total damage of the Character with currect condition & equipment.
int Character::attackDamage() {
    int weaponDamage = this->weapon.getDamage();
    return weaponDamage;
}

string Character::getName() {
    return name;
}

Weapon Character::getWeapon() {
    return weapon;
}

// 0 means enemy character
int Character::getIsPlayer() {
    return isPlayer;
}

int Character::getHitPoints() {
    return hitPoints;
}

// Checkup if the character is still combat capable.
// For now only checking if health is above 0, later on maybe more.
int Character::isOperational() {
    return hitPoints > 0;
}