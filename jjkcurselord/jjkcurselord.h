//JJKCurseLord: Samuel Goosey
#pragma once
#include <vector>
#include <string>
#include <ncurses.h>
#include "unordered_map"

class Player {
    WINDOW* win;
	WINDOW* debugwin;
	int yPos, xPos;
	int playerChar;
public:
    struct Player_Map{
		std::vector<std::string> mapvec;
		Player_Map* next;
		Player_Map* prev;
        int ID;
		Player_Map(std::vector<std::string> newmapvec);
		void setpointers(Player_Map* newprev, Player_Map* newnext, int mapid);
		std::unordered_map<char, std::pair<int, int>> scene_data;
	};
    std::vector<std::string> backpack;
	Player_Map* currmap;
    Player(WINDOW* w, int y, int x, int pchar);
	~Player();
	WINDOW* getwin();
	void mvup();
	void mvdown();
	void mvleft();
	void mvright();
	char checkup();
	char checkdown();
	char checkleft();
	char checkright();
    char getinput();
    void loadmap();
	void debug();
	void display();
    void linkmaps();
};

class UI {
    unsigned int option;
    int yPos;
    int xPos;
    int menu;
    WINDOW* win;
    WINDOW* debugwin;
    unsigned int menuOffset;
    Player* player;
public:
    UI(Player* p);
    void setpos(int y, int x);
    void mvup();
    void mvdown();
    char select();
    char getinput();
    void debug();
    void display();
    void loadmenu();
    void loadparty();
    void loadinventory();
    void clearwin();
};

void load_color();

void mvwaddchcolor(WINDOW* w, int y, int x, char c, int pairID);

void mvwprintwcolor(WINDOW* w, int y, int x, std::string s, int pairID);

int getcolorID(const char c, const Player* p);

bool canwalk(const char c, const Player* p);

bool hasDialogue(const char c);

struct Character {
    int yPos, xPos;
    char charLetter;
    Character* next;
    WINDOW* win;
    int hp;
    Character(int y, int x, char letter, WINDOW* w);
    Character(int y, int x, char letter, WINDOW* w, int h);
    void printHP();
    void moveChar(int direction, int amount, int speed);
    void display();
};

class turn_order {
    Character* first;
public:
    turn_order();
    Character* getfirst();
    void add(Character* c);
};

void start_combat_intro(Player* p);

void cutscene_check(Player* p);

void cutscene_intro(Player* p);

class Textbox {
    WINDOW* win;
public:
    Textbox();
    Textbox(char npc);
    void print(std::string line);
    bool print_select(std::string line, std::string select1, std::string select2);
    void clearwin();
    void confirm();
    bool select(std::string option1, std::string option2);
    void delwin();
};