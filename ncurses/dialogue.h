#pragma once
#include "player.h"
#include <ncurses.h>

class Textbox {
    WINDOW* win;
    Player* p;
public:
    Textbox(const char npc, Player* p);
    void clearwin();
    void confirm();
};