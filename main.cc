#include "jjkcurselord.h"
using namespace std;

int main() {
    initscr();
    noecho();
	keypad(stdscr, true);

	WINDOW* mainwin = newwin(25, 87, 0, 0);
	wborder(mainwin, (int)'|', (int)'|', (int)'-', (int)'-', (int)'+', (int)'+', (int)'+', (int)'+');
	refresh();

	Player* p = new Player(mainwin, 13, 22);
    int choice;
    do {
        p->display();
        choice = p->getinput();
    } while (choice != 'z');
    endwin();

    return 0;
}