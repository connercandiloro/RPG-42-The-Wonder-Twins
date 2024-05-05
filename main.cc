#include "jjkcurselord.h"
using namespace std;

int main() {
    //starts ncurses mode
    initscr();
    noecho();
    start_color();

    //makes main game window
	WINDOW* mainwin = newwin(25, 87, 0, 0);
	wborder(mainwin, (int)'|', (int)'|', (int)'-', (int)'-', (int)'+', (int)'+', (int)'+', (int)'+');
    keypad(stdscr, true);
	refresh();

    //makes new player with parameters (game window, yPos, xPos, player character)
	Player* p = new Player(mainwin, 11, 44, 'G');
    p->loadmap();
    wrefresh(mainwin);
    int choice;
    //main game loop
    cutscene_check(p);
    do {
        p->display(); //updates player position
        if (cutscene_check(p)) {
            break; //breaks game loop if final cutscene is played
        }
        choice = p->getinput(); //waits for player input
    } while (choice != 'z'); //game quits whenever player inputs 'z'
    endwin();

    return 0;
}