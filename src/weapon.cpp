#include "weapon.h"

Weapon::Weapon() {
    this-> name = "Fists";
    this->damage = 1;
    this->type = eUnarmed;
}

Weapon::Weapon(string name, int damage, weaponType type) {
    this->name = name;
    this->damage = damage;
    this->type = type;
}

int Weapon::getDamage() {
    return this->damage;
}

weaponType Weapon::getType() {
    return this->type;
}

string Weapon::getName() {
    return name;
}