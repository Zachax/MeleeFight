#include "ui.h"

Ui::Ui() {
    // Hmm, nothing?
}

// After player turn, do enemy operations
// Basically, all enemies attack player
void Ui::doEnemyActions(Battlefield *field) {
    Character *player = field->getPlayer();
    vector<Character> characters = field->getCombatants();
    for (int i = 0; i < characters.size(); i++) {
        Character *combatant = &characters.at(i);
        if (!combatant->getIsPlayer() && combatant->isOperational()) {
            attack(combatant, player);
        } else {
            continue;
        }
    }
}

// Perform a player default attack
void Ui::playerAttack(Battlefield *field) {
    Character *player = field->getPlayer();
    Character *enemy = field->getNextEnemy();
    if (enemy != NULL) {
        attack(player, enemy);
    } else {
        cout << "There are no more enemies standing to attack against!" << endl;
    }
}

// Perform a generic attack a character against a character
void Ui::attack(Character *attacker, Character *target) {
    int damage = attacker->attackDamage();
    float skill = attacker->getSkill();
    
    // Get random number
    mt19937 rng(rd()); // Set the random number engine
    uniform_int_distribution<int> uni(0,100);
    int diceRoll = uni(rng);
    
    string attackerName = attacker->getName();
    string targetName = target->getName();
    cout << attackerName << " attacks " << targetName << " with " << attacker->getWeapon().getName() << " - ";
    if (diceRoll < skill) {
        cout << "and hits!" << endl;
        int hitPointsRemaining = target->causeDamage(damage);    
        cout << "The attack caused " << damage << " damage. " << targetName << " has " << hitPointsRemaining << " health remaining." << endl;
        if (hitPointsRemaining < 0) {
            cout << targetName << " drops dead!" << endl;
        }
    } else {
        cout << "but misses!" << endl;
    }    
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
        playerAttack(field);
    } else if (actionMatched == DEFEND) {
        cout << DEFEND << endl;
    } else if (actionMatched == QUIT) {
        cout << QUIT << endl;
        endGame();
    } else {
        cout << "Error, action code does not match: " << action << " (" << actionMatched << ")" << endl;
    }
}

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
        int hp = warrior.getHitPoints();
        int maxHp = warrior.getMaxHitPoints();
        if (warrior.getIsPlayer()) {
            cout << "You, " << warrior.getName() << " [" << hp << "/" << maxHp << "], equipped with " << warrior.getWeapon().getName() << endl;
        } else {
            if (hp > 0) {
                cout << "Enemy warrior, " << warrior.getName() << " [" << hp << "/" << maxHp << "], equipped with " << warrior.getWeapon().getName() << endl;
            } else {
                cout << "Downed enemy, " << warrior.getName() << endl;
            }
        }
    }
}

bool Ui::isPlayerAlive(Battlefield *field) {
    Character *player = field->getPlayer();
    if (player->getHitPoints() < 1) {
        return false;
    } else {
        return true;
    }
}

/* PUBLIC functions */

// Starts the game and its main loop
void Ui::runBattlefield(Battlefield *field) {
    cout << "Warriors on the battlefield:" << endl;
    if (!getGameRunning()) {
        setGameRunning(1);
    }
    while(getGameRunning()) {
        showWarriors(*field);
        if (isPlayerAlive(field)) {
            if (enemiesRemaining(*field)) {
                showActions();
                int command = inputAction();
                performAction(command, field);
                doEnemyActions(field);
            } else {
                cout << "All enemies are down!" << endl;
                setGameRunning(0);
            }
        } else {
            cout << "You are now dead!" << endl;
            setGameRunning(0);
        }
    }

    cout << "Thanks for playing!" << endl;
}

// 0 stop, anything else is running, obviously
void Ui::setGameRunning(int runningMode) {
    gameRunning = runningMode;
}

int Ui::getGameRunning() {
    return gameRunning;
}

// Quit the game to OS
void Ui::endGame() {
    cout << "Bye bye, hope you at least tried..." << endl;
    exit(0);
}