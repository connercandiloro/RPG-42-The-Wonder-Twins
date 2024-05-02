#pragma once
#include <ncurses.h>
#include <string>

class Textbox {
    WINDOW* win;
public:
    Textbox();
    Textbox(char npc);
    void print(std::string line);
    void clearwin();
    void confirm();
};