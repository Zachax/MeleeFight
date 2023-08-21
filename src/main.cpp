#include <iostream>
#include <string>
#include "ui.h"

using namespace std;

int main() {
    // Reminder: a Character is defined by: name, hp, isPlayer, skill
    Character player("Player", 20, 1, 75);
    Character enemy("Chicken", 10, 0, 10);
    Character enemy2("Dinosaur", 130, 0, 85);

    Weapon playerWeapon("Nasty Saber", 7, eOneHandedSword);
    player.setWeapon(playerWeapon);

    Battlefield field;
    Battlefield *pField = &field;
    field.addCombatant(player);
    field.addCombatant(enemy);
    field.addCombatant(enemy2);

    Ui ui;
    ui.runBattlefield(pField);
    
    return 0;
}