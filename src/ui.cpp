#include "ui.h"

void Ui::showWarriors(Battlefield field) {
    vector<Character> people = field.getCombatants();
    for (int i = 0; i < people.size(); i++) {
        Character warrior = people.at(i);
        if (warrior.getIsPlayer()) {
            cout << "You, " << warrior.getName() << ", equipped with " << warrior.getWeapon().getName() << endl;
        } else {
            cout << "Enemy warrior, " << warrior.getName() << ", equipped with " << warrior.getWeapon().getName() << endl;
        }
    }
}

// Starts the game and its main loop
void Ui::runBattlefield(Battlefield field) {
    cout << "Warriors on the battlefield:" << endl;
    if (!getGameRunning()) {
        setGameRunning(1);
    }
    while(getGameRunning()) {
        showWarriors(field);
        showActions();
        int command = inputAction();
        performAction(command);
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
        cout << i << " " << actions[i] << endl;
    }
}

// Player command
int Ui::inputAction() {
    int command;
    cin >> command;
    return command;
}

// Do the actual action given by ID
// Matching ID name with index
void Ui::performAction(int action) {
    string actionMatched = actions[action];
    cout << "You have decided to: ";
    if (actionMatched == ATTACK) {
        cout << ATTACK << endl;
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