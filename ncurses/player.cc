#include "player.h"
#include "attributes.h"
#include "maps.h"
#include "ui.h"

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