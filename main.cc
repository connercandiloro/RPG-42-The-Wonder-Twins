#include "jjkcurselord.h"
#include "Thread_Lord.h"
#include<thread>
using namespace std;

void inputsafety(Thread_Safety& threadSafety){
while(true){
		char input;
		cin>>input;
		threadSafety.in_char(input);
}
}
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

	Thread_Safety threadSafety;

	thread input(inputsafety, ref(threadSafety));

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
    input.join();
          while (choice == 'z');
    //game quits whenever player inputs 'z'
    endwin();

    return 0;
}
