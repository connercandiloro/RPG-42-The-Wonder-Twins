//JJKCurseLord: Samuel Goosey
#pragma once
#include <ncurses.h>
#include <string>

class Textbox {
    WINDOW* win;
public:
    Textbox();
    Textbox(char npc);
    void print(std::string line);
    bool print_select(std::string line, std::string select1, std::string select2);
    void clearwin();
    void confirm();
    bool select(std::string option1, std::string option2);
    void delwin();
};