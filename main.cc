#include "jjkcurselord.h"
using namespace std;

int main() {
    //starts ncurses mode
    initscr();
    noecho();
    start_color();
	keypad(stdscr, true);

    //makes main game window
	WINDOW* mainwin = newwin(25, 87, 0, 0);
	wborder(mainwin, (int)'|', (int)'|', (int)'-', (int)'-', (int)'+', (int)'+', (int)'+', (int)'+');
	refresh();

    //makes new player with parameters (game window, yPos, xPos, player character)
	Player* p = new Player(mainwin, 11, 44, 'G');
    p->loadmap();
    wrefresh(mainwin);
    int choice;
    //main game loop
    do {
        cutscene_check(p); //checks for cutscene trigger
        p->display(); //updates screen
        choice = p->getinput(); //gets player input
    } while (choice != 'z');
    //game quits whenever player inputs 'z'
    endwin();

    return 0;
}