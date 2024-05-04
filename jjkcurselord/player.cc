//JJKCurseLord: Samuel Goosey
#include "jjkcurselord.h"
#include "maps.h"

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

Player::Player(WINDOW* w, int y, int x, int pchar) {
    win = w;
	debugwin = newwin(4, 16, 0, 88);
    yPos = y;
    xPos = x;
	playerChar = pchar;
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

WINDOW* Player::getwin() {
	return win;
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
            case 'M': {
				wclear(debugwin);
				wrefresh(debugwin);
                UI menu(this);
				choice = menu.getinput();
                break;
			}
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
	for (const auto &pair : currmap->scene_data) {
		mvwaddchcolor(win, pair.second.first, pair.second.second, pair.first, getcolorID(pair.first));
	}
}

void Player::debug() {
	wclear(debugwin);
	mvwprintw(debugwin, 1, 1, "Pos y: %d", yPos);
	mvwprintw(debugwin, 2, 1, "Pos x: %d", xPos);
	wrefresh(debugwin);
}

void Player::display() {
    loadmap();
	debug();
	wborder(win, (int)'|', (int)'|', (int)'-', (int)'-', (int)'+', (int)'+', (int)'+', (int)'+');
    mvwaddch(win, yPos, xPos, playerChar);
    wmove(win, yPos, xPos);
    wrefresh(win);
}

void Player::linkmaps() {
    Player_Map* tavern = new Player_Map(map0);
	Player_Map* outside = new Player_Map(map1);
	//setpointer(north, south, east, west)
	tavern->setpointers(nullptr, nullptr, outside, nullptr);
	outside->setpointers(nullptr, nullptr, nullptr, tavern);
    currmap = tavern;
}