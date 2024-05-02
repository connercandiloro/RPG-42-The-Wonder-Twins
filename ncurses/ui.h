//JJKCurseLord: Samuel Goosey
#pragma once
#include "ncurses.h"
#include "player.h"

class UI {
    unsigned int option;
    int yPos;
    int xPos;
    int menu;
    WINDOW* win;
    WINDOW* debugwin;
    unsigned int menuOffset;
    Player* player;
public:
    UI(Player* p);
    void setpos(int y, int x);
    void mvup();
    void mvdown();
    char select();
    char getinput();
    void debug();
    void display();
    void loadmenu();
    void loadparty();
    void loadinventory();
    void clearwin();
};