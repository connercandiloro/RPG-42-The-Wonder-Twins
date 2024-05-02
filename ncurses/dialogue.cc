//JJKCurseLord: Samuel Goosey
#include "dialogue.h"
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

void Textbox::delwin() {
	wclear(win);
	wrefresh(win);
}