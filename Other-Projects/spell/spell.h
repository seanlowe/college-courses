#pragma once
#include <string>

enum affects { self, others, area };
enum affected_area { mental, physical };
enum movement { follows, stationary };
enum effect { damages, heals };

class spell {
private: affects who;
private: affected_area what;
private: movement mvmt;
private: effect type;
private: string name;

public: void displaySpell() {
    cout << "Spell name: " + name + ". Spell attributes: \n\taffects - " + who + "\n\taffected area is " + what
    + "\n\tmovement is " + mvmt + "\n\teffect is " + type;
}

public: spell() {}
public: spell createSpell() {
    spell p;
    p.who = affectsWho();
    p.what = affectsWhat();
    p.mvmt = movesHow();
    p.type = effectsHow();
    return p;
}

public: affects affectsWho() {
    int input;
    cout << "Who do you want this spell to affect?\n";
    cout << "1. Yourself\n";
    cout << "2. Others\n";
    cout << "3. An area\n";
    cout << " > "; cin >> input;
    switch (input) {
        case 1:
            return affects::self;
        case 2:
            return affects::others;
        case 3:
            return affects::area;
        default:
            return affects::others;
    }
}

public: affected_area affectsWhat() {
    int input;
    cout << "What part do you want this spell to affect?\n";
    cout << "1. Mental\n";
    cout << "2. Physical\n";
    cout << " > "; cin >> input;
    switch (input) {
        case 1:
            return affected_area::mental;
        case 2:
            return affected_area::physical;
        default:
            return affected_area::physical;
    }
       
}

public: movement movesHow() {
    int input;
    cout << "How does this spell move?\n";
    cout << "1. Follow a Target\n";
    cout << "2. It's Stationary\n";
    cout << " > "; cin >> input;
    switch (input) {
        case 1:
            return movement::follows;
        case 2:
            return movement::stationary;
        default:
            return movement::stationary;
    }
}

public: effect effectsHow() {

}

};