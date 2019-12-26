#include <iostream>
#include "tome.h"
using namespace std;

/* 
does the spell follow a person or stay in once place?
    does the spell follow a trajectory?
does the spell apply to caster or someone else?
    is the spell area-of-effect or single person?
is the spell harming or helping?
    does it affect the mind or body?
*/

/*
can assign different traits to the spell to make it behave in different ways
    traits:
        abrasive ->
        aggressive -> 
        angry ->
        balanced ->
        bouncing -> spell bounces along the ground or walls once or more times, losing speed
        brutal ->
        confused ->
        cruel ->
        demanding ->
        destructive ->
        disruptive ->
        dissonant -> lacking harmony
        dominating ->
        energetic -> faster spell, more powerful
        erratic -> 
        fiery ->
        focused -> more powerful but intense straight-line motion
        forceful -> 
        hateful ->
        neurotic (unstable) ->
        pure ->
        quick -> speeds up the spell
        reactionary ->
        relaxed -> 
        ricocheting -> spell ricochets once at full speed (useful around corners)
        slow -> slows down the spell
        tractable (easy to control) -> 
        willful (intentional, deliberate) ->
*/

int main() {
    tome book;
    
    do {
        spell s;
        s.createSpell();
        book.addToSpellBook(s);
    } while (book.length() < 5);

    system("pause");
    return EXIT_SUCCESS;
}