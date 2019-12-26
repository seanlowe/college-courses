#pragma once
#include "spell.h"
#include <vector>

class tome {
    private: std::vector<spell> spellbook;
    public: void addToSpellBook(spell s) {
        spellbook.push_back(s);
    }
    public: void printSpells() {
        for (spell p : spellbook) {
            p.displaySpell();
        }
    }
    public int length() {
        return spellbook.size();
    }
};