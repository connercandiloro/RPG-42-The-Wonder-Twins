//JJKCurseLord: Samuel Goosey
#include "jjkcurselord.h"

void load_color() {
    init_pair(1, COLOR_YELLOW, COLOR_BLACK);
    init_pair(2, COLOR_BLACK, COLOR_YELLOW);
    init_pair(3, COLOR_GREEN, COLOR_BLACK);
    init_pair(4, COLOR_CYAN, COLOR_BLACK);
    init_pair(5, COLOR_WHITE, COLOR_BLACK);
    init_pair(6, COLOR_BLACK, COLOR_WHITE);
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

int getcolorID(const char c, const Player* p) {
    if (p->currmap->ID == 0) {
        switch (c) {
            case '_':
            case '|':
                return 1;
            case '.':
                return 2;
        }
    }
    else if (p->currmap->ID == 1) {
        switch (c) {
            case '.':
                return 2;
            case ',':
                return 3;
        }
    }
    else if (p->currmap->ID == 2) {
        switch (c) {
            case '=':
            case '|':
                return 1;
            case ',':
                return 3;
            case '~':
                return 4;
            case '/':
            case '\\':
            case '<':
            case '>':
                return 5;
        }
    }
    else if (p->currmap->ID == 3) {
        switch (c) {
            case '~':
                return 4;
            case '/':
            case '\\':
            case '<':
            case '>':
                return 5;
        }
    }
    else if (p->currmap->ID == 4) {
        switch (c) {
            case '=':
            case '|':
                return 1;
            case ',':
                return 3;
            case '~':
                return 4;
            case '/':
            case '\\':
            case '<':
            case '>':
                return 5;
        }
    }
    else if (p->currmap->ID == 5) {
        switch (c) {
            case ',':
                return 3;
            case '.':
                return 6;
        }
    }
    else if (p->currmap->ID == 6) {
        switch (c) {
            case '.':
                return 6;
        }
    }
    return 0;
}

bool canwalk(const char c) {
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