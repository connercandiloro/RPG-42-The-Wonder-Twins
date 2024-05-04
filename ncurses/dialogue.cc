//JJKCurseLord: Samuel Goosey
#include "jjkcurselord.h"
using std::string, std::to_string;

Textbox::Textbox() : win(newwin(5, 83, 25, 2)) {}

Textbox::Textbox(const char npc) : win(newwin(5, 83, 25, 2)) {
	clearwin();
	wrefresh(win);
    switch (npc) {
        default:
            break;
    }
}

void Textbox::print(string line) {
	clearwin();
	unsigned int lineSize = 81;
	if (line.size() > lineSize) {
		string line1, line2;
		while (!isspace(line[lineSize - 1])) {
			lineSize--;
		}
		line1 = line.substr(0, lineSize);
		line2 = line.substr(lineSize);
		mvwprintw(win, 1, 1, "%s", line1.c_str());
		mvwprintw(win, 2, 1, "%s", line2.c_str());
	}
	else {
		mvwprintw(win, 1, 1, "%s", line.c_str());
	}
	confirm();
}

bool Textbox::print_select(string line, string select1, string select2) {
	clearwin();
	mvwprintw(win, 1, 1, "%s", line.c_str());
	return select(select1, select2);
}

void Textbox::clearwin() {
    for (int i = 0; i < 5; i++) {
		mvwprintw(win, i, 0, "                                                                                  ");
	}
	wborder(win, (int)'|', (int)'|', (int)'-', (int)'-', (int)'+', (int)'+', (int)'+', (int)'+');
}

void Textbox::confirm() {
    int choice;
	mvwprintw(win, 3, 32, "*Press e to continue*");
	wrefresh(win);
	do {
		choice = getch();
		switch (choice) {
			case 'E':
			case 10:
				choice = 'e';
				break;
			default:
				break;
		}
	} while (choice != 'e');
}

bool Textbox::select(string option1, string option2) {
	mvwprintw(win, 2, 2, "%s", option1.c_str());
	mvwprintw(win, 3, 2, "%s", option2.c_str());
	int cursorY = 2;
	int choice;
	do {
		mvwaddch(win, cursorY, 1, '*');
		wmove(win, cursorY, 1);
		wrefresh(win);
		choice = getch();
		mvwaddch(win, cursorY, 1, ' ');
		switch(choice) {
			case 'W':
			case 'w':
			case KEY_UP:
				if (cursorY == 2) {
					cursorY++;
				}
				else {
					cursorY--;
				}
				break;
			case 'S':
			case 's':
			case KEY_DOWN:
				if (cursorY == 3) {
					cursorY--;
				}
				else {
					cursorY++;
				}
				break;
			case 'E':
			case 10:
				choice = 'e';
				break;
			default:
				break;
		};
	} while (choice != 'e');
	if (cursorY == 2) {
		return true;
	}
	return false;
}

void Textbox::delwin() {
	wclear(win);
	wrefresh(win);
}