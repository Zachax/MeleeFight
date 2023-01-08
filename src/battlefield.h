/*
Battlefield class for Melee Warrior game. This is where the bloody fight ensues... .

Created by: Sakari Eskelinen

Changelog:
7.1.2023 Class created
*/

#include <vector>
#include "character.h"

class Battlefield {
private:
    vector<Character> combatants;
public:
    Battlefield();
    vector<Character> getCombatants();
    void addCombatant(Character);
};