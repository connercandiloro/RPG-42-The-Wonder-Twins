#pragma once
#include <vector>
#include <string>
#include "ncurses.h"
#include "unordered_map"

class Player {
    WINDOW* win;
	int yPos, xPos;
	int playerChar;
public:
    struct Player_Map{
		std::vector<std::string> mapvec;
		Player_Map* north;
		Player_Map* south;
		Player_Map* east;
		Player_Map* west;
		Player_Map(std::vector<std::string> newmapvec);
		void setpointers(Player_Map* newnorth, Player_Map* newsouth, Player_Map* neweast, Player_Map* newwest);
		std::unordered_map<char, std::pair<int, int>> scene_data;
	};
    std::vector<std::string> backpack;
	Player_Map* currmap;
    Player(WINDOW* w, int y, int x, int pchar);
	~Player();
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