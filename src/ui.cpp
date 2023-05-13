#include "ui.h"

// Checks if all enemies are down
bool Ui::enemiesRemaining(Battlefield field) {
    bool enemiesRemaining = false; // flag for whether anyone is still operational
    vector<Character> people = field.getCombatants();
    for (int i = 0; i < people.size(); i++) {
        Character warrior = people.at(i);
        if (warrior.getIsPlayer()) {
            continue;
        } else {
            // If even a single enemy remains, there is still action
            if (warrior.getHitPoints() > 0) {
                enemiesRemaining = true;
                break;
            } 
        }
    }
    return enemiesRemaining;
}

// Prints enemies on the field
void Ui::showWarriors(Battlefield field) {
    vector<Character> people = field.getCombatants();
    for (int i = 0; i < people.size(); i++) {
        Character warrior = people.at(i);
        if (warrior.getIsPlayer()) {
            cout << "You, " << warrior.getName() << ", equipped with " << warrior.getWeapon().getName() << endl;
        } else {
            if (warrior.getHitPoints() > 0) {
                cout << "Enemy warrior, " << warrior.getName() << ", equipped with " << warrior.getWeapon().getName() << endl;
            } else {
                cout << "Downed enemy, " << warrior.getName() << endl;
            }
        }
    }
}

// Starts the game and its main loop
void Ui::runBattlefield(Battlefield *field) {
    cout << "Warriors on the battlefield:" << endl;
    if (!getGameRunning()) {
        setGameRunning(1);
    }
    while(getGameRunning()) {
        showWarriors(*field);
        if (enemiesRemaining(*field)) {
            showActions();
            int command = inputAction();
            performAction(command, field);
        } else {
            cout << "All enemies are down!" << endl;
            setGameRunning(0);
        }
    }
}

// 0 stop, anything else is running, obviously
void Ui::setGameRunning(int runningMode) {
    gameRunning = runningMode;
}

int Ui::getGameRunning() {
    return gameRunning;
}

// Prints list of possible actions defined by actions array in header.
// Action functionality must be defined separately!
void Ui::showActions() {
    cout << "Input action:" << endl;
    for (int i = 0; i < sizeof(actions)/sizeof(actions[0]) ; i++) {
        // Note: index value is added one because action list starting from zero is just annyoing in human UI
        cout << i+1 << " " << actions[i] << endl;
    }
}

// Player command
int Ui::inputAction() {
    int command;
    cin >> command;
    return --command; // Action index value shown to player is one off, see Ui::showActions()
}

// Do the actual action given by ID
// Matching ID name with index
void Ui::performAction(int action, Battlefield *field) {
    string actionMatched = actions[action];
    cout << "You have decided to: ";
    if (actionMatched == ATTACK) {
        cout << ATTACK << endl;
        attack(field);
    } else if (actionMatched == DEFEND) {
        cout << DEFEND << endl;
    } else if (actionMatched == QUIT) {
        cout << QUIT << endl;
        endGame();
    } else {
        cout << "Error, action code does not match: " << action << " (" << actionMatched << ")" << endl;
    }
}

void Ui::endGame() {
    exit(0);
}

void Ui::attack(Battlefield *field) {
    Character *enemy = field->getNextEnemy();
    if (enemy != NULL) {
        Character *player = field->getPlayer();
        int damage = player->attackDamage();
        int hitPointsRemaining = enemy->causeDamage(damage);
        cout << "Attacking " << enemy->getName() << " with " << player->getWeapon().getName() << "!" << endl;
        cout << "Caused " << damage << " damage. Enemy has " << hitPointsRemaining << " health remaining." << endl;
        if (hitPointsRemaining < 0) {
            cout << enemy->getName() << " drops dead!" << endl;
        }
    } else {
        cout << "There are no more enemies standing to attack against!" << endl;
    }
}