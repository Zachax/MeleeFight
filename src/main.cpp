#include <iostream>
#include <string>
#include "ui.h"

using namespace std;

int main() {
    Character player("Player", 20, 1);
    Character enemy("Chicken", 10, 0);
    Character enemy2("Dinosaur", 130, 0);

    Weapon playerWeapon("Nasty Saber", 8, eOneHandedSword);
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