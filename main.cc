#include "jjkcurselord.h"
#include "Thread_Lord.h"
#include<thread>
#include <mutex>
#include <deque>
using namespace std;

class Safe_Thread{
	mutex mut;
	deque<char> deck;
	public:
	Safe_Thread(){};
	void in_char(const char &c){
		lock_guard LG(mut);
		deck.push_back(c);
	}
	[[nodiscard]]	char out_char(){
		lock_guard LG(mut);
		char temp = deck.front();
		deck.pop_front();
		return temp;
	}
	[[nodiscard]]size_t size(){
		lock_guard LG(mut);
		return deck.size();
	}


} TS;

void user_IN(){
	usleep(uint32_t(rand()%5+1) * 1000);
	int  c = getch();
	TS.in_char(char(c));
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

	int choice;
	//main game loop
	cutscene_check(p);
	do {
	p->display(); //updates player position
	if (cutscene_check(p)) {
	break; //breaks game loop if final cutscene is played
	}
	choice = p->getinput();
	} while (choice != 'z'); //game quits whenever player inputs 'z'
	//game quits whenever player inputs 'z'
	endwin();

	return 0;
}
