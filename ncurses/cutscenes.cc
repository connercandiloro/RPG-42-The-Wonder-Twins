#include "cutscenes.h"

Character::Character(int y, int x, char letter) : yPos(y), xPos(x), charLetter(letter) {}

void Character::moveY(int y) {
    yPos += y;
}

void Character::moveX(int x) {
    xPos += x;
}

void cutscene_intro(Player* p) {
    
}