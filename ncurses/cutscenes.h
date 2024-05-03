//JJKCurseLord: Samuel Goosey
#pragma once
#include "ncurses.h"
#include "player.h"

struct Character {
    int yPos, xPos;
    char charLetter;
    Character* next;
    WINDOW* win;
    int hp;
    Character(int y, int x, char letter, WINDOW* w);
    Character(int y, int x, char letter, WINDOW* w, int h);
    void printHP();
    void moveChar(int direction, int amount, int speed);
    void display();
};

class turn_order {
    Character* first;
public:
    turn_order();
    Character* getfirst();
    void add(Character* c);
};

void start_combat_intro(Player* p);

void cutscene_check(Player* p);

void cutscene_intro(Player* p);