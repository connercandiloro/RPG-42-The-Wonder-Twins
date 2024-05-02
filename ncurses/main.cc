#include "player.h"
using namespace std;

int main() {
    initscr();
    noecho();
    start_color();
	keypad(stdscr, true);

	WINDOW* mainwin = newwin(25, 87, 0, 0);
	wborder(mainwin, (int)'|', (int)'|', (int)'-', (int)'-', (int)'+', (int)'+', (int)'+', (int)'+');
	refresh();

	Player* p1 = new Player(mainwin, 13, 22,'G');
    
    //game loop, gets player input and updates the game accordingily
    int choice;
    do {
        p1->display();
        choice = p1->getinput();
    } while (choice != 'z');
    endwin();

    return 0;
}