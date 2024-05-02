#include "attributes.h"

void load_color() {
    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    init_pair(2, COLOR_BLACK, COLOR_WHITE);
}
void mvwaddchcolor(WINDOW* w, int y, int x, char c, int pairID) {
    wattron(w, COLOR_PAIR(pairID));
    mvwaddch(w, y, x, c);
    wattroff(w, COLOR_PAIR(pairID));
}

void mvwprintwcolor(WINDOW* w, int y, int x, std::string s, int pairID) {
    wattron(w, COLOR_PAIR(pairID));
    mvwprintw(w, y, x, "%s", s.c_str());
    wattroff(w, COLOR_PAIR(pairID));
}

int getcolorID(const char c) {
    switch (c) {
        case '_':
        case '|':
            return 1;
        case '.':
            return 2;
    }
    return 0;
}

bool canwalk(const char c, const Player* p) {
    switch (c) {
        case ' ':
            return true;
            break;
    }
    return false;
}

bool hasDialogue(const char c) {
    switch (c) {
        case 'N':
            return true;
            break;
    }
    return false;
}