#include "player.h"
#include "cutscenes.h"
using namespace std;

int main() {
    initscr();
    noecho();
    start_color();
	keypad(stdscr, true);

	WINDOW* mainwin = newwin(25, 87, 0, 0);
	wborder(mainwin, (int)'|', (int)'|', (int)'-', (int)'-', (int)'+', (int)'+', (int)'+', (int)'+');
	refresh();

	Player* p1 = new Player(mainwin, 11, 44,'G');
    //game loop, gets player input and updates the game accordingily
    int choice;
    p1->loadmap();
    wrefresh(mainwin);
    //cutscene_intro(p1);
    do {
        p1->display();
        choice = p1->getinput();
    } while (choice != 'z');
    endwin();

    return 0;
}