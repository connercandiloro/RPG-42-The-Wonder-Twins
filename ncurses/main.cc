#include "jjkcurselord.h"
using namespace std;

int main() {
    initscr();
    noecho();
    start_color();
	keypad(stdscr, true);

	WINDOW* mainwin = newwin(25, 87, 0, 0);
	wborder(mainwin, (int)'|', (int)'|', (int)'-', (int)'-', (int)'+', (int)'+', (int)'+', (int)'+');
	refresh();

	Player* p = new Player(mainwin, 11, 44,'G');
    //game loop, gets player input and updates the game accordingily
    int choice;
    p->loadmap();
    wrefresh(mainwin);
    do {
        cutscene_check(p);
        p->display();
        choice = p->getinput();
    } while (choice != 'z');
    endwin();

    return 0;
}