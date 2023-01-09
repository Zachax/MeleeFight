#include "weapon.h"

Weapon::Weapon() {
    name = "Fists";
    damage = 1;
    type = eUnarmed;
}

Weapon::Weapon(string name, int damage, weaponType type) {
    this->name = name;
    this->damage = damage;
    this->type = type;
}

int Weapon::getDamage() {
    return damage;
}

weaponType Weapon::getType() {
    return type;
}

string Weapon::getName() {
    return name;
}