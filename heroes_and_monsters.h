//Tanner Dunn - Iheritor of Suffering
#pragma once
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

class Actor{
protected:
	int x, y;
public:
	Actor(int new_x, int new_y);
	virtual ~Actor();
	virtual void move_location(int new_x, int new_y);
	virtual int get_location();
};
class Stationary_Object : public Actor{
protected:
	string object_name;
public:
	Stationary_Object(int x, int y);
	void set_name(const string& new_name);
	string get_name();
	void move_location(int new_x, int new_y)override;
	int get_location()override;
};
class Hero : public Actor{ 
protected:
	string name;
	int attack_damage;
	int HP;
public: 
	Hero(int x, int y, int basehealth);
	void set_name(const string &new_name);
	string get_name() const;
	void set_DPS(int DPS);
	int get_DPS() const;
	void set_HP(int newHP);
	int get_HP() const;
	void attack(); 
};
class George_Washington : public Hero{
public:
	George_Washington(int x, int y);
	void attack() override; 
	void move_location(int new_x, int new_y) override;
	int get_location()override;
};
class Benjamin_Franklin : public Hero{
	Benjamin_Franklin(int x, int y);
	void attack() override; 
	void move_location(int new_x, int new_y) override;
	int get_location()override;
};
class John_Adams : public Hero{
	John_Adams(int x, int y);
	void attack() override;
	void move_location(int new_x, int new_y) override;
	int get_location()override;
};
class James_Madison : public Hero{
	James_Madison(int x, int y);
	void attack() override;
	void move_location(int new_x, int new_y) override;
	int get_location()override;
};
class Thomas_Jefferson : public Hero{
	Thomas_Jefferson(int x, int y);
	void attack() override;
	void move_location(int new_x, int new_y) override;
	int get_location()override;
};
class Colonist : public Hero{
	//TODO Need to figure out how to implement ai for non playable characters
};
class Monster : public Actor{
protected:
	string name;
	int attack_damage;
	int HP;
public:
	Monster(int x, int y, int basehealth); 
	void set_DPS(int DPS);
	int get_DPS() const;
	void set_HP(int newHP);
	int get_HP() const;
	void attack();
};
class King_Geroge_III : public Monster{
	King_George_III(int x, int y);
	void attack() override;
	void move_location(int new_x, int new_y) override;
	int get_location()override;
};
class Henry_Clinton : public Monster{
	Henry_Clinton(int x, int y);
	void attack() override;
	void move_location(int new_x, int new_y) override;
	int get_location()override;
};
class Cannon : public Monster{
	Cannon(int x, int y);
	void attack() override;
	void move_location(int new_x, int new_y) override;
	int get_location()override;
};
class Red_Coat_General : public Monster{
	Red_Coat_General(int x, int y);
	void attack() override;
	void move_location(int new_x, int new_y) override;
	int get_location()override;
};
class Red_Coat_Commander : public Monster{
	Red_Coat_Commander(int x, int y);
	void attack() override;
	void move_location(int new_x, int new_y) override;
	int get_location() override;
};
class Red_Coats : public Monster{
	//TODO Need to figure out how to implement ai for non playable characters
};
//HOW TO USE:
//To create a character, perform the following command: "George_Washington gerorge_washinton(10, 10)." Remember that (10, 10) only holds ints that are supposed to represent the characters location on the map. You can move their location by calling the function "move_location(20, 20)." You can also get the location by calling "get_location()." Some error checking may be needed in main to ensure that the character does not go out of bounds.
//To attack, perform the following command: "george_washington.attack()." This will pull up a multiple choice selection of attacks to choose from. Each attack has a designated DPS number, than can be accessed by calling "get_DPS()." The monster have random attacks based on a random number generator I made. 
//To access the HP of the characters, perform the following command: "george_washington.get_HP()." This will return the current HP of the character. If HP is 0 or less then a message will be printed to the screen saying "YOU DIED." 
#endif
