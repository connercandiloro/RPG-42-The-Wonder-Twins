#pragma once
#include <string>
#include "player.h"
#include "ncurses.h"

void load_color();

void mvwaddchcolor(WINDOW* w, int y, int x, char c, int pairID);

void mvwprintwcolor(WINDOW* w, int y, int x, std::string s, int pairID);

int getcolorID(const char c);

bool canwalk(const char c, const Player* p);

bool hasDialogue(const char c);