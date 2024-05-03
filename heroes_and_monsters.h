//Tanner Dunn - Iheritor of Suffering
#pragma once
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <string>
#include <stdexcept>
#include "unistd.h"
using namespace std;

class Actor{
protected:
	int y, x = 0;
	bool is_called = false;
	int total = 0;
public:
	Actor(int new_y, int new_x);
	virtual ~Actor() = default;
	virtual pair<int, int> get_location() = 0;
	void move_location(int new_y, int new_x);
	void total_characters();	
};
class Stationary_Object : public Actor{
protected:
	string object_name = "";
public:
	Stationary_Object(int y, int x);
	void set_name(const string& new_name);
	string get_name();
	pair<int, int> get_location() override;
};
class Hero : public Actor{ 
protected:
	string name = "";
	int attack_damage = 0;
	int HP = 0;
	int init = 0;
public: 
	Hero(int y, int x, int basehealth, int initiative);
	void set_name(const string &new_name);
	string get_name() const;
	void set_DPS(int DPS);
	int get_DPS() const;
	void set_HP(int newHP);
	int get_HP() const;
	void set_initiative(int new_initiative);
	int get_initiative() const;
	virtual void attack(int x) = 0; 
};
class George_Washington : public Hero{
public:
	George_Washington(int y, int x);
	void attack(int x) override; 
	pair<int, int> get_location() override;
};
class Benjamin_Franklin : public Hero{
public:
	Benjamin_Franklin(int y, int x);
	void attack(int x) override; 
	pair<int, int> get_location() override;
};
class John_Adams : public Hero{
public:
	John_Adams(int y, int x);
	void attack(int x) override;
	pair<int, int> get_location() override;
};
class James_Madison : public Hero{
public:
	James_Madison(int y, int x);
	void attack(int x) override;
	pair<int, int> get_location() override;
};
class Thomas_Jefferson : public Hero{
public:
	Thomas_Jefferson(int y, int x);
	void attack(int x) override;
	pair<int, int> get_location() override;
};
class Monster : public Actor{
protected:
	string name = "";
	int attack_damage = 0;
	int HP = 0;
	int init = 0;
public:
	Monster(int y, int x, int basehealth, int initiative); 
	void set_DPS(int DPS);
	int get_DPS() const;
	void set_HP(int newHP);
	int get_HP() const;
	void set_initiative(int new_initiative);
	int get_initiative() const;
	virtual void attack() = 0;
	virtual void run_ai() = 0;
};
class King_George_III : public Monster{
public:
	King_George_III(int y, int x);
	void attack() override;
	pair<int, int> get_location() override;
	void run_ai() override;
};
class Robo_Shakespeare : public Monster{
public:
	Robo_Shakespeare(int y, int x);
	void attack() override;
	pair<int, int> get_location() override;
	void run_ai() override;
};
class Kraken : public Monster{
public:
	Kraken(int y, int x);
	void attack() override;
	pair<int, int> get_location() override;
	void run_ai() override;
};
class Red_Coat_General : public Monster{
public:
	Red_Coat_General(int y, int x);
	void attack() override;
	pair<int, int> get_location() override;
	void run_ai() override;
};
class Three_Musketeers : public Monster{
public:
	Three_Musketeers(int y, int x);
	void attack() override;
	pair<int, int> get_location() override;
	void run_ai() override;
};
class Red_Coats : public Monster{
public:
	Red_Coats(int y, int x);
	void attack() override;
	pair<int, int> get_location() override;
	void run_ai() override;
};
//HOW TO USE:
//To create a character, perform the following command: "George_Washington gerorge_washington(10, 10)." Remember that (10, 10) only holds ints that are supposed to represent the characters location on the map. You can move their location by calling the function "move_location(20, 20)." You can also get the location by calling "get_location()." Some error checking may be needed in main to ensure that the character does not go out of bounds.
//To attack, perform the following command: "george_washington.attack()." This will pull up a multiple choice selection of attacks to choose from. Each attack has a designated DPS number, than can be accessed by calling "get_DPS()." The monster have random attacks based on a random number generator I made. 
//To access the HP of the characters, perform the following command: "george_washington.get_HP()." This will return the current HP of the character. If HP is 0 or less then a message will be printed to the screen saying "YOU DIED."
//To set the name of a character, perform the following command: "George_Washington.set_name("George Washington")." To get the name simply call "George_Washington.get_name()." The Founding fathers will want want to have their own respective names.
//Regarding the ai, the only classes that have an ai function are going to be the colonists and the monsters since the heroes are controlled by people. To run the ai function, all you do is create a colonist like "Colonist colonist(15,10)" and call "colonist.run_ai()" this will update the positon of the character randomly every three seconds.
//The function "total_character()" returns the total amount of character on the map by checking how many times a class has been called. I couldn't figure out then shared pointer stuff so it just returns an int.
