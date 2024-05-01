//JJK Curse Lord: Samuel Goosey
#include "jjkcurselord.h"
#include "maps.h"
#include "attributes.h"
using std::vector, std::string;

Player::Player_Map::Player_Map(vector<string> newmapvec) {
	mapvec = newmapvec;
	north = south = east = west = nullptr;
}

void Player::Player_Map::setpointers(Player_Map* newnorth, Player_Map* newsouth, Player_Map* neweast, Player_Map* newwest) {
	north = newnorth;
	south = newsouth;
	east = neweast;
	west = newwest;
}

Player::Player(WINDOW* w, int y, int x) {
    win = w;
    yPos = y;
    xPos = x;
    linkmaps();
	load_color();
    //placeholder items for debug purposes
    backpack.push_back("Item 1");
    backpack.push_back("Item 2");
    backpack.push_back("Item 3");
    backpack.push_back("Item 4");
    backpack.push_back("Item 5");
    backpack.push_back("Item 6");
    backpack.push_back("Item 7");
    backpack.push_back("Item 8");
    backpack.push_back("Item 9");
    backpack.push_back("Item 10");
}

Player::~Player() {
    delete currmap;
}

void Player::mvup() {
    if (canwalk(checkup(), this)) {
        yPos--;
    }
}

void Player::mvdown() {
    if (canwalk(checkdown(), this)) {
        yPos++;
    }
}

void Player::mvleft() {
    if (canwalk(checkleft(), this)) {
        xPos--;
    }
}

void Player::mvright() {
    if (canwalk(checkright(), this)) {
            xPos++;
        }
}

char Player::checkup() {
	if (yPos - 1 == 0) {
		currmap = currmap->north; 
		yPos = 24;
		wclear(win);
	}
	return mvwinch(win, yPos - 1, xPos);
}

char Player::checkdown() { 
	if (yPos + 1 == 24) {
		currmap = currmap->south;
		yPos = 0;
		wclear(win);
	}
	return mvwinch(win, yPos + 1, xPos);
}

char Player::checkleft() {
	if (xPos - 1 == 0) {
		currmap = currmap->west;
		xPos = 86;
		wclear(win);
	}
	return mvwinch(win, yPos, xPos - 1);
}

char Player::checkright() {
	if (xPos + 1 == 86) {
		currmap = currmap->east;
		xPos = 0;
		wclear(win);
	}
	return mvwinch(win, yPos, xPos + 1);
}

char Player::getinput() {
    int choice;
    choice = getch();
		switch (choice){
			case 'w':
			case 'W':
			case KEY_UP:
				mvup();
				break;
			case 'a':
			case 'A':
			case KEY_LEFT:
				mvleft();
				break;
			case 's':
			case 'S':
			case KEY_DOWN:
				mvdown();
				break;
			case 'd':
			case 'D':
			case KEY_RIGHT:
			    mvright();
				break;
            case 'm':
            case 'M':
                UI(this);
                break;
			default:
				break;
		}
    return choice;
}

void Player::loadmap() {
    for (unsigned int i = 0; i < currmap->mapvec.size(); i++) {
		for (unsigned j = 0; j < currmap->mapvec[i].size(); j++) {
			mvwaddchcolor(win, i + 1, j + 1, currmap->mapvec[i][j], getcolorID(currmap->mapvec[i][j]));
		}
	}
}

void Player::debug() {
    WINDOW* debug = newwin(4, 16, 0, 88);
	mvwprintw(debug, 1, 1, "Pos y: %d", yPos);
	mvwprintw(debug, 2, 1, "Pos x: %d", xPos);
	wrefresh(debug);
}

void Player::display() {
    loadmap();
	debug();
	wborder(win, (int)'|', (int)'|', (int)'-', (int)'-', (int)'+', (int)'+', (int)'+', (int)'+');
    mvwaddch(win, yPos, xPos, '@');
    wmove(win, yPos, xPos);
    wrefresh(win);
}

void Player::linkmaps() {
    Player_Map* start = new Player_Map(map0);
	Player_Map* up = new Player_Map(map1);
	Player_Map* left = new Player_Map(map2);
	Player_Map* end = new Player_Map(map3);
	//setpointer(north, south, east, west)
	start->setpointers(up, nullptr, left, nullptr);
	up->setpointers(nullptr, start, end, nullptr);
	left->setpointers(end, nullptr, nullptr, start);
	end->setpointers(nullptr, left, nullptr, up);
    currmap = start;
}

UI::UI(Player* p) {
    yPos = 4;
	xPos = 7;
	option = 0;
	menu = 0;
	menuOffset = 0;
	player = p;
    win = newwin(21, 22, 2, 63);
	loadmenu();
    getinput();
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
    return 'm';
}

void UI::debug() {
    WINDOW* debug = newwin(6, 16, 0, 88);
	mvwprintw(debug, 1, 1, "Pos y: %d", yPos);
	mvwprintw(debug, 2, 1, "Pos x: %d", xPos);
	mvwprintw(debug, 3, 1, "Option: %d", option);
	mvwprintw(debug, 4, 1, "Menu Offset: %d", menuOffset);
	wrefresh(debug);
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