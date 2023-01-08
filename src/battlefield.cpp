#include "battlefield.h"

Battlefield::Battlefield() {

}

vector<Character> Battlefield::getCombatants() {
    return combatants;
}

void Battlefield::addCombatant(Character combatant) {
    combatants.push_back(combatant);
}