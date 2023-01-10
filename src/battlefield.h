/*
Battlefield class for Melee Warrior game. This is where the bloody fight ensues...

Created by: Sakari Eskelinen

Changelog (all little changes not necessarily booked up):
7.1.2023 Class created
10.1.2023 Added getNextEnemy and getPlayer methods.
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
    Character* getNextEnemy();
    Character* getPlayer();
};