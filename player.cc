//JJKCurseLord: Samuel Goosey
#include "jjkcurselord.h"
#include "maps.h"

using std::vector, std::string;

Player::Player_Map::Player_Map(vector<string> newmapvec) {
	mapvec = newmapvec;
	prev = next = nullptr;
}

void Player::Player_Map::setpointers(Player_Map* newprev, Player_Map* newnext, int mapid) {
	prev = newprev;
	next = newnext;
	ID = mapid;
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

int Player::gety() {
	return yPos;
}

int Player::getx() {
	return xPos;
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
		yPos = 24;
		wclear(win);
	}
	return mvwinch(win, yPos - 1, xPos);
}

char Player::checkdown() { 
	if (yPos + 1 == 24) {
		yPos = 0;
		wclear(win);
	}
	return mvwinch(win, yPos + 1, xPos);
}

char Player::checkleft() {
	if (xPos - 1 == 0) {
		currmap = currmap->prev;
		xPos = 86;
		wclear(win);
	}
	return mvwinch(win, yPos, xPos - 1);
}

char Player::checkright() {
	if (xPos + 1 == 86) {
		currmap = currmap->next;
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
			mvwaddchcolor(win, i + 1, j + 1, currmap->mapvec[i][j], getcolorID(currmap->mapvec[i][j], this));
		}
	}
	for (const auto &pair : currmap->scene_data) {
		mvwaddchcolor(win, pair.second.first, pair.second.second, pair.first, getcolorID(pair.first, this));
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
	Player_Map* outside_tavern = new Player_Map(map1);
	Player_Map* tavern_harbor = new Player_Map(map2);
	Player_Map* ocean = new Player_Map(map3);
	Player_Map* castle_harbor = new Player_Map(map4);
	Player_Map* outside_castle = new Player_Map(map5);
	Player_Map* castle = new Player_Map(map6);
	//setpointer(prev, next, mapID)
	tavern->setpointers(nullptr, outside_tavern, 0);
	outside_tavern->setpointers(tavern, tavern_harbor, 1);
	tavern_harbor->setpointers(outside_tavern, ocean, 2);
	ocean->setpointers(tavern_harbor, castle_harbor, 3);
	castle_harbor->setpointers(ocean, outside_castle, 4);
	outside_castle->setpointers(castle_harbor, castle, 5);
	castle->setpointers(outside_castle, nullptr, 6);
    currmap = tavern;
}