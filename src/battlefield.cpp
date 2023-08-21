#include "battlefield.h"

Battlefield::Battlefield() {
    // Hmm... To be done?
}

vector<Character> Battlefield::getCombatants() {
    return combatants;
}

void Battlefield::addCombatant(Character combatant) {
    combatants.push_back(combatant);
}

// Seeks and returns the first operational enemy Character from the battlefield
Character* Battlefield::getNextEnemy() {
    Character *nextEnemy = 0;
    int index = 0;
    do {
        nextEnemy = &combatants.at(index);
        if (!nextEnemy->getIsPlayer()) {
            // Next enemy found, but is it in OK condition?...
            if (nextEnemy->isOperational()) {
                return nextEnemy;
            } else {
                nextEnemy = 0;
            }
        } 
        index++;
    } while (nextEnemy != NULL || index < combatants.size());
    return nextEnemy;
}

// Seeks and returns the first player Character from the battlefield
Character* Battlefield::getPlayer() {
    Character *player = 0;
    int index = 0;
    do {
        player = &combatants.at(index);
        if (player->getIsPlayer()) {
            return player; // Player found
        }
        index++;
    } while (player != NULL || index < combatants.size());
    return NULL;
}