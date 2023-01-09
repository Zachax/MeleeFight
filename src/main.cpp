#include <iostream>
#include <string>
#include "ui.h"

using namespace std;

int main() {
    Character player("Player", 20, 1);
    Character enemy("Enemy", 15, 0);
    Character enemy2("Enemy2", 13, 0);

    Weapon playerWeapon("Nasty Saber", 8, eOneHandedSword);
    player.setWeapon(playerWeapon);

    Battlefield field;
    field.addCombatant(player);
    field.addCombatant(enemy);
    field.addCombatant(enemy2);

    Ui ui;
    ui.runBattlefield(field);
    
    return 0;
}