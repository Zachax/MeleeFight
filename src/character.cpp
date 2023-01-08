#include <string>
#include "character.h"

Character::Character(string name, int hp) {
    this->hitPoints = hp;
    this->name = name;
}

// Returns remaining hitpoints, so the return value can be directly printed out.
int Character::causeDamage(int damage) { 
    this->hitPoints -= damage;
    return hitPoints;
}

void Character::setWeapon(Weapon newWeapon) { 
    this->weapon = newWeapon;
}

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