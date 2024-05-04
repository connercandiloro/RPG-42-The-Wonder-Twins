//JJKCurseLord: Samuel Goosey
#include "jjkcurselord.h"
using std::string;

UI::UI(Player* p) {
    yPos = 4;
	xPos = 7;
	option = 0;
	menu = 0;
	menuOffset = 0;
	player = p;
    win = newwin(21, 22, 2, 90);
	debugwin = newwin(6, 16, 0, 112);
	loadmenu();
}

void UI::setpos(int y, int x) {
    yPos = y;
    xPos = x;
}

void UI::mvup() {
    mvwaddch(win, yPos, xPos, ' ');
	if (menu == 0){
		xPos = (option % 2 == 0) ? xPos - 1 : xPos + 1;
		if (option > 0) {
			yPos -= 4;
			option--;
		}
		else if (option == 0) {
			yPos = 16;
			option = 3;
		}
	}
	else if (menu == 1) {
		if (option > 0) {
			yPos -= 3;
			option--;
		}
		else if (option == 0) {
			yPos = 19;
			option = 6;
		}
	}
	else if (menu == 2) {
		if (option > menuOffset) {
			yPos -= 3;
			option--;
		}
		else if (menuOffset > 0) {
			menuOffset--;
			option--;
			loadinventory();
		}
		else if (menuOffset + option == 0 and player->backpack.size() - 1 > 6 and player->backpack.size() != 0) {
			option = player->backpack.size() - 1;
			menuOffset = player->backpack.size() - 7;
			setpos(19, 1);
			loadinventory();
		}
	}
}

void UI::mvdown() {
    mvwaddch(win, yPos, xPos, ' ');
	if (menu == 0) {
		xPos = (option % 2 == 0) ? xPos - 1 : xPos + 1;
		if (option < 3) {
			yPos += 4;
			option++;
		}
		else if (option == 3) {
			yPos = 4;
			option = 0;
		}
	}
	else if (menu == 1) {
		if (option < 6) {
			yPos += 3;
			option++;
		}
		else if (option == 6) {
			yPos = 1;
			option = 0;
		}
	}
	else if (menu == 2) {
		if (option < player->backpack.size() - 1 and player->backpack.size() != 0) {
			if (yPos == 19) {
				menuOffset++;
				loadinventory();
			}
			else {
				yPos += 3;
			}
			option++;
		}
		else if (option == player->backpack.size() - 1 and player->backpack.size() - 1 > 6) {
			menuOffset = 0;
			option = 0;
			setpos(1, 1);
			loadinventory();
		}
	}
}

char UI::select() {
    if (menu == 0) {
		if (yPos == 4) {
			setpos(1,1);
			option = 0;
			loadparty();
		}
		else if (yPos == 8) {
			setpos(1,1);
			option = 0;
			loadinventory(); 
		}
		else if (yPos == 12) { return 'm'; }
		else if (yPos == 16) { return 'z'; }
	}
	else if (menu == 1) {
		if (yPos == 1) {}
		else if (yPos == 4) {}
		else if (yPos == 7) {}
		else if (yPos == 10) {}
		else if (yPos == 13) {}
		else if (yPos == 16) {}
		else if (yPos == 19) {
			setpos(4, 7);
			option = 0;
			loadmenu();
		}
	}
	return 'e';
}

char UI::getinput() {
    int choice;
	do {
		display();
		choice = getch();
		switch (choice){
			case 'w':
			case 'W':
			case KEY_UP:
				mvup();
				break;
			case 's':
			case 'S':
			case KEY_DOWN:
				mvdown();
				break;
			case 'e':
			case 'E':
			case 10: //Return/Enter
				choice = select();
				if (choice == 'z') {
					return 'z';
				}
				break;
			default:
				break;
		}
	} while (choice != 'm');
	wclear(win);
	wclear(debugwin);
	wrefresh(win);
	wrefresh(debugwin);
    return 'm';
}

void UI::debug() {
	wclear(debugwin);
	mvwprintw(debugwin, 1, 1, "Pos y: %d", yPos);
	mvwprintw(debugwin, 2, 1, "Pos x: %d", xPos);
	mvwprintw(debugwin, 3, 1, "Option: %d", option);
	mvwprintw(debugwin, 4, 1, "Menu Offset: %d", menuOffset);
	wrefresh(debugwin);
}

void UI::display() {
    debug();
	mvwaddch(win, yPos, xPos, '*');
	wmove(win, yPos, xPos);
	wrefresh(win);
}

void UI::loadmenu() {
    menu = 0;
	clearwin();
	wborder(win, (int)'|', (int)'|', (int)'-', (int)'-', (int)'+', (int)'+', (int)'+', (int)'+');
	mvwprintw(win, 4, 8, "Party");
	mvwprintw(win, 8, 7, "Backpack");
	mvwprintw(win, 12, 8, "Resume");
	mvwprintw(win, 16, 7, "Exit Game");
	wrefresh(win);
}

void UI::loadparty() {
    menu = 1;
	clearwin();
	wborder(win, (int)'|', (int)'|', (int)'-', (int)'-', (int)'+', (int)'+', (int)'+', (int)'+');
	mvwprintw(win, 1, 2, "Member 1");
	mvwprintw(win, 4, 2, "Member 2");
	mvwprintw(win, 7, 2, "Member 3");
	mvwprintw(win, 10, 2, "Member 4");
	mvwprintw(win, 13, 2, "Member 5");
	mvwprintw(win, 16, 2, "Member 6");
	mvwprintw(win, 19, 2, "Return");
	wrefresh(win);
}

void UI::loadinventory() {
    menu = 2;
	clearwin();
	wborder(win, (int)'|', (int)'|', (int)'-', (int)'-', (int)'+', (int)'+', (int)'+', (int)'+');
	int y = 1;
	for (unsigned int i = menuOffset; i < player->backpack.size(); i++) {
		string line = player->backpack[i];
		mvwprintw(win, y, 2, "%s", line.c_str());
		if (y == 19) {
			break;
		}
		y += 3;
	}
}

void UI::clearwin() {
    for (int i = 0; i < 20; i++) {
		mvwprintw(win, i, 1, "                     ");
	}
}