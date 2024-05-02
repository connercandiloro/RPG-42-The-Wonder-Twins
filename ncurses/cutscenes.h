//JJKCurseLord: Samuel Goosey
#pragma once
#include "ncurses.h"
#include "player.h"

struct Character {
    int yPos, xPos;
    char charLetter;
    WINDOW* win;
    Character(int y, int x, char letter, WINDOW* w);
    void moveChar(int direction, int amount, int speed);
    void display();
};

void cutscene_check(Player* p);

void cutscene_intro(Player* p);