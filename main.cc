#include "jjkcurselord.h"
#include "Thread_Lord.h"
#include<thread>
using namespace std;

void inputsafety(Thread_Safety& threadSafety){
	char input;
	cin>>input;
while(true){
		if(!cin) break;
		threadSafety.in_char(input);
	//	cout<< threadSafety.out_char()<< endl;
}
}
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
	//	p->getinput();
   // p->getinput(threadSafety.out_char());
choice= threadSafety.out_char();
//		choice = p->getinput(); //waits for player input

    } while (choice != 'z'); //game quits whenever player inputs 'z'
    input.join();
          while (choice == 'z');
    //game quits whenever player inputs 'z'
    endwin();

    return 0;
}
