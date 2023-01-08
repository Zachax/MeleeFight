#include <iostream>
#include "battlefield.h"

using namespace std;

int main() {
    Character player("Player", 20);
    Character enemy("Enemy", 15);
    Character enemy2("Enemy2", 13);

    Weapon playerWeapon("Nasty Saber", 8, eOneHandedSword);
    player.setWeapon(playerWeapon);

    Battlefield field;
    field.addCombatant(player);
    field.addCombatant(enemy);
    field.addCombatant(enemy2);

    vector<Character> people = field.getCombatants();
    cout << "Warriors on the battlefield:" << endl;
    for (int i = 0; i < people.size(); i++) {
        Character warrior = people.at(i);
        cout << warrior.getName() << " equipped with " << warrior.getWeapon().getName() << endl;
    }
    return 0;
}