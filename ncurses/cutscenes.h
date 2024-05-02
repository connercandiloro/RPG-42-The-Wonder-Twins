#pragma once
#include "ncurses.h"
#include "player.h"

struct Character {
    int yPos, xPos;
    char charLetter;
    Character(int y, int x, char letter);
    void moveX(int x);
    void moveY(int y);
};

void cutscene_intro(Player* p);